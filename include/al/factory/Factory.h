#pragma once

#include "types.h"
#include "al/util.hpp"

namespace al {
template <class T>
class Factory {
public:
    inline Factory() {};

    virtual const char * convertName(char const *name) const {
        return name; 
    };
    
    inline T getCreator(const char *name) {
        for (size_t i = 0; i < this->factoryCount; i++) {
            if (al::isEqualString(this->actorTable[i].actorName, name)) 
                return this->actorTable[i].createActorFunction;
        }
        return nullptr;
    };

public:
    const char *mName;
    al::NameToCreator<T> *mTable;
    int mCount;
};
} // namespace al
