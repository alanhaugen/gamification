#ifndef LevelSelectMenu_H
#define LevelSelectMenu_H

#include <core/x-platform/scene.h>
#include <core/components/sprite.h>
#include "level.h"
#include "mousecursor.h"

class LevelSelectMenu : public IScene
{
private:
    Sprite* background;
    MouseCursor* cursor;
    Sprite* backButton;
    Sprite* iphone;
    Level* level1;
    Level* level2;

public:
    LevelSelectMenu();

    void Init();
    void Update(float dt);
    void UpdateAfterPhysics();
};

#endif
