#include "Game.h"

void Game::initVariable(){
    //bullet variable
    this -> timeBetween2BulletsMax = 200.f;
    this -> timeBetween2Bullets = 0.f;
    this -> timeBetween2ShootsMax = 10.f;
    this -> timeBetween2Shoot = this -> timeBetween2ShootsMax;
    //Player's point
    this -> point = 0.f;

    //health
    this -> healthMax = 10.f;
    this -> curr_health = 10.f;

    this -> waitingBeginingTime = 200.f;
    this -> isClosed = false;

    this -> pause = new Pause;
    this -> isShooted = false;
    this -> isEndTimer = true;
}
void Game::initPlayer(const int &playerChoice){
    this -> playerSpeed = 20.f;
    this -> player = new Player;
    player -> getChoice(playerChoice);
}

void Game::initbackground(){
    this -> background = new Background;
}

void Game::initTextures(){
    /*

    return void: store the textures' resource
        - "background": texture of class Player
        - "BULLET": texture of class Bullet
        - "alien", "rock1", "rock2", "rock3": textures of class enermy objects
    */

    this -> resources["BULLET"] = new sf::Texture;
    this -> resources["BULLET"]->loadFromFile("image/bullet.png");

    this -> resources["lazer"] = new sf::Texture;
    this -> resources["lazer"]-> loadFromFile("image/lazer.PNG");

    this -> resources["alien"] = new sf::Texture;
    this -> resources["alien"]->loadFromFile("image/alien.png");

    this -> resources["Rock1"] = new sf::Texture;
    this -> resources["Rock1"] -> loadFromFile("image/rock1.PNG");

    this -> resources["Rock2"] = new sf::Texture;
    this -> resources["Rock2"] -> loadFromFile("image/rock2.PNG");

    this -> resources["Rock3"] = new sf::Texture;
    this -> resources["Rock3"] -> loadFromFile("image/rock3.PNG");

    this -> resources["Rock4"] = new sf::Texture;
    this -> resources["Rock4"] -> loadFromFile("image/rock4.PNG");

    this -> resources["planet1"] = new sf::Texture;
    this -> resources["planet1"] -> loadFromFile("image/planet1.PNG");

    this -> resources["planet2"] = new sf::Texture;
    this -> resources["planet2"] -> loadFromFile("image/planet2.PNG");

    this -> resources["planet3"] = new sf::Texture;
    this -> resources["planet3"] -> loadFromFile("image/planet3.PNG");

    this -> resources["planet4"] = new sf::Texture;
    this -> resources["planet4"] -> loadFromFile("image/planet4.PNG");

    this -> resources["planet5"] = new sf::Texture;
    this -> resources["planet5"] -> loadFromFile("image/planet5.PNG");

    this -> resources["planet6"] = new sf::Texture;
    this -> resources["planet6"] -> loadFromFile("image/planet6.PNG");

    this -> resources["boom1"] = new sf::Texture;
    this -> resources["boom1"] -> loadFromFile("image/boom1.PNG");

    this -> resources["boom2"] = new sf::Texture;
    this -> resources["boom2"] -> loadFromFile("image/boom2.PNG");

    this -> resources["boom3"] = new sf::Texture;
    this -> resources["boom3"] -> loadFromFile("image/boom3.PNG");

    this -> resources["boom4"] = new sf::Texture;
    this -> resources["boom4"] -> loadFromFile("image/boom4.PNG");

    this -> resources["boom5"] = new sf::Texture;
    this -> resources["boom5"] -> loadFromFile("image/boom5.PNG");

}

void Game::initObjects(){

    /*
    return void:
        - set the speed
        - set the text when speeding up
        - set the interval betwween 2 times objeccs appear
        - save types of objects into a array to get random object appearing
    */

    this -> objectSpeed = 1.f;
    this -> level = 1.f;

    //speeding up text
    this -> fontSpeed.loadFromFile("fonts/Pixeboy.ttf");
    this -> speedup.setFont(this -> fontSpeed);
    this -> speedup.setString("Speed up");
    this -> speedup.setScale(3.f, 3.f);
    this -> speedup.setColor(sf::Color::Red);
    this -> timeTextLast = 0.f;


    this -> timeBetween2ObjectsMax = 20.f;
    this -> timeBetween2Objects = this -> timeBetween2ObjectsMax;

    //enum the objects' type
    this -> objectTypes.push_back("alien");
    this -> objectTypes.push_back("Rock1");
    this -> objectTypes.push_back("Rock2");
    this -> objectTypes.push_back("Rock3");
    this -> objectTypes.push_back("Rock4");
}
void Game::initPlanet(){
    /*
    return void:
        -set the interval between 2 planet appear
        -save type of planets
    */
    this -> timeBetween2PlanetsMax = 200.f;
    this -> timeBetween2Planets = 0.f;

    for(int i = 1; i <= 6; i++){
        std::string name = "planet";
        name.push_back(i + '0');
        planetTypes.push_back(name);
    }
}
void Game::initFontsandText(){
    /*
    return void:
        Args:
            - pointFont & pointText: font and text to show player's point
    */
    this -> pointFont.loadFromFile("fonts/ConnectionIi.otf");
    this -> pointText.setFont(pointFont);
    this -> health.setFont(pointFont);


}
void Game::initHealthBar(){
    /*
    return void: Create a health bar
        Args:   - surround: the border of the full health bar
                - fill: the percentage of health remaining
    */
    this -> surround.setSize(sf::Vector2f(healthBarWidth, healthBarHeight));
    this -> surround.setOutlineThickness(1.f);
    this -> surround.setOutlineColor(sf::Color::Black);


    float percent = curr_health / healthMax;
    this -> fill.setSize(sf::Vector2f(percent * healthBarWidth, healthBarHeight));
    this -> fill.setFillColor(sf::Color::Red);

}
void Game::initGameOver()
{
    this -> gameOver = new GameOver;
}
void Game::initLoading()
{
    this -> loading = new Loading();
}
void Game::initSound()
{
    //collision
    this -> collisionBuf.loadFromFile("audio/collision.wav");
    this -> collision.setBuffer(this -> collisionBuf);

    //bullet
    this -> bulletShootBuffer.loadFromFile("audio/bulletShoot.wav");
    this -> bulletShoot.setBuffer(this -> bulletShootBuffer);

    this -> bgkBuf.loadFromFile("audio/bgkmusicGame.wav");
    this -> bgk.setBuffer(this -> bgkBuf);
    this -> bgk.setLoop(true);

    this -> bgkGOBuf.loadFromFile("audio/bgkmusicGO.wav");
    this -> bgkGO.setBuffer(this -> bgkGOBuf);
    this -> bgkGO.setLoop(true);

    this -> earnHealBuf.loadFromFile("audio/ting.wav");
    this -> earnHeal.setBuffer(this -> earnHealBuf);

    this -> loseHealBuf.loadFromFile("audio/loseHeal.wav");
    this -> loseHeal.setBuffer(this -> loseHealBuf);

    this -> clockBuff.loadFromFile("audio/clock.wav");
    this -> clockSound.setBuffer(this -> clockBuff);
    this -> clockSound.setLoop(true);




}
void Game::initBoom()
{
    for(unsigned i = 1; i <= 5; i++)
    {
        std::string str = "boom";
        str.push_back(i + '0');
        booms.push_back(new Boom(resources[str]));
    }
    this -> boomSpawnTimerMax = 5.f;
    this -> boomSpawnTimer = 0.f;
    this -> isBoom = false;
    this -> frame = 0;
}
void Game::initShootedArea()
{
    this -> radius = 150.f;
    this -> shootedArea.setRadius(this -> radius);
    this -> shootedArea.setFillColor(sf::Color(255, 255, 255, 0));
}
void Game::initClock()
{
    this -> clockText.loadFromFile("image/clock.PNG");
    this -> clock.setTexture(this -> clockText);
    this -> clock.setScale(0.5f, 0.5f);
}
