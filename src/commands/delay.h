#pragma once

#include <vector>
using std::vector;
#include <string>
using std::string;

#include "../Whisperer.h"

#include "../states/InputDelay.h"

class State;

// Halts the current chapter until any key or mouse button is pressed.
State* AwaitInput(Whisperer* game, vector<string> args)
{
    return new InputDelay();
}
