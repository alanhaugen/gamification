#ifndef QUIZ_H
#define QUIZ_H

#include <core/x-platform/scene.h>
#include <core/containers/stack.h>
#include <core/components/text.h>
#include "dictionary.h"

class Quiz : public IScene
{
public:
    Quiz();

    void Init();
    void Update();
    void UpdateAfterPhysics();

    Stack<Lexeme> questions;
    Text* question;
    Text* answer;

    Sprite* button1;
    Sprite* button2;
    Sprite* button3;
    Sprite* button4;

    Text* buttonText1;
    Text* buttonText2;
    Text* buttonText3;
    Text* buttonText4;
};

#endif // QUIZ_H
