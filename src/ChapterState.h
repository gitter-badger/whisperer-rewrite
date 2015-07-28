#pragma once

#include "State.h"

#include "Input.h"
#include "Graphics.h"

#include "ScriptManager.h"

class Whisperer;


// This state runs a chapter of the game. It contains its own script manager
// to do this. One command is executed every frame in the Update() method,
// until one of the script commands requires that the game wait for something
// to happen. For example, A command displaying a message box will create
// a state that awaits the player pressing a key to continue. As long as this
// state has not finished, the ScriptManager will be paused at that point.
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
        Whisperer* mWhisperer;
        State* currentState;
        ScriptManager scriptManager;
        unsigned int mChapter;
};
