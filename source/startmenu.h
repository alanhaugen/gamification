#ifndef STARTMENU_H
#define STARTMENU_H

#include <core/x-platform/scene.h>
#include <core/components/text.h>
#include <core/components/camera.h>
#include "tetris.h"
#include "mousecursor.h"

class StartMenu : public IScene
{
private:
    Camera* cam;
    Sprite* logo;
    MouseCursor* cursor;

    Sprite* playTetrisButton;
    Sprite* dictionaryButton;
    Sprite* settingsButton;

    Sprite* background;

    Tetris* tetris;

public:

    StartMenu();

    void Init();
    void Update(float dt);
    void UpdateAfterPhysics();
};

#endif
