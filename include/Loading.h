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
public:
    Loading();
    virtual ~Loading();
    float getNumber();
    void updateTexts(sf::Vector2f windowsize);
    void setFont();
    void setString();
    void setScale();
    void setColor();
    void setPos(sf::Vector2f windowsize);
    void update(sf::Vector2f windowsize);
    void render(sf::RenderTarget *target);
};

#endif // LOADING_H
