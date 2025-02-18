#include <core/application.h>
#include "settingsmenu.h"
#include "main.h"

SettingsMenu::SettingsMenu()
{
}

void SettingsMenu::Init()
{
}

void SettingsMenu::Update()
{
    if (input.Released(input.Key.ESCAPE))
    {
        Application::LoadScene(Scenes::StartMenu);
    }
}

void SettingsMenu::UpdateAfterPhysics()
{
}

