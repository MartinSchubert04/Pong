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
    void validate();

    void setPos(const Vector2 &pos) { _pos = pos; }
    void setPosX(const float &x) { _pos.x = x; }
    void setPosY(const float &y) { _pos.y = y; }
    void setSpeedX(const float &x) { _speed.x = x; }
    void setSpeedY(const float &y) { _speed.y = y; }

    void scaleSpeed(const float factor) {
      _speed.x *= factor;
      _speed.y *= factor;
    }

    Vector2 &getPos() { return _pos; }
    Vector2 &getPrevPos() { return _prevPos; }
    float &getRadius() { return _radius; }
    Vector2 &getSpeed() { return _speed; }

private:
    Vector2 _pos;
    Vector2 _prevPos;
    Vector2 _speed;
    float _radius;
    Color _color;
};


}


