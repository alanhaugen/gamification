#ifndef INTRO_H
#define INTRO_H

#include <core/x-platform/scene.h>
#include <core/components/sprite.h>
#include <core/components/cube.h>

class Intro : public IScene
{
public:
    Intro();

    void Init();
    void Update();
    void UpdateAfterPhysics();

    Sprite* croco;
    Sprite* bubble;
    Sprite* bubbleScaled;
    ITime* startTime;
    Cube* cube;
    float t;
    float i;
};

#endif
