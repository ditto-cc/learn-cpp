#ifndef _DBCOMMAND_
#define _DBCOMMAND_

#include "DBConnection.h"

class DBCommand {
public:
    virtual ~DBCommand() = default;

    virtual void execute(DBConnection *dbConnection) = 0;
};

#endif
