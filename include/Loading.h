#ifndef LOADING_H
#define LOADING_H

#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <sstream>

class Loading
{
private:
    sf::Text loading;
    sf::Text number;
    float num;
    sf::Font font;

    float spawnTimer;
    float spawnTimerMax;
    void initVariable();
    void initFont();
public:
    Loading();
    virtual ~Loading();
    float getNumber();

    void update(const sf::Vector2f &windowSize);
    void updateTexts(const sf::Vector2f &windowSize);
    void setFont();
    void setString();
    void setScale();
    void setColor();
    void setPos(const sf::Vector2f &windowSize);

    void render(sf::RenderTarget *target);
};

#endif // LOADING_H
