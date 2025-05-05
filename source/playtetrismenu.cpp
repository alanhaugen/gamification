#include <core/application.h>
#include "playtetrismenu.h"
#include "main.h"

PlayTetrisMenu::PlayTetrisMenu()
{
}

void PlayTetrisMenu::Init()
{
    cam = new Camera();

    background = new Sprite("data/art/new/bg.png", 0, 0, 1.0, 1.0);

    backButton = new Sprite("data/art/backArrow.png", 40, 120, 0.5, 0.5);

    levelSelectButton = new Sprite("data/art/levelSelectButton.png", 320, 200, 0.5, 0.5);
    endlessModeButton = new Sprite("data/art/endlessModeButton.png", 320, 400, 0.5, 0.5);

    cursor = new Sprite("data/art/BlackCursor.png", 0, 0);

    components.Add(levelSelectButton);
    components.Add(endlessModeButton);
    components.Add(backButton);
    components.Add(background);
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

