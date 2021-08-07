// fstunion.cc

// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
// Copyright 2005-2010 Google, Inc.
// Author: riley@google.com (Michael Riley)
// Modified: jpr@google.com (Jake Ratkiewicz) - to use FstClass
//
// \file
// Creates the union of two FSTs.
//

#include <string>

#include <fst/script/union.h>
#include <iostream>
#include <fstream>

int main(int argc, char **argv) {
  using fst::script::FstClass;
  using fst::script::MutableFstClass;
  using fst::script::VectorFstClass;
  using fst::script::Union;

  string usage = "Creates the union of two FSTs.\n\n  Usage: ";
  usage += argv[0];
  usage += " in1.fst in2.fst [out.fst]\n";

  std::set_new_handler(FailedNewHandler);
  SetFlags(usage.c_str(), &argc, &argv, true);
  if (argc < 3 || argc > 4) {
    ShowUsage();
    return 1;
  }

  string in1_name = strcmp(argv[1], "-") != 0 ? argv[1] : "";
  string in2_name = strcmp(argv[2], "-") != 0 ? argv[2] : "";
  string out_name = argc > 3 ? argv[3] : "";

  if (in1_name == "" && in2_name == "") {
    LOG(ERROR) << argv[0]
               << ": Can't use standard i/o for both inputs.";
    return 1;
  }

  FstClass *ifst1 = FstClass::Read(in1_name);
  if (!ifst1) {
    return 0;
  }

  MutableFstClass *ofst = 0;
  if (ifst1->Properties(fst::kMutable, false)) {
    ofst = static_cast<MutableFstClass *>(ifst1);
  } else {
    ofst = new VectorFstClass(*ifst1);
    delete ifst1;
  }

  FstClass *ifst2 = FstClass::Read(in2_name);
  if (!ifst2) {
    return 1;
  }

  Union(ofst, *ifst2);
  ofst->Write(out_name);

  return 0;
}
