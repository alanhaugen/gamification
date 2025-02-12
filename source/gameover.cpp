#include <core/components/camera.h>
#include <core/components/text.h>
#include <core/application.h>
#include "gameover.h"

extern int highscore;

GameOver::GameOver()
{
}

void GameOver::Init()
{
    components.Add(new Camera());
    components.Add(new Text("GAME OVER", 200, 300));
    components.Add(new Text("HIGHSCORE: " + String(highscore), 200, 400));
    components.Add(new Text("PRESS SPACE TO CONTINUE", 200, 500));
}

void GameOver::Update()
{
    if (input.Pressed(input.Key.SPACE))
    {
        Application::LoadScene(0);
    }
}

void GameOver::UpdateAfterPhysics()
{
}

