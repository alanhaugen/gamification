#ifndef LEVEL_H
#define LEVEL_H

#include <vector>
#include <core/x-platform/string.h>
#include <core/components/sprite.h>

class Level : public Component
{
private:
    Sprite* lvlImg;

    int lvlStatus;
    char findKana(std::string token);
public:
    std::vector<String> lvlKana;
    std::vector<String> wordList;

    int lvlSeed;
    void Update();
    void UpdateAfterPhysics();
    Level(int lvlNumber, float posX, float posY);
};

#endif // LEVEL_H
