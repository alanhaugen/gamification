#include <core/application.h>
#include "startmenu.h"
#include "main.h"

StartMenu::StartMenu()
{
}

void StartMenu::Init()
{
    cam = new Camera();

    background = new Sprite("data/art/new/bg.png", 0, 0, 1.0, 1.0);

    playTetrisButton = new Sprite("data/art/playTetrisButton.png", 350-25, 360, 0.5, 0.5);
    dictionaryButton = new Sprite("data/art/dictionaryButton.png", 350-15, 500, 0.5, 0.5);
    settingsButton = new Sprite("data/art/settingsButton.png",     350+15, 640, 0.5, 0.5);

    logo = new Sprite("data/art/new/LB_Logo_outline.png", 200, 40, 0.2, 0.2);

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

    /*if (settingsButton->IsPressed())
    {
        Application::LoadScene(Scenes::SettingsMenu);
    }*/
}

void StartMenu::UpdateAfterPhysics()
{
}
