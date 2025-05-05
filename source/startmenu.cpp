#include <core/application.h>
#include "startmenu.h"
#include "main.h"

StartMenu::StartMenu()
{
}

void StartMenu::Init()
{
    cam = new Camera();

    background = new Sprite("data/art/new/bg.png", -100, -100, 0.7, 0.7);

    playTetrisButton = new Sprite("data/art/playTetrisButton.png", 350-25, 360, 0.5, 0.5);
    dictionaryButton = new Sprite("data/art/dictionaryButton.png", 350-15, 500, 0.5, 0.5);
    settingsButton = new Sprite("data/art/settingsButton.png",     350+15, 640, 0.5, 0.5);

    //iphone = new Sprite("data/iphone.png", 0, 0, 0.75, 0.75);

    logo = new Sprite("data/art/new/logo.png", 200, 20, 0.2, 0.2);

    cursor = new MouseCursor();

    components.Add(playTetrisButton);
    components.Add(dictionaryButton);
    components.Add(settingsButton);
    components.Add(background);
    components.Add(logo);
    //components.Add(iphone);
    components.Add(cursor);
}

void StartMenu::Update()
{
    cursor->Update();
    if (playTetrisButton->IsPressed())
    {
        Application::LoadScene(Scenes::PlayTetrisMenu);
    }

    if (dictionaryButton->IsPressed())
    {
        Application::LoadScene(Scenes::DictionaryMenu);
    }

    if (settingsButton->IsPressed())
    {
        Application::LoadScene(Scenes::SettingsMenu);
    }
}

void StartMenu::UpdateAfterPhysics()
{
}
