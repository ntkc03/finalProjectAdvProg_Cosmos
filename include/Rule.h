#ifndef RULE_H
#define RULE_H

#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Rule
{
private:
    sf::Text title;
public:
    Rule();
    virtual ~Rule();
};

#endif // RULE_H
