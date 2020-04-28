#ifndef _MYSQLCOMMAND_H
#define _MYSQLCOMMAND_H

#include <iostream>
#include "DBCommand.h"
#include "DBConnection.h"

class MySqlCommand : public DBCommand {
public:
    MySqlCommand() {
        std::cout << "Creating MySql Command" << std::endl;
    }

    ~MySqlCommand() override = default;

    void execute(DBConnection *dbConnection) override {
        std::cout << "Execute MySql DBCommand" << std::endl;
    }
};

#endif
