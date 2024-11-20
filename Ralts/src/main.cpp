#include "App/Application.h"

int main(int argc, char **argv)
{

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