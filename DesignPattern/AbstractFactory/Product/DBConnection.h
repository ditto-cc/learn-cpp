#ifndef _DBCONNECTION_H
#define _DBCONNECTION_H

class DBConnection {
public:
    virtual ~DBConnection() = default;

    virtual void *connect() = 0;
};

#endif
