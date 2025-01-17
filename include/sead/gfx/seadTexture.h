#pragma once

#include <sead/basis/seadTypes.h>
#include <sead/prim/seadRuntimeTypeInfo.h>

namespace sead {
class Texture
{
    SEAD_RTTI_BASE(Texture)

public:
    Texture() {}
    virtual ~Texture() {}

    virtual u32 getWidth() const = 0;
    virtual u32 getHeight() const = 0;
};

}  // namespace sead


