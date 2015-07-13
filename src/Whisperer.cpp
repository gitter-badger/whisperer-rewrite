#include "Whisperer.h"

#include <fstream>
#include <sstream>

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
}

void Whisperer::Draw(Graphics& graphics)
{
    //scriptManager.RunScript("content/scripts/draw.wsp");
    graphics.clear();

    graphics.blitString(textManager.GetText("herald-title").c_str(), Color::White, 5, 5);
    graphics.update();
}
