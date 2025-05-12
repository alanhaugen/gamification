#include "tetris.h"
#include <core/application.h>
#include <core/components/cube.h>
#include <core/components/camera.h>
#include <core/components/background.h>
#include "main.h"
#include "dictionary.h"

extern int highscore;
extern Level* currentLevel;
extern Dictionary dictionary;

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

    if (kana == Kana::a || kana == Kana::i || kana == Kana::u || kana == Kana::e || kana == Kana::o)
    {
        background->Uniform("colour", static_cast<glm::vec4>(glm::vec4(1.0f, 0.0f, 1.0f, 1.0f)));
    }
    if (kana == Kana::ka || kana == Kana::ki || kana == Kana::ku || kana == Kana::ke || kana == Kana::ko)
    {
        background->Uniform("colour", static_cast<glm::vec4>(glm::vec4(0.0f, 1.0f, 0.0f, 1.0f)));
    }
    if (kana == Kana::sa || kana == Kana::shi || kana == Kana::su || kana == Kana::se || kana == Kana::so)
    {
        background->Uniform("colour", static_cast<glm::vec4>(glm::vec4(0.0f, 1.0f, 1.0f, 1.0f)));
    }
    if (kana == Kana::ta || kana == Kana::chi || kana == Kana::tsu || kana == Kana::te || kana == Kana::to)
    {
        background->Uniform("colour", static_cast<glm::vec4>(glm::vec4(0.8f, 0.2f, 0.1f, 1.0f)));
    }
    if (kana == Kana::na || kana == Kana::ni || kana == Kana::nu || kana == Kana::ne || kana == Kana::no)
    {
        background->Uniform("colour", static_cast<glm::vec4>(glm::vec4(0.8f, 0.2f, 0.1f, 1.0f)));
    }
    if (kana == Kana::ha || kana == Kana::hi || kana == Kana::fu || kana == Kana::he || kana == Kana::ho)
    {
        background->Uniform("colour", static_cast<glm::vec4>(glm::vec4(0.0f, 1.0f, 1.0f, 1.0f)));
    }
    if (kana == Kana::ma || kana == Kana::mi || kana == Kana::mu || kana == Kana::me || kana == Kana::mo)
    {
        background->Uniform("colour", static_cast<glm::vec4>(glm::vec4(1.0f, 1.0f, 0.0f, 1.0f)));
    }
    if (kana == Kana::ya || kana == Kana::yu || kana == Kana::yo)
    {
        background->Uniform("colour", static_cast<glm::vec4>(glm::vec4(1.0f, 1.0f, 0.0f, 1.0f)));
    }
    if (kana == Kana::ra || kana == Kana::ri || kana == Kana::ru || kana == Kana::re || kana == Kana::ro)
    {
        background->Uniform("colour", static_cast<glm::vec4>(glm::vec4(1.0f, 1.0f, 0.0f, 1.0f)));
    }
    if (kana == Kana::wa || kana == Kana::wo || kana == Kana::n)
    {
        background->Uniform("colour", static_cast<glm::vec4>(glm::vec4(1.0f, 1.0f, 0.0f, 1.0f)));
    }
}

void LetterCube::Remove()
{
    matrix.Translate(glm::vec3(1000.0f));
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

void Block::Remove()
{
    for (unsigned int i = 0; i < components.Size(); i++)
    {
        LetterCube* cube = dynamic_cast<LetterCube*>(*components[i]);

        if (cube)
        {
            cube->Remove();
        }
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

    if (type == I) // +
    {
        Add(new LetterCube(0,0,0, this));
        Add(new LetterCube(1*2,0,0, this));
        Add(new LetterCube(-1*2,0,0, this));
        Add(new LetterCube(0,1*2,0, this));
        Add(new LetterCube(0,-1*2,0, this));
    }
    else if (type == O) // x
    {
        Add(new LetterCube(0,0,0, this));
        Add(new LetterCube(1*2,1*2,0, this));
        Add(new LetterCube(-1*2,1*2,0, this));
        Add(new LetterCube(1*2,-1*2,0, this));
        Add(new LetterCube(-1*2,-1*2,0, this));

        //canRotate = false;
    }
    else if (type == T) // l
    {
        Add(new LetterCube(0,0*2,0, this));
        Add(new LetterCube(0,1*2,0, this));
        Add(new LetterCube(1*2,1*2,0, this));
    }
    else if (type == S) // .
    {
        Add(new LetterCube(0,0,0, this));
    }
    else if (type == Z) // ..
    {
        Add(new LetterCube(0,0,0, this));
        Add(new LetterCube(-1*2,0,0, this));
    }
    else if (type == J) // clump
    {
        Add(new LetterCube(0,-1*2,0, this));
        Add(new LetterCube(0,0*2,0, this));
        Add(new LetterCube(0,1*2,0, this));
        Add(new LetterCube(1*2,1*2,0, this));
        Add(new LetterCube(1*2,0*2,0, this));
    }
    else if (type == L)
    {
        Add(new LetterCube(0,0*2,0, this));
        Add(new LetterCube(0,1*2,0, this));
        Add(new LetterCube(-1*2,1*2,0, this));
    }

    matrix.Translate(glm::vec3(0, 15, -45));
}

Tetris::Tetris()
{
}

void Tetris::Init()
{
    components.Clear();
    words.Clear();

    random.SetRandomSeed(currentLevel->lvlSeed);
    score = 0;
    speed = 1;
    paused = false;
    timer = Application::GetTime();
    gameTickTime = 500.0f;

    activePiece = new Block();

    if(currentLevel != nullptr)
    {
        //Sprite* wordListBox = new Sprite("data/art/wordListBox.png", 40, 40, 1, 1, glm::vec2(0,0));
        //components.Add(wordListBox);
    }

    if (currentLevel != nullptr)
    {
        wordList = currentLevel->wordList;
    }

    for (unsigned int i = 0; i < wordList.size(); i++)
    {
        Text* text = new Text(wordList[i], 50, 50 + 50 * i, 1.0f, 1.0f, glm::vec2(0,0), "data/hiragana.png", 1.3f);
        components.Add(text);
        words.Add(text);
    }

    Pause = new PauseMenu();

    Camera* cam = new Camera();

    components.Add(cam);
    components.Add(activePiece);

    // Grid around board code follows

    // bottom (10 block)
    for (int i = 0; i < GRID_LENGTH; i++)
    {
        Cube* cube = new Cube(i*2  - 10,-35 + 10,-45, 1, 0, 1);
        cube->tag = "wall";
        components.Add(cube);
    }

    // side left (22 blocks)
    for (int i = 0; i < GRID_HEIGHT; i++)
    {
        Cube* cube = new Cube( -12,-35 + 10 + i*2,-45, 1, 0, 1);
        cube->tag = "wall";
        components.Add(cube);
    }

    // side right (22 blocks)
    for (int i = 0; i < GRID_HEIGHT; i++)
    {
        Cube* cube = new Cube(10,-35 + 10 + i*2,-45, 1, 0, 1);
        cube->tag = "wall";
        components.Add(cube);
    }

    components.Add(new Text("Make these words:",0,30, 0.5, 0.5));
    components.Add(new Background(glm::vec3(0.776470588235294, 0.870588235294118, 0.945098039215686), cam));
    //components.Add(new Background("data/art/new/background.png", cam));//glm::vec3(0.776470588235294, 0.870588235294118, 0.945098039215686), cam));

    croco = new Sprite("data/art/new/DrCroco_Chibi_Idle.png",renderer->windowWidth - 300,200,0.2,0.2);
    //croco = new Sprite("data/art/new/DrCroco_Chibi_Jump_Throw.png",renderer->windowWidth - 300,200,0.2,0.2);
}

void Tetris::Update(float dt)
{
    if(input.Pressed(input.Key.P))
    {
        Pause->Pause();
        timer->Pause();
    }

    if(Pause->isPaused)
    {
        Pause->Update(dt);
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
        physics->Reset();
        currentLevel = nullptr;
        Application::LoadScene(Scenes::StartMenu);
    }

    if (IsNoWordsLeft())
    {
        physics->Reset();
        currentLevel = nullptr;
        Application::LoadScene(Scenes::Quiz);
    }

    croco->Update();
}

void Tetris::UpdateAfterPhysics()
{
    if (physics->Collide())
    {
        // GameOver
        if (activePiece->matrix.position.y - activePiece->direction.y == 15.0f)
        {
            physics->Reset();
            currentLevel = nullptr;
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
            activePiece->Update();
            components.Add(activePiece);

            while(CheckForWords(false))
            {
                activePiece->Remove();

                activePiece = new Block();
                activePiece->Update();
                components.Add(activePiece);
            }
        }
        // Move back out of collision
        else
        {
            activePiece->matrix.Translate(-activePiece->direction);
            activePiece->Update();
        }
    }
}

bool Tetris::Approx(float a, float b)
{
    if (abs(a - b) < EPSILON)
    {
        return true;
    }

    return false;
}

bool Tetris::CheckForWords(bool reward)
{
    //int multiplier = 1;
    bool isWord = false;

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

            if (isWord == false)
            {
                isWord = ProcessLetter(letter, reward);
            }
            else
            {
                ProcessLetter(letter, reward);
            }
        }
    }

    return isWord;
}

void Tetris::MoveAllCubesDown()
{
    // The Scene has Blocks in components. The blocks have components also, with the actual cubes
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

bool Tetris::ProcessLetter(LetterCube *letter, bool reward)
{
    bool isWord = false;

    // No words list in endless mode
    if (currentLevel == nullptr)
    {
        return false;
    }

    for (int wordIndex = 0; wordIndex < wordList.size(); wordIndex++)
    {
        // If the current word doesn't start with this letter, go to the next word
        if (letter->kana != wordList[wordIndex][0])
        {
            continue;
        }

        // Check east (j == 0: words going left to right) and south (j == 1: words going down)
        for (int j = 0; j < 2; j++)
        {
            Array<LetterCube*> cubes;
            cubes.Add(letter);

            for (int i = 1; i < GRID_HEIGHT; i++)
            {
                LetterCube* nextLetter;

                if (j == 0)
                {
                    nextLetter = GetLetter(letter->pos.x + (i * CUBE_HEIGHT), letter->pos.y);
                }
                else
                {
                    nextLetter = GetLetter(letter->pos.x, letter->pos.y - (i * CUBE_HEIGHT));
                }

                if (nextLetter == nullptr)
                {
                    break;
                }

                if (nextLetter->kana == wordList[wordIndex][i])
                {
                    cubes.Add(nextLetter);
                }
                else
                {
                    break;
                }
            }

            if (cubes.Size() == wordList[wordIndex].Length())
            {
                for (unsigned int i = 0; i < cubes.Size(); i++)
                {
                    LetterCube* cube;

                    cube = GetLetter(cubes[i]->pos.x - CUBE_HEIGHT, cubes[i]->pos.y, false);

                    if (cube != nullptr)
                    {
                        cube->Remove();
                    }

                    cube = GetLetter(cubes[i]->pos.x + CUBE_HEIGHT, cubes[i]->pos.y, false);

                    if (cube != nullptr)
                    {
                        cube->Remove();
                    }

                    cube = GetLetter(cubes[i]->pos.x, cubes[i]->pos.y + CUBE_HEIGHT, false);

                    if (cube != nullptr)
                    {
                        cube->Remove();
                    }

                    cube = GetLetter(cubes[i]->pos.x, cubes[i]->pos.y - (CUBE_HEIGHT), false);

                    if (cube != nullptr)
                    {
                        cube->Remove();
                    }

                    cubes[i]->Remove();

                    // Add all over these blocks to a list and move them down
                }

                //RemoveLine();
                isWord = true;
                if (reward)
                {
                    if (*words[wordIndex]->matrix.x < 100)
                    {
                        dictionary.words.Add(wordList[wordIndex]);
                        *words[wordIndex]->matrix.x = renderer->windowWidth - 200;
                    }
                }
            }
        }
    }

    return isWord;
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

LetterCube *Tetris::GetLetter(float x, float y, bool onlyReturnVisible)
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
            // Then the letter cubes
            LetterCube* letter = dynamic_cast<LetterCube*>(*block->components[i]);

            if (letter != nullptr)
            {
                if (Approx(letter->pos.x, x) && Approx(letter->pos.y, y))
                {
                    if (onlyReturnVisible == true && letter->isVisible())
                    {
                        return letter;
                    }
                    else if (onlyReturnVisible == false)
                    {
                        return letter;
                    }
                }
            }
        }
    }

    return nullptr;
}

bool Tetris::IsNoWordsLeft()
{
    int wordsDone = 0;
    for (int i = 0; i < words.Size(); i++)
    {
        if (*words[i]->matrix.x > 100)
        {
            wordsDone++;
        }
    }

    if (wordsDone == words.Size())
    {
        return true;
    }

    return false;
}
