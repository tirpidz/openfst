// Copyright 2005-2020 Google LLC
//
// Licensed under the Apache License, Version 2.0 (the 'License');
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an 'AS IS' BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
// See www.openfst.org for extensive documentation on this weighted
// finite-state transducer library.
//
// Returns the shortest path in a (bounded-stack) PDT.

#include <fst/flags.h>

DEFINE_bool(keep_parentheses, false, "Keep PDT parentheses in result?");
DEFINE_string(queue_type, "fifo",
              "Queue type: one of: "
              "\"fifo\", \"lifo\", \"state\"");
DEFINE_bool(path_gc, true, "Garbage collect shortest path data?");
DEFINE_string(pdt_parentheses, "", "PDT parenthesis label pairs");

int pdtshortestpath_main(int argc, char **argv);

int main(int argc, char **argv) { return pdtshortestpath_main(argc, argv); }
