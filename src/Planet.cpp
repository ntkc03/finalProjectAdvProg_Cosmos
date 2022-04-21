#include "Planet.h"

Planet::Planet(sf::Texture *texture, float posX, float posY, float movementSpeed_){
    this -> sprite.setTexture(*texture);
    this -> sprite.setPosition(posX, posY);
    this -> sprite.setScale(0.5f, 0.5f);
    this -> movementSpeed = movementSpeed_;
}
Planet::~Planet(){

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
