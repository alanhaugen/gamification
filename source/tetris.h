#ifndef Tetris_H
#define Tetris_H

#include <core/x-platform/scene.h>
#include <core/components/actor.h>
#include "pausemenu.h"

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
};


class Tetris : public IScene
{
private:
    int score;
    int speed;
    bool paused;
    bool isRotated;
    ITime *timer;
    Block *activePiece;
    float gameTickTime;
    PauseMenu* Pause;

    void CheckScore();

public:
    Tetris();

    void Init();
    void Update();
    void UpdateAfterPhysics();
};

#endif
