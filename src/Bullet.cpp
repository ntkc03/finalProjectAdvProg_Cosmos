#include "Bullet.h"


Bullet::Bullet(sf::Texture *texture,const sf::Vector2f &pos,const sf::Vector2f &scale, const int &movementSpeed_){
    this -> sprite.setTexture(*texture);
    this -> sprite.setPosition(pos);
    this -> sprite.setScale(scale);
    this -> movementSpeed = movementSpeed_;
}
Bullet::~Bullet(){

}

const sf::FloatRect Bullet::getBounds(){
    return this -> sprite.getGlobalBounds();
}
void Bullet::update(const sf::Vector2f &direction ){
    this -> sprite.move(direction * movementSpeed);
}
void Bullet::render(sf::RenderTarget *target){
    target -> draw(this -> sprite);
}
