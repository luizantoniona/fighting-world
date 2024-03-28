#pragma once

#include <map>
#include <list>

#include <Thread/Thread.h>
#include <Thread/ThreadTypeEnum.h>

BEGIN_NAMESPACE_THREAD

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

END_NAMESPACE_THREAD