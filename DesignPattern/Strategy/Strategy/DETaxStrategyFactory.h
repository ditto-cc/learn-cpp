
#ifndef STRATEGY_DETAXSTRATEGYFACTORY_H
#define STRATEGY_DETAXSTRATEGYFACTORY_H

#include "TaxStrategyFactory.h"
#include "DETaxStrategy.h"

class DETaxStrategyFactory : public TaxStrategyFactory {
public:
    ~DETaxStrategyFactory() override = default;
    TaxStrategy *createTaxStrategy() override {
        return new DETaxStrategy();
    }
};
#endif
