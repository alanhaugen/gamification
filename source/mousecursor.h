#ifndef MOUSECURSOR_H
#define MOUSECURSOR_H

#include <core/components/sprite.h>

class MouseCursor : public Component
{
private:
    Sprite* cursor = nullptr;
public:
    void Update();
    void UpdateAfterPhysics();

    MouseCursor();
};

#endif // MOUSECURSOR_H
