#pragma once

#include <vector>
using std::vector;
#include <string>
using std::string;

#include "../Whisperer.h"

#include "../states/TimeDelay.h"
#include "../states/InputDelay.h"

#include "util.h"

class State;


// Halt the current chapter until the given amount of time elapses
State* Wait(Whisperer* game, vector<string> args)
{
    // Syntax: Wait [ms]
    int ms = coord(args.at(0));

    return new TimeDelay(ms);
}

// Halts the current chapter until any key or mouse button is pressed.
State* AwaitInput(Whisperer* game, vector<string> args)
{
    return new InputDelay();
}
