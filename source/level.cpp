#include "level.h"
#include <fstream>
#include <sstream>
#include <string>
#include <core/application.h>
#include "main.h"
#include "japanesekana.h"

extern Level* currentLevel;

void Level::Update()
{
    if (lvlStatus == DONE)
    {
        lvlImgDone->Update();
    }
    else if (lvlStatus == INCOMPLETE)
    {
        lvlImg->Update();
    }
    else
    {
        lvlImg->Update();
    }

    if(lvlImg->IsPressed() && lvlStatus != 0)
    {
        currentLevel = this;
        Application::LoadScene(Scenes::Tetris);
    }
}

char Level::findKana(std::string token)
{
    char currentKana;

    if(token == "a")
        currentKana = Kana::a;
    if(token == "i")
        currentKana = Kana::i;
    if(token == "u")
        currentKana = Kana::u;
    if(token == "e")
        currentKana = Kana::e;
    if(token == "o")
        currentKana = Kana::o;
    if(token == "ka")
        currentKana = Kana::ka;
    if(token == "ki")
        currentKana = Kana::ki;
    if(token == "ku")
        currentKana = Kana::ku;
    if(token == "ke")
        currentKana = Kana::ke;
    if(token == "ko")
        currentKana = Kana::ko;
    if(token == "sa")
        currentKana = Kana::sa;
    if(token == "shi")
        currentKana = Kana::shi;
    if(token == "su")
        currentKana = Kana::su;
    if(token == "se")
        currentKana = Kana::se;
    if(token == "so")
        currentKana = Kana::so;
    if(token == "ta")
        currentKana = Kana::ta;
    if(token == "chi")
        currentKana = Kana::chi;
    if(token == "tsu")
        currentKana = Kana::tsu;
    if(token == "te")
        currentKana = Kana::te;
    if(token == "to")
        currentKana = Kana::to;
    if(token == "na")
        currentKana = Kana::na;
    if(token == "ni")
        currentKana = Kana::ni;
    if(token == "nu")
        currentKana = Kana::nu;
    if(token == "ne")
        currentKana = Kana::ne;
    if(token == "no")
        currentKana = Kana::no;
    if(token == "ha")
        currentKana = Kana::ha;
    if(token == "hi")
        currentKana = Kana::hi;
    if(token == "fu")
        currentKana = Kana::fu;
    if(token == "he")
        currentKana = Kana::he;
    if(token == "ho")
        currentKana = Kana::ho;
    if(token == "ma")
        currentKana = Kana::ma;
    if(token == "mi")
        currentKana = Kana::mi;
    if(token == "mu")
        currentKana = Kana::mu;
    if(token == "me")
        currentKana = Kana::me;
    if(token == "mo")
        currentKana = Kana::mo;
    if(token == "ya")
        currentKana = Kana::ya;
    if(token == "yu")
        currentKana = Kana::yu;
    if(token == "yo")
        currentKana = Kana::yo;
    if(token == "ra")
        currentKana = Kana::ra;
    if(token == "ri")
        currentKana = Kana::ri;
    if(token == "ru")
        currentKana = Kana::ru;
    if(token == "re")
        currentKana = Kana::re;
    if(token == "ro")
        currentKana = Kana::ro;
    if(token == "wa")
        currentKana = Kana::wa;
    if(token == "wo")
        currentKana = Kana::wo;
    if(token == "n")
        currentKana = Kana::n;
    if(token == "ga")
        currentKana = Kana::ga;
    if(token == "gi")
        currentKana = Kana::gi;
    if(token == "gu")
        currentKana = Kana::gu;
    if(token == "ge")
        currentKana = Kana::ge;
    if(token == "go")
        currentKana = Kana::go;
    if(token == "za")
        currentKana = Kana::za;
    if(token == "ji")
        currentKana = Kana::ji;
    if(token == "zu")
        currentKana = Kana::zu;
    if(token == "ze")
        currentKana = Kana::ze;
    if(token == "zo")
        currentKana = Kana::zo;
    if(token == "da")
        currentKana = Kana::da;
    if(token == "dzu")
        currentKana = Kana::dzu;
    if(token == "de")
        currentKana = Kana::de;
    if(token == "do")
        currentKana = Kana::doo;
    if(token == "ba")
        currentKana = Kana::ba;
    if(token == "bi")
        currentKana = Kana::bi;
    if(token == "bu")
        currentKana = Kana::bu;
    if(token == "be")
        currentKana = Kana::be;
    if(token == "bo")
        currentKana = Kana::bo;
    if(token == "pa")
        currentKana = Kana::pa;
    if(token == "pi")
        currentKana = Kana::pi;
    if(token == "pu")
        currentKana = Kana::pu;
    if(token == "pe")
        currentKana = Kana::pe;
    if(token == "po")
        currentKana = Kana::po;

    return currentKana;
}

Level::Level(int lvlNumber, float posX, float posY)
{
    /*std::ifstream lvlFile("data/levels/" + std::to_string(lvlNumber) + ".txt");
    std::string line;

    if(lvlFile.is_open())
    {
        std::getline(lvlFile, line);
        lvlStatus = stoi(line);
    }

    while(std::getline(lvlFile, line))
    {
        if(line == ";")
            break;

        std::string token;
        std::istringstream stream(line);

        std::string currentKana;
        String currentWord;
        while(std::getline(stream, token, ' '))
        {
            currentKana = std::string(1, findKana(token));

            bool notAdded = true;

            for(unsigned int i = 0; i < lvlKana.size(); i++)
            {
                if(lvlKana[i] == currentKana.c_str())
                {
                    notAdded = false;
                    break;
                }
            }

            if(notAdded)
            {
                lvlKana.push_back(currentKana.c_str());
            }

            currentWord.Append(currentKana.c_str());
        }

        wordList.push_back(currentWord);
    }

    std::getline(lvlFile, line);
    lvlSeed = stoi(line);

    lvlFile.close();*/

    lvlStatus = 1;

    lvlImg = new Sprite("data/art/lvlIncomplete.png", posX, posY);
    lvlImgLocked = new Sprite("data/art/lvlLock.png", posX, posY);
    lvlImgDone = new Sprite("data/art/lvlComplete.png", posX, posY);
}

void Level::UpdateAfterPhysics()
{

}
