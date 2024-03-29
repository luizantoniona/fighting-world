#pragma once

#include <Database/Database_Globals.h>

#include <string>

#include <sqlite3.h>

BEGIN_NAMESPACE_DATABASE

class Database
{
public:
    Database();
    ~Database();

    void init();
    void close();

private:
    sqlite3 *_database;
};

END_NAMESPACE_DATABASE