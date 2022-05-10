#ifndef HELLO_H
#define HELLO_H

#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <random>
#include <ctime>
#include "background.h"
#include "Player.h"
#include "Rule.h"
class Hello
{
private:

    sf::Event ev;
    sf::Font font1, font2, font3;

    sf::Text welcome;
    sf::Text name;
    sf::Text demand;
    sf::Text choice1;
    sf::Text choice2;
    sf::Text choice3;
    Background *background;

    sf::Texture returnTex;
    sf::Sprite returnButton;
    bool isReturn;

    sf::Vector2i mousePosWindow;
	sf::Vector2f mousePosView;

	//music
	sf::SoundBuffer bgkBuf;
    sf::Sound bgk;

    //Player choice
    int playerChoice;
    Player *playerRange;
    sf::Text textOfchoice;

    int choices;
    bool closed;
    void initVariables();
    void initFont();
    void initBKG();
    void initSound();
    void initImage();
public:
    //Constructor & Destructor
    Hello();
    virtual ~Hello();

    void running(sf::RenderWindow *window);

    //check running
    const bool isRunning(sf::RenderWindow *window) const;
    bool isClosed();
    int choice();
    void setChoiceAfterOnShift(int choice);


    //update
    void update(sf::RenderWindow *window);
    void PollEv(sf::RenderWindow *window);
    void updateMousePos(sf::RenderWindow *window);
    void updateText(sf::RenderWindow *window);
    void setString();
    void setColor();
    sf::Color randomColor();
    void setPos(sf::RenderWindow *window);
    void setFont();
    void setScale();


    //render
    void render(sf::RenderWindow *window);

    //choose Player
    void pollChoosePlayerEvent(sf::RenderWindow *window);
    void updateChoosePlayer(sf::RenderWindow *window);
    void setTextOfChoice();
    void renderChoosePlayer(sf::RenderWindow *window);
    int getplayerChoice();
};

#endif // HELLO_H
