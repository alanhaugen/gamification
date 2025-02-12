#ifndef LevelSelectMenu_H
#define LevelSelectMenu_H

#include <core/x-platform/scene.h>
#include <core/components/sprite.h>

class LevelSelectMenu : public IScene
{
private:
    Sprite* overview;
    Sprite* cursor;
    Sprite* backButton;
    Sprite* iphone;

public:
    LevelSelectMenu();

    void Init();
    void Update();
    void UpdateAfterPhysics();
};

#endif
