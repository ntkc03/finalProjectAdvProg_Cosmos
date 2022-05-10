#ifndef STAR_H
#define STAR_H

#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <random>
class Star
{
private:
    sf::CircleShape circle;
    float movementSpeed = 1.f;
public:
    Star(float radius);
    virtual ~Star();

    void setFirstPos(float posX, float posY);
    void circleMove(float x, float y);
    sf::Color randomColor();
    void setRandomColor();
    void render(sf::RenderWindow *window);
};

#endif // STAR_H
