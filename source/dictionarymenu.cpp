#include <core/application.h>
#include <core/components/sprite.h>
#include "dictionarymenu.h"
#include "main.h"
#include "dictionary.h"

extern Dictionary dictionary;

DictionaryMenu::DictionaryMenu()
{
}

void DictionaryMenu::Init()
{
    components.Add(new Sprite("data/art/new/quizbg.png", 0.0f, 0.0f, 0.58f, 0.5f));

    for (int i = 0; i < dictionary.words.Size(); i++)
    {
        components.Add(new Text(dictionary.words[i], 100, 100 + 50 * i, 1.0f, 1.0f, glm::vec2(0,0), "data/hiragana.png"));
    }

    backButton = new Sprite("data/art/backArrow.png", 40, 120, 0.5, 0.5);
    cursor = new MouseCursor();

    components.Add(backButton);
}

void DictionaryMenu::Update()
{
    cursor->Update();

    if (input.Released(input.Key.ESCAPE) || backButton->IsPressed())
    {
        Application::LoadScene(Scenes::StartMenu);
    }
}

void DictionaryMenu::UpdateAfterPhysics()
{
}

