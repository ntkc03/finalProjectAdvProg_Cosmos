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
    while(true){
        hello.running(this -> window);
        if(hello.isClosed()) {
            break;
        }
        else{
            if(hello.choice() == 1){
                hello.setChoiceAfterOnShift(0);
                bool isContinue = true;
                while(isContinue){
                    Game game(hello.getplayerChoice());
                    game.running(this -> window);
                    if(game.Closed()){
                        break;
                    }
                    else{
                        if(game.choice() == 1)
                        {
                            continue;
                        }
                        else if(game.choice() == 2){
                            isContinue = false;
                            break;
                        }
                    }
                }
                if(isContinue == false) break;
            }
            else if(hello.choice() == 2){
                hello.setChoiceAfterOnShift(0);
                Rule rule;
                rule.run(this -> window);
                if(rule.isClosed())
                {
                    break;
                }
                else if(rule.choice() == 1){
                    continue;
                }

            }
            else {
                break;
            }
        }

    }

}
