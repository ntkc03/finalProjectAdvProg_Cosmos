#include "Loading.h"

void Loading::initVariable()
{
    this -> font.loadFromFile("fonts/ConnectionIi.otf");
    this -> num = 0.f;
    this -> spawnTimerMax = 10.f;
    this -> spawnTimer = this -> spawnTimerMax;
}

Loading::Loading()
{
    this -> initVariable();
}
Loading:: ~Loading()
{

}
float Loading::getNumber()
{
    return num;
}
void Loading::updateTexts(sf::Vector2f windowsize)
{
    this -> setFont();
    this -> setString();
    this -> setScale();
    this -> setColor();
    this -> setPos(windowsize);
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
void Loading::setPos(sf::Vector2f windowsize)
{
    this -> loading.setPosition(windowsize.x / 2 - 100.f, windowsize.y / 2 - 100.f);
    this -> number.setPosition(this -> loading.getPosition().x + 80.f, this -> loading.getPosition().y + 80.f);
}
void Loading::update(sf::Vector2f windowsize)
{
    if(spawnTimer > spawnTimerMax)
    {
        this -> updateTexts(windowsize);
        num += 5.f;
        this -> spawnTimer = 0.f;
    }
    else spawnTimer += 1.f;

}
void Loading::render(sf::RenderTarget *target){
    target -> draw(this -> loading);
    target -> draw(this -> number);
}
