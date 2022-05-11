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

    void initVariable();
    void initFontsandText();
public:
    GameOver();
    virtual ~GameOver();


    int choice();

    void update(sf::Vector2f windowSize);
    void pollEv();
    void updateTexts(sf::Vector2f windowSize);
    void updateMousePos(sf::Vector2f mousePosView_);
    void updatePoint(float point_);
    void setStringTexts();
    void setScaleTexts();
    void setPos(sf::Vector2f windowSize);
    void SetColor();

    void render(sf::RenderTarget *target);
};

#endif // GAMEOVER_H
