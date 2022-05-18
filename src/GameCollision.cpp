#include "Game.h"

void Game::updateCollision(sf::RenderWindow *window){
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
        i->update();
        if(i ->getBounds().top + i -> getBounds().height <= 0.f){
            delete this -> bullets.at(idx);
            this -> bullets.erase(this -> bullets.begin() + idx);
        }
        else idx++;
    }

    idx = 0;
    for(auto *i: this -> lazerBullets){
        i->update();
        if(i ->getBounds().top + i -> getBounds().height <= 0.f){
            delete this -> lazerBullets.at(idx);
            this -> lazerBullets.erase(this -> lazerBullets.begin() + idx);
        }
        else idx++;
    }
}
void Game::updateObjectsCollision(sf::RenderWindow *window)
{
    int idx = 0;
        for(auto *i: this -> objects){
            i->updateSpeed(objectSpeed);
            i->update();

            if(i->getBounds().top > window->getSize().y){
                delete this -> objects.at(idx);
                this -> objects.erase(this -> objects.begin() + idx);
            }
            else if(i->getBounds().intersects(this -> player->getBounds())){
                delete this -> objects.at(idx);
                this -> objects.erase(this -> objects.begin() + idx);
                this -> curr_health -= 1.f;
                this -> loseHeal.play();
            }
            idx++;
        }
}
void Game::updatePlanetCollision(sf::RenderWindow *window)
{
    int idx = 0;
    for(auto *i: this -> planets){
        i->update();

        if(i->getBounds().top > window->getSize().y){
            delete this -> planets.at(idx);
            this -> planets.erase(this -> planets.begin() + idx);
        }
        else if(i->getBounds().intersects(this -> player->getBounds())){
            this -> earnHeal.play();
            delete this -> planets.at(idx);
            this -> planets.erase(this -> planets.begin() + idx);
            this -> curr_health += 1.f;
            this -> curr_health = curr_health >= healthMax ? healthMax : curr_health;

        }
        idx++;
    }
}


