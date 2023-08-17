// Copyright 2023 TikTok Pte. Ltd.
//
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

#pragma once

#include "solo/util/config.h"
#ifdef SOLO_USE_AES_INTRIN

#include <wmmintrin.h>

#include <array>
#include <cstddef>
#include <cstdint>
#include <memory>

#include "solo/util/defines.h"

namespace petace {
namespace solo {
namespace util {
namespace aes {

typedef __m128i Block;
typedef __m128i RoundKey[11];

void set_round_key(const Block& key, RoundKey& round_key);

void encrypt_ecb_ctr(const RoundKey& round_key, std::uint64_t counter, Block* out, std::size_t out_block_count);

}  // namespace aes
}  // namespace util
}  // namespace solo
}  // namespace petace
#endif
