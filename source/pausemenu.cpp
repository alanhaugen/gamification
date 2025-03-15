#include "pausemenu.h"
#include "main.h"

void PauseMenu::Init()
{
    backGround = new Sprite("data/pause.png", renderer->windowWidth/2, renderer->windowHeight/2, 1, 1, glm::vec2(0.5, 0.5));
    buttonDictionary = new Sprite(
        "data/art/dictionary.png",
        renderer->windowWidth/2 - backGround->width/2,
        renderer->windowHeight/2 - backGround->height/2,
        0.25, 0.25
        );
    cursor = new MouseCursor();

    isPaused = false;
}

void PauseMenu::Pause()
{
    isPaused = !isPaused;
}


void PauseMenu::Update()
{
    cursor->Update();
    backGround->Update();
    buttonDictionary->Update();
    if(buttonDictionary->IsPressed())
    {
        Application::LoadScene(Scenes::DictionaryMenu);
    }

}

PauseMenu::PauseMenu()
{
    Init();
}

void PauseMenu::UpdateAfterPhysics()
{

}
