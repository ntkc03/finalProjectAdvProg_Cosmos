#include "Object.h"

Object::Object(sf::Texture *texture, float posX, float posY, float sizeX, float sizeY,float speed, bool isAlien_){
    this -> movementSpeed = speed;
    this -> sprite.setTexture(*texture);
    this -> sprite.setPosition(posX, posY);
    this -> sprite.setScale(sizeX, sizeY);
    this -> Alien = isAlien_;
}
Object::~Object(){

}
sf::Vector2f Object::getPos()
{
    return this -> sprite.getPosition();
}
sf::FloatRect Object::getBounds(){
    return this -> sprite.getGlobalBounds();
}
const bool Object::isAlien() const{
    return Alien;
}
void Object::updateSpeed(float laterSpeed)
{
   this ->  movementSpeed = laterSpeed;
}
void Object::update(){
    this -> sprite.move(movementSpeed * sf::Vector2f(0.f, 1.f));
}
void Object::render(sf::RenderTarget *target){
    target->draw(this -> sprite);
}
