#ifndef GameMenu_H
#define GameMenu_H

#include <core/x-platform/scene.h>

class GameMenu : public IScene
{
public:
    GameMenu();

    void Init();
    void Update(float dt);
    void UpdateAfterPhysics();
};

#endif
