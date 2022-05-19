#include "Object.h"

Object::Object(sf::Texture *texture, const sf::Vector2f &pos, const sf::Vector2f &Size, const float &speed){
    this -> movementSpeed = speed;
    this -> sprite.setTexture(*texture);
    this -> sprite.setPosition(pos);
    this -> sprite.setScale(Size);
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
void Object::updateSpeed(const float &laterSpeed)
{
   this ->  movementSpeed = laterSpeed;
}
void Object::update(const sf::Vector2f &direction){
    this -> sprite.move(movementSpeed * direction);
}
void Object::render(sf::RenderTarget *target){
    target->draw(this -> sprite);
}
