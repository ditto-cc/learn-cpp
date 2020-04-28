
#ifndef STRATEGY_TAXSTRATEGY_H
#define STRATEGY_TAXSTRATEGY_H

#include <iostream>
#include "../Context.h"
using namespace std;

class TaxStrategy {
public:
    virtual ~TaxStrategy() = default;
    virtual double calculate(const Context &context) = 0;
};

#endif //STRATEGY_TAXSTRATEGY_H
