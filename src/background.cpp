#include "background.h"

Background::Background(sf::Texture *texture){
    this -> sprite.setTexture(*texture);
}
Background::~Background(){

}
void Background::render(sf::RenderTarget *target){
    target->draw(sprite);
}
