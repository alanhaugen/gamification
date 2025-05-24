#ifndef DictionaryMenu_H
#define DictionaryMenu_H

#include <core/x-platform/scene.h>
#include "mousecursor.h"

class Text;

class DictionaryMenu : public IScene
{
private:
    MouseCursor* cursor = nullptr;
    Sprite* backButton;
    Array<Text*> dicItems;
    Array<Text*> lexemes;
    Text* activeLexeme = nullptr;

public:
    DictionaryMenu();

    void Init();
    void Update(float dt);
    void UpdateAfterPhysics();
};

#endif
