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

    void setX(const float x) { _pos.x = x; }
    void setSpeed(const Vector2 &speed) { _speed = speed; }


    Vector2 &getPos() { return _pos; }
    Vector2 &getSpeed() { return _speed; }
    Vector2 &getSize() { return _size; }


private:
    Vector2 _speed;
    Vector2 _pos;
    Vector2 _size;
    Color _color;
};

} // Pong
