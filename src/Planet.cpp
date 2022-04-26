#include "Planet.h"

Planet::Planet(sf::Texture *texture, float posX, float posY, float movementSpeed_){
    this -> sprite.setTexture(*texture);
    this -> sprite.setPosition(posX, posY);
    this -> sprite.setScale(0.6f, 0.6f);
    this -> movementSpeed = movementSpeed_;
}
Planet::~Planet(){

}
sf::Vector2f Planet::getPos()
{
    return this -> sprite.getPosition();
}
sf::FloatRect Planet::getBounds(){
    return this -> sprite.getGlobalBounds();
}
void Planet::update(){
    this -> sprite.move(sf::Vector2f(0.f, 1.f) * movementSpeed);
}
void Planet::render(sf::RenderTarget *target){
    target -> draw(this -> sprite);
}
