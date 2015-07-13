#include "Whisperer.h"

#include <fstream>
#include <sstream>

#include <SDL.h>

#include "Color.h"

#include "commands/graphics.h"

using namespace ascii;


void Whisperer::RegisterScriptCommands()
{
    scriptManager.RegisterCommand("Clear", &Clear);
    scriptManager.RegisterCommand("LoadSurface", &LoadSurface);
    scriptManager.RegisterCommand("FreeSurface", &FreeSurface);
    scriptManager.RegisterCommand("PrintSurfaceContents", &PrintSurfaceContents);
    scriptManager.RegisterCommand("BlitSurface", &BlitSurface);
    scriptManager.RegisterCommand("LoadImage", &LoadImage);
    scriptManager.RegisterCommand("AddForegroundImage", &AddForegroundImage);
    scriptManager.RegisterCommand("UpdateScreen", &UpdateScreen);
    scriptManager.RegisterCommand("ClearImages", &ClearImages);
}

void Whisperer::LoadContent(ImageCache* imageCache, SoundManager* soundManager)
{
    textManager.SetPack("Official English Pack");
    textManager.LoadFile("chapter1.json");

    scriptManager.RunScript("content/scripts/load.wsp");
}

void Whisperer::Update(int deltaMS)
{
    while (scriptManager.HasNextCommand())
    {
        scriptManager.ProcessNextCommand(this);
    }
}

void Whisperer::HandleInput(Input& input)
{
    bool fullscreen = false;
    if (input.isKeyHeld(SDLK_SPACE))
    {
        fullscreen = true;
    }

    if (input.wasKeyPressed(SDLK_a))
    {
        graphics()->SetVideoMode(1.0f, fullscreen);
        scriptManager.RunScript("content/scripts/load.wsp");
    }
    if (input.wasKeyPressed(SDLK_b))
    {
        graphics()->SetVideoMode(1.5f, fullscreen);
        scriptManager.RunScript("content/scripts/load.wsp");
    }
    if (input.wasKeyPressed(SDLK_c))
    {
        graphics()->SetVideoMode(2.0f, fullscreen);
        scriptManager.RunScript("content/scripts/load.wsp");
    }

    mouseX = graphics()->pixelToCellX(input.mouseX());
    mouseY = graphics()->pixelToCellY(input.mouseY());

    if (input.wasKeyPressed(SDLK_ESCAPE))
    {
        Quit();
    }
}

void Whisperer::Draw(Graphics& graphics)
{
    graphics.clear();

    graphics.blitString(textManager.GetText("herald-title").c_str(), Color::White, 5, 5);

    std::stringstream sstream;

    sstream << "x: " << mouseX << " y: " << mouseY;

    graphics.blitString(sstream.str().c_str(), Color::White, 0, 0);
    graphics.setBackgroundColor(mouseX, mouseY, Color::Green);
    

    graphics.update();
    scriptManager.RunScript("content/scripts/draw.wsp");
}
