#pragma once

#include "Paddle.h"
#include "Ball.h"

namespace Pong {

class Player {
public:
    Player(Paddle paddle) : _paddle(paddle) {};

    void update(DeltaTime dt);
    void draw();

    void addPoints(int amount) { _points += amount; }
    int &getPoints() { return _points; }
    Paddle &getPaddle() { return _paddle; }

private:
    Paddle _paddle;
    int _points;
};

}

