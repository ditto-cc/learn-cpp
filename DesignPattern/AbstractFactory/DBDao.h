
#ifndef ABSTRACTFACTORY_DBDAO_H
#define ABSTRACTFACTORY_DBDAO_H

#include "Factory/DBFactory.h"

class DBDao {
private:
    DBFactory *dbFactory;

public:
    explicit DBDao(DBFactory *dbFactory) : dbFactory(dbFactory) {}
    ~DBDao() {
        delete dbFactory;
    }

    DBConnection *createDBConnection() {
        return dbFactory->createDBConnection();
    }

    DBCommand *createDBCommand() {
        return dbFactory->createDBCommand();
    }
};

#endif
