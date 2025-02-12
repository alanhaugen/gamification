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

int highscore = 0;

class MainMenu : public IScene
{
private:
    Text *name;
    Text *startGame;
    Text *highScore;
    Text *quit;
    Text *selector;

    bool isStartSelected;

public:
    MainMenu();

    void Init();
    void Update();
    void UpdateAfterPhysics();
};

MainMenu::MainMenu()
{
}

void MainMenu::Init()
{
    highScore = new Text("HIGHSCORE: " + String(highscore), 0, 0);
    name = new Text("TETRIS", 475, 100);

    selector = new Text(">", 475, 225);
    startGame = new Text("START", 500, 225);
    quit = new Text("QUIT", 500, 275);

    components.Add(new Camera());

    components.Add(name);
    components.Add(startGame);
    components.Add(highScore);
    components.Add(quit);
    components.Add(selector);

    isStartSelected = true;
}

void MainMenu::Update()
{
    if (input.Pressed(input.Key.DOWN))
    {
        isStartSelected = false;
        *selector->matrix.y = *quit->matrix.y;
    }
    if (input.Pressed(input.Key.UP))
    {
        isStartSelected = true;
        *selector->matrix.y = *startGame->matrix.y;
    }
    if (input.Pressed(input.Key.ENTER))
    {
        if (isStartSelected == true)
        {
            Application::NextScene();
        }
        else if (isStartSelected == false)
        {
            Application::Quit();
        }
    }
}

void MainMenu::UpdateAfterPhysics()
{
}

int main(int argc, char **argv)
{
    Application application(argc, argv);
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
