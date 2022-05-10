#include "gameEngine.h"

void gameEngine::initWindow()
{
     // initualize a complete window

    this -> windowSize.width = 1000;
    this -> windowSize.height = 650;
    this -> window = new sf::RenderWindow(this->windowSize, "COSMOS", sf::Style::Default);

    //make window more smooth
    this -> window->setFramerateLimit(144);
    this -> window->setVerticalSyncEnabled(false);
}
gameEngine::gameEngine()
{
    this -> initWindow();
}
gameEngine::~gameEngine()
{
    delete window;
}
void gameEngine::running()
{
    Hello hello;
    hello.running(this -> window);
    if(hello.isClosed()) {
        return;
    }
    else{
        if(hello.choice() == 1){
            hello.setChoiceAfterOnShift(0);
            bool isContinue = true;
            while(isContinue){
                Game game(hello.getplayerChoice());
                game.running(this -> window);
                if(game.Closed()){
                    return;
                }
                else{
                    if(game.choice() == 1)
                    {
                        continue;
                    }
                    else if(game.choice() == 2){
                        isContinue = false;
                        return;
                    }
                }
            }
        }
        else {
            return;
        }
    }


}
