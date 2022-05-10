#ifndef PAUSE_H
#define PAUSE_H

#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
class Pause
{
private:
    sf::Texture pauseText;
    sf::Sprite pause;
    sf::Texture conText;
    sf::Sprite continueSprite;
    sf::Event ev;
    bool isPause;
    sf::Vector2f mousePosView;
    void initTexture();
    void initSprite();
public:
    Pause();
    virtual ~Pause();
    bool isPlay();
    void setPos(sf::RenderWindow *window, float posX, float posY);
    void pollEv(sf::RenderWindow *window);
    void updateMousePos(sf::Vector2f mousePosView_);
    void render(sf::RenderWindow *window);
};

#endif // PAUSE_H
