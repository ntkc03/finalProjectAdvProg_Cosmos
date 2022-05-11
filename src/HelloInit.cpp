#include "Hello.h"

void Hello::initVariables()
{
    this -> choices = 0;
    this -> closed = false;

    this -> playerRange = new Player;
    this -> playerChoice = 0;

    this -> isReturn = false;
}

void Hello::initFont(){
    this -> font1.loadFromFile("fonts/04B.ttf");
    this -> font2.loadFromFile("fonts/ConnectionIi.otf");
    this -> font3.loadFromFile("fonts/PixeBoy.ttf");
}
void Hello::initBKG()
{

    this -> background = new Background;
}
void Hello::initSound()
{
    //background music
    this -> bgkBuf.loadFromFile("audio/bgkmusicHello.wav");
    this -> bgk.setBuffer(this -> bgkBuf);
    this -> bgk.setLoop(true);

    this -> clickBuff.loadFromFile("audio/mouse.wav");
    this -> click.setBuffer(this -> clickBuff);
}
void Hello::initImage()
{
   this -> returnTex.loadFromFile("image/exit.PNG");
   this -> returnButton.setTexture(this -> returnTex);
   this -> returnButton.setScale(0.3f, 0.3f);
   this -> returnButton.setPosition(0.f, 0.f);
}
