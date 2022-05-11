#include "Game.h"

bool Game::Closed()
{
    return this -> isClosed;
}
int Game::choice()
{
    return gameOver -> choice();
}

void Game::updateMousePos(sf::RenderWindow *window){
    this->mousePosWindow = sf::Mouse::getPosition(*window);
	this->mousePosView = window->mapPixelToCoords(this->mousePosWindow);
}
void Game::getWindowSize(sf::RenderWindow *window)
{
    this -> windowsize.x = window->getSize().x;
    this -> windowsize.y = window->getSize().y;
}
