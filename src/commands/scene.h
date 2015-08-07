#pragma once

#include <map>
using std::map;
#include <vector>
using std::vector;
#include <string>
using std::string;

#include "../Whisperer.h"
#include "../Scene.h"
#include "../State.h"

#include "util.h"

map<string, Scene> scenes;

// Create a new empty scene
State* CreateScene(Whisperer* game, vector<string> args)
{
    // Syntax: CreateScene [name]
    string name = args.at(0);
    scenes[name] = Scene();

    return NULL;
}

// Delete a scene
State* DeleteScene(Whisperer* game, vector<string> args)
{
    // Syntax: DeleteScene [name]
    string name = args.at(0);
    scenes.erase(name);

    return NULL;
}

// Blit a surface to the background of a scene
State* BlitSceneBackgroundSurface(Whisperer* game, vector<string> args)
{
    // Syntax: BlitSceneBackgroundSurface [scene] [surface] [x] [y]
    //         BlitSceneBackgroundSurface [scene] [surface]
    string sceneKey = args.at(0);
    string surfaceKey = args.at(1);
    int x = 0;
    int y = 0;

    if (args.size() > 2)
    {
        x = coord(args.at(2));
        y = coord(args.at(3));
    }

    scenes[sceneKey].BlitBackgroundSurface(surfaces[surfaceKey], x, y);
}

// Copy a surface to the background of a scene
State* CopySceneBackgroundSurface(Whisperer* game, vector<string> args)
{
    // Syntax: CopySceneBackgroundSurface [scene] [surface] [x] [y]
    //         CopySceneBackgroundSurface [scene] [surface]
    string sceneKey = args.at(0);
    string surfaceKey = args.at(1);
    int x = 0;
    int y = 0;

    if (args.size() > 2)
    {
        x = coord(args.at(2));
        y = coord(args.at(3));
    }

    scenes[sceneKey].CopyBackgroundSurface(surfaces[surfaceKey], x, y);
}

// Add an image to the background of a surface
State* AddSceneBackgroundImage(Whisperer* game, vector<string> args)
{
}
