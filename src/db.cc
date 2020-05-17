#include "db.h"

MySQL::MySQL() {
    mysql_ = mysql_init(NULL);
}

bool MySQL::Connect(char* host, char* db, char* user, char* pass, unsigned int port) {
    MYSQL* ret = mysql_real_connect(mysql_, host, user, pass, db, port, NULL, 0);
    if(ret == NULL) {
        fprintf(stderr, "mysql connect has failed: %d\n", mysql_error(mysql_));
        return false;
    }
    return true;
}

bool MySQL::Query(char* sql) {
    int ret = mysql_query(mysql_, sql);
    if(ret) {
        fprintf(stderr, "mysql query has failed: %d\n", mysql_error(mysql_));
        return false;
    }
    return true;
}

int MySQL::GetKeyID() {
    Query("select * from KEYID");
    MYSQL_RES* res = mysql_store_result(mysql_);
    MYSQL_ROW row = mysql_fetch_row(res);
    mysql_free_result(res);
    return atoi(row[0]);
}

bool MySQL::InsertKeyInfo(char* client, char* server, int keyid, char* key, int status = 1) {
    char sql[256] = {0};
    sprintf(sql, "insert into INFO (`CLIENT`,`SERVER`,`ID`,`STATUS`,`KEY`) values('%s','%s',%d,%d,'%s')", client, server, keyid, status, key);
    if(Query(sql) && Query("update KEYID set KEYID = KEYID + 1")) {
        return true;
    }
    return false;
}

MySQL::~MySQL() {
    mysql_close(mysql_);
}