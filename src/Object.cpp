#include "Object.h"

Object::Object(sf::Texture *texture, const sf::Vector2f &pos, const sf::Vector2f &Size, const float &speed, const bool &isAlien_){
    this -> movementSpeed = speed;
    this -> sprite.setTexture(*texture);
    this -> sprite.setPosition(pos);
    this -> sprite.setScale(Size);
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
void Object::updateSpeed(const float &laterSpeed)
{
   this ->  movementSpeed = laterSpeed;
}
void Object::update(){
    this -> sprite.move(movementSpeed * sf::Vector2f(0.f, 1.f));
}
void Object::render(sf::RenderTarget *target){
    target->draw(this -> sprite);
}
