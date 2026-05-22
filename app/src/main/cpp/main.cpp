#include "raymob.h"
#include "Pong/Application.h"

int main() {
  auto *app = new Pong::Application;

  app->run();

  delete app;
}
