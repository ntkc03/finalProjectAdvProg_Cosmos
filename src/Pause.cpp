#include "Pause.h"

void Pause::initTexture()
{
    this -> pauseText.loadFromFile("image/pause.PNG");
    this -> conText.loadFromFile("image/start.png");
    this -> stopText.loadFromFile("image/stop.png");
    this -> isPause = false;
    this -> isStop = false;
}
void Pause::initSprite()
{
    this -> pause.setTexture(this -> pauseText);
    this -> pause.setScale(0.5f, 0.5f);
    this -> continueSprite.setTexture(this -> conText);
    this -> continueSprite.setScale(0.5f, 0.5f);
    this -> stop.setTexture(this -> stopText);
    this -> stop.setScale(0.35f, 0.35f);
}


Pause::Pause()
{
    this -> clickBuff.loadFromFile("audio/mouse.wav");
    this -> click.setBuffer(this -> clickBuff);
    this -> initTexture();
    this -> initSprite();
}
Pause::~Pause()
{
    this -> click.stop();
}


bool Pause::isPlay()
{
    return this -> isStop;
}
bool Pause::isContinue()
{
    return this -> isPause;
}


void Pause::setPos(sf::RenderWindow *window, float posX, float posY)
{
    this -> pause.setPosition(posX, posY);
    this -> continueSprite.setPosition(window -> getSize().x / 2 - 100.f, window -> getSize().y / 2 - 50.f);
    this -> stop.setPosition(this -> pause.getGlobalBounds().left + this -> pause.getGlobalBounds().width, this -> pause.getPosition().y);
}


void Pause::pollEv(sf::RenderWindow *window)
{
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
        if(this -> pause.getGlobalBounds().contains(this -> mousePosView))
        {
            isPause = true;
            this -> click.play();
        }
        else if(this -> continueSprite.getGlobalBounds().contains(this -> mousePosView))
        {
            isPause = false;
            this -> click.play();
        }
        else if(this -> stop.getGlobalBounds().contains(this -> mousePosView))
        {
            isStop = true;
            this -> click.play();
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
    else window -> draw(this -> pause);
    window -> draw(this -> stop);
}
