#include "block.h"
#include "japanesekana.h"
#include "level.h"

extern Level* currentLevel;

LetterCube::LetterCube(float x, float y, float z, Actor* parent)
    : Cube(x, y, z, 1, 0, 1, "data/hiragana.png", true, glm::vec4(1.0f, 1.0f, 1.0f, 1.0f),
           "data/block.vert",
           "data/block.frag")
{
    background = new Cube(x,y,-0.01, 1, 0, 1, "data/block.png", false);
    parent->Add(background);

    if(currentLevel != nullptr)
    {
        int rnd;
        rnd = random.RandomRange(0, currentLevel->lvlKana.size());
        kana = currentLevel->lvlKana[rnd].At(0);
    }
    else
    {
        kana = random.RandomRange(0, Kana::NumberOfKana);
    }

    background->drawable->uniforms.index[0] = (kana) - 32.0f;

    if (kana == Kana::a || kana == Kana::i || kana == Kana::u || kana == Kana::e || kana == Kana::o)
    {
        background->drawable->uniforms.colour = glm::vec4(1.0f, 0.0f, 1.0f, 1.0f);
    }
    if (kana == Kana::ka || kana == Kana::ki || kana == Kana::ku || kana == Kana::ke || kana == Kana::ko)
    {
        background->drawable->uniforms.colour = glm::vec4(0.0f, 1.0f, 0.0f, 1.0f);
    }
    if (kana == Kana::sa || kana == Kana::shi || kana == Kana::su || kana == Kana::se || kana == Kana::so)
    {
        background->drawable->uniforms.colour = glm::vec4(0.0f, 1.0f, 1.0f, 1.0f);
    }
    if (kana == Kana::ta || kana == Kana::chi || kana == Kana::tsu || kana == Kana::te || kana == Kana::to)
    {
        background->drawable->uniforms.colour = glm::vec4(0.8f, 0.2f, 0.1f, 1.0f);
    }
    if (kana == Kana::na || kana == Kana::ni || kana == Kana::nu || kana == Kana::ne || kana == Kana::no)
    {
        background->drawable->uniforms.colour = glm::vec4(0.8f, 0.2f, 0.1f, 1.0f);
    }
    if (kana == Kana::ha || kana == Kana::hi || kana == Kana::fu || kana == Kana::he || kana == Kana::ho)
    {
        background->drawable->uniforms.colour = glm::vec4(0.0f, 1.0f, 1.0f, 1.0f);
    }
    if (kana == Kana::ma || kana == Kana::mi || kana == Kana::mu || kana == Kana::me || kana == Kana::mo)
    {
        background->drawable->uniforms.colour = glm::vec4(1.0f, 0.2f, 0.1f, 1.0f);
    }
    if (kana == Kana::ya || kana == Kana::yu || kana == Kana::yo)
    {
        background->drawable->uniforms.colour = glm::vec4(1.0f, 1.0f, 0.0f, 1.0f);
    }
    if (kana == Kana::ra || kana == Kana::ri || kana == Kana::ru || kana == Kana::re || kana == Kana::ro)
    {
        background->drawable->uniforms.colour = glm::vec4(1.0f, 1.0f, 0.0f, 1.0f);
    }
    if (kana == Kana::wa || kana == Kana::wo || kana == Kana::n)
    {
        background->drawable->uniforms.colour = glm::vec4(1.0f, 1.0f, 0.0f, 1.0f);
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
