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
#include "Input.h"

using namespace ascii;

#include "Tween.h"

class Whisperer;


// This class represents a visual scene in the game containing ASCII art,
// images, and also handling surface tweens and dialog boxes.
class Scene
{
    public:
        Scene();

        // Blit a surface to the background of this scene
        void BlitBackgroundSurface(Surface* background, int x, int y);

        // Copy a surface to the background of this scen
        void CopyBackgroundSurface(Surface* background, int x, int y);

        // Add an image to the background of this scene
        void AddBackgroundImage(string key, int x, int y);

        // Add an image to the foreground of this scene
        void AddForegroundImage(string key, int x, int y);

        // Clear all images from this scene
        void ClearImages();

        // Tween a surface between the given points
        void TweenSurface(Surface* surface, int sourceX, int sourceY,
                int destX, int destY, unsigned int totalMS);

        // Clear all tweens from this scene
        void ClearTweens();

        // Update this scene's tweens and dialogs
        void Update(int deltaMS);

        void Show(Graphics& graphics);
        void Draw(Graphics& graphics);
        void Hide(Graphics& graphics);

        bool IsShown() { return mShown; }

        // Check whether this scene's Draw() must be called every frame
        bool DrawEveryFrame();
    private:
        Surface mBackgroundSurface;
        map<string, Point> mBackgroundImages;
        map<string, Point> mForegroundImages;

        vector<Tween> mTweens;

        bool mShown;
};
