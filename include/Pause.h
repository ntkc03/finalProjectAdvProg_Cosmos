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
    sf::Texture stopText;
    sf::Sprite stop;
    sf::Event ev;
    bool isPause;
    bool isStop;
    sf::SoundBuffer clickBuff;
	sf::Sound click;
    sf::Vector2f mousePosView;
    void initTexture();
    void initSprite();
public:
    Pause();
    virtual ~Pause();
    bool isPlay();
    bool isContinue();
    void setPos(sf::RenderWindow *window, float posX, float posY);
    void pollEv(sf::RenderWindow *window);
    void updateMousePos(sf::Vector2f mousePosView_);
    void render(sf::RenderWindow *window);
};

#endif // PAUSE_H
