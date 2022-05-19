#include "Game.h"

//render main game
void Game::render(sf::RenderWindow *window){

    window -> clear(sf::Color::Black);

    // render player
    this -> background -> render(window);
    this -> player -> render(window);
    for(auto *i: this -> bullets){
        i -> render(window);
    }
    for(auto *i: this -> lazerBullets)
    {
        i -> render(window);
    }
    for(auto *i: this -> rocks){
        i -> render(window);
    }
    for(auto *i: this -> aliens){
        i -> renderBullets(window);
        i -> render(window);

    }
    for(auto *i: this -> planets){
        i -> render(window);
    }
    this -> renderText(window);
    this -> renderHealthBar(window);
    if(timeTextLast > 0)
    {
        window -> draw(this -> speedup);
        timeTextLast -= 1.f;
    }
    this -> renderBoom(window);
    this -> pause -> render(window);
    if(this -> timeBetween2Bullets < timeBetween2BulletsMax && isShooted)
    {
        window -> draw(this -> clock);

    }

    window -> display();
}
void Game::renderText(sf::RenderWindow *window){
    window->draw(pointText);
}
void Game::renderHealthBar(sf::RenderWindow *window){
    window -> draw(this -> surround);
    window -> draw(this -> fill);
    window -> draw(this -> health);
}

void Game::renderBoom(sf::RenderWindow *window)
{
    if(isBoom)
    {
        if(boomSpawnTimer > boomSpawnTimerMax)
        {
            boomSpawnTimer = 0.f;
            this -> frame += 1.f;
            if(frame >= 5)
            {
                isBoom = false;
                frame = 0;
                boomSpawnTimer = 0.f;
            }
        }
        else{
            booms[frame] -> render(window);
            boomSpawnTimer += 1.f;
        }
    }
}

//render game over
void Game::renderFinalPoint(sf::RenderWindow *window)
{
    window -> clear(sf::Color::Black);
    this -> background -> render(window);
    this -> gameOver ->render(window);
    window -> display();
}
