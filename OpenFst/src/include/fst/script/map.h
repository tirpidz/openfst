
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
// Author: jpr@google.com (Jake Ratkiewicz)

#ifndef FST_SCRIPT_MAP_H_
#define FST_SCRIPT_MAP_H_

#include <fst/script/arg-packs.h>
#include <fst/script/fst-class.h>
#include <fst/script/weight-class.h>
#include <fst/map.h>

namespace fst {
namespace script {

template <class M>
Fst<typename M::ToArc> *Map(const Fst<typename M::FromArc> &fst,
                            const M &mapper) {
  typedef typename M::ToArc ToArc;
  VectorFst<ToArc> *ofst = new VectorFst<ToArc>;
  Map(fst, ofst, mapper);
  return ofst;
}

enum MapType { IDENTITY_MAPPER, INVERT_MAPPER, PLUS_MAPPER, QUANTIZE_MAPPER,
               RMWEIGHT_MAPPER, SUPERFINAL_MAPPER, TIMES_MAPPER,
               TO_LOG_MAPPER, TO_LOG64_MAPPER, TO_STD_MAPPER };

typedef args::Package<const FstClass&, MapType, float,
                      const WeightClass &> MapInnerArgs;
typedef args::WithReturnValue<FstClass*, MapInnerArgs> MapArgs;

template <class Arc>
void Map(MapArgs *args) {
  const Fst<Arc> &ifst = *(args->args.arg1.GetFst<Arc>());
  MapType map_type = args->args.arg2;
  float delta =  args->args.arg3;
  typename Arc::Weight w = *(args->args.arg4.GetWeight<typename Arc::Weight>());

  if (map_type == IDENTITY_MAPPER) {
    args->retval = new FstClass(
        script::Map(ifst, IdentityMapper<Arc>()));
  } else if (map_type == INVERT_MAPPER) {
    args->retval = new FstClass(
        script::Map(ifst, InvertWeightMapper<Arc>()));
  } else if (map_type == PLUS_MAPPER) {
    args->retval = new FstClass(
        script::Map(ifst, PlusMapper<Arc>(w)));
  } else if (map_type == QUANTIZE_MAPPER) {
    args->retval = new FstClass(
        script::Map(ifst, QuantizeMapper<Arc>(delta)));
  } else if (map_type == RMWEIGHT_MAPPER) {
    args->retval = new FstClass(
        script::Map(ifst, RmWeightMapper<Arc>()));
  } else if (map_type == SUPERFINAL_MAPPER) {
    args->retval = new FstClass(
        script::Map(ifst, SuperFinalMapper<Arc>()));
  } else if (map_type == TIMES_MAPPER) {
    args->retval = new FstClass(
        script::Map(ifst, TimesMapper<Arc>(w)));
  } else if (map_type == TO_LOG_MAPPER) {
    args->retval = new FstClass(
        script::Map(ifst, WeightConvertMapper<Arc, LogArc>()));
  } else if (map_type == TO_LOG64_MAPPER) {
    args->retval = new FstClass(
        script::Map(ifst, WeightConvertMapper<Arc, Log64Arc>()));
  } else if (map_type == TO_STD_MAPPER) {
    args->retval = new FstClass(
        script::Map(ifst, WeightConvertMapper<Arc, StdArc>()));
  } else {
    LOG(FATAL) << "Error: unknown/unsupported mapper type un enum: "
               << map_type;
  }
}


#ifdef SWIG
%newobject Map;
#endif
FstClass *Map(const FstClass& f, MapType map_type,
         float delta = fst::kDelta,
         const WeightClass &w = fst::script::WeightClass::Zero());

}  // namespace script
}  // namespace fst

#endif  // FST_SCRIPT_MAP_H_
