#include "Whisperer.h"

#include <iostream>
#include <fstream>
#include <sstream>

#include "json.h"

#include "Color.h"

using namespace ascii;

void Whisperer::LoadContent(ImageCache* imageCache, SoundManager* soundManager)
{
    textManager.SetPack("Official English Pack");
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
    graphics.clear();

    graphics.blitString(textManager.GetText("p1").c_str(), ascii::Color::Green, 9, 3);
    graphics.update();
}
