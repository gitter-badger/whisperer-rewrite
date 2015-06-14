#pragma once

#include "Game.h"

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
        }
    protected:
        void LoadContent(ImageCache* imageCache, SoundManager* soundManager);
        void Update(Game* game, int deltaMS);
        void HandleInput(Game* game, Input& input);
        void Draw(Graphics& graphics);
};
