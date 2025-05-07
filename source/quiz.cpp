#include "quiz.h"

#include <core/application.h>
#include <core/components/camera.h>
#include <core/components/background.h>
#include <core/components/text.h>
#include "main.h"
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

    button1 = new Sprite("data/art/button.png", 110, 400, 0.5, 0.5);
    button2 = new Sprite("data/art/button.png", 510, 400, 0.5, 0.5);
    button3 = new Sprite("data/art/button.png", 110, 550, 0.5, 0.5);
    button4 = new Sprite("data/art/button.png", 510, 550, 0.5, 0.5);

    components.Add(button1);
    components.Add(button2);
    components.Add(button3);
    components.Add(button4);

    buttonText1 = new Text(questions.Top().word, *button1->matrix.x + 20, *button1->matrix.y + 20, 1.0f, 1.0f, glm::vec2(0,0), "data/hiragana.png");
    buttonText2 = new Text(dictionary.words[random.RandomRange(0, dictionary.words.Size())], *button2->matrix.x + 20, *button2->matrix.y + 20, 1.0f, 1.0f, glm::vec2(0,0), "data/hiragana.png");
    buttonText3 = new Text(dictionary.words[random.RandomRange(0, dictionary.words.Size())], *button3->matrix.x + 20, *button3->matrix.y + 20, 1.0f, 1.0f, glm::vec2(0,0), "data/hiragana.png");
    buttonText4 = new Text(dictionary.words[random.RandomRange(0, dictionary.words.Size())], *button4->matrix.x + 20, *button4->matrix.y + 20, 1.0f, 1.0f, glm::vec2(0,0), "data/hiragana.png");

    components.Add(buttonText1);
    components.Add(buttonText2);
    components.Add(buttonText3);
    components.Add(buttonText4);

    components.Add(new MouseCursor());
}

void Quiz::Update()
{
    if (button1->IsPressed())
    {
        Application::LoadScene(Scenes::LevelSelectMenu);
    }
}

void Quiz::UpdateAfterPhysics()
{

}
