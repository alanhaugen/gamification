#ifndef PAUSEMENU_H
#define PAUSEMENU_H

#include <core/application.h>
#include "mousecursor.h"

class PauseMenu : public IScene
{
private:
    Sprite* backGround = nullptr;
    Sprite* buttonDictionary = nullptr;
    MouseCursor* cursor = nullptr;
public:
    void Update();
    void UpdateAfterPhysics();
    void Init();
    void Pause();

    bool isPaused;

    PauseMenu();
};

#endif // PAUSEMENU_H
