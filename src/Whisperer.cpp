#include "Whisperer.h"

#include <fstream>
#include <sstream>

#include "json.h"

#include "Color.h"

#include "commands/graphics.h"

using namespace ascii;


void Whisperer::RegisterScriptCommands()
{
    scriptManager.RegisterCommand("Clear", &Clear);
    scriptManager.RegisterCommand("LoadSurface", &LoadSurface);
    scriptManager.RegisterCommand("FreeSurface", &FreeSurface);
    scriptManager.RegisterCommand("BlitSurface", &BlitSurface);
}

void Whisperer::LoadContent(ImageCache* imageCache, SoundManager* soundManager)
{
    textManager.SetPack("Spanish");
    textManager.LoadFile("chapter1.json");

    scriptManager.RunCommand("LoadSurface journal content/journal.srf");
    scriptManager.ProcessNextCommand(this);
}

void Whisperer::Update(int deltaMS)
{

}

void Whisperer::HandleInput(Input& input)
{
}

void Whisperer::Draw(Graphics& graphics)
{
    scriptManager.RunCommand("Clear");
    scriptManager.ProcessNextCommand(this);

    scriptManager.RunCommand("BlitSurface journal 0 0");
    scriptManager.ProcessNextCommand(this);

    graphics.update();
}
