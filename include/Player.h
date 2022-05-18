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
    sf::Sprite ship1Sprite, ship2Sprite, ship3Sprite, playerSprite;
    sf::Texture ship1, ship2, ship3;
    sf::Font font;
    sf::Text speedText1, speedText2, speedText3;
    float speedShip1, speedShip2, speedShip3, movementSpeed;
    int choice;
    void initVariable();
    void initTexture();
    void initSprite();
    void initFont();
public:
    Player();
    virtual ~Player();


    //used in Game (using only one player)
    sf::Vector2f getPos();
    sf::FloatRect getBounds();

    void setPos(const sf::Vector2f &pos);
    void setPlayer();
    void setChoice();
    void move(const sf::Vector2f &offset);
    void render(sf::RenderTarget *target);

    //used in Hello (print 3 spaceship types for player to choose)
    void updateChoosePlayer(sf::RenderWindow *window);
    void setPosChoosePlayer(sf::RenderWindow *window);
    void getChoice(const int &choice_);
    void setString();
    sf::FloatRect getBounds(const int &choice);
    sf::Vector2f getPos(const int &choice);
    void renderChoosePlayer(sf::RenderTarget * target);


};

#endif // PLAYER_H
