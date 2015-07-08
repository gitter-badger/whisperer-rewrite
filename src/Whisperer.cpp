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
}

void Whisperer::LoadContent(ImageCache* imageCache, SoundManager* soundManager)
{
    textManager.SetPack("Spanish");
    textManager.LoadFile("chapter1.json");
}

void Whisperer::Update(int deltaMS)
{

}

void Whisperer::HandleInput(Input& input)
{
}

void Whisperer::Draw(Graphics& graphics)
{
    graphics.blitString(textManager.GetText("p1").c_str(), ascii::Color::Green, 9, 3);

    scriptManager.RunCommand("Clear");
    scriptManager.ProcessNextCommand(this);
    graphics.update();
}
