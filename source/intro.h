#ifndef INTRO_H
#define INTRO_H

#include <core/x-platform/scene.h>
#include <core/components/sprite.h>
#include <core/components/cube.h>
#include <core/components/text.h>
#include <core/containers/queue.h>

class TextBlock : public Component
{
public:
    TextBlock(String top, String bottom = "")
    {
        topText    = new Text(top, 100, 150, 0.5, 0.5);
        bottomText = new Text(bottom, 100, 200, 0.5, 0.5);
    }

    void Update()
    {
        topText->Update();
        bottomText->Update();
    }

    void UpdateAfterPhysics()
    {
    }

private:
    Text* topText;
    Text* bottomText;
};

class Intro : public IScene
{
public:
    Intro();

    void Init();
    void Update(float dt);
    void UpdateAfterPhysics();

    Sprite* croco;
    Sprite* bubble;
    Sprite* bubbleScaled;
    ITime* startTime;
    Cube* cube;
    float t;
    float i;

    Queue<TextBlock*> speech;
};

#endif
