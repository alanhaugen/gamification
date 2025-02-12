#include <core/application.h>
#include "levelselectmenu.h"
#include "main.h"

LevelSelectMenu::LevelSelectMenu()
{
}

void LevelSelectMenu::Init()
{
    overview = new Sprite("data/art/levelSelectOverview.png", 10, 170, 0.4, 0.8);
    backButton = new Sprite("data/art/backArrow.png", 40, 120, 0.5, 0.5);
    iphone = new Sprite("data/iphone.png", 0, 0, 0.75, 0.75);
    cursor = new Sprite("data/art/BlackCursor.png", 0, 0);

    components.Add(backButton);
    components.Add(overview);
    components.Add(cursor);
    components.Add(iphone);
}

void LevelSelectMenu::Update()
{
    *cursor->matrix.x = input.Mouse.x;
    *cursor->matrix.y = input.Mouse.y;

    if (backButton->IsPressed())
    {
        Application::LoadScene(Scenes::PlayTetrisMenu);
    }
}

void LevelSelectMenu::UpdateAfterPhysics()
{
}

