#ifndef LEVEL_H
#define LEVEL_H

#include <vector>
#include <string>
#include <core/x-platform/string.h>
#include <core/components/sprite.h>

class Level : public Component
{
private:
    Sprite* lvlImg;
    Sprite* lvlImgDone;
    Sprite* lvlImgLocked;
    char findKana(std::string token);
public:
    enum
    {
        LOCKED = 0,
        INCOMPLETE = 1,
        DONE
    };

    int lvlStatus;
    std::vector<String> lvlKana;
    std::vector<String> wordList;

    int lvlSeed;
    void Update();
    void UpdateAfterPhysics();
    Level(int lvlNumber, float posX, float posY);
};

#endif // LEVEL_H
