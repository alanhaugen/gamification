#ifndef DictionaryMenu_H
#define DictionaryMenu_H

#include <core/x-platform/scene.h>
#include "mousecursor.h"

class DictionaryMenu : public IScene
{
private:
    MouseCursor* cursor = nullptr;
public:
    DictionaryMenu();

    void Init();
    void Update();
    void UpdateAfterPhysics();
};

#endif
