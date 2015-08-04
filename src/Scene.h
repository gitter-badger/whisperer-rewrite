#pragma once

#include <vector>
using std::vector;
#include <string>
using std::string;
#include <map>
using std::map;

#include "Surface.h"
#include "Point.h"
#include "Graphics.h"

using namespace ascii;


// This class represents a visual scene in the game containing ASCII art,
// images, and also handling surface tweens and dialog boxes.
class Scene
{
    public:
        Scene() : mBackground(NULL) { }

        void SetBackgroundSurface(Surface* background) { mBackground = background; }

        void AddBackgroundImage(string key, int x, int y);
        void AddBackgroundImage(string key);

        void AddForegroundImage(string key, int x, int y);
        void AddForegroundImage(string key);

        void Update(int deltaMS);

        void Show(Graphics& graphics);
        void Draw(Graphics& graphics);
        void Hide(Graphics& graphics);
    private:
        Surface* mBackgroundSurface;
        map<string, Point> mBackgroundImages;
        map<string, Point> mForegroundImages;
};
