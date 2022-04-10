#include "Object.h"

void Object::initVariable(){
    this -> movementSpeed = 2.f;
}

Object::Object(sf::Texture *texture, float posX, float posY, float sizeX, float sizeY, bool isAlien_){
    this -> sprite.setTexture(*texture);
    this -> sprite.setPosition(posX, posY);
    this -> sprite.setScale(sizeX, sizeY);
    this -> initVariable();
    this -> Alien = isAlien_;
}
Object::~Object(){

}
sf::FloatRect Object::getBounds(){
    return this -> sprite.getGlobalBounds();
}
const bool Object::isAlien() const{
    return Alien;
}
void Object::update(){
    this -> sprite.move(movementSpeed * sf::Vector2f(0.f, 1.f));
}
void Object::render(sf::RenderTarget *target){
    target->draw(this -> sprite);
}
