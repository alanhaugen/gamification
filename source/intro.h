#ifndef INTRO_H
#define INTRO_H

#include <core/x-platform/scene.h>
#include <core/components/sprite.h>

class Intro : public IScene
{
public:
    Intro();

    void Init();
    void Update();
    void UpdateAfterPhysics();

    Sprite* croco;
    ITime* startTime;
    float t;
};

#endif
