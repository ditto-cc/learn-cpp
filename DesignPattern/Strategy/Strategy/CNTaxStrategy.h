
#ifndef STRATEGY_CNTAXSTRATEGY_H
#define STRATEGY_CNTAXSTRATEGY_H

#include <iostream>
#include "TaxStrategy.h"
using namespace std;

class CNTaxStrategy : public TaxStrategy {
public:
    ~CNTaxStrategy() override = default;

    double calculate(const Context &context) override {
        cout << "Calculate CN Tax" << endl;
        return 0;
    }
};

#endif //STRATEGY_CNTAXSTRATEGY_H
