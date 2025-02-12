#include "playtetrismenu.h"

PlayTetrisMenu::PlayTetrisMenu()
{
}

void PlayTetrisMenu::Init()
{
    cam = new Camera();

    background = new Sprite("data/art/bg.png", 0, 0, 0.5, 0.5);

    iphone = new Sprite("data/iphone.png", 0, 0, 0.75, 0.75);
    cursor = new Sprite("data/art/BlackCursor.png", 0, 0);

    components.Add(background);
    components.Add(iphone);
    components.Add(cursor);
}

void PlayTetrisMenu::Update()
{
    *cursor->matrix.x = input.Mouse.x;
    *cursor->matrix.y = input.Mouse.y;
}

void PlayTetrisMenu::UpdateAfterPhysics()
{
}

