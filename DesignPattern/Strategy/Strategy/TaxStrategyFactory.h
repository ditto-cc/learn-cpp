
#ifndef STRATEGY_TAXSTRATEGYFACTORY_H
#define STRATEGY_TAXSTRATEGYFACTORY_H

#include "TaxStrategy.h"

class TaxStrategyFactory {
public:
    virtual ~TaxStrategyFactory() = default;
    virtual TaxStrategy *createTaxStrategy() = 0;
};

#endif
