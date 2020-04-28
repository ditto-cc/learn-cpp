#ifndef _DBFACTORY_H
#define _DBFACTORY_H
#include "../Product/DBConnection.h"
#include "../Product/DBCommand.h"

class DBFactory {
public:
    virtual ~DBFactory() = default;
    virtual DBConnection *createDBConnection() = 0;
    virtual DBCommand *createDBCommand() = 0;
};

#endif
