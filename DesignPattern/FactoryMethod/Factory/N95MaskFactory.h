#ifndef _N95MASKFACTORY_H
#define _N95MASKFACTORY_H

#include "Factory.h"
#include "../Product/N95Mask.h"

class N95MaskFactory : public Factory {
public:
    Mask *createMask() override {
        return new N95Mask();
    }
};

#endif
