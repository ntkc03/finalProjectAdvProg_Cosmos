#ifndef SOUND_H
#define SOUND_H

#include <iostream>
#include <SFML/Graphics.hpp>

class Sound
{
    sf::Texture musicText;
    sf::Sprite music;
    sf::Texture muteText;
    sf::Sprite mute;
    bool isPlay;
    sf::Vector2f mousePos;
    void initTexture();
    void initSprite();
public:
    Sound();
    virtual ~Sound();

    bool isMusicPlaying();
    void setPos(const sf::Vector2f &pos);
    void pollEv(sf::RenderWindow *window);
    void updateMousePos(sf::Vector2f *mousePosView_);
    void render(sf::RenderWindow *window);
};

#endif // SOUND_H
