#pragma once

#include <map>
#include <list>

#include <Thread/Thread.h>
#include <Thread/ThreadTypeEnum.h>

class ThreadManager
{
public:
    ThreadManager();
    ~ThreadManager();

    void create(const ThreadTypeEnum type);

private:
    Thread *threadByType(const ThreadTypeEnum type);

    std::map<ThreadTypeEnum, std::list<Thread *>> _threads;
};