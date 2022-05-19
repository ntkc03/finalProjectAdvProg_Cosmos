#ifndef ALIEN_H
#define ALIEN_H

#include "Object.h"
#include "Bullet.h"
#include <vector>
class Alien: public Object
{

    sf::Texture *bulletTexture;
    std::vector<Bullet *>bullets;
    sf::Vector2f bulletPos;
    float bulletSpeed;
    sf::CircleShape radarArea;
    float spawnTimer;
    float spawnTimerMax;
    float timeBetweenRadarRenderMax;
    float timeBetweenRadarRender;
    float radius;
    bool isShooted;
    int lostHeath;

public:
    Alien(sf::Texture *texture, const sf::Vector2f &pos, const sf::Vector2f &Size, const float &speed);
    virtual ~Alien();

    void setLostHealth();
    int lostHealths();

    void setRadarArea();

    void updateBullets();
    void updateCollision(sf::RenderWindow *window, sf::FloatRect playerBounds);
    void updateMove(const sf::Vector2f &playerPo);
    bool isInRadarArea(const sf::Vector2f &playerPo);
    void moveToThePlayer(const sf::Vector2f &playerPo);
    void renderBullets(sf::RenderWindow *window);
};

#endif // ALIEN_H
