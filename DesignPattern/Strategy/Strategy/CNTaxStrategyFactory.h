
#ifndef STRATEGY_CNTAXSTRATEGYFACTORY_H
#define STRATEGY_CNTAXSTRATEGYFACTORY_H

#include "TaxStrategyFactory.h"
#include "CNTaxStrategy.h"

class CNTaxStrategyFactory : public TaxStrategyFactory {
public:
    ~CNTaxStrategyFactory() override = default;
    TaxStrategy *createTaxStrategy() override {
        return new CNTaxStrategy();
    }
};


#endif //STRATEGY_CNTAXSTRATEGYFACTORY_H
