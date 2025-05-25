#ifndef TETRIS_H
#define TETRIS_H

#include <core/x-platform/scene.h>
#include <core/components/actor.h>
#include "core/components/cube.h"
#include "japanesekana.h"
#include "pausemenu.h"

class LetterCube : public Cube
{
public:
    LetterCube(float x, float y, float z, Actor *parent);
    char kana;
    Cube* background;
    void Remove();
    bool active = true;
};

class Block : public Actor
{
private:
    // In tetris the shapes (tetrominos) consist of four cubes
    enum TETROMINOS
    {
        I,
        O,
        T,
        S,
        Z,
        J,
        L,
        RANDOM
    };

public:
    Block(int type = RANDOM);
    bool canRotate;
    glm::vec3 direction;

    void Rotate();
    void RotateBack();
    void Remove();
};

class Tetris : public IScene
{
private:
    const int GRID_LENGTH = 10;
    const int GRID_HEIGHT = 22;
    const float START_Y = -23.0f;
    const float CUBE_HEIGHT = 2.0f;
    const float EPSILON = 0.00001f;

    int score;
    int speed;
    bool paused;
    bool isRotated;
    ITime *timer;
    Block *activePiece;
    float gameTickTime;
    PauseMenu* Pause;

    Sprite* croco;
    Sprite* dicBg;
    Text* dicTitle;
    Text* dicWord;
    Text* dicTrans;
    Text* dicInstruction;

    bool newWord = false;

    std::vector<String> wordList;
    Array<Text*> words;

    Sprite* dictionaryButton;
    bool left;
    bool right;
    bool down;
    bool tap;
    bool justTapped = false;
    ITime* tapTimer;

    bool Approx(float a, float b);

    bool CheckForWords(bool reward = true);
    void MoveAllCubesDown();
    bool ProcessLetter(LetterCube* letter, bool reward);
    void RemoveLine(int numberOfLines = 1);
    LetterCube* GetLetter(float x, float y, bool onlyReturnVisible = true);

    bool IsNoWordsLeft();

public:
    Tetris();

    void Init();
    void Update(float dt);
    void UpdateAfterPhysics();
};

#endif
