#include <core/application.h>
#include "levelselectmenu.h"
#include "tetris.h"
#include "main.h"

extern Level* currentLevel;

LevelSelectMenu::LevelSelectMenu()
{
}

void LevelSelectMenu::Init()
{
    background = new Sprite("data/art/new/bg.png", -100, -100, 0.7, 0.7);
    backButton = new Sprite("data/art/backArrow.png", 40, 120, 0.5, 0.5);
    level1 = new Level(1, renderer->windowWidth/2 - 150, renderer->windowHeight/2 - 64);
    level2 = new Level(99, renderer->windowWidth/2, renderer->windowHeight/2 - 64);
    cursor = new MouseCursor();

    components.Add(backButton);
    components.Add(cursor);
    components.Add(background);
}

void LevelSelectMenu::Update()
{
    cursor->Update();
    level1->Update();
    level2->Update();

    if (backButton->IsPressed())
    {
        Application::LoadScene(Scenes::PlayTetrisMenu);
    }
}

void LevelSelectMenu::UpdateAfterPhysics()
{
}

