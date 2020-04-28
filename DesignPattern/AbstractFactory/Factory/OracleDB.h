#ifndef _ORACLEDB_H
#define _ORACLEDB_H

#include "DBFactory.h"
#include "../Product/OracleConnection.h"
#include "../Product/OracleCommand.h"

class OracleDB : public DBFactory {
public:
    DBConnection *createDBConnection() override {
        std::cout << "Oracle Factory: ";
        return new OracleConnection();
    }

    DBCommand *createDBCommand() override {
        std::cout << "Oracle Factory: ";
        return new OracleCommand();
    }
};

#endif
