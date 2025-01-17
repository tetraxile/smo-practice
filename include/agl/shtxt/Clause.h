/**
 * @file Clause.h
 * @brief Defines a clause for shader processing.
 */

#pragma once

#include <sead/prim/seadSafeString.h>
#include "types.h"

namespace agl {
    namespace shtxt
    {
        class Clause
        {
        public:
            class TableChecker
            {
            public:
                TableChecker();
            };

            typedef u8 Type;

            Clause();
            Clause(agl::shtxt::Clause::Type, char const *, char const *);
            ~Clause();

            u64 findNumberBlock(agl::shtxt::Clause::Type *, char const *);
            void appendTo(sead::BufferedSafeString *) const;
            void appendTo(sead::BufferedSafeString *, u32) const;
            void copyTo(sead::BufferedSafeString *) const;
            f64 toNumber() const;
            f64 forceNumber() const;
            u32 calcLineFeedCount() const;
            bool compareImpl(agl::shtxt::Clause const &, u32, agl::shtxt::Clause const *, agl::shtxt::Clause const *) const;
            bool compare(sead::SafeString const &, u32) const;
            bool compare(agl::shtxt::Clause const &, u32) const;
            s32 calcHash(void const *, u32, u32) const;

            agl::shtxt::Clause* _0;
            agl::shtxt::Clause* _8;
            u8 mClauseType;
            u8 _11;
            u8 _12;
            u8 _13;
            u32 _14;
            char* _18;
            char* _20;

            static bool cTableChecked;
            static u32* cHashTable;
        };
    };
};
