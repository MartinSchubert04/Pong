#include "Player.h"

namespace Pong {

void Player::update(DeltaTime dt) {
  float prevX = _paddle.getPos().x;
  auto pos = (float) GetTouchX() - _paddle.getSize().x / 2;
  _paddle.setX(pos);
  _paddle.update(dt);

  _paddle.setSpeed({(_paddle.getPos().x - prevX) / dt.getSeconds(),
                     0.0f });
}

void Player::draw() {
  _paddle.draw();
}

}