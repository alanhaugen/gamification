#include <core/application.h>
#include <core/x-platform/scene.h>
#include <core/components/camera.h>
#include <core/components/text.h>
#include <glm/gtc/constants.hpp>

#include "dictionarymenu.h"
#include "gamemenu.h"
#include "playtetrismenu.h"
#include "startmenu.h"
#include "settingsmenu.h"
#include "levelselectmenu.h"
#include "tetris.h"
#include "gameover.h"
#include "intro.h"
#include "dictionary.h"

int highscore = 0;
Level* currentLevel = nullptr;
Dictionary dictionary;

int main(int argc, char **argv)
{
    Application application(argc, argv);
    application.AddScene(new Intro());
    application.AddScene(new StartMenu());
    application.AddScene(new PlayTetrisMenu());
    application.AddScene(new DictionaryMenu());
    application.AddScene(new LevelSelectMenu());
    application.AddScene(new GameMenu());
    application.AddScene(new SettingsMenu());
    application.AddScene(new Tetris());
    application.AddScene(new GameOver());

    return application.Exec();
}
