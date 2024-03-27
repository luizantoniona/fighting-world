#include "threadmanager.h"

#include <Thread/Database/ThreadDatabase.h>

ThreadManager::ThreadManager() : _threads({})
{
}

ThreadManager::~ThreadManager()
{
}

void ThreadManager::create(const ThreadTypeEnum type)
{
    Thread *thread = threadByType(type);

    if (!thread)
    {
        return;
    }

    _threads.at(type).insert(_threads.at(type).cend(), thread);
}

Thread *ThreadManager::threadByType(const ThreadTypeEnum type)
{
    switch (type)
    {
    case ThreadTypeEnum::THREAD_DATABASE:
        return new ThreadDatabase();
        break;
    default:
        return nullptr;
        break;
    }
}