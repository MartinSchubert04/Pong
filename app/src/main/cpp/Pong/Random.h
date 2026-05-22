#pragma once

#include "pch.h"

inline int &getRandBool() {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<int> dist(0, 1);
  auto rand = dist(gen);
  return rand;
}

inline float &getRandRange(float min, float max) {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_real_distribution<float> dist(min, max);
  auto rand = dist(gen);
  return rand;
}
