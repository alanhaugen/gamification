#ifndef GameOver_H
#define GameOver_H

#include <core/x-platform/scene.h>

class GameOver : public IScene
{
public:
    GameOver();

    void Init();
    void Update(float dt);
    void UpdateAfterPhysics();
};

#endif
