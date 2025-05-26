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
    components.Add(new Sprite("data/art/new/quizbg.png", 0.0f, 0.0f, 1.0f, 1.0f));

    for (int i = 0; i < dictionary.words.Size(); i++)
    {
        Text* item = new Text(dictionary.words[i], 100, 200 + 50 * i, 1.0f, 1.0f, glm::vec2(0,0), "data/hiragana.png", 1.3f);
        Text* trans = new Text(dictionary.Translate(dictionary.words[i]), 200, 200 + 50, 1.0f, 1.0f);
        components.Add(item);
        dicItems.Add(item);
        lexemes.Add(trans);
    }

    backButton = new Sprite("data/art/backArrow.png", 40, 120, 0.2, 0.2);
    cursor = new MouseCursor();

    components.Add(backButton);
}

void DictionaryMenu::Update(float dt)
{
    cursor->Update();

    if (input.Released(input.Key.ESCAPE) || backButton->IsPressed())
    {
        Application::LoadScene(Scenes::StartMenu);
    }

    for (unsigned int i = 0; i < dicItems.Size(); i++)
    {
        if (dicItems[i]->IsPressed())
        {
            activeLexeme = lexemes[i];
        }
    }

    if (activeLexeme != nullptr)
    {
        activeLexeme->Update();
    }
}

void DictionaryMenu::UpdateAfterPhysics()
{
}

