#include "Hello.h"

void Hello::initVariables()
{
    this -> choices = 0;
    this -> closed = false;

    //background music

    this -> bgkBuf.loadFromFile("audio/bgkmusicHello.wav");
    this -> bgk.setBuffer(this -> bgkBuf);
    this -> bgk.setLoop(true);
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
Hello::Hello(sf::RenderWindow *target){
    this -> initVariables();
    this -> window = target;
    this -> initFont();
    this -> initBKG();
}
Hello::Hello()
{

}
Hello::~Hello()
{
    delete background;
    delete bkg;
}
const bool Hello::isRunning() const{
    return window->isOpen();
}
bool Hello::isClosed(){
    return this -> closed;
}
int Hello::choice()
{
    return this -> choices;
}
sf::Color Hello::randomColor()
{
    uint8_t r = rand() % 256;
    uint8_t g = rand() % 256;
    uint8_t b = rand() % 256;
    sf::Color color = {r, g, b};
    return color;
}
void Hello::updateMousePos(){
    this->mousePosWindow = sf::Mouse::getPosition(*window);
	this->mousePosView = window->mapPixelToCoords(this->mousePosWindow);
}
void Hello::updateText(){
    this -> welcome.setString("Welcome to");
    this -> welcome.setFont(this -> font3);
    this -> welcome.setColor(sf::Color::White);
    this -> welcome.setScale(1.5f, 1.5f);
    this -> welcome.setPosition(this -> name.getPosition().x + 100.f, this -> name.getPosition().y - 50.f);

    this -> name.setString("COSMOS");
    this -> name.setFont(this -> font1);
    this -> name.setColor(this -> randomColor());
    this -> name.setScale(2.f, 2.f);
    this -> name.setPosition(window -> getSize(). x / 2.0 - 180.f ,window->getSize().y / 2.0 - 100.f);

    this -> demand.setString("> Click to start");
    this -> demand.setFont(this -> font2);
    this -> demand.setColor(sf::Color::White);
    this -> demand.setScale(1.5f, 1.5f);
    this -> demand.setPosition(this -> name.getPosition().x, this -> name.getPosition().y + 100.f);

    this -> choice1.setString("1. Play Game");
    this -> choice1.setFont(this -> font2);
    this -> choice1.setColor(sf::Color::White);
    this -> choice1.setScale(1.5f, 1.5f);
    this -> choice1.setPosition(this -> demand.getPosition().x + 50.f, this -> demand.getPosition().y + 50.f);

    this -> choice2.setString("2. Rule");
    this -> choice2.setFont(this -> font2);
    this -> choice2.setColor(sf::Color::White);
    this -> choice2.setScale(1.5f, 1.5f);
    this -> choice2.setPosition(this -> choice1.getPosition().x , this -> choice1.getPosition().y + 50.f);

    this -> choice3.setString("3. Exit");
    this -> choice3.setFont(this -> font2);
    this -> choice3.setColor(sf::Color::White);
    this -> choice3.setScale(1.5f, 1.5f);
    this -> choice3.setPosition(this -> choice2.getPosition().x , this -> choice2.getPosition().y + 50.f);
}
void Hello::beginPollEv()
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
void Hello::update()
{
    this -> beginPollEv();
    this -> updateMousePos();
    this -> updateText();
}
void Hello::render()
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
void Hello::running(){
    this -> bgk.play();
    while(this -> isRunning())
    {
        this -> update();
        this -> render();
        if(this -> choice() != 0) {
            this -> bgk.stop();
            break;
        }

    }

}

