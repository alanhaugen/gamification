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
    background = new Sprite("data/art/new/bg.png", 0, 0, 1.3, 1.3);
    backButton = new Sprite("data/art/backArrow.png", 40, 120, 0.2, 0.2);
    level1 = new Level(1, renderer->windowWidth/2 - 150, renderer->windowHeight/2 - 64);
    level2 = new Level(99, renderer->windowWidth/2, renderer->windowHeight/2 - 64);
    cursor = new MouseCursor();

    components.Add(backButton);
    components.Add(cursor);
    components.Add(background);
}

void LevelSelectMenu::Update(float dt)
{
    cursor->Update();
    level1->Update();
    level2->Update();

    if (backButton->IsPressed())
    {
        Application::LoadScene(Scenes::StartMenu);
    }

    if (input.Held(input.Key.R))
    {
        Application::LoadScene(Scenes::Intro);
    }
}

void LevelSelectMenu::UpdateAfterPhysics()
{
}

