#ifndef DictionaryMenu_H
#define DictionaryMenu_H

#include <core/x-platform/scene.h>

class DictionaryMenu : public IScene
{
public:
    DictionaryMenu();

    void Init();
    void Update();
    void UpdateAfterPhysics();
};

#endif
