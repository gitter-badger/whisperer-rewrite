#pragma once

// TODO debug
#include <iostream>

#include <vector>
using std::vector;
#include <string>
using std::string;
#include <map>
using std::map;

#include "../Whisperer.h"
#include "Surface.h"
using ascii::Surface;

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

void Clear(Whisperer* game, vector<string> args)
{
    game->graphics()->clear();
}

void ClearTransparent(Whisperer* game, vector<string> args)
{
    game->graphics()->clearTransparent();
}

void ClearOpaque(Whisperer* game, vector<string> args)
{
    game->graphics()->clearOpaque();
}

// UPDATE

void UpdateScreen(Whisperer* game, vector<string> args)
{
    game->graphics()->update();
}

// SURFACES

// Loads a ASCIILib surface and stores it by the given identifier
void LoadSurface(Whisperer* game, vector<string> args)
{
    // Syntax: LoadSurface [identifier] [filename]
    string key = args.at(0);
    string path = args.at(1);

    // Make sure the identifier isn't in use yet
    if (!surfaces[key])
    {
        std::cout << "Loading a surface" << std::endl;
        surfaces[key] = Surface::FromFile(path.c_str());
        std::cout << "done Loading a surface" << std::endl;
    }
}

// Frees an ASCIILib surface from memory
void FreeSurface(Whisperer* game, vector<string> args)
{
    // Syntax: FreeSurface [identifier]
    string key = args.at(0);

    delete surfaces[key];
    surfaces.erase(key);
}

// Blits a loaded ASCIILib surface to the screen (ignoring transparent parts)
void BlitSurface(Whisperer* game, vector<string> args)
{
    // Syntax: BlitSurface [identifier] [x] [y]
    string key = args.at(0);
    int x = coord(args.at(1));
    int y = coord(args.at(2));

    game->graphics()->blitSurface(surfaces[key], x, y);
}

// Copies a loaded ASCIILib surface to the screen (preserving transparency)
void CopySurface(Whisperer* game, vector<string> args)
{
    // Syntax: CopySurface [identifier] [x] [y]
    string key = args.at(0);
    int x = coord(args.at(1));
    int y = coord(args.at(2));

    game->graphics()->copySurface(surfaces[key], x, y);
}

// IMAGES

// Loads an image and stores it by the given identifier
void LoadImage(Whisperer* game, vector<string> args)
{
    // Syntax: LoadImage [identifier] [filename]
    string key = args.at(0);
    string path = args.at(1);

    game->imageCache()->loadTexture(key, path.c_str());
}

// Frees an image from memory
void FreeImage(Whisperer* game, vector<string> args)
{
    // Syntax: FreeImage [identifier]
    string key = args.at(0);

    game->imageCache()->freeTexture(key);
}

// Adds an image to the background of the scene
void AddBackgroundImage(Whisperer* game, vector<string> args)
{
    // Syntax: AddBackgroundImage [identifier] [x] [y]
    string key = args.at(0);
    int x = coord(args.at(1));
    int y = coord(args.at(2));

    game->graphics()->addBackgroundImage(key, key, x, y);
}

// Adds an image to the foreground of the scene
void AddForegroundImage(Whisperer* game, vector<string> args)
{
    // Syntax: AddForegroundImage [identifier] [x] [y]
    string key = args.at(0);
    int x = coord(args.at(1));
    int y = coord(args.at(2));

    game->graphics()->addForegroundImage(key, key, x, y);
}

// Clears all images from the scene
void ClearImages(Whisperer* game, vector<string> args)
{
    game->graphics()->clearImages();
}
