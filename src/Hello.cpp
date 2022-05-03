#include "Hello.h"

void Hello::initVariables()
{
    this -> choices = 0;
    this -> closed = false;

    //background music

    this -> bgkBuf.loadFromFile("audio/bgkmusicHello.wav");
    this -> bgk.setBuffer(this -> bgkBuf);
    this -> bgk.setLoop(true);

    this -> playerRange = new Player;
    this -> playerChoice = 0;
}

void Hello::initFont(){
    this -> font1.loadFromFile("fonts/DayDream.ttf");
    this -> font2.loadFromFile("fonts/ConnectionIi.otf");
    this -> font3.loadFromFile("fonts/PixeBoy.ttf");
}
void Hello::initBKG()
{
    this -> bkg = new sf::Texture;
    if(!this -> bkg -> loadFromFile("image/bkg.jpg"))
    {
        std::cout << "ERROR::HELLO::INITBKG::Can't load image\n";
    }
    this -> background = new Background(bkg);
    this -> background ->setSize(sf::Vector2f(1.9f, 1.9f));
}
Hello::Hello(){
    this -> initVariables();
    this -> initFont();
    this -> initBKG();
}

Hello::~Hello()
{
    delete background;
    delete bkg;
}
void Hello::running(sf::RenderWindow *window){
    this -> bgk.play();
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
            if(playerChoice != 0) break;
        }
    }
    this -> bgk.stop();
}
const bool Hello::isRunning(sf::RenderWindow *window) const{
    return window->isOpen();
}
bool Hello::isClosed(){
    return this -> closed;
}
int Hello::choice()
{
    return this -> choices;
}
void Hello::update(sf::RenderWindow *window)
{
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
                    choices = 1;
                }
                else if(this -> choice2.getGlobalBounds().contains(this -> mousePosView)){
                    choices = 2;
                }
                else if(this -> choice3.getGlobalBounds().contains(this -> mousePosView))
                {
                    choices = 3;
                }
        }
    }
}
void Hello::updateMousePos(sf::RenderWindow *window){
    this->mousePosWindow = sf::Mouse::getPosition(*window);
	this->mousePosView = window->mapPixelToCoords(this->mousePosWindow);
}
void Hello::updateText(sf::RenderWindow *window)
{
    this -> setFont();
    this -> setString();
    this -> setColor();
    this -> setScale();
    this -> setPos(window);
}
void Hello::setString()
{
    this -> welcome.setString("Welcome to");
    this -> name.setString("COSMOS");
    this -> demand.setString("> Click to start");
    this -> choice1.setString("1. Play Game");
    this -> choice2.setString("2. How to play");
    this -> choice3.setString("3. Exit");

}
void Hello::setColor()
{
    this -> welcome.setColor(sf::Color::White);
    this -> name.setColor(this -> randomColor());
    this -> demand.setColor(sf::Color::White);
    this -> choice1.setColor(sf::Color::White);
    this -> choice2.setColor(sf::Color::White);
    this -> choice3.setColor(sf::Color::White);

}
sf::Color Hello::randomColor()
{
    uint8_t r = rand() % 256;
    uint8_t g = rand() % 256;
    uint8_t b = rand() % 256;
    sf::Color color = {r, g, b};
    return color;
}
void Hello::setPos(sf::RenderWindow *window)
{
    this -> welcome.setPosition(this -> name.getPosition().x + 100.f, this -> name.getPosition().y - 50.f);
    this -> name.setPosition(window -> getSize(). x / 2.0 - 180.f ,window->getSize().y / 2.0 - 100.f);
    this -> demand.setPosition(this -> name.getPosition().x, this -> name.getPosition().y + 100.f);
    this -> choice1.setPosition(this -> demand.getPosition().x + 50.f, this -> demand.getPosition().y + 50.f);
    this -> choice2.setPosition(this -> choice1.getPosition().x , this -> choice1.getPosition().y + 50.f);
    this -> choice3.setPosition(this -> choice2.getPosition().x , this -> choice2.getPosition().y + 50.f);
}
void Hello::setFont()
{
    this -> welcome.setFont(this -> font3);
    this -> name.setFont(this -> font1);
    this -> demand.setFont(this -> font2);
    this -> choice1.setFont(this -> font2);
    this -> choice2.setFont(this -> font2);
    this -> choice3.setFont(this -> font2);
}
void Hello::setScale()
{
    this -> welcome.setScale(1.5f, 1.5f);
    this -> name.setScale(2.f, 2.f);
    this -> demand.setScale(1.5f, 1.5f);
    this -> choice1.setScale(1.5f, 1.5f);
    this -> choice2.setScale(1.5f, 1.5f);
    this -> choice3.setScale(1.5f, 1.5f);
}

void Hello::render(sf::RenderWindow *window)
{
    window-> clear(sf::Color::Black);
    this -> background -> render(window);
    window -> draw(this -> welcome);
    window -> draw(this -> name);
    window -> draw(this -> demand);
    window -> draw(this -> choice1);
    window -> draw(this -> choice2);
    window -> draw(this -> choice3);
    window -> display();
}

void Hello::pollChoosePlayerEvent(sf::RenderWindow *window)
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
                if(this -> playerRange -> getBounds(1).contains(this -> mousePosView)){
                    playerChoice = 1;
                }
                else if(this -> playerRange -> getBounds(2).contains(this -> mousePosView)){
                    playerChoice = 2;
                }
                else if(this -> playerRange -> getBounds(3).contains(this -> mousePosView))
                {
                    playerChoice = 3;
                }
        }
    }
}
void Hello::updateChoosePlayer(sf::RenderWindow *window)
{
    this -> pollChoosePlayerEvent(window);
    this -> playerRange -> updateChoosePlayer(window);
    this -> setTextOfChoice();
    this -> updateMousePos(window);
}
void Hello::setTextOfChoice()
{
    this -> textOfchoice.setFont(this -> font3);
    this -> textOfchoice.setString("Choose your favourite space ship");
    this -> textOfchoice.setColor(sf::Color::White);
    this -> textOfchoice.setScale(1.5f, 1.5);
    this -> textOfchoice.setPosition(200.f, 50.f);
}
void Hello::renderChoosePlayer(sf::RenderWindow *window)
{
    window-> clear(sf::Color::Black);
    this -> background -> render(window);
    this -> playerRange -> renderChoosePlayer(window);
    window -> draw(this -> textOfchoice);
    window -> display();
}
int Hello::getplayerChoice()
{
    return this ->  playerChoice;
}

