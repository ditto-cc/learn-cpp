#ifndef _N90MASK_H
#define _N90MASK_H

#include <iostream>
#include "Mask.h"

class N90Mask : public Mask {
public:
    N90Mask() {
        std::cout << "Creating N90Mask" << std::endl;
    }

    ~N90Mask() = default;

    void wear() override {
        std::cout << "Using N90Mask" << std::endl;
    }
};

#endif
