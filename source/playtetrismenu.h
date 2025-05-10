#ifndef PlayTetrisMenu_H
#define PlayTetrisMenu_H

#include <core/x-platform/scene.h>
#include <core/components/text.h>
#include <core/components/camera.h>

class PlayTetrisMenu : public IScene
{
private:
    Camera* cam;
    Sprite* logo;
    Sprite* cursor;

    Sprite* backButton;

    Sprite* levelSelectButton;
    Sprite* endlessModeButton;

    Sprite* background;
    Sprite* iphone;

public:
    PlayTetrisMenu();

    void Init();
    void Update(float dt);
    void UpdateAfterPhysics();
};

#endif
