#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include <sstream>

class Player
{
private:
    sf::Sprite sprite1, sprite2, sprite3, sprite;
    sf::Texture ship1, ship2, ship3;
    sf::Font font;
    sf::Text speedText1, speedText2, speedText3;
    float speedShip1, speedShip2, speedShip3, movementSpeed;
    int choice;
    void initVariable();
    void initTexture();
    void initSprite();
    void initFontsandTexts();
public:
    Player();
    virtual ~Player();

    sf::Vector2f getPos();
    sf::FloatRect getBounds();

    //used in Game (using only one player)
    void setPos(const sf::Vector2f &pos);
    void setChoice();
    void move(const float &X, const float &Y);
    void update();
    void render(sf::RenderTarget *target);

    //used in Hello (print 3 spaceship types for player to choose)
    void updateChoosePlayer(sf::RenderWindow *window);
    void setPosChoosePlayer(sf::RenderWindow *window);
    void getChoice(int choice);
    void setString();
    sf::FloatRect getBounds(int choice);
    void renderChoosePlayer(sf::RenderTarget * target);


};

#endif // PLAYER_H
