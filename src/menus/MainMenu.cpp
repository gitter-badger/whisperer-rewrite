#include "MainMenu.h"

#include "ChapterState.h"

MainMenu::MainMenu(TextManager* textManager)
    : mTextManager(textManager), finished(false),
    chapter1(textManager->GetText("chapter-one"), 5, 5)
{
}

void MainMenu::Update(int deltaMS)
{
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
    graphics.clear();
    chapter1.Draw(graphics);
    graphics.update();
}

bool MainMenu::IsFinished()
{
    return finished;
}

State* MainMenu::NextState(Whisperer* whisperer)
{
    return new ChapterState(whisperer, 1);
}
