#include <core/application.h>
#include "levelselectmenu.h"
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
    level1 = new Level(1, renderer->windowWidth/2 - 150, renderer->windowHeight/2 - 64);
    level2 = new Level(99, renderer->windowWidth/2, renderer->windowHeight/2 - 64);
    cursor = new MouseCursor();

    components.Add(backButton);
    components.Add(overview);
    components.Add(cursor);
    components.Add(iphone);
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

