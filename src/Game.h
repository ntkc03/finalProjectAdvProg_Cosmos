#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <sstream>
#include <vector>
#include <map>

#include "Player.h"
#include "background.h"
#include "Object.h"
#include "Bullet.h"
class Game{
private:
    // Create window
    sf::RenderWindow *window;
    sf::VideoMode windowSize;

    //Player
    Player *player;

    //Health
    float curr_health;
    float healthMax;
    sf::RectangleShape surround;
    sf::RectangleShape fill;
    const float healthBarHeight = 20.f;
    const float healthBarWidth = 200.f;


    //Points
    float point;
    sf::Font pointFont;
    sf::Text pointText;

    //Background
    Background *background;

    //Object
    std::vector<Object *>objects;
    float objectNum;
    float objectNumsMax;

    //Resources
    std::map<std::string, sf::Texture*> resources;
    std::vector<std::string> objectTypes;

    //spawn Timer;
    float timeBetween2ObjectsMax;
    float timeBetween2Objects;

    //Bullet CoolDown
    float timeBetween2Bullets;
    float timeBetween2BulletsMax;

    //Bullet
    std::vector<Bullet *> bullets;

    //Event
    sf::Event ev;

    //Private functions
    void initVariable();
    void initWindow();
    void initTextures();
    void initPlayer();
    void initbackground();
    void initObjects();
    void initFontsandText();
    void initHealthBar();
public:
    //Constructor & Destructor
    Game();
    virtual ~Game();

    //check running
    const bool isRunning() const;

    bool isCoolDown();
    void updateCollision();

    //update
    void update();
    void pollEv();
    void updateBullets();
    void updateObjects();
    void updateCombats();
    void updateHealthBar();
    void updateInput();
    void updateText();

    //render
    void render();
    void renderText();
    void renderHealthBar();

    void running();
};
#endif // GAME_H
