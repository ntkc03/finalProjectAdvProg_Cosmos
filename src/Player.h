#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Player
{
private:
    sf::Sprite sprite;
    float movementSpeed;
public:
    Player(sf::Texture *texture);
    virtual ~Player();

    sf::Vector2f getPos();
    sf::FloatRect getBounds();
    void setPos(const sf::Vector2f &pos);


    void move(const float &X, const float &Y);
    void update();
    void render(sf::RenderTarget *target);
};

#endif // PLAYER_H
