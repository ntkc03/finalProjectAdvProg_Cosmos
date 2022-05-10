#include "Star.h"

Star::Star(float radius)
{
    this -> circle.setRadius(radius);
}
Star::~Star()
{

}

void Star::setFirstPos(float posX, float posY)
{
    this -> circle.setPosition(posX, posY);
}

void Star::circleMove(float x, float y)
{
    this -> circle.move(x * this -> movementSpeed, this -> movementSpeed * y);
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
