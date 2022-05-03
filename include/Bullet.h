#ifndef BULLET_H
#define BULLET_H

#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Bullet{
private:
    sf::Sprite sprite;
    float movementSpeed;

public:
    Bullet(sf::Texture *texture, float posX, float posY, float scaleX, float scaleY,int movementSpeed_);
    virtual ~Bullet();

    const sf::FloatRect getBounds();
    void update();
    void render(sf::RenderTarget *target);
};


#endif // BULLET_H
