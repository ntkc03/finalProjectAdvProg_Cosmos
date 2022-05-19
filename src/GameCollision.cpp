#include "Game.h"

void Game::updatePlayerCollision(sf::RenderWindow *window){
    /*
    return void
        - set the bound collisions of player that player can't go out of the window
    */

    if (this->player->getBounds().left < 0.f)
	{
		this->player->setPos(sf::Vector2f(0.f, this->player->getBounds().top));
	}
	else if (this->player->getBounds().left + this->player->getBounds().width >= window->getSize().x)
	{
		this->player->setPos(sf::Vector2f(window->getSize().x - this->player->getBounds().width, this->player->getBounds().top));
	}

    if(this -> player -> getBounds().top <= 0.f){
        this -> player -> setPos(sf::Vector2f( this -> player -> getBounds().left, 0.f));
    }
    else if(this -> player -> getBounds().top + this -> player -> getBounds().height >= window -> getSize().y){
        this -> player -> setPos(sf::Vector2f(this -> player -> getBounds(). left, window -> getSize().y - this -> player -> getBounds().height));
    }
}
void Game::updateBullets(){
    /*
    return void:
        - if bullet crush the top of the window, the bullet disappear
    */
    int idx = 0;
    for(auto *i: this -> bullets){
        i->update(sf::Vector2f(0.f, -1.f));
        if(i ->getBounds().top + i -> getBounds().height <= 0.f){
            delete this -> bullets.at(idx);
            this -> bullets.erase(this -> bullets.begin() + idx);
        }
        else idx++;
    }

    idx = 0;
    for(auto *i: this -> lazerBullets){
        i->update(sf::Vector2f(0.f, -1.f));
        if(i ->getBounds().top + i -> getBounds().height <= 0.f){
            delete this -> lazerBullets.at(idx);
            this -> lazerBullets.erase(this -> lazerBullets.begin() + idx);
        }
        else idx++;
    }
}
void Game::updateObjectsCollision(sf::RenderWindow *window, std::vector<Object *> &obj, bool isPlanet)
{
    int idx = 0;
    for(auto *i: obj){
        i->updateSpeed(objectSpeed);
        i->update(sf::Vector2f(0.f, 1.f));

        if(i->getBounds().top > window->getSize().y){
            delete obj.at(idx);
            obj.erase(obj.begin() + idx);
        }
        else if(i->getBounds().intersects(this -> player->getBounds())){
            delete obj.at(idx);
            obj.erase(obj.begin() + idx);
            if(!isPlanet)
            {
                this -> curr_health -= 1.f;
                this -> loseHeal.play();
            }
            else{
                this -> curr_health += 1.f;
                this -> curr_health = curr_health >= healthMax ? healthMax : curr_health;
            }
        }
        idx++;
    }
}
void Game::updateObjectsCollision(sf::RenderWindow *window, std::vector<Alien *> &obj)
{
    int idx = 0;
    for(auto *i: obj){
        i->updateSpeed(objectSpeed);
        i->update(sf::Vector2f(0.f, 1.f));
        i -> updateCollision(window, this -> player->getBounds());
        if(i -> lostHealths() > 0){
            this -> loseHeal.play();
            curr_health -= i ->lostHealths();
            i -> setLostHealth();
        }
        if(i->getBounds().top > window->getSize().y){
            delete obj.at(idx);
            obj.erase(obj.begin() + idx);
        }
        else if(i->getBounds().intersects(this -> player->getBounds())){
            delete obj.at(idx);
            obj.erase(obj.begin() + idx);
            this -> curr_health -= 1.f;
            this -> loseHeal.play();

        }
        idx++;
    }
}
