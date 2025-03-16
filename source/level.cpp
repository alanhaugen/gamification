#include "level.h"
#include <fstream>
#include <string>
#include <core/application.h>
#include "main.h"

void Level::Update()
{
    lvlImg->Update();
    if(lvlImg->IsPressed() && lvlStatus != 0)
    {
        Application::LoadScene(Scenes::Tetris);
    }
}

void Level::UpdateAfterPhysics()
{

}

Level::Level(int lvlNumber, float posX, float posY)
{
    std::ifstream lvlFile("data/levels/" + std::to_string(lvlNumber) + ".txt");
    std::string line;

    if(lvlFile.is_open())
    {
        std::getline(lvlFile, line);
        lvlStatus = stoi(line);
    }

    if(lvlStatus == 0)
    {
        lvlImg = new Sprite("data/art/lvlLock.png", posX, posY);
    }
    else if(lvlStatus == 1)
    {
        lvlImg = new Sprite("data/art/lvlIncomplete.png", posX, posY);
    }
    else
    {
        lvlImg = new Sprite("data/art/lvlComplete.png", posX, posY);
    }

}
