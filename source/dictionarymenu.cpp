#include <core/application.h>
#include <core/components/sprite.h>
#include "dictionarymenu.h"
#include "main.h"

DictionaryMenu::DictionaryMenu()
{
}

void DictionaryMenu::Init()
{
    components.Add(new Sprite("data/quiz.png", 0.0f, 120.0f, 0.45f, 0.45f));
}

void DictionaryMenu::Update()
{
    if (input.Released(input.Key.ESCAPE))
    {
        Application::LoadScene(Scenes::StartMenu);
    }
}

void DictionaryMenu::UpdateAfterPhysics()
{
}

