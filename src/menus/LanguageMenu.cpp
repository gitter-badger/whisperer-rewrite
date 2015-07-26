#include "LanguageMenu.h"

LanguageMenu::LanguageMenu(TextManager* textManager)
    : textManager(textManager)
{
    buttons.push_back(Button("Test 1", 5, 3));
    buttons.push_back(Button("Test 2", 5, 4));
    buttons.push_back(Button("Test 3", 5, 5));
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
