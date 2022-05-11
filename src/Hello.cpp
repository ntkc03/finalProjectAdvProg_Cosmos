#include "Hello.h"


Hello::Hello(){
    this -> initVariables();
    this -> initFont();
    this -> initBKG();
    this -> initSound();
    this -> initImage();
}

Hello::~Hello()
{
    delete background;
    this -> click.stop();
}
void Hello::running(sf::RenderWindow *window){
    this -> bgk.play();
    this -> background -> setFirstPos(window);
    while(true){
        while(this -> isRunning(window))
        {
            this -> update(window);
            this -> render(window);
            if(this -> choice() != 0) {
                break;
            }

        }
        if(choices == 1){
            while(this -> isRunning(window))
            {
                this -> updateChoosePlayer(window);
                this -> renderChoosePlayer(window);
                if(playerChoice != 0 || this -> isReturn) break;
            }
        }
        else if(choices == 2)
        {
            Rule rule;
            rule.run(window);
            if(rule.isClosed())
            {
                break;
            }
            this -> click.play();
            this -> isReturn = rule.isReturnFun();
            choices = 0;
        }
        if(isReturn)
        {
            this -> choices = 0;
            this -> isReturn = false;
            continue;
        }
        break;
    }
    this -> bgk.stop();
}


