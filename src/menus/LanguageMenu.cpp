#include "LanguageMenu.h"

#include <map>


LanguageMenu::LanguageMenu(TextManager* textManager)
    : mTextManager(textManager)
{
    map<string, PackInfo> packs = mTextManager->LanguagePacks();

    int y = 3;
    for (auto it = packs.begin(); it != packs.end(); ++it)
    {
        buttons.push_back(Button(it->second.language, 5, y++));
    }
}

void LanguageMenu::Update(int deltaMS)
{
    for (auto it = buttons.begin(); it != buttons.end(); ++it)
    {
        if (it->IsPressed())
        {
            // TODO Set the game to the button's language!
        }
    }
}

void LanguageMenu::HandleInput(Input& input)
{
    for (auto it = buttons.begin(); it != buttons.end(); ++it)
    {
        it->HandleInput(input);
    }
}

void LanguageMenu::Draw(Graphics& graphics)
{
    graphics.clear();

    graphics.blitString("Choose your language.", Color::White, 0, 0);

    for (auto it = buttons.begin(); it != buttons.end(); ++it)
    {
        it->Draw(graphics);
    }

    graphics.update();
}

bool LanguageMenu::IsFinished()
{
    return false; // TODO
}

State* LanguageMenu::NextState()
{
    return NULL; // TODO
}
