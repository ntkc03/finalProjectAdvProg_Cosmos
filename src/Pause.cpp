#include "Pause.h"

void Pause::initTexture()
{
    this -> pauseText.loadFromFile("image/pause.PNG");
    this -> conText.loadFromFile("image/start.png");
    this -> isPause = false;
}
void Pause::initSprite()
{
    this -> pause.setTexture(this -> pauseText);
    this -> pause.setScale(0.5f, 0.5f);
    this -> continueSprite.setTexture(this -> conText);
    this -> continueSprite.setScale(0.5f, 0.5f);
}
Pause::Pause()
{
    this -> initTexture();
    this -> initSprite();
}
Pause::~Pause()
{

}
bool Pause::isPlay()
{
    return this -> isPause;
}
void Pause::setPos(sf::RenderWindow *window, float posX, float posY)
{
    this -> pause.setPosition(posX, posY);
    this -> continueSprite.setPosition(window -> getSize().x / 2 - 100.f, window -> getSize().y / 2 - 50.f);
}
void Pause::pollEv(sf::RenderWindow *window)
{
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
        if(this -> pause.getGlobalBounds().contains(this -> mousePosView))
        {
            isPause = true;
        }
        else if(this -> continueSprite.getGlobalBounds().contains(this -> mousePosView))
        {
            isPause = false;
        }
    }
}
void Pause::updateMousePos(sf::Vector2f mousePosView_)
{
    this -> mousePosView = mousePosView_;
}
void Pause::render(sf::RenderWindow *window)
{
    if(isPause)
    {
        window -> draw(this -> continueSprite);
    }
    else
    {

        window -> draw(this -> pause);
    }
}
