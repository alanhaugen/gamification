#ifndef BLOCK_H
#define BLOCK_H

#include <core/components/actor.h>
#include <core/components/cube.h>

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


#endif // BLOCK_H
