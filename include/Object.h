#ifndef OBJECT_H
#define OBJECT_H

#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Object{
private:
    sf::Sprite sprite;
    float movementSpeed;
public:

    Object(sf::Texture *texture, const sf::Vector2f &pos, const sf::Vector2f &Size, const float &speed);
    virtual ~Object();

    sf::Vector2f getPos();
    sf::FloatRect getBounds();

    void updateSpeed(const float &laterSpeed);
    void update(const sf::Vector2f &direction);
    void render(sf::RenderTarget *target);
};

#endif // OBJECT_H
