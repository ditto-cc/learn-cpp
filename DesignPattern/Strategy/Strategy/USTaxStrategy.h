
#ifndef STRATEGY_USTAXSTRATEGY_H
#define STRATEGY_USTAXSTRATEGY_H

#include <iostream>
#include "TaxStrategy.h"
using namespace std;

class USTaxStrategy : public TaxStrategy {
public:
    ~USTaxStrategy() override = default;

    double calculate(const Context &context) override {
        cout << "Calculate US Tax" << endl;
        return 0;
    }
};
#endif
