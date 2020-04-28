#ifndef _N95MASK_H
#define _N95MASK_H

#include <iostream>
#include "Mask.h"

class N95Mask : public Mask {
public:
    N95Mask() {
        std::cout << "Creating N95Mask" << std::endl;
    }

    ~N95Mask() = default;

    void wear() override {
        std::cout << "Using N95Mask" << std::endl;
    }
};

#endif
