#include "Bullet.h"


Bullet::Bullet(sf::Texture *texture, float posX, float posY, float scaleX, float scaleY, int movementSpeed_){
    this -> sprite.setTexture(*texture);
    this -> sprite.setPosition(posX, posY);
    this -> sprite.setScale(scaleX, scaleY);
    this -> movementSpeed = movementSpeed_;
}
Bullet::~Bullet(){

}

const sf::FloatRect Bullet::getBounds(){
    return this -> sprite.getGlobalBounds();
}
void Bullet::update(){
    this -> sprite.move(sf::Vector2f(0.f, -1.f) * movementSpeed);
}
void Bullet::render(sf::RenderTarget *target){
    target -> draw(this -> sprite);
}
