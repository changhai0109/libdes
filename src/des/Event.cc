/*
 * Copyright (c) 2012-2015, Nic McDonald
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * - Redistributions of source code must retain the above copyright notice, this
 * list of conditions and the following disclaimer.
 *
 * - Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the following disclaimer in the documentation
 * and/or other materials provided with the distribution.
 *
 * - Neither the name of prim nor the names of its
 * contributors may be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */
#include "des/Event.h"

#include <prim/prim.h>

#include "des/Model.h"

namespace des {

Event::Event()
    : model(nullptr), handler(nullptr), time(U64_MAX), epsilon(U8_MAX) {}

Event::Event(Model* _model, EventHandler _handler)
    : model(_model), handler(_handler), time(U64_MAX), epsilon(U8_MAX) {}

Event::Event(Model* _model, EventHandler _handler, u64 _time, u8 _epsilon)
    : model(_model), handler(_handler), time(_time), epsilon(_epsilon) {}

Event::~Event() {}

bool timeGreater(u64 _time1, u8 _epsilon1, u64 _time2, u8 _epsilon2) {
  if (_time1 == _time2) {
    return _epsilon1 > _epsilon2;
  } else {
    return _time1 > _time2;
  }
}

s32 timeCompare(u64 _time1, u8 _epsilon1, u64 _time2, u8 _epsilon2) {
  if (_time1 == _time2) {
    if (_epsilon1 == _epsilon2) {
      return 0;
    } else if (_epsilon1 > _epsilon2) {
      return 1;
    } else {
      return -1;
    }
  } else if (_time1 > _time2) {
    return 1;
  } else {
    return -1;
  }
}

bool EventComparator::operator()(const Event* _lhs, const Event* _rhs) const {
  return timeGreater(_lhs->time, _lhs->epsilon, _rhs->time, _rhs->epsilon);
}

}  // namespace des
