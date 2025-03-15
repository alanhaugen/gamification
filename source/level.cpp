#include "level.h"
#include <fstream>
#include <string>

void Level::Update()
{
    if(lvlStatus == 0)
    {
        lvlLockedImg->Update();
    }
    else if(lvlStatus == 1)
    {
        lvlIncompleteImg->Update();

        if(lvlIncompleteImg->IsPressed())
        {

        }
    }
    else
    {
        lvlCompleteImg->Update();

        if(lvlCompleteImg->IsPressed())
        {

        }
    }
}

void Level::UpdateAfterPhysics()
{

}

Level::Level(int lvlNumber)
{
    std::ifstream lvlFile(std::to_string(lvlNumber) + ".txt");
    std::string line;

    if(lvlFile.is_open())
    {

    }
}
