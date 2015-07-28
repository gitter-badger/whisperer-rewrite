#include "ChapterState.h"

#include <sstream>
using std::stringstream;

#include "commands/graphics.h"

ChapterState::ChapterState(Whisperer* whisperer, const unsigned int chapter)
    : mWhisperer(whisperer), currentState(NULL)
{
    // Register all script commands
    RegisterCommands();

    // Select the script file for the given chapter
    stringstream scriptname;
    scriptname << "content/scripts/chapter" << chapter << ".wsp";

    // Start running the chapter's script
    scriptManager.RunScript(scriptname.str());
}

void ChapterState::Update(int deltaMS)
{
    // If a state has been entered, process the current state until
    // it is finished
    if (currentState != NULL)
    {
        currentState->Update(deltaMS);

        if (currentState->IsFinished())
        {
            State* nextState = currentState->NextState(mWhisperer);
            delete currentState;
            currentState = nextState;
        }
    }
    // If there is no current state, continue executing the script
    if (currentState == NULL)
    {
        // If the next script command evokes a new State, save it
        currentState = scriptManager.ProcessNextCommand(mWhisperer);
        // FIXME: This could cause a crash if Update is called once 
        // after the chapter finishes but before the next chapter starts.
    }
}

void ChapterState::HandleInput(Input& input)
{
    if (currentState != NULL)
    {
        currentState->HandleInput(input);
    }
}

void ChapterState::Draw(Graphics& graphics)
{
    if (currentState != NULL)
    {
        currentState->Draw(graphics);
    }
}

bool ChapterState::IsFinished()
{
    // If there is no state, and the script has been fully executed,
    // then the chapter is complete.
    return !scriptManager.HasNextCommand() && currentState == NULL;
}

State* ChapterState::NextState(Whisperer* whisperer)
{
}

void ChapterState::RegisterCommands()
{
    // graphics.h
    scriptManager.RegisterCommand("Clear", &Clear);
    scriptManager.RegisterCommand("ClearTransparent", &ClearTransparent);
    scriptManager.RegisterCommand("ClearOpaque", &ClearOpaque);

    scriptManager.RegisterCommand("UpdateScreen", &UpdateScreen);

    scriptManager.RegisterCommand("LoadSurface", &LoadSurface);
    scriptManager.RegisterCommand("FreeSurface", &FreeSurface);
    scriptManager.RegisterCommand("PrintSurfaceContents", &PrintSurfaceContents);
    scriptManager.RegisterCommand("BlitSurface", &BlitSurface);
    scriptManager.RegisterCommand("CopySurface", &CopySurface);

    scriptManager.RegisterCommand("LoadImage", &LoadImage);
    scriptManager.RegisterCommand("FreeImage", &FreeImage);
    scriptManager.RegisterCommand("AddBackgroundImage", &AddBackgroundImage);
    scriptManager.RegisterCommand("AddForegroundImage", &AddForegroundImage);
    scriptManager.RegisterCommand("ClearImages", &ClearImages);
}
