#include "Game.h"
void Game::initVariable(){
    //window variable
    this-> window = nullptr;

    //bullet variable
    this -> timeBetween2BulletsMax = 10.f;
    this -> timeBetween2Bullets = this -> timeBetween2BulletsMax;



    //Player's point
    this -> point = 0.f;

    //health
    this -> healthMax = 10.f;
    this -> curr_health = 10.f;

    this -> waitingBeginingTime = 200.f;
    this -> isClosed = false;



}
void Game::initPlayer(){
    this -> playerSpeed = 20.f;
    this -> player = new Player(this -> resources["player"], this -> playerSpeed);
    this -> player->setPos(sf::Vector2f(this -> window -> getSize(). x / 2.0 ,this -> window->getSize().y - this -> player->getBounds().height));

}

void Game::initbackground(){
    this -> background = new Background(this -> resources["background"]);
}

void Game::initTextures(){
    /*

    return void: store the textures' resource
        - "player": texture of class Player
        - "background": texture of class Player
        - "BULLET": texture of class Bullet
        - "alien", "rock1", "rock2", "rock3": textures of class enermy objects

    */
    this -> resources["player"] = new sf::Texture;
    this -> resources["player"]->loadFromFile("image/spaceship1.PNG");

    this -> resources["background"] = new sf::Texture;
    this -> resources["background"]->loadFromFile("image/background.jpg");

    this -> resources["BULLET"] = new sf::Texture;
    this -> resources["BULLET"]->loadFromFile("image/bullet.png");

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

    this -> resources["planet7"] = new sf::Texture;
    this -> resources["planet7"] -> loadFromFile("image/planet7.PNG");

    this -> resources["planet8"] = new sf::Texture;
    this -> resources["planet8"] -> loadFromFile("image/planet8.PNG");

    this -> resources["planet9"] = new sf::Texture;
    this -> resources["planet9"] -> loadFromFile("image/planet9.PNG");

}

void Game::initObjects(){

    /*
    return void:
        - set the interval betwween 2 times objeccs appear
        - save types of objects into a array to get random object appearing
    */

    this -> objectSpeed = 1.f;
    this -> level = 1.f;

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

    for(int i = 1; i <= 9; i++){
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
    this -> surround.setPosition(this -> window -> getSize().x - healthBarWidth - 4.f , 10.f);

    float percent = curr_health / healthMax;
    this -> fill.setSize(sf::Vector2f(percent * healthBarWidth, healthBarHeight));
    this -> fill.setPosition(surround.getPosition());
    this -> fill.setFillColor(sf::Color::Red);

}
void Game::initGameOver()
{
    this -> windowsize.x = this -> window->getSize().x;
    this -> windowsize.y = this -> window->getSize().y;
    this -> gameOver = new GameOver( windowsize);
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



}
Game::Game(sf::RenderWindow *target){

    this -> initVariable();
    this -> initTextures();
    this -> initSound();
    this -> window = target;
    this -> initPlayer();
    this -> initbackground();
    this -> initObjects();
    this -> initPlanet();
    this -> initFontsandText();
    this -> initHealthBar();
    this -> initGameOver();
    this -> initLoading();
}

Game::~Game(){
    delete player;
    delete background;
    for(auto i: this -> bullets){
        delete i;
    }

    for(auto i: this -> resources){
        delete i.second;
    }

    for(auto i: this -> objects){
        delete i;
    }
    delete gameOver;
    delete loading;
}
const bool Game::isRunning() const{
    return this->window->isOpen();
}
bool Game::Closed()
{
    return this -> isClosed;
}
int Game::choice()
{
    return gameOver -> choice();
}
bool Game::isCoolDown(){
    /*
    return void:
        - generate the cooldown time between 2 times bullets shooted
    */
    if(this -> timeBetween2Bullets >= this -> timeBetween2BulletsMax){
        this -> timeBetween2Bullets = 0.f;
        return true;
    }
    else timeBetween2Bullets += 0.5f;
    return false;
}
void Game::updateCollision(){
    /*
    return void
        - set the bound collisions of player that player can't go out of the window
    */

    if (this->player->getBounds().left < 0.f)
	{
		this->player->setPos(sf::Vector2f(0.f, this->player->getBounds().top));
	}
	else if (this->player->getBounds().left + this->player->getBounds().width >= this->window->getSize().x)
	{
		this->player->setPos(sf::Vector2f(this->window->getSize().x - this->player->getBounds().width, this->player->getBounds().top));
	}

    if(this -> player -> getBounds().top <= 0.f){
        this -> player -> setPos(sf::Vector2f( this -> player -> getBounds().left, 0.f));
    }
    else if(this -> player -> getBounds().top + this -> player -> getBounds().height >= this -> window -> getSize().y){
        this -> player -> setPos(sf::Vector2f(this -> player -> getBounds(). left, this -> window -> getSize().y - this -> player -> getBounds().height));
    }
}

void Game::pollEv(){
    /*
    return void: check input event to escape the game
        - Closed
        - KeyPressed: Escape
    */
    while(this->window->pollEvent(this -> ev)){
        if(ev.type == sf::Event::Closed){
            this -> window -> close();
            isClosed = true;
        }
        if(ev.sf::Event::KeyPressed && ev.key.code == sf::Keyboard::Escape){
            this -> window -> close();
            isClosed = true;

        }

    }

}

void Game::updateInput(){
    /*
    return void: enter the input from mouse or keyboard to control the player
        - move player using keypressed: up, down, left, right
        - shooting bullets by using keypressed: "A", after one press, shoot a bullet
    */

    //moving
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        this -> player->move(-0.1f, 0.f);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        this -> player->move(0.1f, 0.f);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        this -> player->move(0.f, -0.1f);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        this -> player->move(0.f, 0.1f);


    //Shooting
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A) && isCoolDown()){
        this -> bullets.push_back(new Bullet(this -> resources["BULLET"],
                                    this -> player -> getPos().x + this -> player -> getBounds().width / 2.f,
                                    this -> player -> getPos().y,
                                    5.f));
        this -> bulletShoot.play();

    }
}
void Game::updateObjectsSpeed()
{
    if(this -> point >= this -> level * 5000)
    {
        this -> objectSpeed += 0.5f;
        this -> level++;
    }
    if(this -> point >= level * 10000)
    {
        timeBetween2ObjectsMax -= 2.f;
    }
}
void Game::updateObjects(){
    /*
    return void:
        - generate random objects
        - update object: if object crash the bounders of the window or the player, the health is subtracted
    */
    this -> updateObjectsSpeed();
    if(this -> waitingBeginingTime < 0){
        int type = rand() % this -> objectTypes.size();
        if(this -> timeBetween2Objects >= this -> timeBetween2ObjectsMax){
            if(objectTypes[type] == "alien")
                this -> objects.push_back(new Object(this -> resources["alien"], rand() % this->window->getSize().x-20.f, -100.f, 0.5f, 0.5f, this -> objectSpeed, true));
            else
                this -> objects.push_back(new Object(this -> resources[objectTypes[type]], rand() % this->window->getSize().x-20.f, -100.f, 0.8f, 0.8f, this -> objectSpeed, false));
            this -> timeBetween2Objects = 0.f;
        }
        else timeBetween2Objects += 0.5f;



        int idx = 0;
        for(auto *i: this -> objects){
            i->updateSpeed(this -> objectSpeed);
            i->update();

            if(i->getBounds().top > this -> window->getSize().y){
                delete this -> objects.at(idx);
                this -> objects.erase(this -> objects.begin() + idx);
            }
            else if(i->getBounds().intersects(this -> player->getBounds())){
                delete this -> objects.at(idx);
                this -> objects.erase(this -> objects.begin() + idx);
                this -> curr_health -= 1.f;
            }
            idx++;
        }
    }
    else this -> waitingBeginingTime -= 1.f;
}
void Game::updatePlanet(){
    int type = rand() % planetTypes.size();
    if(this -> timeBetween2Planets >= this -> timeBetween2PlanetsMax){
        this -> planets.push_back(new Planet(this -> resources[planetTypes[type]], rand() % this->window->getSize().x-20.f, -100.f, 1.f));
        this -> timeBetween2Planets = 0.f;
    }
    else this -> timeBetween2Planets += 0.5f;

    int idx = 0;
    for(auto *i: this -> planets){
        i->update();

        if(i->getBounds().top > this -> window->getSize().y){
            delete this -> planets.at(idx);
            this -> planets.erase(this -> planets.begin() + idx);
        }
        else if(i->getBounds().intersects(this -> player->getBounds())){
            delete this -> planets.at(idx);
            this -> planets.erase(this -> planets.begin() + idx);
            this -> curr_health += 1.f;
            this -> curr_health = curr_health >= healthMax ? healthMax : curr_health;
        }
        idx++;
    }
}
void Game::updateCombats(){
    /*
    return void:
        - if a bullet crashed into an object, both object and bullet are disappear
        - if object is an alien's space, point add 200.f
        - if object is rock, point add 100.f
    */
    for(unsigned i = 0; i < this -> objects.size(); i++){
        for(unsigned j = 0; j < this -> bullets.size(); j++){
            if(this->objects[i]->getBounds().intersects(this->bullets[j]->getBounds())){
                delete this -> objects[i];
                this -> objects.erase(this -> objects.begin() + i);

                delete this -> bullets[j];
                this -> bullets.erase(this -> bullets.begin() + j);
                if(objects[i]->isAlien()) point += 200.f;
                else point += 100.f;
                this -> collision.play();
                break;

            }
        }
    }

    for(unsigned i = 0; i < this -> planets.size(); i++){
        for(unsigned j = 0; j < this -> bullets.size(); j++){
            if(this->planets[i]->getBounds().intersects(this->bullets[j]->getBounds())){
                delete this -> planets[i];
                this -> planets.erase(this -> planets.begin() + i);

                delete this -> bullets[j];
                this -> bullets.erase(this -> bullets.begin() + j);
                this -> curr_health -= 1.f;
                break;
            }
        }
    }
}
void Game::updateBullets(){
    /*
    return void:
        - if bullet crush the top of the window, the bullet disappear
    */
    int idx = 0;
    for(auto *i: this -> bullets){
        i->update();
        if(i ->getBounds().top + i -> getBounds().height <= 0.f){
            delete this -> bullets.at(idx);
            this -> bullets.erase(this -> bullets.begin() + idx);
        }
        else idx++;
    }

}
void Game::updateText(){
    std::stringstream ss;
    ss <<"Points: " << this -> point;
    this -> pointText.setString(ss.str());
    this -> pointText.setScale(1.5f, 1.5f);
}
void Game::updateHealthBar(){
    float percent = curr_health / healthMax;
    this -> fill.setSize(sf::Vector2f(percent * healthBarWidth, healthBarHeight));
    std::stringstream ss;
    ss << percent*100 <<'%';
    this -> health.setString(ss.str());
    this -> health.setPosition(this -> surround.getPosition().x - 100.f, this -> surround.getPosition().y - 10.f);
    this -> health.setScale(1.2f, 1.2f);
}
void Game::updateMousePos(){
    this->mousePosWindow = sf::Mouse::getPosition(*this->window);
	this->mousePosView = this->window->mapPixelToCoords(this->mousePosWindow);
}

void Game::updateFinalPoints()
{
    this -> gameOver -> update();
}
void Game::renderText(){
    this -> window->draw(pointText);
}
void Game::renderHealthBar(){
    this -> window -> draw(this -> surround);
    this -> window -> draw(this -> fill);
    this -> window -> draw(this -> health);
}
void Game::update(){
    this->pollEv();
    this -> player -> update();
    this -> updateCollision();
    this -> updateInput();
    this -> updateBullets();
    this -> updateObjects();
    this -> updatePlanet();
    this -> updateCombats();
    this -> updateText();
    this -> updateHealthBar();
}

void Game::render(){

    this -> window -> clear(sf::Color::Black);

    // render player
    this -> background -> render(this -> window);
    this -> player -> render(this -> window);

    for(auto *i: this -> bullets){
        i -> render(this -> window);
    }
    for(auto *i: this -> objects){
        i -> render(this -> window);
    }
    for(auto *i: this -> planets){
        i -> render(this -> window);
    }
    this -> renderText();
    this -> renderHealthBar();
    this -> window -> display();
}
void Game::renderFinalPoint()
{
    this -> window -> clear(sf::Color::Black);
    this -> background -> render(this -> window);
    this -> gameOver ->render(this -> window);
    this -> window -> display();
}
void Game::running(){
    while(this -> loading ->getNumber() <= 100)
    {
        this -> pollEv();
        this -> loading -> update(windowsize);
        this -> window -> clear(sf::Color::Black);
        this -> loading -> render(this -> window);
        this -> window -> display();
    }
    this -> bgk.play();
    while(this -> isRunning() && curr_health > 0.f){


        //update
        this -> update();

        //render
        this -> render();

    }
    this -> bgk.stop();
    //print the score
    this -> bgkGO.play();
    while(this -> isRunning() && curr_health <= 0.f)
    {
        this -> pollEv();
        this -> updateMousePos();
        this -> gameOver -> updatePoint(this -> point);
        this -> gameOver -> updateMousePos(this -> mousePosView);
        this -> updateFinalPoints();
        this -> renderFinalPoint();
        if(gameOver -> choice() != 0)
        {
            break;
        }
    }
    this -> bgkGO.stop();
}



