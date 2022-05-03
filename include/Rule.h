#ifndef RULE_H
#define RULE_H

#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "background.h"

class Rule
{
private:
    sf::Font titleFont;
    sf::Font contentFont;
    sf::Text title;
    sf::Text intruction1;
    sf::Text intruction2;
    sf::Text title_;
    sf::Text scoreCal1, scoreCal2;

    sf::Sprite button;
    sf::Texture button_;
    sf::Texture returnButt_;
    sf::Sprite returnButt;
    Background *background;
    sf::Texture* bkg;

    sf::CircleShape circle;

    sf::Vector2i mousePosWindow;
	sf::Vector2f mousePosView;

	sf::Event ev;
	int choices;
    bool closed;
    //private function
    void initFont();
    void initText();
    void initTexture();
    void initSprite();
    void initBKG();
    void initShape();
public:
    Rule();
    virtual ~Rule();

    const bool isRunning(sf::RenderWindow *window) const;
    bool isClosed();
    int choice();

    void run(sf::RenderWindow *window);
    void update(sf::RenderWindow *window);
    void pollEve(sf::RenderWindow * window);
    void updateMousePos(sf::RenderWindow * window);
    void setPos(sf::RenderWindow *window);
    void setScale();
    void setColor();
    void render(sf::RenderWindow *window);

};

#endif // RULE_H
