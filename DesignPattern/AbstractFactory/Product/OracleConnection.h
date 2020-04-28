#ifndef _ORACLECONNECTION_H
#define _ORACLECONNECTION_H

#include <iostream>
#include "DBConnection.h"
#include "OracleCommand.h"

class OracleConnection : public DBConnection {
public:
    OracleConnection() {
        std::cout << "Creating Oracle Connection" << std::endl;
    }

    ~OracleConnection() override = default;

    void *connect() override {
        std::cout << "Making Oracle Connection" << std::endl;
    }
};

#endif
