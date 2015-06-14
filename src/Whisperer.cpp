#include "Whisperer.h"

#include <iostream>
#include <fstream>
#include <sstream>

#include "json.h"

#include "Color.h"

using namespace ascii;

void Whisperer::LoadContent(ImageCache* imageCache, SoundManager* soundManager)
{
}

void Whisperer::Update(Game* game, int deltaMS)
{
}

void Whisperer::HandleInput(Game* game, Input& input)
{
}

void Whisperer::Draw(Graphics& graphics)
{
    graphics.clear();

    graphics.blitString("Hello world!", ascii::Color::Green, 9, 3);
    graphics.update();
}
