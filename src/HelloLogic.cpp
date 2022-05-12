#include "Hello.h"

const bool Hello::isRunning(sf::RenderWindow *window) const{
    return window->isOpen();
}

//menu part
void Hello::update(sf::RenderWindow *window)
{
    this -> background -> update(window);
    this -> PollEv(window);
    this -> updateMousePos(window);
    this -> updateText(window);
}
void Hello::PollEv(sf::RenderWindow *window)
{
    while(window->pollEvent(this -> ev)){
        if(ev.type == sf::Event::Closed){
                window -> close();
                closed = true;
        }
        if(ev.sf::Event::KeyPressed && ev.key.code == sf::Keyboard::Escape){
            window -> close();
            closed = true;
        }
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){

                if(this -> choice1.getGlobalBounds().contains(this -> mousePosView)){
                    this -> click.play();
                    choices = 1;
                }
                else if(this -> choice2.getGlobalBounds().contains(this -> mousePosView)){
                    this -> click.play();
                    choices = 2;
                }
                else if(this -> choice3.getGlobalBounds().contains(this -> mousePosView))
                {
                    this -> click.play();
                    choices = 3;
                }
        }
    }
}
void Hello::updateMousePos(sf::RenderWindow *window){
    this->mousePosWindow = sf::Mouse::getPosition(*window);
	this->mousePosView = window->mapPixelToCoords(this->mousePosWindow);
}


//choose player part
void Hello::updateChoosePlayer(sf::RenderWindow *window)
{
    this -> pollChoosePlayerEvent(window);
    this -> updateMousePos(window);
    this -> background -> update(window);
    this -> playerRange -> updateChoosePlayer(window);
    this -> setTextOfChoice();

}
void Hello::pollChoosePlayerEvent(sf::RenderWindow *window)
{
    if(window->pollEvent(this -> ev)){
        if(ev.type == sf::Event::Closed){
                window -> close();
                closed = true;
        }
        if(ev.sf::Event::KeyPressed && ev.key.code == sf::Keyboard::Escape){
            window -> close();
            closed = true;
        }
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                if(this -> playerRange -> getBounds(1).contains(this -> mousePosView)){
                    this -> click.play();
                    playerChoice = 1;
                }
                else if(this -> playerRange -> getBounds(2).contains(this -> mousePosView)){
                    this -> click.play();
                    playerChoice = 2;
                }
                else if(this -> playerRange -> getBounds(3).contains(this -> mousePosView))
                {
                    this -> click.play();
                    playerChoice = 3;
                }
                else if(this -> returnButton.getGlobalBounds().contains(this -> mousePosView))
                {
                    this -> click.play();
                    isReturn = true;
                }

        }
    }
}


