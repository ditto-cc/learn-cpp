
#ifndef STRATEGY_USTAXSTRATEGYFACTORY_H
#define STRATEGY_USTAXSTRATEGYFACTORY_H

#include "TaxStrategyFactory.h"
#include "USTaxStrategy.h"

class USTaxStrategyFactory : public TaxStrategyFactory {
public:
    ~USTaxStrategyFactory() override = default;
    TaxStrategy *createTaxStrategy() override {
        return new USTaxStrategy();
    }
};
#endif
