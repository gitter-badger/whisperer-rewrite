#pragma once

#include "Game.h"

#include "TextManager.h"
#include "ScriptManager.h"

#include "State.h"

using namespace ascii;

namespace
{
    const char* kWindowTitle = "The Whisperer in Darkness";
    const char* kFontPath = "content/terminal.fon";
}

class Whisperer : public Game
{
    public:
        Whisperer()
            : Game(kWindowTitle, kFontPath, WINDOW_WIDTH, WINDOW_HEIGHT)
        {
        }

        static const unsigned short LAST_CHAPTER;
        static const unsigned int WINDOW_WIDTH;
        static const unsigned int WINDOW_HEIGHT;

        TextManager* textManager() { return &mTextManager; }
    protected:
        // Virtual methods
        void LoadContent(ImageCache* imageCache, SoundManager* soundManager);
        void Update(int deltaMS);
        void HandleInput(Input& input);
        void Draw(Graphics& graphics);
    private:
        void RegisterScriptCommands();

        TextManager mTextManager;

        State* mCurrentState;
};
