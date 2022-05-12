#include"Game.h"

//main game
const bool Game::isRunning(sf::RenderWindow *window) const{
    return window->isOpen();
}

bool Game::isCoolDown(){
    /*
    return void:
        - generate the cooldown time between 2 times shooted
    */
    if(this -> timeBetween2Shoot >= this -> timeBetween2ShootsMax){
        this -> timeBetween2Shoot = 0.f;
        return true;
    }
    else timeBetween2Shoot += 0.5f;
    return false;
}
void Game::CoolDownBullets(){
    /*
    @return void:
        - minium time between 2 bullets shooting
    */
    if(this -> timeBetween2Bullets >= this -> timeBetween2BulletsMax){
        this -> timeBetween2Bullets = 0.f;
        this -> clockSound.pause();
        this -> isShooted = false;
    }
    else
    {
        timeBetween2Bullets += 0.5f;
    }
}
void Game::setOriginPos(sf::RenderWindow *window)
{
    this -> getWindowSize(window);
    this -> player->setPos(sf::Vector2f(window -> getSize(). x / 2.0 ,window->getSize().y - this -> player->getBounds().height));
    this -> speedup.setPosition(window -> getSize().x / 2.0 - 150.f ,window->getSize().y / 2.0 - 80.f);
    this -> surround.setPosition(window -> getSize().x - healthBarWidth - 4.f , 10.f);
    this -> fill.setPosition(surround.getPosition());
    this -> background -> setFirstPos(window);
    this -> pause -> setPos(window, window -> getSize().x - 320.f, 50.f);
    this -> clock.setPosition(15.f, 60.f);
}

void Game::updatePause(sf::RenderWindow *window)
{
    this -> pollEv(window);
    this -> pause -> pollEv(window);
    this -> updateMousePos(window);
    this -> pause -> updateMousePos(mousePosView);
}
void Game::update(sf::RenderWindow *window){
    this -> pollEv(window);
    this -> background -> update(window);
    this -> player -> update();
    this -> updateCollision(window);
    this -> updateInput(window);
    this -> updateBullets();
    this -> updateObjects(window);
    this -> updatePlanet(window);
    this -> updateBulletsCombats();
    this -> updatelazerCombat();
    this -> updateText();
    this -> updateHealthBar();
    if(isShooted)
    {
        this -> CoolDownBullets();
        isEndTimer = false;
    }
    else isEndTimer = true;
}


void Game::pollEv(sf::RenderWindow *window){
    /*
    return void: check input event to escape the game
        - Closed
        - KeyPressed: Escape
    */
    while(window->pollEvent(this -> ev)){
        if(ev.type == sf::Event::Closed){
            window -> close();
            isClosed = true;
        }
        if(ev.sf::Event::KeyPressed && ev.key.code == sf::Keyboard::Escape){
            window -> close();
            isClosed = true;

        }

    }

}

void Game::updateInput(sf::RenderWindow *window){
    /*
    return void: enter the input from mouse or keyboard to control the player
        - move player using keypressed: up, down, left, right
        - shooting lazers by using keypressed: "A"
        - shooting bullets by using keypressed: "S"
    */

    //moving
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        this -> player->move(-0.1f, 0.f);
        this -> background -> moveStars(window, 1.f, 0.f);
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
   {
       this -> player->move(0.1f, 0.f);
       this -> background -> moveStars(window, -1.f, 0.f);
   }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        this -> player->move(0.f, -0.1f);
        this -> background -> moveStars(window, 0.f, 1.f);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        this -> player->move(0.f, 0.1f);
        this -> background -> moveStars(window, 0.f, -1.f);
    }


    //Shooting
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S) && isCoolDown() && isEndTimer){
        this -> isShooted = true;
        this -> clockSound.play();
        this -> bullets.push_back(new Bullet(this -> resources["BULLET"],
                                    this -> player -> getPos().x + this -> player -> getBounds().width / 2.f,
                                    this -> player -> getPos().y,
                                    0.7f,
                                    0.7f,
                                    5.f));
        this -> bulletShoot.play();

    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A) && isCoolDown()){
            this -> lazerBullets.push_back(new Bullet(this -> resources["lazer"],
                                        this -> player -> getPos().x + this -> player -> getBounds().width / 2.f - 60.f,
                                        this -> player -> getPos().y,
                                        0.5f,
                                        0.5f,
                                        5.f));
            this -> lazerBullets.push_back(new Bullet(this -> resources["lazer"],
                                        this -> player -> getPos().x + this -> player -> getBounds().width / 2.f  + 40.f,
                                        this -> player -> getPos().y,
                                        0.5f,
                                        0.5f,
                                        5.f));
            this -> bulletShoot.play();
    }


}

void Game::updateObjects(sf::RenderWindow *window){
    /*
    return void:
        - generate random objects after beginning time and spawn timer of objects
    */
    this -> updateObjectsSpeed();
    if(this -> waitingBeginingTime < 0){
        int type = rand() % this -> objectTypes.size();
        if(this -> timeBetween2Objects >= this -> timeBetween2ObjectsMax){
            if(objectTypes[type] == "alien")
                this -> objects.push_back(new Object(this -> resources["alien"], rand() % window->getSize().x-20.f, -100.f, 0.5f, 0.5f, this -> objectSpeed, true));
            else
                this -> objects.push_back(new Object(this -> resources[objectTypes[type]], rand() % window->getSize().x-20.f, -100.f, 0.8f, 0.8f, this -> objectSpeed, false));
            this -> timeBetween2Objects = 0.f;
        }
        else timeBetween2Objects += 0.5f;
        this -> updateObjectsCollision(window);
    }
    else this -> waitingBeginingTime -= 1.f;
}
void Game::updateObjectsSpeed()
{
    /*
    @return void:
        - When the point reach a paticular target, go to the next level by increasing the speed of objects
    */

    if(this -> point >= this -> level * 5000)
    {

        this -> objectSpeed += 0.5f;
        this -> level++;
        this -> timeTextLast = 50.f;
        this -> timeBetween2PlanetsMax -= 5.f;
    }
}
void Game::updatePlanet(sf::RenderWindow *window){
    int type = rand() % planetTypes.size();
    if(this -> timeBetween2Planets >= this -> timeBetween2PlanetsMax){
        this -> planets.push_back(new Planet(this -> resources[planetTypes[type]], rand() % window->getSize().x-20.f, -100.f, 1.2f));
        this -> timeBetween2Planets = 0.f;
    }
    else this -> timeBetween2Planets += 0.5f;
    this -> updatePlanetCollision(window);
}
void Game::updateBulletsCombats(){
    /*
    return void:
        - Enemies: bullets can destroy all the objects that in the shooted area which is a circle with a particular radius
        Any object has its bound in the circle may be erased
        - Planet: 1 bullet can destroy only the planet that it crash into.
    */

    //combat with enemies
    for(unsigned j = 0; j < this -> bullets.size(); j++){
        for(unsigned i = 0; i < this -> objects.size(); i++){
            if(this->objects[i]->getBounds().intersects(this->bullets[j]->getBounds())){
                this -> isBoom = true;
                for(auto num: booms)
                {
                    num -> setPos(objects[i] -> getPos());
                }
                this -> shootedArea.setPosition(this -> objects[i] -> getPos().x - 150.f, this -> objects[i] -> getPos().y - 150.f);
                int num = 0;
                while(num < objects.size()){
                    if(this -> shootedArea.getGlobalBounds().intersects(this -> objects[num] -> getBounds()))
                       {
                           delete this -> objects[num];
                           this -> objects.erase(this -> objects.begin() + num);
                           if(objects[i]->isAlien()) point += 200.f;
                            else point += 100.f;
                       }
                       else num++;
                }

                num = 0;
                while(num < planets.size()){
                    if(this -> shootedArea.getGlobalBounds().intersects(this -> planets[num] -> getBounds()))
                       {
                           delete this -> planets[num];
                           this -> planets.erase(this -> planets.begin() + num);
                           this -> curr_health -= 1.f;
                            this -> loseHeal.play();
                       }
                       else num++;
                }
                delete this -> bullets[j];
                this -> bullets.erase(this -> bullets.begin() + j);

                this -> collision.play();
                break;
            }
        }
    }

    //combat with planets
    for(unsigned j = 0; j < this -> bullets.size(); j++){
        for(unsigned i = 0; i < this -> planets.size(); i++){
            if(this->planets[i]->getBounds().intersects(this->bullets[j]->getBounds())){
                this -> isBoom = true;
                for(auto num: booms)
                {
                    num -> setPos(this -> planets[i] -> getPos());
                }
                delete this -> planets[i];
                this -> planets.erase(this -> planets.begin() + i);

                delete this -> bullets[j];
                this -> bullets.erase(this -> bullets.begin() + j);
                this -> curr_health -= 1.f;
                this -> loseHeal.play();
                break;

            }
        }
    }
}
void Game::updatelazerCombat()
{
    /*
    return void:
        one lazer bullet can destroy only one object or planet
    */

    //Combat with enemies
    for(unsigned j = 0; j < this -> lazerBullets.size(); j++){
        for(unsigned i = 0; i < this -> objects.size(); i++){
            if(this->objects[i]->getBounds().intersects(this->lazerBullets[j]->getBounds())){
                this -> isBoom = true;
                for(auto num: booms)
                {
                    num -> setPos(objects[i] -> getPos());
                }

                delete this -> objects[i];
                this -> objects.erase(this -> objects.begin() + i);

                delete this -> lazerBullets[j];
                this -> lazerBullets.erase(this -> lazerBullets.begin() + j);
                if(objects[i]->isAlien()) point += 200.f;
                else point += 100.f;
                this -> collision.play();
                break;
            }
        }
    }

    //combat with planets
    for(unsigned j = 0; j < this -> lazerBullets.size(); j++){
        for(unsigned i = 0; i < this -> planets.size(); i++){
            if(this->planets[i]->getBounds().intersects(this->lazerBullets[j]->getBounds())){
                this -> isBoom = true;
                for(auto num: booms)
                {
                    num -> setPos(this -> planets[i] -> getPos());
                }
                delete this -> planets[i];
                this -> planets.erase(this -> planets.begin() + i);

                delete this -> lazerBullets[j];
                this -> lazerBullets.erase(this -> lazerBullets.begin() + j);
                this -> curr_health -= 1.f;
                this -> loseHeal.play();
                break;

            }
        }
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


//game over
void Game::updateFinalPoints(sf::RenderWindow *window)
{
    this -> pollEv(window);
    this -> updateMousePos(window);
    this -> background -> update(window);
    this -> gameOver -> updatePoint(this -> point);
    this -> gameOver -> updateMousePos(this -> mousePosView);
    this -> gameOver -> update(windowsize);
}



