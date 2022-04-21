#include "Player.h"

Player::Player(sf::Texture *texture, float movementSpeed_){
    this -> movementSpeed = movementSpeed_;
    this -> sprite.setTexture(*texture);
    this -> sprite.setScale(0.8f, 0.8f);

}
Player::~Player(){

}
sf::Vector2f Player::getPos(){
    return this -> sprite.getPosition();
}
sf::FloatRect Player::getBounds(){
    return this -> sprite.getGlobalBounds();
}
void Player::setPos(const sf::Vector2f &pos){
    this -> sprite.setPosition(pos);
}
void Player::move(const float &X, const float &Y){
    sprite.move(this -> movementSpeed * X, this -> movementSpeed * Y);
}
void Player::update(){

}
void Player::render(sf::RenderTarget *target){
    target->draw(this -> sprite);
}
