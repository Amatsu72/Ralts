#include "App/Application.h"

int main(int argc, char** argv) {

    App::app.init();
    while(App::app.isRunning()) {
        App::app.update();
    }
    std::cout << "Hello, world!" << std::endl;
    std::cout << "This is a test program" << std::endl;
    return 0;

}