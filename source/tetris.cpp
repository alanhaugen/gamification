#include "tetris.h"
#include <core/application.h>
#include <core/components/cube.h>
#include <core/components/camera.h>
#include "main.h"

extern int highscore;
extern Level* currentLevel;

LetterCube::LetterCube(float x, float y, float z, Actor* parent)
    : Cube(x, y, z, 1, 0, 1, "data/hiragana.png", true, glm::vec4(1.0f, 1.0f, 1.0f, 1.0f), "data/block.vert", "data/block.frag")
{
    background = new Cube(x,y,-0.01, 1, 0, 1, "data/block.png", false);
    parent->Add(background);

    if(currentLevel != nullptr)
    {
        int rnd;
        rnd = random.RandomRange(0, currentLevel->lvlKana.size());
        kana = currentLevel->lvlKana[rnd][0];

    }
    else
    {
        kana = random.RandomRange(0, Kana::NumberOfKana);

    }

    Uniform("index", static_cast<int>(kana) - 32);
}

void LetterCube::Remove()
{
    background->Hide();
    Hide();
    collisionBox->active = false;
}

void Block::Rotate()
{
    matrix.Rotate(glm::half_pi<float>(), glm::vec3(0.0f, 0.0f, 1.0f));

    for (unsigned int i = 0; i < components.Size(); i++)
    {
        Cube* cube = dynamic_cast<Cube*>(*components[i]);
        cube->matrix.Rotate(glm::half_pi<float>(), glm::vec3(0.0f, 0.0f, -1.0f));
    }
}

void Block::RotateBack()
{
    matrix.Rotate(glm::half_pi<float>(), glm::vec3(0.0f, 0.0f, -1.0f));

    for (unsigned int i = 0; i < components.Size(); i++)
    {
        Cube* cube = dynamic_cast<Cube*>(*components[i]);
        cube->matrix.Rotate(glm::half_pi<float>(), glm::vec3(0.0f, 0.0f, 1.0f));
    }
}

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
        colour = glm::vec4(1.0f, 0.0f, 1.0f, 1.0f);

        Add(new LetterCube(0,-1*2,0, this));
        Add(new LetterCube(0,0*2,0, this));
        Add(new LetterCube(0,1*2,0, this));
        Add(new LetterCube(0,2*2,0, this));
    }
    else if (type == O)
    {
        colour = glm::vec4(0.0f, 1.0f, 0.0f, 1.0f);

        Add(new LetterCube(0,0,0, this));
        Add(new LetterCube(0,1*2,0, this));
        Add(new LetterCube(1*2,1*2,0, this));
        Add(new LetterCube(1*2,0,0, this));

        //canRotate = false;
    }
    else if (type == T)
    {
        colour = glm::vec4(0.0f, 0.0f, 1.0f, 1.0f);

        Add(new LetterCube(0,0,0, this));
        Add(new LetterCube(1*2,0,0, this));
        Add(new LetterCube(-1*2,0,0, this));
        Add(new LetterCube(0,1*2,0, this));
    }
    else if (type == S)
    {
        colour = glm::vec4(1.0f, 0.5f, 0.5f, 1.0f);

        Add(new LetterCube(0,0,0, this));
        Add(new LetterCube(1*2,0,0, this));
        Add(new LetterCube(0,1*2,0, this));
        Add(new LetterCube(-1*2,1*2,0, this));
    }
    else if (type == Z)
    {
        colour = glm::vec4(0.8f, 0.2f, 0.1f, 1.0f);

        Add(new LetterCube(0,0,0, this));
        Add(new LetterCube(-1*2,0,0, this));
        Add(new LetterCube(0,1*2,0, this));
        Add(new LetterCube(1*2,1*2,0, this));
    }
    else if (type == J)
    {
        colour = glm::vec4(0.0f, 1.0f, 1.0f, 1.0f);

        Add(new LetterCube(0,-1*2,0, this));
        Add(new LetterCube(0,0*2,0, this));
        Add(new LetterCube(0,1*2,0, this));
        Add(new LetterCube(-1*2,1*2,0, this));
    }
    else if (type == L)
    {
        colour = glm::vec4(1.0f, 1.0f, 0.0f, 1.0f);

        Add(new LetterCube(0,-1*2,0, this));
        Add(new LetterCube(0,0*2,0, this));
        Add(new LetterCube(0,1*2,0, this));
        Add(new LetterCube(1*2,1*2,0, this));
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

    Pause = new PauseMenu();

    components.Add(new Camera());
    components.Add(activePiece);

    if (currentLevel != nullptr)
    {
        wordList = currentLevel->wordList;
    }

    for (unsigned int i = 0; i < wordList.size(); i++)
    {
        components.Add(new Text(wordList[i], 50, 50 + 50 * i, 1.0f, 1.0f, glm::vec2(0,0), "data/hiragana.png"));
    }

    // Grid around board code follows

    // bottom (10 block)
    for (int i = 0; i < GRID_LENGTH; i++)
    {
        Cube* cube = new Cube(i*2  - 10,-35 + 10,-45);
        cube->tag = "wall";
        components.Add(cube);
    }

    // side left (22 blocks)
    for (int i = 0; i < GRID_HEIGHT; i++)
    {
        Cube* cube = new Cube( -12,-35 + 10 + i*2,-45);
        cube->tag = "wall";
        components.Add(cube);
    }

    // side right (22 blocks)
    for (int i = 0; i < GRID_HEIGHT; i++)
    {
        Cube* cube = new Cube(10,-35 + 10 + i*2,-45);
        cube->tag = "wall";
        components.Add(cube);
    }
}

void Tetris::Update()
{
    if(input.Pressed(input.Key.P))
    {
        Pause->Pause();
        timer->Pause();
    }

    if(Pause->isPaused)
    {
        Pause->Update();
        return;
    }

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
        activePiece->Rotate();
        isRotated = true;
    }
    if (input.Pressed(input.Key.SPACE))
    {
        // Go to bottom
        while(true)
        {
            activePiece->direction.x = 0.0f;
            activePiece->direction.y = -2.0f;
            activePiece->matrix.Translate(activePiece->direction);
            activePiece->Update();
            physics->Update();

            if(physics->Collide())
            {
                activePiece->matrix.Translate(-activePiece->direction);
                activePiece->Update();
                break;
            }
        }
    }
    else if (timer->TimeSinceStarted() > gameTickTime / speed || input.Pressed(input.Key.DOWN))
    {
        timer->Reset();
        activePiece->direction.x = 0.0f;
        activePiece->direction.y = -2.0f;
    }

    activePiece->matrix.Translate(activePiece->direction);

    if (input.Released(input.Key.ESCAPE))
    {
        Application::LoadScene(Scenes::StartMenu);
    }
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
            activePiece->RotateBack();
            activePiece->Update();
        }
        // Make new brick
        else if (activePiece->direction.y < 0.0f)
        {
            activePiece->matrix.Translate(-activePiece->direction);
            activePiece->Update();

            CheckForWords();

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

void Tetris::CheckForWords()
{
    //int multiplier = 1;

    // In the scene we have the blocks, the blocks has have our letter cubes
    for (unsigned int i = 0; i < components.Size(); i++)
    {
        // The block will have our letters
        Block* block = dynamic_cast<Block*>(*components[i]);

        if (block == nullptr)
        {
            continue;
        }

        for (unsigned int i = 0; i < block->components.Size(); i++)
        {
            // Here's a letter cube
            LetterCube* letter = dynamic_cast<LetterCube*>(*block->components[i]);

            if (letter == nullptr)
            {
                continue;
            }

            ProcessLetter(letter);
        }
    }
}

void Tetris::MoveAllCubesDown()
{
    // The Scene has Blocks in components. The blocks components also, with the actual cubes
    for (unsigned int i = 0; i < components.Size(); i++)
    {
        // We will move the blocks, the cubes will follow
        Block* block = dynamic_cast<Block*>(*components[i]);

        if (block == nullptr)
        {
            continue;
        }

        *block->matrix.y -= CUBE_HEIGHT;
    }
}

void Tetris::ProcessLetter(LetterCube *letter)
{
    Array<LetterCube*> cubes;

    cubes.Add(letter);

    if (letter->kana != wordList[currentWordIndex][0])
    {
        return;
    }

    // Check south (words going downwards)
    /*for (int i = 1; i < GRID_HEIGHT; i++)
    {
        LetterCube* bottomLetter = GetLetter(letter->pos.x, letter->pos.y + i);

        if (bottomLetter == nullptr)
        {
            break;
        }

        if (letter->kana == wordList[currentWordIndex][i])
        {
            cubes.Add(letter);
        }
        else
        {
            break;
        }
    }

    if (cubes.Size() == wordList[currentWordIndex].Length())
    {
        for (unsigned int i = 0; i < cubes.Size(); i++)
        {
            cubes[i]->Remove();
        }

        RemoveLine();
        currentWordIndex++;

        return;
    }

    cubes.Clear();*/

    // Check east (words going to the right)
    for (int i = 1; i < GRID_LENGTH; i++)
    {
        LetterCube* rightLetter = GetLetter(letter->pos.x + i, letter->pos.y);

        if (rightLetter == nullptr)
        {
            break;
        }

        if (letter->kana == wordList[currentWordIndex][i])
        {
            cubes.Add(letter);
        }
        else
        {
            break;
        }
    }

    if (cubes.Size() == wordList[currentWordIndex].Length())
    {
        for (unsigned int i = 0; i < cubes.Size(); i++)
        {
            cubes[i]->Remove();
        }

        RemoveLine();
        currentWordIndex++;

        return;
    }
}

void Tetris::RemoveLine(int numberOfLines)
{
    // Delete a number of lines
    for (int i = 0; i < numberOfLines; i++)
    {
        bool isLineDeleted = false;

        // The Scene has Blocks in components. The blocks components also, with the actual cubes
        for (unsigned int i = 0; i < components.Size(); i++)
        {
            // First get the blocks
            Block* block = dynamic_cast<Block*>(*components[i]);

            if (block == nullptr)
            {
                continue;
            }

            // Then process the cubes which the tetrominos consist of
            for (unsigned int i = 0; i < block->components.Size(); i++)
            {
                // Then the letter cubes
                LetterCube* cube = dynamic_cast<LetterCube*>(*block->components[i]);

                if (cube != nullptr)
                {
                    if (cube->pos.y < -GRID_HEIGHT)
                    {
                        cube->Remove();

                        isLineDeleted = true;
                    }
                }
            }
        }

        if (isLineDeleted)
        {
            MoveAllCubesDown();
        }
    }
}

LetterCube *Tetris::GetLetter(float x, float y)
{
    // The Scene has Blocks in components. The blocks components also, with the actual cubes
    for (unsigned int i = 0; i < components.Size(); i++)
    {
        // First get the blocks
        Block* block = dynamic_cast<Block*>(*components[i]);

        if (block == nullptr)
        {
            continue;
        }

        // Then process the cubes which the tetrominos consist of
        for (unsigned int i = 0; i < block->components.Size(); i++)
        {
            // First get the blocks
            LetterCube* letter = dynamic_cast<LetterCube*>(*block->components[i]);

            if (letter != nullptr)
            {
                if (letter->pos.x == x && letter->pos.y == y && letter->isVisible())
                {
                    return letter;
                }
            }
        }
    }

    return nullptr;
}
