#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "Star.h"
class Background
{
private:
    std::vector<Star*> stars;
    float numOfStarMax;

    void initVariable();
    void initStar();
public:
    Background();
    virtual ~Background();
    void setFirstPos(sf::RenderWindow *window);
    void moveStars(const sf::Vector2f &offset);
    void update(sf::RenderWindow * window);
    void render(sf::RenderWindow *target);
};

#endif // BACKGROUND_H
