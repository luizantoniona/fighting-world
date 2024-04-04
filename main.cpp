#include <Components/Window/Window.h>
#include <Database/Database.h>
#include <Thread/ThreadManager.h>

using namespace Component;
using namespace Database;

int main(void)
{
    Database::Database database;

    Component::Window window;
    window.init();
}