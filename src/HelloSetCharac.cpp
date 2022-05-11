#include "Hello.h"

void Hello::updateText(sf::RenderWindow *window)
{
    this -> setFont();
    this -> setString();
    this -> setColor();
    this -> setScale();
    this -> setPos(window);
}
void Hello::setString()
{
    this -> welcome.setString("Welcome to");
    this -> name.setString("COSMOS");
    this -> demand.setString("> Click to start");
    this -> choice1.setString("1. Play Game");
    this -> choice2.setString("2. How to play");
    this -> choice3.setString("3. Exit");

}
void Hello::setColor()
{
    this -> welcome.setColor(sf::Color::White);
    this -> name.setColor(this -> randomColor());
    this -> demand.setColor(sf::Color::White);
    this -> choice1.setColor(sf::Color::White);
    this -> choice2.setColor(sf::Color::White);
    this -> choice3.setColor(sf::Color::White);

}
sf::Color Hello::randomColor()
{
    uint8_t r = rand() % 256;
    uint8_t g = rand() % 256;
    uint8_t b = rand() % 256;
    sf::Color color = {r, g, b};
    return color;
}
void Hello::setPos(sf::RenderWindow *window)
{
    this -> welcome.setPosition(this -> name.getPosition().x + 100.f, this -> name.getPosition().y - 50.f);
    this -> name.setPosition(window -> getSize(). x / 2.0 - 180.f ,window->getSize().y / 2.0 - 100.f);
    this -> demand.setPosition(this -> name.getPosition().x, this -> name.getPosition().y + 100.f);
    this -> choice1.setPosition(this -> demand.getPosition().x + 50.f, this -> demand.getPosition().y + 50.f);
    this -> choice2.setPosition(this -> choice1.getPosition().x , this -> choice1.getPosition().y + 50.f);
    this -> choice3.setPosition(this -> choice2.getPosition().x , this -> choice2.getPosition().y + 50.f);
}
void Hello::setFont()
{
    this -> welcome.setFont(this -> font3);
    this -> name.setFont(this -> font1);
    this -> demand.setFont(this -> font2);
    this -> choice1.setFont(this -> font2);
    this -> choice2.setFont(this -> font2);
    this -> choice3.setFont(this -> font2);
}
void Hello::setScale()
{
    this -> welcome.setScale(1.5f, 1.5f);
    this -> name.setScale(2.5f, 2.5f);
    this -> demand.setScale(1.5f, 1.5f);
    this -> choice1.setScale(1.5f, 1.5f);
    this -> choice2.setScale(1.5f, 1.5f);
    this -> choice3.setScale(1.5f, 1.5f);
}


void Hello::setTextOfChoice()
{
    this -> textOfchoice.setFont(this -> font3);
    this -> textOfchoice.setString("Choose your favourite space ship");
    this -> textOfchoice.setColor(sf::Color::White);
    this -> textOfchoice.setScale(1.5f, 1.5);
    this -> textOfchoice.setPosition(200.f, 50.f);
}
