#include "Exit.h"

void Exit::initFontsandTexts()
{
    this -> font.loadFromFile("fonts/");
    this -> question.setFont(this -> font);
    this -> choice1.setFont(this -> font);
    this -> choice2.setFont(this -> font);
}
Exit::Exit()
{

}
Exit::Exit(sf::RenderWindow *target)
{
    this -> window = target;
    this -> initFontsandTexts();
}
Exit::~Exit()
{

}
void Exit::update()
{
    this -> updateTexts();
}
void Exit::updateTexts()
{
    this -> setString();
    this -> setColor();
    this -> setPos();
    this -> setScale();
}
 void Exit::setString()
 {
    this -> question.setString("Do you wanna exit this game?");
    this -> choice1.setString("Yes");
    this -> choice2.setString("No");
 }
void Exit::setColor()
{
    this -> question.setColor(sf::Color::White);
    this -> choice1.setColor(sf::Color::White);
    this -> choice2.setColor(sf::Color::White);
}
void Exit::setScale()
{
    this -> question.setScale(1.f, 1.f);
    this -> choice1.setScale(1.f, 1.f);
    this -> choice2.setScale(1.f, 1.f);
}
void Exit::setPos()
{

}
void Exit::render()
{
    this -> window -> draw(this -> question);
    this -> window -> draw(this -> choice1);
    this -> window -> draw(this -> choice2);
}
void Exit::running()
{

}
