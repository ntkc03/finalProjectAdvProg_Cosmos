#include "background.h"

Background::Background(sf::Texture *texture){
    this -> sprite.setTexture(*texture);
    this -> sprite.setScale(1.5f, 1.5f);
    this -> sprite.setPosition(-10.f, -10.f);
}
Background::~Background(){

}
void Background::setSize(sf::Vector2f bkgSize){
    this -> sprite.setScale(bkgSize);
}
void Background::render(sf::RenderTarget *target){
    target->draw(sprite);
}
