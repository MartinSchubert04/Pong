#pragma once

#include "pch.h"
#include "Ball.h"
#include "Paddle.h"
#include "Player.h"
#include "Bot.h"


namespace Pong {

class World {

public:
    World()  {
      _scoreSound = LoadSound("score.wav");
      _wallHitSound = LoadSound("wall.mp3");
      _paddleHitSound = LoadSound("paddle.mp3");
    }

    void collisionBorder(Ball &ball, Player &p, Bot &b);
    void collisionBallPaddle(Ball &ball, Paddle &paddle);

private:
  Sound _scoreSound;
  Sound _wallHitSound;
  Sound _paddleHitSound;
};

}

