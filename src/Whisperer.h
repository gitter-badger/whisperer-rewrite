#pragma once

#include <vector> // TODO
#include "Color.h" // TODO

#include "Game.h"

#include "TextManager.h"
#include "ScriptManager.h"

using namespace ascii;

namespace
{
    const char* kWindowTitle = "The Whisperer in Darkness";
    const char* kFontPath = "content/terminal.fon";
    const int kWindowWidth = 100;
    const int kWindowHeight = 40;
}

class Whisperer : public Game
{
    public:
        Whisperer()
            : Game(kWindowTitle, kFontPath, kWindowWidth, kWindowHeight)
        {
            RegisterScriptCommands();
        }
    protected:
        // Virtual methods
        void LoadContent(ImageCache* imageCache, SoundManager* soundManager);
        void Update(int deltaMS);
        void HandleInput(Input& input);
        void Draw(Graphics& graphics);
    private:
        void RegisterScriptCommands();

        TextManager textManager;
        ScriptManager scriptManager;
};
