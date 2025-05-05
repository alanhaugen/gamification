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
    bubble = new Sprite("data/art/speechbubble.png", 0, 0, 0.75);
    bubbleScaled = new Sprite("data/art/speechbubblescaling.png", 0, 0, 0.75f, 0.0f);
    bubble->FlipHorizontal();
    croco = new Sprite("data/art/new/chib.png", 1000, 50);
    Camera* cam = new Camera();
    components.Add(cam);

    speech.Enqueue(new Text("Welcome to LexiBlocks!", 100, 150, 0.5, 0.5));
    speech.Enqueue(new Text("I am Professor Croco.", 100, 200, 0.5, 0.5));
    speech.Enqueue(new Text("In my lab I have designed blocks", 100, 200, 0.5, 0.5));
    speech.Enqueue(new Text("that teach languages!", 100, 200, 0.5, 0.5));
    speech.Enqueue(new Text("Line them up, and make a word.", 100, 200, 0.5, 0.5));
    speech.Enqueue(new Text("The bricks can be moved left", 100, 200, 0.5, 0.5));
    speech.Enqueue(new Text("and right, and rotate.", 100, 200, 0.5, 0.5));
    speech.Enqueue(new Text("In this game you will learn", 100, 200, 0.5, 0.5));
    speech.Enqueue(new Text("150 japanese words and the", 100, 200, 0.5, 0.5));
    speech.Enqueue(new Text("Japanese alphabets Hirigana", 100, 200, 0.5, 0.5));
    speech.Enqueue(new Text("and Katakana.", 100, 200, 0.5, 0.5));
    speech.Enqueue(new Text("Before we begin, may I ask,", 100, 200, 0.5, 0.5));
    speech.Enqueue(new Text("Do you know any Japanese already?", 100, 200, 0.5, 0.5));
    speech.Enqueue(new Text("Since you are already knowledgable", 100, 200, 0.5, 0.5));
    speech.Enqueue(new Text("about the japanese kana", 100, 200, 0.5, 0.5));
    speech.Enqueue(new Text("Feel free to jump into a game through level select", 100, 200, 0.5, 0.5));
    //components.Add(new Text("Welcome to LexiBlocks!", 100, 150, 0.5, 0.5));
    //components.Add(new Text("I am Professor Croco.", 100, 200, 0.5, 0.5));
    //components.Add(new Background(glm::vec3(0.972549019607843f, 0.929411764705882f, 0.92156862745098f), cam));
    components.Add(croco);
    //components.Add(bubble);
    //components.Add(bubbleScaled);
    components.Add(new Background(glm::vec3(0.776470588235294, 0.870588235294118, 0.945098039215686), cam));

    startTime = Application::GetTime();

    bubble->Hide();

    t = 0.0;
    i = 0;
}

void Intro::Update()
{
    if (speech.Empty())
    {
        Application::NextScene();
    }
    else
    {
        speech.Front()->Update();
    }

    if (bubbleScaled->scaleY < 1.0f)
    {
        bubbleScaled->scaleY += 0.05;
    }
    else
    {
        bubbleScaled->Hide();
        bubble->Show();
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
    }

    i += 0.1;
}

void Intro::UpdateAfterPhysics()
{
}

