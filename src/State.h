#pragma once

#include "Input.h"
#include "Graphics.h"

using namespace ascii;

// Interface for game states which stop the flow of
// chapter scripts until being processed.
class State
{
    public:
        // Functioning loop of the state
        virtual void Update(int deltaMS)=0;
        virtual void HandleInput(Input& input)=0;
        virtual void Draw(Graphics& graphics)=0;

        // Called by the game to monitor whether the state
        // has been fully processed
        virtual bool IsFinished()=0;
};
