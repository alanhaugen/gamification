#include <core/application.h>
#include "startmenu.h"
#include "main.h"

StartMenu::StartMenu()
{
}

void StartMenu::Init()
{
    cam = new Camera();

    background = new Sprite("data/art/bg.png", 0, 0, 0.39, 0.39);

    logo = new Sprite("data/art/logo.png", 20, 120);

    playTetrisButton = new Sprite("data/art/playTetrisButton.png", 20, 280);
    dictionaryButton = new Sprite("data/art/dictionaryButton.png", 20, 380);
    settingsButton = new Sprite("data/art/settingsButton.png", 20, 480);

    iphone = new Sprite("data/iphone.png", 0, 0, 0.75, 0.75);
    cursor = new Sprite("data/art/BlackCursor.png", 0, 0);

    components.Add(playTetrisButton);
    components.Add(dictionaryButton);
    components.Add(settingsButton);
    components.Add(background);
    components.Add(logo);
    components.Add(iphone);
    components.Add(cursor);
}

void StartMenu::Update()
{
    *cursor->matrix.x = input.Mouse.x;
    *cursor->matrix.y = input.Mouse.y;

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
