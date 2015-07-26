#include "Button.h"

Button::Button(string text, int cellX, int cellY)
    : text(text), cellX(cellX), cellY(cellY),
    textColor(Color::White), textColorSelected(Color::Yellow),
    backgroundColor(Color::Black), backgroundColorSelected(Color::Black),
    mouseX(0), mouseY(0), pressed(false), mousePressed(false)
{
}

void Button::HandleInput(Input& input)
{
    // Retrieve input regarding the cursor position and left mouse button
    mouseX = input.mouseX();
    mouseY = input.mouseY();

    mousePressed = input.mouseButtonClicked(LEFT);
}

void Button::Draw(Graphics& graphics)
{
    // Convert input into cell terms
    const int cellMouseX = graphics.pixelToCellX(mouseX);
    const int cellMouseY = graphics.pixelToCellY(mouseY);

    int left = cellX;
    int right = cellX + text.size();

    // Then check if this button is selected by the cursor
    const bool selected = cellMouseY == cellY && cellMouseX >= left
        && cellMouseX < right;

    // Choose the appropriate colors for drawing the button
    Color textCol = selected ? textColorSelected : textColor;
    Color backgroundCol = selected ? backgroundColorSelected : backgroundColor;

    // Draw the button background
    for (int x = left; x < right; ++x)
    {
        graphics.setBackgroundColor(x, cellY, backgroundCol);
    }

    // Then draw the button text
    graphics.blitString(text.c_str(), textCol, cellX, cellY);

    // If the button has been pressed, set a flag so the containing menu
    // can handle the event
    pressed = mousePressed && selected;
}
