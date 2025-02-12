#include <core/application.h>
#include "playtetrismenu.h"
#include "main.h"

PlayTetrisMenu::PlayTetrisMenu()
{
}

void PlayTetrisMenu::Init()
{
    cam = new Camera();

    background = new Sprite("data/art/bg.png", 0, 0, 0.39, 0.39);

    backButton = new Sprite("data/art/backArrow.png", 40, 120, 0.5, 0.5);

    levelSelectButton = new Sprite("data/art/levelSelectButton.png", 20, 220);
    endlessModeButton = new Sprite("data/art/endlessModeButton.png", 20, 320);

    iphone = new Sprite("data/iphone.png", 0, 0, 0.75, 0.75);
    cursor = new Sprite("data/art/BlackCursor.png", 0, 0);

    components.Add(levelSelectButton);
    components.Add(endlessModeButton);
    components.Add(backButton);
    components.Add(background);
    components.Add(iphone);
    components.Add(cursor);
}

void PlayTetrisMenu::Update()
{
    *cursor->matrix.x = input.Mouse.x;
    *cursor->matrix.y = input.Mouse.y;

    if (backButton->IsPressed())
    {
        Application::LoadScene(Scenes::StartMenu);
    }

    if (levelSelectButton->IsPressed())
    {
        Application::LoadScene(Scenes::LevelSelectMenu);
    }

    if (endlessModeButton->IsPressed())
    {
        Application::LoadScene(Scenes::Tetris);
    }
}

void PlayTetrisMenu::UpdateAfterPhysics()
{
}

