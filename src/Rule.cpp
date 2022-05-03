#include "Rule.h"
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
    this -> intruction1.setString("Move: ");

    this -> intruction2.setFont(this -> contentFont);
    this -> intruction2.setString("Shoot: Press A for Lazer Mode, press S for Bullet Mode.");

    this -> title_.setFont(this -> titleFont);
    this -> title_.setString("Score");

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
    this -> bkg = new sf::Texture;
    if(!this -> bkg -> loadFromFile("image/bkg.jpg"))
    {
        std::cout << "ERROR::HELLO::INITBKG::Can't load image\n";
    }
    this -> background = new Background(bkg);
    this -> background ->setSize(sf::Vector2f(1.9f, 1.9f));
}
 void Rule::initShape()
 {
     this -> circle.setRadius(35.f);
     this -> circle.setFillColor(sf::Color::Black);
     this -> circle.setOutlineColor(sf::Color::White);
     this -> circle.setOutlineThickness(5.f);
     this -> circle.setPosition(0.f, 0.f);
 }
Rule::Rule()
{
    this -> choices = 0;
    this -> initFont();
    this -> initText();
    this -> initTexture();
    this -> initSprite();
    this -> initShape();
    this -> initBKG();
}

Rule::~Rule()
{
    delete background;
    delete bkg;
}
const bool Rule::isRunning(sf::RenderWindow *window) const
{
    return window->isOpen();
}
bool Rule::isClosed()
{
    return closed;
}
int Rule::choice()
{
    return choices;
}
void Rule::run(sf::RenderWindow *window)
{
    while(this -> isRunning(window) && choices == 0){
        this -> update(window);
        this -> render(window);
    }
}
void Rule::update(sf::RenderWindow *window)
{
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
                    choices = 1;
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
    this -> intruction2.setPosition(10.f, this -> intruction1.getGlobalBounds().top + this -> intruction1.getGlobalBounds().height + 100.f);
    this -> button.setPosition(this -> intruction1.getGlobalBounds().left + this -> intruction1.getGlobalBounds().width + 30.f, 100.f);
    this -> title_.setPosition(window -> getSize().x / 2.0 - 100.f,
                              this -> button.getGlobalBounds().top + this -> button.getGlobalBounds().height + 50.f);
    this -> scoreCal1.setPosition(window -> getSize().x / 2.0 - 180.f, this -> title_.getGlobalBounds().top + this -> title_.getGlobalBounds().height + 10.f);
    this -> scoreCal2.setPosition(window -> getSize().x / 2.0 - 180.f, this -> scoreCal1.getGlobalBounds().top + this -> scoreCal1.getGlobalBounds().height + 10.f);
    this -> returnButt.setPosition(1.f, 1.f);
}
void Rule::setScale()
{
    this -> title.setScale(2.f, 2.f);
    this -> intruction1.setScale(1.f, 1.f);
    this -> intruction2.setScale(1.f, 1.f);
    this -> button.setScale(0.8f, 0.8f);
    this -> title_.setScale(2.f, 2.f);
    this -> scoreCal1.setScale(1.5f, 1.5f);
    this -> scoreCal2.setScale(1.5f, 1.5f);
    this -> returnButt.setScale(0.8f, 0.8f);
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
    window -> draw(this -> button);
    window -> draw(this -> title_);
    window -> draw(this -> scoreCal1);
    window -> draw(this -> scoreCal2);
    window -> draw(this -> circle);
    window -> draw(this -> returnButt);
    window -> display();
}
