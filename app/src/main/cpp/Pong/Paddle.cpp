#include "Paddle.h"

namespace Pong {


Paddle::Paddle(Vector2 pos, Vector2 size, Vector2 speed, Color color)
              : _pos(pos), _size(size), _speed(speed), _color(color) {
}

void Paddle::update(DeltaTime dt) {
  _pos.x = (float)GetTouchX();
  auto width = (float)GetScreenWidth();
  if (_pos.x + _size.x >= width) _pos.x = width - _size.x;
}

void Paddle::draw() {
  DrawRectangle(_pos.x, _pos.y, _size.x, _size.y, _color);
}

} // Pong