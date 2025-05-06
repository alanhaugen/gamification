#ifndef QUIZ_H
#define QUIZ_H

#include <core/x-platform/scene.h>

class Quiz : public IScene
{
public:
    Quiz();

    void Init();
    void Update();
    void UpdateAfterPhysics();
};

#endif // QUIZ_H
