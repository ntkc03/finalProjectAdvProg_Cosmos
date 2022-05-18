#ifndef SCORE_H
#define SCORE_H

#include <iostream>
#include <algorithm>
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <map>
#include <background.h>
class Score
{
    sf::Font titleFont;
    sf::Font contentFont;
    sf::Text title;
    std::vector<sf::Text> highestScore;
    std::vector<int> score;
    int numOfHighestScore;

    sf::Sprite button;
    sf::Texture button_;
    sf::Texture returnButt_;
    sf::Sprite returnButt;
    Background *background;

    sf::Vector2i mousePosWindow;
	sf::Vector2f mousePosView;

	sf::Event ev;
	bool isReturn;
    bool closed;

    void initFont();
    void initScore();
    void initHighestScore();
    void initText();
    void initTexture();
    void initSprite();
    void initBKG();
public:
    Score();
    virtual ~Score();

    const bool isRunning(sf::RenderWindow *window) const;
    bool isClosed();
    bool isReturnFun();

    void run(sf::RenderWindow *window);

    void setText(sf::RenderWindow *window);
    void setString();
    void setPos(sf::RenderWindow *window);
    void setScale();
    void setColor();

    void update(sf::RenderWindow *window);
    void pollEve(sf::RenderWindow * window);
    void updateMousePos(sf::RenderWindow *window);

    void render(sf::RenderWindow *window);


};
void enterNewScore(const float &score);
#endif // SCORE_H
