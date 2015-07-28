#pragma once

#include <vector>
using std::vector;
#include <string>
using std::string;
#include <map>
using std::map;

#include "../Whisperer.h"
#include "Surface.h"
using ascii::Surface;

class State;


// Global fields
namespace
{
    map<string, Surface*> surfaces;
}

// HELPER FUNCTIONS

// parses a coordinate argument
int coord(string arg)
{
    return atoi(arg.c_str());
}

// CLEAR FUNCTIONS

State* Clear(Whisperer* game, vector<string> args)
{
    game->graphics()->clear();
    return NULL;
}

State* ClearTransparent(Whisperer* game, vector<string> args)
{
    game->graphics()->clearTransparent();
    return NULL;
}

State* ClearOpaque(Whisperer* game, vector<string> args)
{
    game->graphics()->clearOpaque();
    return NULL;
}

// UPDATE

State* UpdateScreen(Whisperer* game, vector<string> args)
{
    game->graphics()->update();
    return NULL;
}

// SURFACES

// Loads a ASCIILib surface and stores it by the given identifier
State* LoadSurface(Whisperer* game, vector<string> args)
{
    // Syntax: LoadSurface [identifier] [filename]
    string key = args.at(0);
    string path = args.at(1);

    // Make sure the identifier isn't in use yet
    if (!surfaces[key])
    {
        surfaces[key] = Surface::FromFile(path.c_str());
    }

    return NULL;
}

// Frees an ASCIILib surface from memory
State* FreeSurface(Whisperer* game, vector<string> args)
{
    // Syntax: FreeSurface [identifier]
    string key = args.at(0);

    delete surfaces[key];
    surfaces.erase(key);

    return NULL;
}

// Prints the characters in an ASCIILib surface.
State* PrintSurfaceContents(Whisperer* game, vector<string> args)
{
    // Syntax: PrintSurfaceContents [identifier]
    string key = args.at(0);

    surfaces[key]->printContents();

    return NULL;
}

// Blits a loaded ASCIILib surface to the screen (ignoring transparent parts)
State* BlitSurface(Whisperer* game, vector<string> args)
{
    // Syntax: BlitSurface [identifier] [x] [y]
    string key = args.at(0);
    int x = coord(args.at(1));
    int y = coord(args.at(2));

    game->graphics()->blitSurface(surfaces[key], x, y);

    return NULL;
}

// Copies a loaded ASCIILib surface to the screen (preserving transparency)
State* CopySurface(Whisperer* game, vector<string> args)
{
    // Syntax: CopySurface [identifier] [x] [y]
    string key = args.at(0);
    int x = coord(args.at(1));
    int y = coord(args.at(2));

    game->graphics()->copySurface(surfaces[key], x, y);

    return NULL;
}

// IMAGES

// Loads an image and stores it by the given identifier
State* LoadImage(Whisperer* game, vector<string> args)
{
    // Syntax: LoadImage [identifier] [filename]
    string key = args.at(0);
    string path = args.at(1);

    game->imageCache()->loadTexture(key, path.c_str());

    return NULL;
}

// Frees an image from memory
State* FreeImage(Whisperer* game, vector<string> args)
{
    // Syntax: FreeImage [identifier]
    string key = args.at(0);

    game->imageCache()->freeTexture(key);

    return NULL;
}

// Adds an image to the background of the scene
State* AddBackgroundImage(Whisperer* game, vector<string> args)
{
    // Syntax: AddBackgroundImage [identifier] [x] [y]
    string key = args.at(0);
    int x = coord(args.at(1));
    int y = coord(args.at(2));

    game->graphics()->addBackgroundImage(key, key, x, y);

    return NULL;
}

// Adds an image to the foreground of the scene
State* AddForegroundImage(Whisperer* game, vector<string> args)
{
    // Syntax: AddForegroundImage [identifier] [x] [y]
    string key = args.at(0);
    int x = coord(args.at(1));
    int y = coord(args.at(2));

    game->graphics()->addForegroundImage(key, key, x, y);

    return NULL;
}

// Clears all images from the scene
State* ClearImages(Whisperer* game, vector<string> args)
{
    game->graphics()->clearImages();

    return NULL;
}
