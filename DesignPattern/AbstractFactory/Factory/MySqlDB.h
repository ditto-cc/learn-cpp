#ifndef _MYSQLDB_H
#define _MYSQLDB_H

#include "DBFactory.h"
#include "../Product/MySqlConnection.h"
#include "../Product/MySqlCommand.h"

class MySqlDB: public DBFactory {
public:
    DBConnection *createDBConnection() override {
        std::cout << "MySqlDB Factory: ";
        return new MySqlConnection();
    }

    DBCommand *createDBCommand() override {
        std::cout << "MySqlDB Factory: ";
        return new MySqlCommand();
    }
};

#endif
