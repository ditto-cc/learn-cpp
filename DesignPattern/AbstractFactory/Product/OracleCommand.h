#ifndef _ORACLECOMMAND_H
#define _ORACLECOMMAND_H

#include <iostream>
#include "DBConnection.h"
#include "DBCommand.h"

class OracleCommand : public DBCommand {
public:
    OracleCommand() {
        std::cout << "Creating Oracle DBCommand" << std::endl;
    }

    ~OracleCommand() override = default;

    void execute(DBConnection *dbConnection) override {
        std::cout << "Execute Oracle DBCommand" << std::endl;
    }
};

#endif
