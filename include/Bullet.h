#ifndef BULLET_H
#define BULLET_H

#include <iostream>
#include <SFML/Graphics.hpp>


class Bullet{
private:
    sf::Sprite sprite;
    float movementSpeed;

public:
    Bullet(sf::Texture *texture, const sf::Vector2f &pos, const sf::Vector2f &scale, const int &movementSpeed_);
    virtual ~Bullet();

    const sf::FloatRect getBounds();
    void update(const sf::Vector2f &direction);
    void render(sf::RenderTarget *target);
};


#endif // BULLET_H
