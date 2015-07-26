#include "Whisperer.h"

#include <fstream>
#include <sstream>

#include <SDL.h>

#include "menus/LanguageMenu.h"

using namespace ascii;


//void Whisperer::RegisterScriptCommands()
//{
    //// graphics.h
    //scriptManager.RegisterCommand("Clear", &Clear);
    //scriptManager.RegisterCommand("ClearTransparent", &ClearTransparent);
    //scriptManager.RegisterCommand("ClearOpaque", &ClearOpaque);

    //scriptManager.RegisterCommand("UpdateScreen", &UpdateScreen);

    //scriptManager.RegisterCommand("LoadSurface", &LoadSurface);
    //scriptManager.RegisterCommand("FreeSurface", &FreeSurface);
    //scriptManager.RegisterCommand("PrintSurfaceContents", &PrintSurfaceContents);
    //scriptManager.RegisterCommand("BlitSurface", &BlitSurface);
    //scriptManager.RegisterCommand("CopySurface", &CopySurface);

    //scriptManager.RegisterCommand("LoadImage", &LoadImage);
    //scriptManager.RegisterCommand("FreeImage", &FreeImage);
    //scriptManager.RegisterCommand("AddBackgroundImage", &AddBackgroundImage);
    //scriptManager.RegisterCommand("AddForegroundImage", &AddForegroundImage);
    //scriptManager.RegisterCommand("ClearImages", &ClearImages);
//}

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
            State* newState = mCurrentState->NextState();
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
