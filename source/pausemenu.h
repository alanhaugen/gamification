#ifndef PAUSEMENU_H
#define PAUSEMENU_H

#include <core/application.h>

class PauseMenu : public IScene
{
private:
    Sprite* backGround = nullptr;

public:
    void Update();
    void UpdateAfterPhysics();
    void Init();
    void Pause();

    bool isPaused;

    PauseMenu();
};

#endif // PAUSEMENU_H
