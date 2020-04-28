#ifndef STRATEGY_SALESORDER_H
#define STRATEGY_SALESORDER_H

#include <iostream>
#include "Context.h"
#include "Strategy/TaxStrategyFactory.h"
using namespace std;

class SalesOrder {
private:
    TaxStrategy *strategy;
public:
    explicit SalesOrder(TaxStrategyFactory *factory) {
        strategy = factory->createTaxStrategy();
    }

    ~SalesOrder() {
        delete strategy;
    }

    double CalculateTax() {
        Context context;
        return strategy->calculate(context);
    }
};

#endif
