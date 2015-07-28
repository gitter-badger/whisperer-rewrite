#include "InputDelay.h"


InputDelay::InputDelay(vector<SDL_Keycode keys, vector<MouseButton> mouseButtons)
    : mKeys(keys), mMouseButtons(mouseButtons), mFinished(false)
{
}

InputDelay::InputDelay()
    : mFinished(false)
{
}

void InputDelay::HandleInput(Input& input)
{
    if (mKeys.empty())
    {
        // Accept any key if no specific keys are desired
        if (input.anyKeyPressed()) mFinished = true;
    }
    else
    {
        // Otherwise check every key we're interested in
        for (auto it = mKeys.begin(); it != mKeys.end(); ++it)
        {
            if (input.wasKeyPressed(*it)) mFinished = true;
        }
    }

    if (mMouseButtons.empty())
    {
        // Accept any mouse button if no specific buttons are desired
        for (int mb = MB_BEGIN; mb <= MB_END; ++mb)
        {
            if (input.mouseButtonClicked(mb)) mFinished = true;
        }
    }
    else
    {
        // Otherwise check every mouse button we're interested in
        for (auto it = mMouseButtons.begin(); it != mMouseButtons.end(); ++it)
        {
            if (input.mouseButtonClicked(*it)) mFinished = true;
        }
    }
}
