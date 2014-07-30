#include "Whisperer.h"

#include <iostream>


void Whisperer::LoadContent(ImageCache* imageCache, SoundManager* soundManager)
{
    std::cout << "Load content" << std::endl;
}

void Whisperer::Update(Game* game, int deltaMS)
{
    std::cout << "Update" << std::endl;
}

void Whisperer::HandleInput(Game* game, Input& input)
{
    std::cout << "Handle input" << std::endl;
}

void Whisperer::Draw(Graphics& graphics)
{
    std::cout << "Draw" << std::endl;
}
