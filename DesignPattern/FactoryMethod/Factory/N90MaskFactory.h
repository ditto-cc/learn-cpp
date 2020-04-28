#ifndef _N90MASKFACTORY_H
#define _N90MASKFACTORY_H

#include "Factory.h"
#include "../Product/N90Mask.h"

class N90MaskFactory : public Factory {
public:
    Mask *createMask() override {
        return new N90Mask();
    }
};

#endif
