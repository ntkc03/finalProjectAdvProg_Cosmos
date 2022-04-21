#ifndef HELLO_H
#define HELLO_H

#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <random>
#include <ctime>
#include "background.h"
class Hello
{
private:

    sf::RenderWindow *window;
    sf::Event ev;
    sf::Font font1, font2, font3;

    sf::Text welcome;
    sf::Text name;
    sf::Text demand;
    sf::Text choice1;
    sf::Text choice2;
    sf::Text choice3;
    Background *background;
    sf::Texture* bkg;

    sf::Vector2i mousePosWindow;
	sf::Vector2f mousePosView;

	//music
	sf::SoundBuffer bgkBuf;
    sf::Sound bgk;

    int choices;
    bool closed;
    void initVariables();
    void initFont();
    void initBKG();
public:
    Hello();
    Hello(sf::RenderWindow *target);
    virtual ~Hello();
    const bool isRunning() const;
    bool isClosed();
    int choice();
    sf::Color randomColor();
    void updateMousePos();
    void updateText();
    void beginPollEv();
    void update();
    void render();
    void running();
};

#endif // HELLO_H
