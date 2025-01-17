#pragma once

#include <sead/basis/seadTypes.h>
#include <sead/prim/seadSafeString.h>

namespace sead {
class HashCRC16
{
public:
    struct Context
    {
        u32 hash = 0;
    };

    static u32 calcHash(const void* ptr, u32 size);
    static u32 calcHashWithContext(Context* context, const void* ptr, u32 size);

    static u32 calcStringHash(const char* str);
    static u32 calcStringHash(const SafeString& str) { return calcStringHash(str.cstr()); }
    static u32 calcStringHashWithContext(Context* context, const char* str);
    static u32 calcStringHashWithContext(Context* context, const SafeString& str)
    {
        return calcStringHashWithContext(context, str.cstr());
    }

    static void initialize();

private:
    static u16 sTable[256];
    static bool sInitialized;
};
}  // namespace sead
