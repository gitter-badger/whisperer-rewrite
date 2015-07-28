#pragma once

#include <vector>
using std::vector;

#include <SDL.h>

#include "Input.h"
#include "Graphics.h"
using namespace ascii;

#include "../State.h"


// This state simply pauses the current chapter until the player triggers
// a desired input. If either keys or mouseButtons is left empty, any input
// from the keyboard/mouse will be accepted.
class InputDelay : public State
{
    public:
        InputDelay(vector<SDL_Keycode> keys, vector<MouseButton> mouseButtons);
        InputDelay();

        void Update(int deltaMS) { }
        void HandleInput(Input& input);
        void Draw(Graphics& graphics) { }

        bool IsFinished() { return mFinished; }
        State* NextState(Whisperer* whisperer) { return NULL; }
    private:
        vector<SDL_Keycode> mKeys;
        vector<MouseButton> mMouseButtons;

        bool mFinished;
};
