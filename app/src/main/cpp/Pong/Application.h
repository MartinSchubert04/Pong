#pragma once

#include "DeltaTime.h"
#include "raymob.h"

namespace Pong {

class Application {

public:
    Application();

    void run();

private:
    DeltaTime dt;
    Vector2 _window;
    float _lastTime;
};

}

