#include <core/components/camera.h>
#include <core/components/text.h>
#include <core/application.h>
#include "gameover.h"
#include "main.h"

extern int highscore;

GameOver::GameOver()
{
}

void GameOver::Init()
{
    components.Add(new Camera());
    components.Add(new Sprite("data/art/new/bg2.png", 0, 0, 1.0, 1.0));
    components.Add(new Text("GAME OVER", 200, 300));
    components.Add(new Text("Play Quiz", 200, 400));
    components.Add(new Text("Level Select", 200, 550));
}

void GameOver::Update()
{
    if (input.Pressed(input.Key.SPACE))
    {
        Application::LoadScene(Scenes::StartMenu);
    }
}

void GameOver::UpdateAfterPhysics()
{
}

