#include "quiz.h"

#include <core/components/camera.h>
#include <core/components/background.h>
#include <core/components/text.h>

Quiz::Quiz()
{
}

void Quiz::Init()
{
    Camera* cam = new Camera();
    components.Add(cam);
    components.Add(new Background(glm::vec3(0.776470588235294, 0.870588235294118, 0.945098039215686), cam));
    components.Add(new Text("You completed the level!", 100, 50));
    components.Add(new Text("QUIZ", (renderer->windowWidth / 2) - 75, 150));
    //components.Add(new Background());
}

void Quiz::Update()
{

}

void Quiz::UpdateAfterPhysics()
{

}
