#include "Application.h"
#include "Ball.h"
#include "Paddle.h"
#include "Bot.h"
#include "World.h"

namespace Pong {

Application::Application() {
    InitWindow(0,0, "Pong");
    InitAudioDevice();
    InitSensorManager();
    EnableSensor(SENSOR_ACCELEROMETER);

    _window = {(float)GetScreenWidth(), (float)GetScreenHeight()};
}


void Application::run() {
    World world;

    Ball ball = {{_window.x / 2, _window.y / 2}, 20.0f};

    Paddle paddle1 = {{_window.x / 2, (_window.y / 4) * 3}, {200.f, 25.f}, {0,0}};
    Player p = {paddle1};

    Paddle paddle2 = {{_window.x / 2, (_window.y / 4)}, {200.f, 25.f}, {0,0}};
    Bot bot = {paddle2};

    int p2Points = 0;

    while(!WindowShouldClose()) {
        auto time = (float)GetTime();
        dt = time - _lastTime;
        _lastTime = time;

        BeginDrawing();

        int fontSize = 150;
        const char *text = TextFormat("%i | %i", p.getPoints(), bot.getPoints());
        auto textSize = (float)MeasureText(text, fontSize);
        DrawText(text, (int)(_window.x / 2 - textSize / 2), _window.y / 2 - fontSize / 2, fontSize, {245, 245, 245, 80});

//        int fontSize2 = 40;
//        const char *text2 = TextFormat("Speed x:%.1f y: %.1f", ball.getSpeed().x, ball.getSpeed().y);
//        auto textSize2 = (float)MeasureText(text2, fontSize2);
//        DrawText(text2, (int)(_window.x / 2 - textSize2 / 2), (_window.y / 2 - fontSize2 / 2) - fontSize, fontSize2, {245, 245, 245, 80});

        ball.update(dt);
        p.update(dt);
        bot.update(ball, dt);
        world.collisionBorder(ball, p, bot);
        world.collisionBallPaddle(ball, p.getPaddle());
        world.collisionBallPaddle(ball, bot.getPaddle());

        ball.draw();
        p.draw();
        bot.draw();


        EndDrawing();
    }
}

}

