#pragma once

#include <vector>
using std::vector;

#include "../State.h"

#include "Input.h"
#include "Graphics.h"

#include "../TextManager.h"

#include "Button.h"

// Menu for picking a language to play in
class LanguageMenu : public State
{
    public:
        LanguageMenu(TextManager* textManager);

        void Update(int deltaMS);
        void HandleInput(Input& input);
        void Draw(Graphics& graphics);

        bool IsFinished();
        State* NextState();
    private:
        TextManager* mTextManager;

        vector<Button> buttons;
};
