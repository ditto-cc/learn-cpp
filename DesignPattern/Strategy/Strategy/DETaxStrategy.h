
#ifndef STRATEGY_DETAXSTRATEGY_H
#define STRATEGY_DETAXSTRATEGY_H

#include <iostream>
#include "TaxStrategy.h"
using namespace std;

class DETaxStrategy : public TaxStrategy {
public:
    ~DETaxStrategy() override = default;

    double calculate(const Context &context) override {
        cout << "Calculate DE Tax" << endl;
        return 0;
    }
};
#endif
