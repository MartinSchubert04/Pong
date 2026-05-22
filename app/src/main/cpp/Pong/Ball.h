#pragma  once

#include "pch.h"
#include "DeltaTime.h"
#include "Random.h"

namespace Pong {

class Ball {

public:
    Ball(Vector2 pos, float radius, Color color = RAYWHITE);

    void update(DeltaTime dt);
    void draw();
    void reset();

    Vector2 &getPos() { return _pos; }
    float &getRadius() { return _radius; }

private:
    Vector2 _pos;
    Vector2 _speed;
    float _radius;
    Color _color;
};


}


