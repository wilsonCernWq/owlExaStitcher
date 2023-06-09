// Copyright 2022 The Khronos Group
// SPDX-License-Identifier: Apache-2.0

#pragma once

#include "array/Array.h"

namespace exa {

struct Array3DMemoryDescriptor : public ArrayMemoryDescriptor
{
  uint64_t numItems1{0};
  uint64_t numItems2{0};
  uint64_t numItems3{0};
  uint64_t byteStride1{0};
  uint64_t byteStride2{0};
  uint64_t byteStride3{0};
};

bool isCompact(const Array3DMemoryDescriptor &d);

struct Array3D : public Array
{
  Array3D(ExaStitchGlobalState *state, const Array3DMemoryDescriptor &d);

  size_t totalSize() const override;

  size_t size(int dim) const;
  anari::uint3 size() const;

  void privatize() override;

 private:
  size_t m_size[3] = {0, 0, 0};
};

} // namespace exa

EXA_ANARI_TYPEFOR_SPECIALIZATION(exa::Array3D *, ANARI_ARRAY3D);
