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
    overview = new Sprite("data/art/levelSelectOverview.png", 10, 170, 0.4, 0.8);
    backButton = new Sprite("data/art/backArrow.png", 40, 120, 0.5, 0.5);
    iphone = new Sprite("data/iphone.png", 0, 0, 0.75, 0.75);
    level = new Level(1, renderer->windowWidth/2 - 64, renderer->windowHeight/2 - 64);
    cursor = new MouseCursor();

    components.Add(backButton);
    components.Add(overview);
    components.Add(cursor);
    components.Add(iphone);
}

void LevelSelectMenu::Update()
{
    cursor->Update();
    level->Update();

    if (backButton->IsPressed())
    {
        Application::LoadScene(Scenes::PlayTetrisMenu);
    }
}

void LevelSelectMenu::UpdateAfterPhysics()
{
}

