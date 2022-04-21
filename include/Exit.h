#ifndef EXIT_H
#define EXIT_H

#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Exit
{
private:

    sf::RenderWindow *window;

    sf::Text question;
    sf::Text choice1;
    sf::Text choice2;
    sf::Font font;

    void initFontsandTexts();
public:

    Exit();
    Exit(sf::RenderWindow *target);
    virtual ~Exit();
    void update();
    void updateTexts();
    void setString();
    void setColor();
    void setScale();
    void setPos();
    void render();
    void running();
};

#endif // EXIT_H
