#include "background.h"
void Background::initVariable()
{
    this -> numOfStarMax = 200.f;
}
void Background::initStar()
{
    for(int i = 0; i < numOfStarMax; i++)
    {
        float rad = (rand() % 4) ;
        stars.push_back(new Star(rad));
    }
}

Background::Background()
{
    this -> initVariable();
    this -> initStar();
}
Background::~Background()
{
    for(auto i: stars)
    {
        delete i;
    }
}
void Background::setFirstPos(sf::RenderWindow *window)
{
    for(int i = 0; i <stars.size(); i++)
    {
        stars[i] -> setFirstPos(rand() % (window -> getSize().x + 500) - 100, rand() % (window -> getSize().y + 500) - 100) ;
    }
}
void Background::moveStars(sf::RenderWindow *window, float x, float y)
{
    for(auto *i: stars){
        i -> circleMove(x, y);
    }
}
void Background::update(sf::RenderWindow * window )
{
    for(auto *i: stars)
    {
        i -> setRandomColor();
    }
}
void Background::render(sf::RenderWindow *target)
{
    for(int i = 0; i < stars.size(); i++)
    {
        stars[i] -> render(target);
    }
}
