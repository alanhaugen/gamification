#include "intro.h"
#include <core/application.h>
#include <core/components/camera.h>
#include <core/components/background.h>
#include <core/components/cube.h>
#include <core/components/text.h>

Intro::Intro()
{
}

void Intro::Init()
{
    croco = new Sprite("data/art/croco.png", 1000, 250);
    Camera* cam = new Camera();
    components.Add(cam);
    components.Add(new Text("AB", 0.0f, 240.0f, 10.0f, 10.0f, glm::vec2(0.0f, 0.0f),
                            "data/hirigana.png"));
    components.Add(new Text("Welcome to LexiBlocks!", 100, 150, 2, 2));
    components.Add(new Text("I am Professor Croco.", 100, 200, 2, 2));
    //components.Add(new Background(glm::vec3(0.972549019607843f, 0.929411764705882f, 0.92156862745098f), cam));
    components.Add(croco);
    components.Add(new Background(glm::vec3(0.776470588235294, 0.870588235294118, 0.945098039215686), cam));

    startTime = Application::GetTime();

    t = 0.0;
}

void Intro::Update()
{
    if (*croco->matrix.x > 700)
    {
        *croco->matrix.x = 1000 - (700 * t);
        t += startTime->TimeSinceStarted() / 100000;
    }
    else
    {
        *croco->matrix.x = 700;
    }

    if (input.Released(input.Key.R))
    {
        *croco->matrix.x = 1000;
    }
}

void Intro::UpdateAfterPhysics()
{
}

