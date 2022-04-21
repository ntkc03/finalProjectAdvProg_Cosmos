#ifndef GAMEOVER_H
#define GAMEOVER_H

#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include <sstream>
class GameOver
{
private:
    float score;
    sf::Text Score;
    sf::Text yourScore;
    sf::Text gameOver;
    sf::Text playAgain;
    sf::Text choice1;
    sf::Text choice2;
    sf::Font font;
    sf::Font gameOverFont;

    int choices;

    sf::Event ev;

	sf::Vector2f mousePosView;

	sf::Vector2f windowSize;

    void initVariable();
    void initFontsandText();
public:
    GameOver(sf::Vector2f windowSize_);
    virtual ~GameOver();


    int choice();

    void update();
    void pollEv();
    void updateTexts();
    void updateMousePos(sf::Vector2f mousePosView_);
    void updatePoint(float point_);
    void setStringTexts();
    void setScaleTexts();
    void setPos();
    void SetColor();

    void render(sf::RenderTarget *target);
};

#endif // GAMEOVER_H
