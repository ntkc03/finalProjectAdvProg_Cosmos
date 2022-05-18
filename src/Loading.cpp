#include "Loading.h"

void Loading::initVariable()
{

    this -> num = 0.f;
    this -> spawnTimerMax = 10.f;
    this -> spawnTimer = this -> spawnTimerMax;
}
void Loading::initFont()
{
    this -> font.loadFromFile("fonts/ConnectionIi.otf");
}
Loading::Loading()
{
    this -> initVariable();
    this -> initFont();
}
Loading:: ~Loading()
{

}
float Loading::getNumber()
{
    return num;
}
void Loading::update(const sf::Vector2f &windowSize)
{
    if(spawnTimer > spawnTimerMax)
    {
        this -> updateTexts(windowSize);
        num += 5.f;
        this -> spawnTimer = 0.f;
    }
    else spawnTimer += 1.f;

}
void Loading::updateTexts(const sf::Vector2f &windowSize)
{
    this -> setFont();
    this -> setString();
    this -> setScale();
    this -> setColor();
    this -> setPos(windowSize);
}
void Loading::setFont()
{
    this -> loading.setFont(this -> font);
    this -> number.setFont(this -> font);
}
void Loading::setString()
{
    this -> loading.setString("Loading...");
    std::stringstream ss;
    ss << num << "%";
    this -> number.setString(ss.str());
}
void Loading::setScale()
{
    this -> loading.setScale(2.f, 2.f);
    this -> number.setScale(1.5f, 1.5f);
}
void Loading::setColor()
{
    this -> loading.setColor(sf::Color::White);
    this -> number.setColor(sf::Color::White);
}
void Loading::setPos(const sf::Vector2f &windowSize)
{
    this -> loading.setPosition(sf::Vector2f(windowSize.x / 2 - 100.f, windowSize.y / 2 - 100.f));
    this -> number.setPosition(sf::Vector2f(this -> loading.getPosition().x + 80.f, this -> loading.getPosition().y + 80.f));
}

void Loading::render(sf::RenderTarget *target){
    target -> draw(this -> loading);
    target -> draw(this -> number);
}
