#include "Boom.h"

Boom::Boom()
{

}
Boom::Boom(sf::Texture *texture)
{
    this -> sprite.setTexture(*texture);
    this -> sprite.setScale(0.5f, 0.5f);

}
Boom:: ~Boom()
{

}
void Boom::setPos(sf::Vector2f pos)
{
    this -> sprite.setPosition(pos);
}
void Boom::render(sf::RenderTarget *target)
{
    target -> draw(this -> sprite);
}
