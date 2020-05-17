#ifndef _MYSQL_H_
#define _MYSQL_H_

#include "db/mysql.h"
#include <stdio.h>
#include <stdlib.h>

class MySQL {
private:
    MYSQL* mysql_;
public:
    MySQL();
    bool Connect(char* host, char* db, char* user, char* pass, unsigned int port = 3306);
    bool Query(char* sql);
    int GetKeyID();
    bool InsertKeyInfo(char* client, char* server, int keyid, char* key, int status = 1);
    ~MySQL();
};

#endif