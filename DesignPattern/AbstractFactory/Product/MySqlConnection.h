#ifndef _MYSQLCONNECTION_H
#define _MYSQLCONNECTION_H

#include <iostream>
#include "DBConnection.h"
#include "MySqlCommand.h"

class MySqlConnection : public DBConnection {
public:
    MySqlConnection() {
        std::cout << "Creating MySql Connection" << std::endl;
    }

    ~MySqlConnection() override = default;

    void *connect() override {
        std::cout << "Making MySql Connection" << std::endl;
    }
};

#endif
