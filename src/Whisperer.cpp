#include "Whisperer.h"

#include <fstream>
#include <sstream>

#include <SDL.h>

#include "menus/LanguageMenu.h"

using namespace ascii;


// Static constants
const unsigned short Whisperer::LAST_CHAPTER = 8;
const unsigned int WINDOW_WIDTH = 100;
const unsigned int WINDOW_HEIGHT = 40;

void Whisperer::LoadContent(ImageCache* imageCache, SoundManager* soundManager)
{
    mCurrentState = new LanguageMenu(&mTextManager);
}

void Whisperer::Update(int deltaMS)
{
    // Update the current menu
    if (mCurrentState != NULL)
    {
        mCurrentState->Update(deltaMS);

        // If the current menu is finished, delete it and start the next one
        if (mCurrentState->IsFinished())
        {
            State* newState = mCurrentState->NextState(this);
            delete mCurrentState;
            mCurrentState = newState;
        }
    }
    // now check again in case the state is set to null above
    if (mCurrentState == NULL)
    {
        // If there is no current menu, quit the game.
        Quit();
    }
}

void Whisperer::HandleInput(Input& input)
{
    if (mCurrentState != NULL)
    {
        mCurrentState->HandleInput(input);
    }

    //bool fullscreen = false;
    //if (input.isKeyHeld(SDLK_SPACE))
    //{
        //fullscreen = true;
    //}

    //if (input.wasKeyPressed(SDLK_a))
    //{
        //graphics()->SetVideoMode(1.0f, fullscreen);
        //scriptManager.RunScript("content/scripts/load.wsp");
    //}
    //if (input.wasKeyPressed(SDLK_b))
    //{
        //graphics()->SetVideoMode(1.5f, fullscreen);
        //scriptManager.RunScript("content/scripts/load.wsp");
    //}
    //if (input.wasKeyPressed(SDLK_c))
    //{
        //graphics()->SetVideoMode(2.0f, fullscreen);
        //scriptManager.RunScript("content/scripts/load.wsp");
    //}
}

void Whisperer::Draw(Graphics& graphics)
{
    if (mCurrentState != NULL)
    {
        mCurrentState->Draw(graphics);
    }
}
