#include <core/application.h>
#include "startmenu.h"
#include "main.h"

StartMenu::StartMenu()
{
}

void StartMenu::Init()
{
    cam = new Camera();

    background = new Sprite("data/art/new/bg.png", 0, 0, 1.3, 1.3);

    playTetrisButton = new Sprite("data/art/playTetrisButton.png", (renderer->windowWidth / 2) - 200, 360, 0.5, 0.5);
    dictionaryButton = new Sprite("data/art/dictionaryButton.png", (renderer->windowWidth / 2) - 200, 500, 0.5, 0.5);
    settingsButton = new Sprite("data/art/settingsButton.png",     (renderer->windowWidth / 2) - 200, 640, 0.5, 0.5);

    logo = new Sprite("data/art/new/LB_Logo_outline.png", (renderer->windowWidth / 2) - 300, 40, 0.2, 0.2);

    cursor = new MouseCursor();

    components.Add(playTetrisButton);
    components.Add(dictionaryButton);
    //components.Add(settingsButton);
    components.Add(background);
    components.Add(logo);
    components.Add(cursor);
}

void StartMenu::Update(float dt)
{
    cursor->Update();

    if (playTetrisButton->IsPressed())
    {
        Application::LoadScene(Scenes::LevelSelectMenu);
    }

    if (dictionaryButton->IsPressed())
    {
        Application::LoadScene(Scenes::DictionaryMenu);
    }

    if (input.Held(input.Key.R))
    {
        Application::LoadScene(Scenes::Intro);
    }

    /*if (settingsButton->IsPressed())
    {
        Application::LoadScene(Scenes::SettingsMenu);
    }*/
}

void StartMenu::UpdateAfterPhysics()
{
}
