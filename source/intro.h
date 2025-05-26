#ifndef INTRO_H
#define INTRO_H

#include <core/x-platform/scene.h>
#include <core/components/sprite.h>
#include <core/components/cube.h>
#include <core/components/text.h>
#include <core/containers/queue.h>
#include "block.h"

class TextBlock : public Component
{
public:
    TextBlock(String top, String bottom = "")
    {
        topText    = new Text(top, 450, 150, 0.5, 0.5, glm::vec2(0.5,0));
        bottomText = new Text(bottom, 450, 200, 0.5, 0.5, glm::vec2(0.5,0));
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

    int count = 0;

    Sprite* croco;
    Sprite* crocoTalk;
    Sprite* bubble;
    Sprite* bubbleScaled;
    ITime* startTime;
    Cube* cube;
    float t;
    float i;
    float j;

    Queue<TextBlock*> speech;
};

#endif
