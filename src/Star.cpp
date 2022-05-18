#include "Star.h"

Star::Star(float radius)
{
    this -> circle.setRadius(radius);
}
Star::~Star()
{

}

void Star::setFirstPos(const sf::Vector2f &pos)
{
    this -> circle.setPosition(pos);
}

void Star::circleMove(const sf::Vector2f &offset)
{
    this -> circle.move(offset * this -> movementSpeed);
}
sf::Color Star::randomColor()
{
    uint8_t r = rand() % 256;
    uint8_t g = rand() % 256;
    uint8_t b = rand() % 256;
    sf::Color color = {r, g, b};
    return color;
}
void Star::setRandomColor()
{
    this -> circle.setFillColor(randomColor());

}
void Star::render(sf::RenderWindow *window)
{
    window -> draw(this -> circle);
}
