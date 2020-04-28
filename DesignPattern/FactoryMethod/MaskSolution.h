#ifndef _MASKSOLUTION_H
#define _MASKSOLUTION_H

#include <iostream>
#include "Factory/Factory.h"
#include "Product/Mask.h"

class MaskSolution {
private:
    Factory *factory = nullptr;

public:
    explicit MaskSolution(Factory *factory) : factory(factory) {}

    ~MaskSolution() {
        delete factory;
    }

    void setFactory(Factory *pFactory) {
        delete factory;
        this->factory = pFactory;
    }

    void getMaskSolution() {
        if (factory == nullptr) {
            std::cout << "NULL Factory. Error Occurred." << std::endl;
            return;
        }
        Mask *m = factory->createMask();
        m->wear();
        delete m;
    }
};

#endif
