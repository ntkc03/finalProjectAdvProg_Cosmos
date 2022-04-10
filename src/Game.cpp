#include "Game.h"
void Game::initVariable(){
    //window variable
    this-> window = nullptr;

    //bullet variable
    this -> timeBetween2BulletsMax = 10.f;
    this -> timeBetween2Bullets = this -> timeBetween2BulletsMax;

    //object variable
    this -> objectNumsMax = 30.f;
    this -> objectNum = 0.f;


    //Player's point
    this -> point = 0.f;

    //health
    this -> healthMax = 5.f;
    this -> curr_health = 5.f;

}
void Game::initWindow(){
    // initualize a complete window

    this -> windowSize.width = 1000;
    this -> windowSize.height = 650;
    this -> window = new sf::RenderWindow(this->windowSize, "COSMOS", sf::Style::Default);

    //make window more smooth
    this -> window->setFramerateLimit(144);
    this -> window->setVerticalSyncEnabled(false);
}
void Game::initPlayer(){
    this -> player = new Player(this -> resources["player"]);
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
    this -> resources["player"]->loadFromFile("image/ship.png");

    this -> resources["background"] = new sf::Texture;
    this -> resources["background"]->loadFromFile("image/background.png");

    this -> resources["BULLET"] = new sf::Texture;
    this -> resources["BULLET"]->loadFromFile("image/bullet.png");

    this -> resources["alien"] = new sf::Texture;
    this -> resources["alien"]->loadFromFile("image/alien.png");

    this -> resources["Rock1"] = new sf::Texture;
    this -> resources["Rock1"] -> loadFromFile("image/rock1.png");

    this -> resources["Rock2"] = new sf::Texture;
    this -> resources["Rock2"] -> loadFromFile("image/rock2.png");

    this -> resources["Rock3"] = new sf::Texture;
    this -> resources["Rock3"] -> loadFromFile("image/rock3.png");

}

void Game::initObjects(){

    /*
    return void:
        - set the interval betwween 2 times objeccs appear
        - save types of objects into a array to get random object appearing
    */

    this -> timeBetween2ObjectsMax = 20.f;
    this -> timeBetween2Objects = this -> timeBetween2ObjectsMax;

    //enum the objects' type
    this -> objectTypes.push_back("alien");
    this -> objectTypes.push_back("Rock1");
    this -> objectTypes.push_back("Rock2");
    this -> objectTypes.push_back("Rock3");

}

void Game::initFontsandText(){
    /*
    return void:
        Args:
            - pointFont & pointText: font and text to show player's point
    */
    this -> pointFont.loadFromFile("fonts/VHBAHAB.TTF");
    this -> pointText.setFont(pointFont);

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

Game::Game(){

    this -> initVariable();
    this -> initWindow();
    this -> initTextures();
    this -> initPlayer();
    this -> initbackground();
    this -> initObjects();
    this -> initFontsandText();
    this -> initHealthBar();
}

Game::~Game(){
    delete window;
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
}
const bool Game::isRunning() const{
    return this->window->isOpen();
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
                this->window->close();
        }
        if(ev.sf::Event::KeyPressed && ev.key.code == sf::Keyboard::Escape){
            this -> window -> close();
        }
        if(this -> curr_health == 0.f){
            this -> window->close();
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
    }
}
void Game::updateObjects(){
    /*
    return void:
        - generate random objects
        - update object: if object crash the bounders of the window or the player, the health is subtracted
    */
    int type = rand() % this -> objectTypes.size();
    if(this -> timeBetween2Objects >= this -> timeBetween2ObjectsMax){
        if(objectTypes[type] == "alien")
            this -> objects.push_back(new Object(this -> resources["alien"], rand() % this->window->getSize().x-20.f, -100.f, 0.2f, 0.2f, true));
        else
            this -> objects.push_back(new Object(this -> resources[objectTypes[type]], rand() % this->window->getSize().x-20.f, -100.f, 0.5f, 0.5f, false));
        this -> timeBetween2Objects = 0.f;
        this -> objectNum += 1.f;
    }
    else timeBetween2Objects += 0.5f;



    int idx = 0;
    for(auto *i: this -> objects){
        i->update();

        if(i->getBounds().top > this -> window->getSize().y){
            delete this -> objects.at(idx);
            this -> objects.erase(this -> objects.begin() + idx);
            objectNum -= 1.f;
        }
        else if(i->getBounds().intersects(this -> player->getBounds())){
            delete this -> objects.at(idx);
            this -> objects.erase(this -> objects.begin() + idx);
            objectNum -= 1.f;
            this -> curr_health -= 1.f;
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
                objectNum -= 1.f;

                delete this -> bullets[j];
                this -> bullets.erase(this -> bullets.begin() + j);
                if(objects[i]->isAlien()) point += 200.f;
                else point += 100.f;
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
}
void Game::updateHealthBar(){
    float percent = curr_health / healthMax;
    this -> fill.setSize(sf::Vector2f(percent * healthBarWidth, healthBarHeight));
}
void Game::renderText(){
    this -> window->draw(pointText);
}
void Game::renderHealthBar(){
    this -> window -> draw(this -> surround);
    this -> window -> draw(this -> fill);
}
void Game::update(){
    this->pollEv();
    this -> player -> update();
    this -> updateCollision();
    this -> updateInput();
    this -> updateBullets();
    this -> updateObjects();
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
    this -> renderText();
    this -> renderHealthBar();
    this -> window -> display();
}

void Game::running(){
    while(this -> isRunning()){

        //update
        this -> update();

        //render
        this -> render();
    }
}
