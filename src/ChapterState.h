#pragma once

#include "State.h"

#include "Input.h"
#include "Graphics.h"

#include "ScriptManager.h"

class Whisperer;


class ChapterState : public State
{
    public:
        ChapterState(Whisperer* whisperer, const unsigned int chapter);

        void Update(int deltaMS);
        void HandleInput(Input& input);
        void Draw(Graphics& graphics);

        bool IsFinished();
        State* NextState(Whisperer* whisperer);
    private:
        // Helpers
        void RegisterCommands();

        // Fields
        ScriptManager scriptManager;
};
