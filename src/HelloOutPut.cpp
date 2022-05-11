#include "Hello.h"

bool Hello::isClosed(){
    return this -> closed;
}
int Hello::choice()
{
    return this -> choices;
}
void Hello::setChoiceAfterOnShift(int choice)
{
    this -> choices = choice;
}
int Hello::getplayerChoice()
{
    return this ->  playerChoice;
}
