#include "Player.h"

void Player::initVariable()
{
    this -> speedShip1= 15.f;
    this -> speedShip2 = 20.f;
    this -> speedShip3 = 25.f;
    this -> choice = 0;
}
void Player::initTexture()
{
    this -> ship1.loadFromFile("image/spaceship1.PNG");
    this -> ship2.loadFromFile("image/spaceship2.PNG");
    this -> ship3.loadFromFile("image/spaceship3.PNG");
}
void Player::initSprite()
{
    this -> sprite1.setTexture(this -> ship1);
    this -> sprite2.setTexture(this -> ship2);
    this -> sprite3.setTexture(this -> ship3);
}
void Player::initFontsandTexts()
{
    this -> font.loadFromFile("fonts/PixeBoy.ttf");
    this -> speedText1.setFont(this -> font);
    this -> speedText2.setFont(this -> font);
    this -> speedText3.setFont(this -> font);
}
Player::Player(){
    this -> initVariable();
    this -> initTexture();
    this -> initSprite();
    this -> initFontsandTexts();
}

Player::~Player(){

}


// Player in main Game
sf::Vector2f Player::getPos(){
    return this -> sprite.getPosition();
}
sf::FloatRect Player::getBounds(){
    return this -> sprite.getGlobalBounds();
}
void Player::setPos(const sf::Vector2f &pos){
    this -> sprite.setPosition(pos);
}
void Player::setChoice()
{
    if(this -> choice == 1)
    {
        this -> sprite.setTexture(this -> ship1);
        movementSpeed = speedShip1;
    }
    else if(this -> choice == 2)
    {
        sprite.setTexture(this -> ship2);
        movementSpeed = speedShip2;
    }
    else if(this -> choice == 3){
        sprite.setTexture(this -> ship3);
        movementSpeed = speedShip3;
    }
}
void Player::move(const float &X, const float &Y){
    sprite.move(this -> movementSpeed * X, this -> movementSpeed * Y);
}
void Player::update(){
    if(this -> choice != 0)
    {
        setChoice();
        this -> sprite.setScale(0.8f, 0.8f);
    }
}
void Player::render(sf::RenderTarget *target){
    target->draw(this -> sprite);
}

//Players in Hello
void Player::updateChoosePlayer(sf::RenderWindow *window)
{
    this -> setString();
    this -> setPosChoosePlayer(window);
}
void Player::getChoice(int choice_)
{
    this -> choice = choice_;
}
void Player::setString()
{
    std::stringstream ss1;
    ss1 << speedShip1 * 10 << "m/s";
    this -> speedText1.setString(ss1.str());

    std::stringstream ss2;
    ss2 << speedShip2 * 10 << "m/s";
    this -> speedText2.setString(ss2.str());

    std::stringstream ss3;
    ss3 << speedShip3 * 10 << "m/s";
    this -> speedText3.setString(ss3.str());
}
sf::FloatRect Player::getBounds(int choice)
{
    if(choice == 1) return this -> sprite1.getGlobalBounds();
    else if(choice == 2) return this -> sprite2.getGlobalBounds();
    else if(choice == 3) return this -> sprite3.getGlobalBounds();
}
sf::Vector2f Player::getPos(int choice)
{
    if(choice == 1) return this -> sprite1.getPosition();
    else if(choice == 2) return this -> sprite2.getPosition();
    else if(choice == 3) return this -> sprite3.getPosition();
}
void Player::setPosChoosePlayer(sf::RenderWindow *window)
{

    this -> sprite1.setPosition(100.f, window->getSize().y / 2.0 - 100.f);
    this -> sprite2.setPosition(this -> sprite1.getPosition().x + 300.f, sprite1.getPosition().y);
    this -> sprite3.setPosition(this -> sprite2.getPosition().x + 300.f, sprite2.getPosition().y);

    this -> speedText1.setPosition(this -> sprite1.getPosition().x + 30.f, this -> sprite1.getGlobalBounds().top + this -> sprite1.getGlobalBounds().height + 10.f);
    this -> speedText2.setPosition(this -> sprite2.getPosition().x + 40.f, this -> speedText1.getPosition().y);
    this -> speedText3.setPosition(this -> sprite3.getPosition().x + 30.f, this -> speedText1.getPosition().y);
}
void Player::renderChoosePlayer(sf::RenderTarget * target)
{
    target -> draw(this -> sprite1);
    target -> draw(this -> sprite2);
    target -> draw(this -> sprite3);

    target -> draw(this -> speedText1);
    target -> draw(this -> speedText2);
    target -> draw(this -> speedText3);
}


