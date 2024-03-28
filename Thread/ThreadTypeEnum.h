#pragma once

#include <Thread/Thread_Globals.h>

BEGIN_NAMESPACE_THREAD

enum class ThreadTypeEnum : int
{
    THREAD_BASE = 0,
    THREAD_DATABASE = 1,
};

END_NAMESPACE_THREAD