#include "Whisperer.h"

#include <fstream>
#include <sstream>

// TODO debug
#include <iostream>

#include "json.h"

#include "Color.h"

using namespace ascii;


void Whisperer::RegisterScriptCommands()
{
}

void Whisperer::LoadContent(ImageCache* imageCache, SoundManager* soundManager)
{
    textManager.SetPack("Spanish");
    textManager.LoadFile("chapter1.json");
    std::cout << textManager.GetText("p1") << std::endl;
}

void Whisperer::Update(int deltaMS)
{
}

void Whisperer::HandleInput(Input& input)
{
}

void Whisperer::Draw(Graphics& graphics)
{
    graphics.clear();

    graphics.blitString(textManager.GetText("p1").c_str(), ascii::Color::Green, 9, 3);
    graphics.update();
}
