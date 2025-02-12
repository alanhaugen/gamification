#include "tetris.h"
#include <core/application.h>
#include <core/components/cube.h>
#include <core/components/camera.h>

extern int highscore;

Block::Block(int type)
{
    const int NUMBER_OF_TETROMINOS = 7;

    if (type == RANDOM)
    {
        type = random.RandomRange(0, NUMBER_OF_TETROMINOS);
    }

    canRotate = true;
    tag = "block";

    if (type == I)
    {
        Uniform("colour", glm::vec4(1.0f, 0.0f, 1.0f, 1.0f));

        Add(new Cube(0,0,0));
        Add(new Cube(0,1*2,0));
        Add(new Cube(0,2*2,0));
        Add(new Cube(0,3*2,0));
    }
    else if (type == O)
    {
        Uniform("colour", glm::vec4(0.0f, 1.0f, 0.0f, 1.0f));

        Add(new Cube(0,0,0));
        Add(new Cube(0,1*2,0));
        Add(new Cube(1*2,1*2,0));
        Add(new Cube(1*2,0,0));

        canRotate = false;
    }
    else if (type == T)
    {
        Uniform("colour", glm::vec4(0.0f, 0.0f, 1.0f, 1.0f));

        Add(new Cube(0,0,0));
        Add(new Cube(1*2,0,0));
        Add(new Cube(-1*2,0,0));
        Add(new Cube(0,1*2,0));
    }
    else if (type == S)
    {
        Uniform("colour", glm::vec4(1.0f, 0.5f, 0.5f, 1.0f));

        Add(new Cube(0,0,0));
        Add(new Cube(1*2,0,0));
        Add(new Cube(0,1*2,0));
        Add(new Cube(-1*2,1*2,0));
    }
    else if (type == Z)
    {
        Uniform("colour", glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));

        Add(new Cube(0,0,0));
        Add(new Cube(-1*2,0,0));
        Add(new Cube(0,1*2,0));
        Add(new Cube(1*2,1*2,0));
    }
    else if (type == J)
    {
        Uniform("colour", glm::vec4(0.0f, 1.0f, 1.0f, 1.0f));

        Add(new Cube(0,0,0));
        Add(new Cube(0,1*2,0));
        Add(new Cube(0,2*2,0));
        Add(new Cube(-1*2,2*2,0));
    }
    else if (type == L)
    {
        Uniform("colour", glm::vec4(1.0f, 1.0f, 0.0f, 1.0f));

        Add(new Cube(0,0,0));
        Add(new Cube(0,1*2,0));
        Add(new Cube(0,2*2,0));
        Add(new Cube(1*2,2*2,0));
    }

    matrix.Translate(glm::vec3(0, 15, -45));
}


Tetris::Tetris()
{
}

void Tetris::Init()
{
    score = 0;
    speed = 1;
    paused = false;
    timer = Application::GetTime();
    gameTickTime = 500.0f;

    activePiece = new Block();

    components.Add(new Camera());
    components.Add(activePiece);

    // Grid around board code follows
    int i;

    // bottom (10 block)
    for (i = 0; i < 10; i++)
    {
        components.Add(new Cube(i*2  - 10,-35 + 10,-45));
    }

    // side left (22 blocks)
    for (i = 0; i < 22; i++)
    {
        components.Add(new Cube( -12,-35 + 10 + i*2,-45));
    }

    // side right (22 blocks)
    for (i = 0; i < 22; i++)
    {
        components.Add(new Cube(10,-35 + 10 + i*2,-45));
    }
}

void Tetris::Update()
{
    activePiece->direction = glm::vec3();
    isRotated = false;

    if (input.Pressed(input.Key.LEFT))
    {
        activePiece->direction.x = -2.0f;
    }
    else if (input.Pressed(input.Key.RIGHT))
    {
        activePiece->direction.x = 2.0f;
    }
    else if (input.Pressed(input.Key.UP) && activePiece->canRotate)
    {
        activePiece->matrix.Rotate(glm::half_pi<float>(), glm::vec3(0.0f, 0.0f, 1.0f));
        isRotated = true;
    }
    if (input.Pressed(input.Key.SPACE))
    {
        // Go to bottom
    }
    else if (timer->TimeSinceStarted() > gameTickTime / speed || input.Pressed(input.Key.DOWN))
    {
        timer->Reset();
        activePiece->direction.x = 0.0f;
        activePiece->direction.y = -2.0f;
    }

    activePiece->matrix.Translate(activePiece->direction);
}

void Tetris::UpdateAfterPhysics()
{
    if (physics->Collide())
    {
        // GameOver
        if (activePiece->matrix.position.y - activePiece->direction.y == 15.0f)
        {
            Application::NextScene();
            return;
        }

        // Rotate back
        if (isRotated)
        {
            activePiece->matrix.Rotate(-3.14159/2, glm::vec3(0.0f, 0.0f, 1.0f));
            activePiece->Update();
        }
        // Make new brick
        else if (activePiece->direction.y < 0.0f)
        {
            activePiece->matrix.Translate(-activePiece->direction);
            activePiece->Update();

            CheckScore();

            activePiece = new Block();
            components.Add(activePiece);
        }
        // Move back out of collision
        else
        {
            activePiece->matrix.Translate(-activePiece->direction);
            activePiece->Update();
        }
    }
}

void Tetris::CheckScore()
{
    const int LINE_LENGTH = 10;
    const int GRID_HEIGHT = 22;
    const float START_Y = -23.0f;
    const float CUBE_HEIGHT = 2.0f;

    int multiplier = 1;

    // Check if cubes are making a solid line in the grid
    for (unsigned int k = 0; k < GRID_HEIGHT; k++)
    {
        bool deleteRow = false;
        int line = 0;

        for (unsigned int i = 0; i < components.Size(); i++)
        {
            Component *component = (*components[i]);

            if (component->tag == "block")
            {
                Block *block = static_cast<Block*>(component);

                for (unsigned int j = 0; j < block->components.Size(); j++)
                {
                    Component *cube = *block->components[j];

                    if (cube->matrix.position.y == START_Y + (k * CUBE_HEIGHT))
                    {
                        if (deleteRow)
                        {
                            block->components.RemoveAt(j);
                            j = -1; // Revert search back to start...
                            score = score + (1 * multiplier); // Update score

                            if (score > highscore)
                            {
                                highscore = score;
                            }
                        }
                        else
                        {
                            line++;
                        }
                    }

                    if (line == LINE_LENGTH)
                    {
                        Log("DELETE ROW: " + String(line * multiplier));

                        deleteRow = true;
                        line = 0; // To prevent an infinite loop...
                        i = -1; // Rewind and start deleting the row
                    }
                }
            }
        }

        if (deleteRow == true)
        {
            multiplier++;
        }
    }
}
