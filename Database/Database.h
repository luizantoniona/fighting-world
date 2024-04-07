#pragma once

#include <string>

#include <sqlite3.h>

#include <Database/Database_Globals.h>

BEGIN_NAMESPACE_DATABASE

class Database {
public:
    Database();
    ~Database();

    void init();
    void close();

    void execute(std::string& query) const;

private:
    sqlite3* _database;
};

END_NAMESPACE_DATABASE