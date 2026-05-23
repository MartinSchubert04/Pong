#include "World.h"
#include "raymath.h"

namespace Pong {

void World::collisionBorder(Ball &ball, Player &p, Bot &b) {
  float height = GetScreenHeight();
  auto width = GetScreenWidth();

  if (ball.getPos().x + ball.getRadius() >= (float) width) {
    ball.setPosX((float) width - ball.getRadius());
    ball.setSpeedX(ball.getSpeed().x * -1.0f);
    PlaySound(_wallHitSound);
  }
  if (ball.getPos().x - ball.getRadius() <= 0) {
    ball.setPosX(ball.getRadius());
    ball.setSpeedX(ball.getSpeed().x * -1.0f);
    PlaySound(_wallHitSound);
  }

  if (ball.getPos().y + ball.getRadius() > height){
    p.addPoints(1);
    ball.reset();
    VibrateExMS(30, 0.3);
    PlaySound(_scoreSound);
  }
  if (ball.getPos().y - ball.getRadius() < 0) {
    b.addPoints(1);
    ball.reset();
    VibrateExMS(30, 0.3);
    PlaySound(_scoreSound);
  }
}

void World::collisionBallPaddle(Ball &ball, Paddle &paddle) {
  Vector2 pos = ball.getPos();
  float radius = ball.getRadius();

  float paddleLeft   = paddle.getPos().x;
  float paddleRight  = paddle.getPos().x + paddle.getSize().x;
  float paddleTop    = paddle.getPos().y;
  float paddleBottom = paddle.getPos().y + paddle.getSize().y;

  // punto más cercano del rectángulo al centro de la pelota
  float nearestX = std::max(paddleLeft,  std::min(pos.x, paddleRight));
  float nearestY = std::max(paddleTop,   std::min(pos.y, paddleBottom));

  float dx = pos.x - nearestX;
  float dy = pos.y - nearestY;
  float dist = sqrtf(dx * dx + dy * dy);

  if (dist == 0 || dist >= radius) return;

  float overlap = radius - dist;
  float nx = dx / dist;
  float ny = dy / dist;

  ball.setPos({pos.x + nx * overlap, pos.y + ny * overlap});


  if (std::abs(nx) > std::abs(ny)) {
    ball.setSpeedX(-ball.getSpeed().x);
  } else {
    ball.setSpeedY(-ball.getSpeed().y);
  }

  // more speed
  float factor = 1.05f;
  ball.scaleSpeed(factor);

  // affect ball movement based on paddle momentum
  float momentumFactor = 0.2f;
  ball.setSpeedX(ball.getSpeed().x + paddle.getSpeed().x * momentumFactor);
  ball.setSpeedY(ball.getSpeed().y + paddle.getSpeed().y * momentumFactor);

  PlaySound(_paddleHitSound);
}

}