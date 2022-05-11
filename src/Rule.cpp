#include "Rule.h"
void Rule::initVariables()
{
    this -> closed = false;
    this -> isReturn = false;

}
void Rule::initFont()
{
    this -> titleFont.loadFromFile("fonts/Pixeboy.ttf");
    this -> contentFont.loadFromFile("fonts/ConnectionIi.otf");
}
void Rule::initText()
{
    this -> title.setFont(this -> titleFont);
    this -> title.setString("How to play");

    this -> intruction1.setFont(this -> contentFont);
    this -> intruction1.setString("Plot: Star War is coming. You're the captain of a warship.\nYou have to avoid or destroy rocks and enermy's space ships.\nIf you knock down any rocks or alien's space ships,you can \nearn points, but if you crash into them, you may lose health.\nAnd you can fly into a planet to get aids and health, but\nif you shoot at any planets, you may violate universe's law\nand you have to lose your health.");

    this -> intruction2.setFont(this -> contentFont);
    this -> intruction2.setString("Move: ");

    this -> intruction3.setFont(this -> contentFont);
    this -> intruction3.setString("Shoot: Press A for Lazer Mode, press S for Bullet Mode.");



    this -> title_.setFont(this -> titleFont);
    this -> title_.setString("Score: ");

    this -> scoreCal1.setFont(this -> contentFont);
    this -> scoreCal1.setString("Alien: + 200 pts.");

    this -> scoreCal2.setFont(this -> contentFont);
    this -> scoreCal2.setString("Rock: +100 pts.");
}
void Rule::initTexture()
{
    this -> button_.loadFromFile("image/button.PNG");
    this -> returnButt_.loadFromFile("image/exit.PNG");
}
void Rule::initSprite()
{
    this -> button.setTexture(this -> button_);
    this -> returnButt.setTexture(this -> returnButt_);
}
void Rule::initBKG()
{
    this -> background = new Background;
}
Rule::Rule()
{
    this -> initVariables();
    this -> initFont();
    this -> initText();
    this -> initTexture();
    this -> initSprite();
    this -> initBKG();
}

Rule::~Rule()
{
    delete background;
}
const bool Rule::isRunning(sf::RenderWindow *window) const
{
    return window->isOpen();
}
bool Rule::isClosed()
{
    return this -> closed;
}
bool Rule::isReturnFun()
{
    return this -> isReturn;
}
void Rule::run(sf::RenderWindow *window)
{
    this -> background -> setFirstPos(window);
    while(this -> isRunning(window)){
        this -> update(window);
        this -> render(window);
        if(isReturn) break;
    }
}
void Rule::update(sf::RenderWindow *window)
{
    this -> background -> update(window);
    this -> pollEve(window);
    this -> updateMousePos(window);
    this -> setPos(window);
    this -> setScale();
    this -> setColor();
}
void Rule::pollEve(sf::RenderWindow * window)
{
    while(window->pollEvent(this -> ev)){
        if(ev.type == sf::Event::Closed){
                window -> close();
                closed = true;
        }
        if(ev.sf::Event::KeyPressed && ev.key.code == sf::Keyboard::Escape){
            window -> close();
            closed = true;
        }
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                if(this -> returnButt.getGlobalBounds().contains(this -> mousePosView)){
                    isReturn = true;
                }
        }

    }
}
void Rule::updateMousePos(sf::RenderWindow * window)
{
    this->mousePosWindow = sf::Mouse::getPosition(*window);
	this->mousePosView = window->mapPixelToCoords(this->mousePosWindow);
}
void Rule::setPos(sf::RenderWindow *window)
{
    this -> title.setPosition(window -> getSize().x / 2.0 - 150.f, 10.f);
    this -> intruction1.setPosition(10.f, 100.f);
    this -> intruction2.setPosition(10.f, this -> intruction1.getGlobalBounds().top + this -> intruction1.getGlobalBounds().height + 10.f);
    this -> button.setPosition(this -> intruction2.getGlobalBounds().left + this -> intruction2.getGlobalBounds().width + 30.f, this -> intruction2.getPosition().y);
    this -> intruction3.setPosition(10.f, this -> button.getGlobalBounds().top + this -> button.getGlobalBounds().height + 10.f);
    this -> title_.setPosition(10.f,
                              this -> button.getGlobalBounds().top + this -> button.getGlobalBounds().height + 50.f);
    this -> scoreCal1.setPosition(this -> title_.getGlobalBounds().left + this -> title_.getGlobalBounds().width + 10.f, this -> title_.getPosition().y + 10.f);
    this -> scoreCal2.setPosition(this -> title_.getGlobalBounds().left + this -> title_.getGlobalBounds().width + 10.f,
                                  this -> scoreCal1.getGlobalBounds().top + this -> scoreCal2.getGlobalBounds().height + 10.f );
    this -> returnButt.setPosition(0.f, 0.f);
}
void Rule::setScale()
{
    this -> title.setScale(2.f, 2.f);
    this -> intruction1.setScale(1.f, 1.f);
    this -> intruction2.setScale(1.f, 1.f);
    this -> intruction3.setScale(1.f, 1.f);
    this -> button.setScale(0.8f, 0.8f);
    this -> title_.setScale(2.f, 2.f);
    this -> scoreCal1.setScale(1.f, 1.f);
    this -> scoreCal2.setScale(1.f, 1.f);
    this -> returnButt.setScale(0.3f, 0.3f);
}
void Rule::setColor()
{
    this -> title.setColor(sf::Color::Red);
    this -> title_.setColor(sf::Color::Red);
}
void Rule::render(sf::RenderWindow *window)
{
    window -> clear(sf::Color::Black);
    this -> background -> render(window);
    window -> draw(this -> title);
    window -> draw(this -> intruction1);
    window -> draw(this -> intruction2);
    window -> draw(this -> intruction3);
    window -> draw(this -> button);
    window -> draw(this -> title_);
    window -> draw(this -> scoreCal1);
    window -> draw(this -> scoreCal2);
    window -> draw(this -> returnButt);
    window -> display();
}
