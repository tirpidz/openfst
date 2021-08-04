// union-main.h
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
// Author: riley@google.com (Michael Riley)
//
// \file
// Creates the union of two FSTs. Includes helper function for
// fstunion.cc that templates the main on the arc type to support
// multiple and extensible arc types.

#ifndef FST_UNION_MAIN_H__
#define FST_UNION_MAIN_H__

#include "fst/bin/main.h"
#include "fst/lib/union.h"
#include "fst/lib/vector-fst.h"

namespace fst {

// Main function for fstunion templated on the arc type.
template <class Arc>
int UnionMain(int argc, char **argv, istream &strm,
             const FstReadOptions &opts) {
  Fst<Arc> *ifst1 = Fst<Arc>::Read(strm, opts);
  if (!ifst1) return 1;

  MutableFst<Arc> *ofst = 0;
  if (ifst1->Properties(kMutable, false)) {
    ofst = down_cast<MutableFst<Arc> *>(ifst1);
  } else {
    ofst = new VectorFst<Arc>(*ifst1);
    delete ifst1;
  }

  Fst<Arc> *ifst2 = Fst<Arc>::Read(argv[2]);
  if (!ifst2) return 1;

  Union(ofst, *ifst2);
  ofst->Write(argc > 3 ? argv[3] : "");

  return 0;
}

}  // namespace fst

#endif  // FST_UNION_MAIN_H__
