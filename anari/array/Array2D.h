// Copyright 2022 The Khronos Group
// SPDX-License-Identifier: Apache-2.0

#pragma once

#include "array/Array.h"

namespace exa {

struct Array2DMemoryDescriptor : public ArrayMemoryDescriptor
{
  uint64_t numItems1{0};
  uint64_t numItems2{0};
  uint64_t byteStride1{0};
  uint64_t byteStride2{0};
};

bool isCompact(const Array2DMemoryDescriptor &d);

struct Array2D : public Array
{
  Array2D(ExaStitchGlobalState *state, const Array2DMemoryDescriptor &d);

  size_t totalSize() const override;

  size_t size(int dim) const;
  anari::uint2 size() const;

  void privatize() override;

 private:
  size_t m_size[2] = {0, 0};
};

} // namespace exa

EXA_ANARI_TYPEFOR_SPECIALIZATION(exa::Array2D *, ANARI_ARRAY2D);
