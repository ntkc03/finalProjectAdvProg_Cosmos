#ifndef STAR_H
#define STAR_H

#include <SFML/Graphics.hpp>
#include <random>
class Star
{
private:
    sf::CircleShape circle;
    float movementSpeed = 1.f;
public:
    Star(float radius);
    virtual ~Star();

    void setFirstPos(const sf::Vector2f &pos);
    void circleMove(const sf::Vector2f &offset);
    sf::Color randomColor();
    void setRandomColor();
    void render(sf::RenderWindow *window);
};

#endif // STAR_H
