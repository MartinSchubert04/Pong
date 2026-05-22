#include "Application.h"
#include "Ball.h"
#include "Paddle.h"
#include "Bot.h"

namespace Pong {

Application::Application() {
    InitWindow(0,0, "Pong");
    InitAudioDevice();
    InitSensorManager();
    EnableSensor(SENSOR_ACCELEROMETER);

    _window = {(float)GetScreenWidth(), (float)GetScreenHeight()};
}


void Application::run() {
    Ball ball = {{_window.x / 2, _window.y / 2}, 20.0f};

    Paddle p1 = {{_window.x / 2, (_window.y / 4) * 3}, {200.f, 25.f}, {0,0}};
    Paddle paddle = {{_window.x / 2, (_window.y / 4)}, {200.f, 25.f}, {0,0}};
    Bot bot = {paddle};

    int p1Points = 0;
    int p2Points = 0;

    while(!WindowShouldClose()) {
        auto time = (float)GetTime();
        dt = time - _lastTime;
        _lastTime = time;

        BeginDrawing();

        int fontSize = 150;
        const char *text = TextFormat("%i | %i", p1Points, p2Points);
        auto textSize = (float)MeasureText(text, fontSize);
        DrawText(text, (int)(_window.x / 2 - textSize / 2), _window.y / 2 - fontSize / 2, fontSize, {245, 245, 245, 80});

        ball.update(dt);
        p1.update(dt);
        bot.update(ball);

        ball.draw();
        p1.draw();
        bot.draw();

        if (ball.getPos().y + ball.getRadius() >= _window.y){
            p2Points += 1;
            ball.reset();
        }
        if (ball.getPos().y - ball.getRadius() <= 0) {
            p1Points += 1;
            ball.reset();
        }



        EndDrawing();
    }
}

}

