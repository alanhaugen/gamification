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

    dictionary.SortLexemes();

    for (int i = 0; i < 4; i++)
    {
        questions.Add(dictionary.lexemes[i]);
    }

    question = new Text(questions[arrayIndex].translation, 100, 270);

    button1 = new Sprite("data/art/button.png", 110, 400, 0.5, 0.5);
    button2 = new Sprite("data/art/button.png", 510, 400, 0.5, 0.5);
    button3 = new Sprite("data/art/button.png", 110, 550, 0.5, 0.5);
    button4 = new Sprite("data/art/button.png", 510, 550, 0.5, 0.5);

    components.Add(button1);
    components.Add(button2);
    components.Add(button3);
    components.Add(button4);

    buttonText1 = new Text(questions[arrayIndex].word, *button1->matrix.x + 20, *button1->matrix.y + 20, 1.0f, 1.0f, glm::vec2(0,0), "data/hiragana.png", 1.3f);
    buttonText2 = new Text(RandomWord(), *button2->matrix.x + 20, *button2->matrix.y + 20, 1.0f, 1.0f, glm::vec2(0,0), "data/hiragana.png", 1.3f);
    buttonText3 = new Text(RandomWord(), *button3->matrix.x + 20, *button3->matrix.y + 20, 1.0f, 1.0f, glm::vec2(0,0), "data/hiragana.png", 1.3f);
    buttonText4 = new Text(RandomWord(), *button4->matrix.x + 20, *button4->matrix.y + 20, 1.0f, 1.0f, glm::vec2(0,0), "data/hiragana.png", 1.3f);

    wrongSprite = new Sprite("data/art/lvlLock.png",420,420);
    correctSprite = new Sprite("data/art/lvlComplete.png",420,420);

    components.Add(new MouseCursor());
}

void Quiz::Update(float dt)
{
    if (playing)
    {
        if (button1->IsPressed() || button2->IsPressed() || button3->IsPressed() || button4->IsPressed())
        {
            if (button1->IsPressed())
            {
                questions[arrayIndex].IncreaseCompetence();
                correct = true;
            }
            else
            {
                correct = false;
            }

            arrayIndex++;
            playing = false;
        }
    }
    else
    {
        if (correct)
        {
            correctSprite->Update();
        }
        else
        {
            wrongSprite->Update();
        }

        if (input.Mouse.Pressed)
        {
            playing = true;

            if (arrayIndex == questions.Size())
            {
                Application::LoadScene(Scenes::LevelSelectMenu);
            }
            else
            {
                buttonText1 = new Text(questions[arrayIndex].word, *button1->matrix.x + 20, *button1->matrix.y + 20, 1.0f, 1.0f, glm::vec2(0,0), "data/hiragana.png", 1.3f);
                buttonText2 = new Text(RandomWord(), *button2->matrix.x + 20, *button2->matrix.y + 20, 1.0f, 1.0f, glm::vec2(0,0), "data/hiragana.png", 1.3f);
                buttonText3 = new Text(RandomWord(), *button3->matrix.x + 20, *button3->matrix.y + 20, 1.0f, 1.0f, glm::vec2(0,0), "data/hiragana.png", 1.3f);
                buttonText4 = new Text(RandomWord(), *button4->matrix.x + 20, *button4->matrix.y + 20, 1.0f, 1.0f, glm::vec2(0,0), "data/hiragana.png", 1.3f);
                question = new Text(questions[arrayIndex].translation, 100, 270);
            }
        }
    }

    buttonText1->Update();
    buttonText2->Update();
    buttonText3->Update();
    buttonText4->Update();
    question->Update();
}

void Quiz::UpdateAfterPhysics()
{

}

String Quiz::RandomWord()
{
    String word = questions[arrayIndex].word;

    while(word == questions[arrayIndex].word)
    {
        word = dictionary.words[random.RandomRange(0, dictionary.words.Size())];
    }

    return word;
}
