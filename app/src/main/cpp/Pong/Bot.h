#pragma once

#include "Paddle.h"
#include "Ball.h"

namespace Pong {

class Bot {

public:
    Bot(Paddle paddle) : _paddle(paddle) {};

    void update(Ball &ball);
    void draw();


private:
    Paddle _paddle;
};

}