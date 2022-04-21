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
#include "Planet.h"
#include "GameOver.h"
#include "Loading.h"

class Game{
private:
    // Create window
    sf::RenderWindow *window;


    //Player
    Player *player;
    float playerSpeed;


    //Health
    float curr_health;
    float healthMax;
    sf::RectangleShape surround;
    sf::RectangleShape fill;
    const float healthBarHeight = 30.f;
    const float healthBarWidth = 300.f;
    sf::Text health;


    //Points
    float point;
    sf::Font pointFont;
    sf::Text pointText;

    //Background
    Background *background;
	sf::SoundBuffer bgkBuf;
    sf::Sound bgk;

    //Object
    std::vector<Object *>objects;
    float objectSpeed;
    float level;

    //Resources
    std::map<std::string, sf::Texture*> resources;
    std::vector<std::string> objectTypes;
    std::vector<std::string> planetTypes;
    std::vector<Planet *> planets;

    //spawn Timer;
    float timeBetween2ObjectsMax;
    float timeBetween2Objects;

    //Bullet CoolDown
    float timeBetween2Bullets;
    float timeBetween2BulletsMax;

    // planet
    float timeBetween2Planets;
    float timeBetween2PlanetsMax;

    //Bullet
    std::vector<Bullet *> bullets;
    sf::SoundBuffer bulletShootBuffer;
    sf::Sound bulletShoot;


    //collision
    sf::SoundBuffer collisionBuf;
    sf::Sound collision;

    //Event
    sf::Event ev;


    //game over
    GameOver *gameOver;
    sf::SoundBuffer bgkGOBuf;
    sf::Sound bgkGO;

    float waitingBeginingTime;
    bool isClosed;

    sf::Vector2i mousePosWindow;
	sf::Vector2f mousePosView;

	sf::Vector2f windowsize;

	//loading
	Loading *loading;

    //Private functions
    void initVariable();
    void initTextures();
    void initPlayer();
    void initbackground();
    void initObjects();
    void initPlanet();
    void initFontsandText();
    void initHealthBar();
    void initGameOver();
    void initLoading();
    void initSound();
public:
    //Constructor & Destructor
    Game(sf::RenderWindow *target);
    virtual ~Game();

    //check running
    const bool isRunning() const;
    bool Closed();
    int choice();
    bool isCoolDown();
    void updateCollision();

    //update

    void update();
    void pollEv();
    void updateBullets();
    void updateObjects();
    void updateObjectsSpeed();
    void updatePlanet();
    void updateCombats();
    void updateHealthBar();
    void updateInput();
    void updateText();
    void updateMousePos();
    void updateFinalPoints();
    //render

    void render();
    void renderText();
    void renderHealthBar();
    void renderFinalPoint();

    void running();


};
#endif // GAME_H
