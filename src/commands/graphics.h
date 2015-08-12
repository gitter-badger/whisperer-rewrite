#pragma once

#include <vector>
using std::vector;
#include <string>
using std::string;
#include <map>
using std::map;

#include "Surface.h"
using ascii::Surface;

#include "../Whisperer.h"

#include "../states/TimeDelay.h"

#include "util.h"

class State;


// Global fields

namespace
{
    map<string, Surface*> surfaces;
    map<string, Scene*> scenes;
}

// CLEAR BUFFER SURFACE

// Clears every cell of the game's graphics buffer (a surface).
State* Clear(Whisperer* game, vector<string> args)
{
    game->graphics()->clear();
    return NULL;
}

// Sets every cell of the game's graphics buffer to transparent.
State* ClearTransparent(Whisperer* game, vector<string> args)
{
    game->graphics()->clearTransparent();
    return NULL;
}

// Sets every cell of the game's graphics buffer to opaque.
State* ClearOpaque(Whisperer* game, vector<string> args)
{
    game->graphics()->clearOpaque();
    return NULL;
}

// UPDATE

// Renders the current scene represented by the game's graphics buffer
// OR the currents scene
State* UpdateScreen(Whisperer* game, vector<string> args)
{
    game->UpdateScreen();
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

// Blits a loaded ASCIILib surface to the screen OR the currently active scene
// (ignoring transparent parts)
State* BlitSurface(Whisperer* game, vector<string> args)
{
    // Syntax: BlitSurface [identifier] [x] [y]
    string key = args.at(0);
    int x = coord(args.at(1));
    int y = coord(args.at(2));

    // Blit directly to the graphics buffer if there is no active scene
    if (game->CurrentScene() == NULL)
    {
        game->graphics()->blitSurface(surfaces[key], x, y);
    }
    // Otherwise, blit to the scene's background surface
    else
    {
        game->CurrentScene()->BlitBackgroundSurface(surfaces[key], x, y);
    }

    return NULL;
}

// Copies a loaded ASCIILib surface to the screen OR the currently active scene
// (preserving transparency)
State* CopySurface(Whisperer* game, vector<string> args)
{
    // Syntax: CopySurface [identifier] [x] [y]
    string key = args.at(0);
    int x = coord(args.at(1));
    int y = coord(args.at(2));

    // Copy directly to the graphics buffer if there is no active scene
    if (game->CurrentScene() == NULL)
    {
        game->graphics()->copySurface(surfaces[key], x, y);
    }
    // Otherwise, copy directly to the scene's background surface
    else
    {
        game->CurrentScene()->CopyBackgroundSurface(surfaces[key], x, y);
    }

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

// Adds an image to the background of the screen OR the currently active scene
State* AddBackgroundImage(Whisperer* game, vector<string> args)
{
    // Syntax: AddBackgroundImage [identifier] [x] [y]
    string key = args.at(0);
    int x = coord(args.at(1));
    int y = coord(args.at(2));

    // Add the image directly to the graphics instance if there is no
    // currently active scene
    if (game->CurrentScene() == NULL)
    {
        game->graphics()->addBackgroundImage(key, key, x, y);
    }
    // Otherwise, add the image to the scene instead
    else
    {
        game->CurrentScene()->AddBackgroundImage(key, x, y);
    }

    return NULL;
}

// Adds an image to the foreground of the screen OR the currently active scene
State* AddForegroundImage(Whisperer* game, vector<string> args)
{
    // Syntax: AddForegroundImage [identifier] [x] [y]
    string key = args.at(0);
    int x = coord(args.at(1));
    int y = coord(args.at(2));

    // Add the image directly to the graphics instance if there is no
    // currently active scene
    if (game->CurrentScene() == NULL)
    {
        game->graphics()->addForegroundImage(key, key, x, y);
    }
    // Otherwise, add the image to the scene instead
    else
    {
        game->CurrentScene()->AddForegroundImage(key, x, y);
    }

    return NULL;
}

// Clears all images from the screen OR the currently active scene
State* ClearImages(Whisperer* game, vector<string> args)
{
    // If there is no active scene, clear the graphics instance
    if (game->CurrentScene() == NULL)
    {
        game->graphics()->clearImages();
    }
    // Otherwise, clear the scene
    else
    {
        game->CurrentScene()->ClearImages();
    }

    return NULL;
}

// SCENES

// Create a new empty scene
State* CreateScene(Whisperer* game, vector<string> args)
{
    // Syntax: CreateScene [name]
    string name = args.at(0);
    scenes[name] = new Scene();

    return NULL;
}

// Delete a scene
State* DeleteScene(Whisperer* game, vector<string> args)
{
    // Syntax: DeleteScene [name]
    string name = args.at(0);
    delete scenes[name];
    scenes.erase(name);

    return NULL;
}

// Set the current scene
State* SetScene(Whisperer* game, vector<string> args)
{
    // Syntax: SetScene [name]
    string name = args.at(0);
    game->SetScene(scenes[name]);

    return NULL;
}

// Set the currents scene to NULL
State* ClearScene(Whisperer* game, vector<string> args)
{
    game->SetScene(NULL);
    return NULL;
}

// Show the current scene
State* ShowScene(Whisperer* game, vector<string> args)
{
    game->ShowScene();
    return NULL;
}

// Hide the current scene
State* HideScene(Whisperer* game, vector<string> args)
{
    game->HideScene();
    return NULL;
}

// Tween a surface between two points in the current scene
State* TweenSurface(Whisperer* game, vector<string> args)
{
    // Syntax: TweenSurface [key] [sourcex] [sourcey] [destx] [desty] [totalms]
    string key = args.at(0);
    int sourceX = coord(args.at(1));
    int sourceY = coord(args.at(2));
    int destX = coord(args.at(3));
    int destY = coord(args.at(4));
    int totalMS = coord(args.at(5));

    game->CurrentScene()->TweenSurface(surfaces[key], sourceX, sourceY,
            destX, destY, totalMS);

    // Delay the chapter until the tween is over
    return new TimeDelay(totalMS);
}

// Clear all surface tweens from the current scene
State* ClearTweens(Whisperer* game, vector<string> args)
{
    game->CurrentScene()->ClearTweens();
    return NULL;
}

// MISC.

// Clears glyphs stored in the game's Graphics instance for different
// collections of adjacent ASCII symbols
State* ClearGlyphs(Whisperer* game, vector<string> args)
{
    game->graphics()->clearGlyphs();
    return NULL;
}
