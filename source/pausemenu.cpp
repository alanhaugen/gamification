#include "pausemenu.h"

void PauseMenu::Init()
{
    backGround = new Sprite("data/pause.png", renderer->windowWidth/2, renderer->windowHeight/2, 1, 1, glm::vec2(0.5, 0.5));
    isPaused = false;
}

void PauseMenu::Pause()
{
    isPaused = !isPaused;
}


void PauseMenu::Update()
{
    backGround->Update();
}

PauseMenu::PauseMenu()
{
    Init();
}

void PauseMenu::UpdateAfterPhysics()
{

}
