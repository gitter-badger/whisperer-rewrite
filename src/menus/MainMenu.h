#pragma once

#include "../State.h"

#include "Graphics.h"
#include "Input.h"

#include "../TextManager.h"

#include "Button.h"

class Whisperer;

class MainMenu : public State
{
    public:
        MainMenu(TextManager* textManager);

        void Update(int deltaMS);
        void HandleInput(Input& input);
        void Draw(Graphics& graphics);

        bool IsFinished();
        State* NextState(Whisperer* whisperer);
    private:
        TextManager* mTextManager;
        Button chapter1;
        bool finished;
};
