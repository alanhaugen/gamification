#ifndef DictionaryMenu_H
#define DictionaryMenu_H

#include <core/x-platform/scene.h>
#include "mousecursor.h"

class DictionaryMenu : public IScene
{
private:
    MouseCursor* cursor = nullptr;
    Sprite* backButton;

public:
    DictionaryMenu();

    void Init();
    void Update(float dt);
    void UpdateAfterPhysics();
};

#endif
