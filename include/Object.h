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
    bool Alien;


    void initVariable();
public:

    Object(sf::Texture *texture, float posX, float posY, float sizeX, float sizeY, float speed, bool isAlien_);
    virtual ~Object();
    sf::Vector2f getPos();
    sf::FloatRect getBounds();
    const bool isAlien() const;
    void updateSpeed(float laterSpeed);
    void update();
    void render(sf::RenderTarget *target);
};

#endif // OBJECT_H
