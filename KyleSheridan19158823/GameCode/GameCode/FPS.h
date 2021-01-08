#pragma once

#include <string>
#include <SDL.h>
#include <iostream>

class FPS {
public:
    FPS();

    void init();
    void update();
    void clear();

    const std::string& getFPS() {
        return "FPS: " + std::to_string((int)framespersecond);
    }

    const float getDeltaTime() {
        return deltaTime;
    }

private:
#define FRAME_VALS 10

    // array to store the frame times
    Uint32 frametimes[FRAME_VALS];

    // var to store result in ticks for curr frame - SDL_GetTicks()
    Uint32 frametimelast;

    Uint32 framecount;

    float framespersecond;

    float lastFrameTime;

    float deltaTime;
};