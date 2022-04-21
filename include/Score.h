#ifndef GAMEOVER_H
#define GAMEOVER_H

#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

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

    int choices;

    void initVariable();
    void initFontsandText();
public:
    GameOver(const float &point);
    virtual ~GameOver();

    int choice();

    void update();
    void pollEv();
    void updateTexts();
    void setStringTexts();
    void setScaleTexts();
    void setPos();
    void SetColor();

    void render(sf::RenderTarget *target);
};

#endif // GAMEOVER_H
