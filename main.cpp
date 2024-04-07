#include <Components/Window/Window.h>
#include <Database/Database.h>
#include <Manager/Resource/ResourceManager.h>

using namespace Component;
using namespace Database;
using namespace Manager;

int main(void)
{
    // Database::Database database;
    Manager::ResourceManager::instance();

    Component::Window window;
    window.init();
}