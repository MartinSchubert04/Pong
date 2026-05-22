#include "raymob.h"
#include "DeltaTime.h"

struct Ball {
    Vector2 pos;
    Vector2 speed;
    float radius;
};

int main() {

  InitWindow(0, 0, "Test");
  InitSensorManager();
  EnableSensor(SENSOR_ACCELEROMETER);

  int width = GetScreenWidth();
  int height = GetScreenHeight();

  Ball ball = {{(float)width / 2, (float)height/2}, {0, 0}, 30.0f};

  DeltaTime dt(GetTime());
  double lastTime = 0;
  float accScalar = 1000.f;

  while (!WindowShouldClose()) {
    double time = GetTime();
    dt = time - lastTime;
    lastTime = time;

    BeginDrawing();
    ClearBackground(BLACK);

    DrawCircle(ball.pos.x, ball.pos.y, ball.radius, RAYWHITE);

    Vector3 accValues = GetAccelerotmerAxis();


    ball.pos.x += ball.speed.x + (-accValues.x * accScalar) * dt.getSeconds();
    ball.pos.y += ball.speed.y + (accValues.y * accScalar) * dt.getSeconds();

    if (ball.pos.x + ball.radius >= width) ball.pos.x = width - ball.radius;
    if (ball.pos.x - ball.radius <= 0) ball.pos.x = 0 + ball.radius;
    if (ball.pos.y - ball.radius <= 0) ball.pos.y = 0 + ball.radius;
    if (ball.pos.y + ball.radius >= height) ball.pos.y = height - ball.radius;



    DrawText(TextFormat("Acc x:%.2f y:%.2f", accValues.x, accValues.y), 50, 0, 40, RAYWHITE);


    EndDrawing();
  }
  return 0;
}
