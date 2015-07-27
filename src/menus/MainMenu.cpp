#include "MainMenu.h"

MainMenu::MainMenu(TextManager* textManager)
    : mTextManager(mTextManager), finished(false)
{
    chapter1 = Button(mTextManager->GetText("chapter-one"), 5, 5);
}

void MainMenu::Update(int deltaMS)
{
    chapter1.Update(deltaMS);

    if (chapter1.IsPressed())
    {
        finished = true;
    }
}

void MainMenu::HandleInput(Input& input)
{
    chapter1.HandleInput(input);
}

void MainMenu::Draw(Graphics& graphics)
{
    chapter1.Draw(graphics);
}

void MainMenu::IsFinished()
{
    return finished;
}

State* MainMenu::NextState(Whisperer* whisperer)
{
    return NULL; // TODO
}
