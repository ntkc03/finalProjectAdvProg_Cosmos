#ifndef BOOM_H
#define BOOM_H

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Boom
{
private:
    sf::Sprite sprite;


public:
    Boom();
    Boom(sf::Texture *texture);
    virtual ~Boom();

    void setPos(sf::Vector2f pos);
    void render(sf::RenderTarget *target);
};

#endif // BOOM_H
