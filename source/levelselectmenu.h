#ifndef LevelSelectMenu_H
#define LevelSelectMenu_H

#include <core/x-platform/scene.h>
#include <core/components/sprite.h>
#include "level.h"
#include "mousecursor.h"

class LevelSelectMenu : public IScene
{
private:
    Sprite* overview;
    MouseCursor* cursor;
    Sprite* backButton;
    Sprite* iphone;
    Level* level;

public:
    LevelSelectMenu();

    void Init();
    void Update();
    void UpdateAfterPhysics();
};

#endif
