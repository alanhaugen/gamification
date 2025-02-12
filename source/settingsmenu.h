#ifndef SettingsMenu_H
#define SettingsMenu_H

#include <core/x-platform/scene.h>

class SettingsMenu : public IScene
{
public:
    SettingsMenu();

    void Init();
    void Update();
    void UpdateAfterPhysics();
};

#endif
