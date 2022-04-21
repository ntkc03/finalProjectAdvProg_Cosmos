#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include "Game.h"
#include "Hello.h"

class gameEngine
{
private:
    // Create window
    sf::RenderWindow *window = nullptr;
    sf::VideoMode windowSize;

    void initWindow();
public:
    gameEngine();
    virtual ~gameEngine();
    void running();
};

#endif // GAMEENGINE_H
