#include "Ball.h"

namespace Pong {

Ball::Ball(Vector2 pos, float radius, Color color) : _pos(pos), _radius(radius), _color(color),
                                                     _speed({0.0, 0.0}) {
  _speed = {getRandRange(150.f, 250.f), getRandRange(600.f, 800.f)};

  getRandBool() > 0 ? _speed.y *= 1.0
                    : _speed.y *= -1.0;
  getRandBool() > 0 ? _speed.x *= 1.0
                    : _speed.x *= -1.0;
}

void Ball::update(DeltaTime dt) {
  _prevPos = _pos;
  _pos.x += _speed.x * dt.getSeconds();
  _pos.y += _speed.y * dt.getSeconds();

  validate();
}

void Ball::draw() {
  DrawCircle((int) _pos.x, (int) _pos.y, _radius, _color);
}

void Ball::reset() {
  _speed = {getRandRange(150.f, 250.f), getRandRange(600.f, 800.f)};

  getRandBool() > 0 ? _speed.y *= 1.0
                    : _speed.y *= -1.0;
  getRandBool() > 0 ? _speed.x *= 1.0
                    : _speed.x *= -1.0;

  _pos = {(float) GetScreenWidth() / 2, (float) GetScreenHeight() / 2};
}

void Ball::validate() {
  float maxY = 2200.f;
  float maxX = 1500.f;

  if (_speed.x > maxX) _speed.x = maxX;
  if (_speed.y > maxY) _speed.y = maxY;

  if (_speed.x < -maxX) _speed.x = -maxX;
  if (_speed.y < -maxY) _speed.y = -maxY;
}


}

