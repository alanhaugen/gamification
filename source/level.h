#ifndef LEVEL_H
#define LEVEL_H

#include <vector>
#include <core/x-platform/string.h>
#include <core/components/sprite.h>

class Level : public Component
{
private:
    std::vector<String> lvlKana;

    Sprite* lvlImg;

    int lvlSeed;
    int lvlStatus;
    char findKana(std::string token);
public:
    std::vector<String> wordList;

    void Update();
    void UpdateAfterPhysics();
    Level(int lvlNumber, float posX, float posY);
};

#endif // LEVEL_H
