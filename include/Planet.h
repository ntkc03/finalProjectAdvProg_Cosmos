#ifndef PLANET_H
#define PLANET_H


#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Planet
{
private:
    sf::Sprite sprite;
    float movementSpeed;


public:
    Planet(sf::Texture *texture, float posX, float posY, float movementSpeed_);
    virtual ~Planet();

    sf::Vector2f getPos();
    sf::FloatRect getBounds();

    void update();
    void render(sf::RenderTarget *target);
};

#endif // PLANET_H
