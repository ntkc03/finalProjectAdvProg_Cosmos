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
    this -> ship1Sprite.setTexture(this -> ship1);
    this -> ship2Sprite.setTexture(this -> ship2);
    this -> ship3Sprite.setTexture(this -> ship3);
}
void Player::initFont()
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
    this -> initFont();
}

Player::~Player(){

}


// Player in main Game
sf::Vector2f Player::getPos(){
    return this -> playerSprite.getPosition();
}
sf::FloatRect Player::getBounds(){
    return this -> playerSprite.getGlobalBounds();
}
void Player::setPos(const sf::Vector2f &pos){
    this -> playerSprite.setPosition(pos);
}
void Player::setPlayer(){
    if(this -> choice != 0)
    {
        setChoice();
        this -> playerSprite.setScale(0.8f, 0.8f);
    }
}
void Player::setChoice()
{
    if(this -> choice == 1)
    {
        this -> playerSprite.setTexture(this -> ship1);
        movementSpeed = speedShip1;
    }
    else if(this -> choice == 2)
    {
        playerSprite.setTexture(this -> ship2);
        movementSpeed = speedShip2;
    }
    else if(this -> choice == 3){
        playerSprite.setTexture(this -> ship3);
        movementSpeed = speedShip3;
    }
}
void Player::move(const sf::Vector2f &offset){
    playerSprite.move(this -> movementSpeed * offset);
}

void Player::render(sf::RenderTarget *target){
    target->draw(this -> playerSprite);
}

//Players in Hello
void Player::updateChoosePlayer(sf::RenderWindow *window)
{
    this -> setString();
    this -> setPosChoosePlayer(window);
}
void Player::getChoice(const int &choice_)
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
sf::FloatRect Player::getBounds(const int &choice)
{
    if(choice == 1) return this -> ship1Sprite.getGlobalBounds();
    else if(choice == 2) return this -> ship2Sprite.getGlobalBounds();
    else if(choice == 3) return this -> ship3Sprite.getGlobalBounds();
}
sf::Vector2f Player::getPos(const int &choice)
{
    if(choice == 1) return this -> ship1Sprite.getPosition();
    else if(choice == 2) return this -> ship2Sprite.getPosition();
    else if(choice == 3) return this -> ship3Sprite.getPosition();
}
void Player::setPosChoosePlayer(sf::RenderWindow *window)
{

    this -> ship1Sprite.setPosition(100.f, window->getSize().y / 2.0 - 100.f);
    this -> ship2Sprite.setPosition(this -> ship1Sprite.getPosition().x + 300.f, ship1Sprite.getPosition().y);
    this -> ship3Sprite.setPosition(this -> ship2Sprite.getPosition().x + 300.f, ship2Sprite.getPosition().y);

    this -> speedText1.setPosition(this -> ship1Sprite.getPosition().x + 30.f,
                                   this -> ship1Sprite.getGlobalBounds().top + this -> ship1Sprite.getGlobalBounds().height + 10.f);
    this -> speedText2.setPosition(this -> ship2Sprite.getPosition().x + 40.f, this -> speedText1.getPosition().y);
    this -> speedText3.setPosition(this -> ship3Sprite.getPosition().x + 30.f, this -> speedText1.getPosition().y);
}
void Player::renderChoosePlayer(sf::RenderTarget * target)
{
    target -> draw(this -> ship1Sprite);
    target -> draw(this -> ship2Sprite);
    target -> draw(this -> ship3Sprite);

    target -> draw(this -> speedText1);
    target -> draw(this -> speedText2);
    target -> draw(this -> speedText3);
}


