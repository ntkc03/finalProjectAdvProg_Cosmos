#include "Alien.h"

Alien::Alien(sf::Texture *texture, const sf::Vector2f &pos, const sf::Vector2f &Size,
        const float &speed):Object(texture,pos,Size,speed)
{

    bulletTexture = new sf::Texture;
    bulletTexture -> loadFromFile("image/alienBullet.PNG");
    bulletSpeed = 5.f;
    radius = 200.f;
    isShooted = false;
    this -> spawnTimerMax = 100.f;
    this -> spawnTimer = this -> spawnTimerMax;
    this -> timeBetweenRadarRenderMax = 2.f;
    this -> timeBetweenRadarRender = 0.f;
    lostHeath = 0;

}
Alien:: ~Alien()
{
    for(auto *i: bullets)
    {
        delete i;
    }
}
void Alien::setLostHealth()
{
    this -> lostHeath = 0;
}
int Alien::lostHealths()
{
    return this -> lostHeath;
}
void Alien::setRadarArea()
{

    this -> radarArea.setRadius(radius);
    this -> radarArea.setFillColor(sf::Color(0, 255, 0, 25));
    this -> radarArea.setPosition(getPos().x - radius/2, getPos().y - radius/2);
}
void Alien::updateBullets()
{
    if(isShooted)
    {
        if(spawnTimer >= spawnTimerMax)
        {
            bullets.push_back(new Bullet(bulletTexture, sf::Vector2f (getPos().x + 70.f, getPos().y + 70.f), sf::Vector2f(0.3f, 0.3f), bulletSpeed));
            spawnTimer = 0;
        }
        else spawnTimer += 1.f;

    }
}
void Alien::updateCollision(sf::RenderWindow *window, sf::FloatRect playerBounds)
{
    int idx = 0;
    for(auto *i: this -> bullets){
        i->update(sf::Vector2f(0.f, 1.f));
        if(i->getBounds().top > window->getSize().y){
            delete this -> bullets.at(idx);
            this -> bullets.erase(this -> bullets.begin() + idx);
        }
        else if(i->getBounds().intersects( playerBounds)){
            delete this -> bullets.at(idx);
            this -> bullets.erase(this -> bullets.begin() + idx);
            lostHeath += 1;
        }
        else idx++;
    }
}
void Alien::updateMove(const sf::Vector2f &playerPos)
{
    if(isInRadarArea(playerPos))
    {
        moveToThePlayer(playerPos);
    }
    radarArea.setPosition(getPos().x - radius/2, getPos().y - radius/2);


}
bool Alien::isInRadarArea(const sf::Vector2f &playerPos)
{
    if(radarArea.getGlobalBounds().contains(playerPos))

    {
        isShooted = true;
        return true;
    }
    else isShooted = false;
    return false;
}
void Alien::moveToThePlayer(const sf::Vector2f &playerPos)
{
    if(playerPos.x > getPos().x)
        update(sf::Vector2f(1.f, 0.f));
    else if(playerPos.x < getPos().x)
        update(sf::Vector2f(-1.f, 0.f));
}
void Alien::renderBullets(sf::RenderWindow *window)
{
    if(isShooted)
    {
        for(auto *i: bullets)
        {
            i -> render(window);
        }
    }
    if(timeBetweenRadarRender < timeBetweenRadarRenderMax)
    {
        window ->draw(radarArea);
        timeBetweenRadarRender += 1.f;
    }else timeBetweenRadarRender = 0.f;
}
