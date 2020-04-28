#ifndef _FACTORY_H
#define _FACTORY_H

#include "../Product/Mask.h"

class Factory {
public:
    virtual Mask *createMask() = 0;
    virtual ~Factory() = default;
};

#endif
