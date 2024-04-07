#include "Database.h"

#include <iostream>

BEGIN_NAMESPACE_DATABASE

namespace {
constexpr const char* DATABASE_NAME = "FightingWorld.db";
}

Database::Database()
    : _database(nullptr)
{
    init();
}

Database::~Database()
{
    close();
}

void Database::init()
{

    if (SQLITE_OK != sqlite3_initialize()) {
        std::cout << "Failed to initialize sqlite" << std::endl;
        return;
    }

    if (SQLITE_OK != sqlite3_open_v2(DATABASE_NAME, &_database, SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE, NULL)) {
        std::cout << "Failed to open database [DATABASE_NAME]" << DATABASE_NAME << std::endl;
        return;
    }

    std::cout << "Database initialized" << std::endl;
}

void Database::close()
{
    sqlite3_close(_database);

    sqlite3_shutdown();
}

void Database::execute(std::string& query) const
{
    sqlite3_stmt* sqliteQuery = nullptr;

    if (SQLITE_OK != sqlite3_prepare_v2(_database, query.c_str(), -1, &sqliteQuery, NULL)) {
        std::cout << "Failed prepare query" << std::endl;
        return;
    }

    if (SQLITE_DONE != sqlite3_step(sqliteQuery)) {
        std::cout << "Failed run query" << sqlite3_errmsg(_database) << std::endl;
        return;
    }

    if (nullptr != sqliteQuery) {
        sqlite3_finalize(sqliteQuery);
    }

    std::cout << "Query executed" << std::endl;
}

END_NAMESPACE_DATABASE
