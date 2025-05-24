#include "mousecursor.h"

void MouseCursor::Update()
{
    *cursor->matrix.x = input.Mouse.x;
    *cursor->matrix.y = input.Mouse.y;
#ifndef NDK
    cursor->Update();
#endif
}

void MouseCursor::UpdateAfterPhysics()
{

}

MouseCursor::MouseCursor()
{
    cursor = new Sprite("data/art/BlackCursor.png", 0, 0);
}
