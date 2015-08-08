#pragma once

#include "Input.h"
#include "Graphics.h"
using namespace ascii;

#include "../Whisperer.h"
#include "../State.h"

class TimeDelay : public State
{
    public:
        TimeDelay(unsigned int delayMS)
            : mElapsedMS(0), mDelayMS(delayMS) { }

        void Update(int deltaMS);
        void HandleInput(Input& input) { }
        void Draw(Graphics& graphics) { }

        bool IsFinished();
        State* NextState(Whisperer* whisperer) { return NULL; }
    private:
        int mElapsedMS;
        int mDelayMS;
};
