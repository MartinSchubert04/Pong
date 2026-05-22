#pragma once

#include "DeltaTime.h"
#include "pch.h"

namespace Pong {

class Paddle {
public:
    Paddle() = default;

    Paddle(Vector2 pos, Vector2 size, Vector2 speed, Color color = RAYWHITE);

    void update(DeltaTime dt);

    void draw();

    Vector2 &getPos() { return _pos; }


private:
    Vector2 _speed;
    Vector2 _pos;
    Vector2 _size;
    Color _color;
};

} // Pong
