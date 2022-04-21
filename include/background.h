#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Background
{
 private:
    sf::Sprite sprite;

public:
    Background(sf::Texture *texture);
    virtual ~Background();
    void setSize(sf::Vector2f bkgSize);
    void render(sf::RenderTarget *target);
};

#endif // BACKGROUND_H
