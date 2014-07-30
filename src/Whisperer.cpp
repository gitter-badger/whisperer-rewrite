#include "Whisperer.h"

#include <iostream>
#include <fstream>
#include <sstream>

#include "json.h"

#include "Color.h"


void Whisperer::LoadContent(ImageCache* imageCache, SoundManager* soundManager)
{
    std::cout << "Load content" << std::endl;

    Json::Value root;
    Json::Reader reader;

    std::vector<const char*> languages;

    std::ifstream t("content/text/languages.json");
    std::stringstream buffer;
    buffer << t.rdbuf();

    bool parsingSuccessful = reader.parse(buffer.str(), root, false);

    if (parsingSuccessful)
    {
        Json::Value::Members memberNames = root.getMemberNames();
        for (Json::Value::Members::iterator it = memberNames.begin(); it != memberNames.end(); ++it)
        {
            std::cout << *it << ": " << root[*it].asString() << std::endl;
        }
    }
    else
    {
        std::cout << "oh no!!" << std::endl;
    }
}

void Whisperer::Update(Game* game, int deltaMS)
{
}

void Whisperer::HandleInput(Game* game, Input& input)
{
    if (input.wasKeyPressed(SDLK_1))
    {

    }
}

void Whisperer::Draw(Graphics& graphics)
{
    graphics.clear();

    graphics.blitString("Hello world!", ascii::Color::Green, 9, 3);
    graphics.update();
}
