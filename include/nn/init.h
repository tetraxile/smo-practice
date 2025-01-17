/**
 * @file init.h
 * @brief Initialization functions for OS related functions.
 */

#pragma once

#include "mem.h"
#include "types.h"

namespace nn {
    namespace init
    {
        void InitializeAllocator(void *addr, u64 size);
        nn::mem::StandardAllocator* GetAllocator();

        namespace detail
        {
            void* DefaultAllocatorForThreadLocal(u64, u64);
            void* DefaultDeallocatorForThreadLocal(void *, u64);
        };
    }
};
