#include "Sound.h"

void Sound::initTexture()
{
    this -> musicText.loadFromFile("image/music.png");
    this -> muteText.loadFromFile("image/mute.png");
}
void Sound::initSprite()
{
    this -> music.setTexture(this -> musicText);
    this -> mute.setTexture(this -> muteText);
}
Sound::Sound()
{
    this -> initTexture();
    this -> initSprite();
}
Sound::~Sound()
{

}

bool Sound::isMusicPlaying()
{
    this -> isPlay;
}
void Sound::setPos(const sf::Vector2f &pos)
{
    this -> music.setPosition(pos);
    this -> mute.setPosition(pos);
}
void Sound::pollEv(sf::RenderWindow *window)
{
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
        if(this -> music.getGlobalBounds().contains(this -> mousePosView))
        {
            isPlay = true;
            //this -> click.play();
        }
        else if(this -> mute.getGlobalBounds().contains(this -> mousePosView))
        {
            isPlay = false;
            //this -> click.play();
        }
    }
}
void Sound::updateMousePos(sf::Vector2f *mousePosView_)
{
    this -> mousePos = *mousePosView_;
}
void Sound::render(sf::RenderWindow *window)
{
    if(isPlay) window -> draw(this -> music);
    else window -> draw(this -> mute);
}
