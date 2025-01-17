#pragma once

#include "al/byaml/ByamlIter.h"
#include <sead/prim/seadSafeString.h>

namespace al {
    class PlacementInfo {
    public:
        PlacementInfo();

        void set(const al::ByamlIter &, const al::ByamlIter &);

        al::ByamlIter mPlacementIter;
        al::ByamlIter mZoneIter;
    };

    class PlacementId {
    public:
        PlacementId();
        PlacementId(const char *, const char *, const char *);

        bool init(const al::PlacementInfo &);
        bool isEqual(const al::PlacementId &) const;
        static bool isEqual(const al::PlacementId &, const al::PlacementId &);
        bool isValid() const;
        bool makeString(sead::BufferedSafeString *) const;

        const char* sVar1;
        const char* mUnitConfigName;
        const char* mID;
        const char* mCommonID;
    };
}
