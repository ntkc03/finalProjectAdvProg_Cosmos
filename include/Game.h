#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <sstream>
#include <vector>
#include <map>
#include <string>



#include "Player.h"
#include "background.h"
#include "Object.h"
#include "Bullet.h"
#include "Planet.h"
#include "GameOver.h"
#include "Loading.h"
#include "Boom.h"

class Game{
private:

    sf::Vector2f windowsize;

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
    sf::SoundBuffer earnHealBuf;
    sf::Sound earnHeal;
    sf::SoundBuffer loseHealBuf;
    sf::Sound loseHeal;

    //Points
    float point;
    sf::Font pointFont;
    sf::Text pointText;

    //Background
    Background *background;
	sf::SoundBuffer bgkBuf;
    sf::Sound bgk;

    //Object
    std::vector<std::string> objectTypes;
    std::vector<Object *>objects;
    float objectSpeed;
    float level;
    sf::Text speedup;
    sf::Font fontSpeed;
    float timeTextLast;

    //Resources
    std::map<std::string, sf::Texture*> resources;

    //Planet
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

    //input
    sf::Vector2i mousePosWindow;
	sf::Vector2f mousePosView;

	//boom
	std::vector<Boom *> booms;
	float boomSpawnTimer;
	float boomSpawnTimerMax;
	float frame;
	bool isBoom;
	sf::Vector2f currBoomPos;

    //game over
    GameOver *gameOver;
    sf::SoundBuffer bgkGOBuf;
    sf::Sound bgkGO;

    float waitingBeginingTime;
    bool isClosed;

	//loading
	Loading *loading;

    //Private functions
    void initVariable();
    void initTextures();
    void initPlayer(const int &playerChoice);
    void initbackground();
    void initObjects();
    void initPlanet();
    void initFontsandText();
    void initHealthBar();
    void initGameOver();
    void initLoading();
    void initSound();
    void initBoom();
public:
    //Constructor & Destructor
    Game(const int &playerChoice);
    virtual ~Game();

    void running(sf::RenderWindow *window);

    //main Game
    void runMainGame(sf::RenderWindow *window);

    //check running
    const bool isRunning(sf::RenderWindow *window) const;
    bool Closed();
    int choice();
    bool isCoolDown();

    //set origin position
    void setOriginPos(sf::RenderWindow *window);
    void getWindowSize(sf::RenderWindow *window);

    //update
    void update(sf::RenderWindow *window);
    void pollEv(sf::RenderWindow *window);
    void updateCollision(sf::RenderWindow *window);
    void updateInput();
    void updateBullets();
    void updateObjects(sf::RenderWindow *window);
    void updateObjectsSpeed();
    void updatePlanet(sf::RenderWindow *window);
    void updateCombats();
    void updateText();
    void updateHealthBar();
    void updateMousePos(sf::RenderWindow *window);
    //render
    void render(sf::RenderWindow *window);
    void renderText(sf::RenderWindow *window);
    void renderHealthBar(sf::RenderWindow *window);
    void renderBoom(sf::RenderWindow *window);

    //loading
    void runLoad(sf::RenderWindow *window);

    //Game over
    void runGameOver(sf::RenderWindow *window);
    void updateFinalPoints();
    void renderFinalPoint(sf::RenderWindow *window);
};
#endif // GAME_H
