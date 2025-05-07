#include "quiz.h"

#include <core/components/camera.h>
#include <core/components/background.h>
#include <core/components/text.h>
#include "dictionary.h"
#include "mousecursor.h"

extern Dictionary dictionary;

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
    components.Add(new Text("Translate:", (renderer->windowWidth / 2) - 175, 200));

    questions = dictionary.GetLexemeStack();

    question = new Text(questions.Top().translation, 100, 270);

    components.Add(question);


    components.Add(new Sprite("data/art/button.png", 110, 400, 0.5, 0.5));
    components.Add(new Sprite("data/art/button.png", 510, 400, 0.5, 0.5));
    components.Add(new Sprite("data/art/button.png", 110, 550, 0.5, 0.5));
    components.Add(new Sprite("data/art/button.png", 510, 550, 0.5, 0.5));

    components.Add(new MouseCursor());
}

void Quiz::Update()
{

}

void Quiz::UpdateAfterPhysics()
{

}
