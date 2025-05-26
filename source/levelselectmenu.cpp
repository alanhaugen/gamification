#include <core/application.h>
#include "levelselectmenu.h"
#include "tetris.h"
#include "main.h"

extern Level* currentLevel;

LevelSelectMenu::LevelSelectMenu()
{
    background = new Sprite("data/art/new/bg.png", 0, 0, 1.3, 1.3);
    backButton = new Sprite("data/art/backArrow.png", 40, 120, 0.2, 0.2);
    level1 = new Level(1, renderer->windowWidth/2 - 150, renderer->windowHeight/2 - 64);

    level1->lvlSeed = 89;
    level1->lvlKana.push_back(std::string(1, Kana::mo).c_str());
    level1->lvlKana.push_back(std::string(1, Kana::no).c_str());
    level1->lvlKana.push_back(std::string(1, Kana::ko).c_str());
    level1->lvlKana.push_back(std::string(1, Kana::ka).c_str());
    level1->lvlKana.push_back(std::string(1, Kana::sa).c_str());
    level1->lvlStatus = Level::INCOMPLETE;

    level1->wordList.push_back((std::string(1, Kana::mo)+std::string(1, Kana::no)).c_str());
    level1->wordList.push_back((std::string(1, Kana::ko)+std::string(1, Kana::ko)).c_str());
    level1->wordList.push_back((std::string(1, Kana::ka)+std::string(1, Kana::sa)).c_str());
    level1->wordList.push_back((std::string(1, Kana::mo)+std::string(1, Kana::mo)).c_str());

    level2 = new Level(99, renderer->windowWidth/2, renderer->windowHeight/2 - 64);

    level2->lvlSeed = 89;
    level2->lvlKana.push_back(std::string(1, Kana::a).c_str());
    level2->lvlKana.push_back(std::string(1, Kana::i).c_str());
    level2->lvlKana.push_back(std::string(1, Kana::u).c_str());
    level2->lvlKana.push_back(std::string(1, Kana::e).c_str());
    level2->lvlKana.push_back(std::string(1, Kana::o).c_str());
    level2->lvlKana.push_back(std::string(1, Kana::ki).c_str());
    level2->lvlKana.push_back(std::string(1, Kana::ka).c_str());
    level2->lvlStatus = Level::INCOMPLETE;

    level2->wordList.push_back((std::string(1, Kana::a)+std::string(1, Kana::i)).c_str());
    level2->wordList.push_back((std::string(1, Kana::e)+std::string(1, Kana::ki)).c_str());
    level2->wordList.push_back((std::string(1, Kana::i)+std::string(1, Kana::e)).c_str());
    level2->wordList.push_back((std::string(1, Kana::u)+std::string(1, Kana::e)).c_str());
    level2->wordList.push_back((std::string(1, Kana::ka)+std::string(1, Kana::o)).c_str());
}

void LevelSelectMenu::Init()
{
    cursor = new MouseCursor();

    components.Add(backButton);
    components.Add(cursor);
    components.Add(background);
}

void LevelSelectMenu::Update(float dt)
{
    cursor->Update();
    level1->Update();
    level2->Update();

    if (backButton->IsPressed())
    {
        Application::LoadScene(Scenes::StartMenu);
    }

    if (input.Held(input.Key.R))
    {
        Application::LoadScene(Scenes::Intro);
    }
}

void LevelSelectMenu::UpdateAfterPhysics()
{
}

