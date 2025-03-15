#ifndef LEVEL_H
#define LEVEL_H

#include <vector>
#include <core/x-platform/string.h>
#include <core/components/sprite.h>

class Level : public Component
{
private:
    std::vector<String> wordList;

    String lvlHiragana;

    Sprite* lvlCompleteImg;
    Sprite* lvlLockedImg;
    Sprite* lvlIncompleteImg;

    int lvlSeed;
    int lvlStatus;
public:
    void Update();
    void UpdateAfterPhysics();
    Level(int lvlNumber);
};

#endif // LEVEL_H
