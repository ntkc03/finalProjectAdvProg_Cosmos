#include "Game.h"


Game::Game(const int &playerChoice){

    this -> initVariable();
    this -> initTextures();
    this -> initSound();
    this -> initPlayer(playerChoice);
    this -> initbackground();
    this -> initObjects();
    this -> initPlanet();
    this -> initFontsandText();
    this -> initHealthBar();
    this -> initGameOver();
    this -> initLoading();
    this -> initBoom();
    this -> initShootedArea();
    this -> initClock();
}

Game::~Game(){
    delete player;
    delete background;
    for(auto i: this -> bullets){
        delete i;
    }
    for(auto i: lazerBullets)
    {
        delete i;
    }
    for(auto i: this -> resources){
        delete i.second;
    }

    for(auto i: this -> objects){
        delete i;
    }
    for(auto i: this -> booms)
    {
        delete i;
    }
    delete gameOver;
    delete loading;
    delete pause;
    this -> clockSound.stop();
}

void Game::running(sf::RenderWindow *window){
    this -> setOriginPos(window);
    //loading
    this -> runLoad(window);
    //playing
    this -> runMainGame(window);
    //print the score
    this -> runGameOver(window);

    enterNewScore(this -> point);
}
void Game::runLoad(sf::RenderWindow *window)
{
    while(this -> loading ->getNumber() <= 100)
    {
        this -> pollEv(window);
        this -> loading -> update(windowsize);
        window -> clear(sf::Color::Black);
        this -> loading -> render(window);
        window -> display();
    }
}
void Game::runMainGame(sf::RenderWindow *window)
{
    this -> bgk.play();
    while(this -> isRunning(window) && curr_health > 0.f){
        this -> updatePause(window);
        this -> bgk.pause();
        if(pause -> isContinue() == false){
            //update
            this -> bgk.play();
            this -> update(window);
        }
        if(pause -> isPlay() == true)
            break;
        //render
        this -> render(window);
    }
    this -> bgk.stop();
}


void Game::runGameOver(sf::RenderWindow *window)
{
    this -> clockSound.stop();
    this -> bgkGO.play();
    while(this -> isRunning(window) && (curr_health <= 0.f || pause -> isPlay() == true))
    {

        this -> updateFinalPoints(window);
        this -> renderFinalPoint(window);
        if(gameOver -> choice() != 0)
        {
            break;
        }
    }
    this -> bgkGO.stop();
}






