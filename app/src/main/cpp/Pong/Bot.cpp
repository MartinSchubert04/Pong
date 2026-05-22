#include "Bot.h"

namespace Pong {

void Bot::update(Ball &ball) {
  _paddle.getPos().x = ball.getPos().x;

}

void Bot::draw() {
  _paddle.draw();
}

}

