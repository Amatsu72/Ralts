#include "App/Application.h"
// #include "Engine/ECS/Base/EntityManager.h"

int main(int argc, char **argv)
{
    // Engine::EntityManager manager;
    // auto id1 = manager.addNewEntity();
    // auto id2 = manager.addNewEntity();
    // std::cout << "Entity ID: " << id1 << std::endl;
    // std::cout << "Entity ID: " << id2 << std::endl;
    // manager.destroyEntity(id2);
    // auto id3 = manager.addNewEntity();
    // std::cout << "Entity ID: " << id1 << std::endl;
    // std::cout << "Entity ID: " << id2 << std::endl;
    // std::cout << "Entity ID: " << id3 << std::endl;


    App::app.init();
    Engine::timer.init();
    Engine::event.init();
    while (App::app.isRunning())
    {
        Engine::timer.tick();
        Engine::event.poll();
        App::app.update();
    }
    return 0;
}