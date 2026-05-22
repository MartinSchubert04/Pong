#pragma once

class DeltaTime {
public:
    DeltaTime(double time = 0.0f) : mTime(time) {};

    double getSeconds() const { return mTime; }
    double getMilliseconds() const { return mTime * 1000; }

private:
    double mTime;
};

