#include "intro.h"
#include <core/application.h>
#include <core/components/camera.h>
#include <core/components/background.h>
#include <core/components/cube.h>

Intro::Intro()
{
}

void Intro::Init()
{
    bubble = new Sprite("data/art/new/speech_bubble.png", 0, 0, 0.45, 0.45);
    bubbleScaled = new Sprite("data/art/new/speech_bubble.png", 0, 0, 0.75f, 0.0f);
    bubble->FlipHorizontal();
    croco = new Sprite("data/art/new/DrCroco_Chibi_Idle.png", 1000, 50);
    crocoTalk = new Sprite("data/art/new/DrCroco_Chibi_talking.png", 1000, 50);
    Camera* cam = new Camera();
    components.Add(cam);
    speech.Enqueue(new TextBlock("Welcome to CrocoBlocks!", "I am Professor Croco."));

    speech.Enqueue(new TextBlock("In my lab I have designed blocks", "that teach languages!"));
    speech.Enqueue(new TextBlock("Line them up, and make a word.", "The bricks can be moved left ..."));
    speech.Enqueue(new TextBlock("and right, and rotate.", "In this game you will learn ..."));
    speech.Enqueue(new TextBlock("many japanese words and the", "Japanese alphabets Hirigana ..."));
    speech.Enqueue(new TextBlock("and Katakana.", ""));
    speech.Enqueue(new TextBlock("To rotate a block, tap the screen.", "Swipe left and right to move blocks."));
    speech.Enqueue(new TextBlock("Before we begin, may I ask,", "Do you know any Japanese already?"));
    speech.Enqueue(new TextBlock("Since you are already knowledgable about", "the japanese kana, feel free ..."));
    speech.Enqueue(new TextBlock("to jump into a game through level select.", ""));

    components.Add(bubble);
    //components.Add(bubbleScaled);
    components.Add(new Background(glm::vec3(0.776470588235294, 0.870588235294118, 0.945098039215686), cam));

    startTime = Application::GetTime();

    bubble->Hide();

    t = 0.0;
    i = 0;
    j = 0;
}

void Intro::Update(float dt)
{
    if (speech.Empty())
    {
        Application::NextScene();
    }

    if (startTime->TimeSinceStarted() > 750.0f)
    {
        bubbleScaled->Hide();
        bubble->Show();

        i += 0.1;
        j += 0.1;

        if (speech.Empty() == false)
        {
            speech.Front()->Update();
        }
    }
    if (*croco->matrix.x > 70)
    {
        *croco->matrix.x = 100 - (70 * t);
        t += startTime->TimeSinceStarted() / 200000;
    }
    else
    {
        *croco->matrix.x = 70;
    }

    if (input.Released(input.Key.R))
    {
        *croco->matrix.x = 10000;
        startTime->Reset();
        t = 0.0f;
    }

    if (input.Pressed(input.Key.SPACE) || input.Mouse.Pressed)
    {
        speech.Dequeue();
        count++;
        j = 0.0f;
        i = 0.0f;
    }

    if (count >= 5)
    {
        //*croco->matrix.x = 100;
    }

    if (j < 10)
    {
        if (i < 1.0f)
        {
            croco->Update();
        }
        else
        {
            crocoTalk->Update();

            if (i > 2)
            {
                i = 0.0f;
            }
        }
    }
    else
    {
        croco->Update();
    }

    *crocoTalk->matrix.x = *croco->matrix.x;
    *crocoTalk->matrix.y = *croco->matrix.y;
}

void Intro::UpdateAfterPhysics()
{
}

