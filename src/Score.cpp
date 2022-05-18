#include "Score.h"

void Score::initFont()
{
    this -> titleFont.loadFromFile("fonts/Pixeboy.ttf");
    this -> contentFont.loadFromFile("fonts/ConnectionIi.otf");
}
void Score::initText()
{
    this -> title.setFont(titleFont);
}
void Score::initScore()
{
    numOfHighestScore = 5;
    std::ifstream File;
    File.open("sources.txt");
    if(!File.is_open())
    {
        std::cout << "Can't open file." << std::endl;
        return;
    }
    else{
        while(File.peek() != EOF)
        {
            int temp;
            File >> temp;
            std::string line;
            getline(File, line);
            score.push_back(temp);
        }
        File.close();
    }
}
void Score::initHighestScore()
{
    std::sort(score.begin(), score.end(), [](const int &l, const int &r)
              {
                  return l > r;
              });
    for(int i = 0; i < std::min(numOfHighestScore, (int)score.size()); i++)
    {
        std::stringstream ss;
        ss << i + 1 << ".\t" << score[i];
        sf::Text temp;
        temp.setFont(contentFont);
        temp.setString(ss.str());
        highestScore.push_back(temp);
    }
    std::cout << score.size();
    while(highestScore.size() < numOfHighestScore)
    {
        std::stringstream ss;
        ss << highestScore.size() + 1 << "\t0";
        sf::Text temp;
        temp.setFont(contentFont);
        temp.setString(ss.str());
        highestScore.push_back(temp);
    }
}
void Score::initTexture()
{
    this -> returnButt_.loadFromFile("image/exit.PNG");
}
void Score::initSprite()
{
    this -> returnButt.setTexture(this -> returnButt_);
}
void Score::initBKG()
{
    this -> background = new Background;
}
Score::Score()
{
    this -> closed = false;
    this -> isReturn = false;

    this -> initFont();
    this -> initText();
    this -> initScore();
    this -> initHighestScore();
    this -> initTexture();
    this -> initSprite();
    this -> initBKG();
}

Score::~Score()
{
    //dtor
    delete background;
}
const bool Score::isRunning(sf::RenderWindow *window) const
{
    return window->isOpen();
}
bool Score::isClosed()
{
    return this -> closed;
}
bool Score::isReturnFun()
{
    return this -> isReturn;
}
void Score::run(sf::RenderWindow *window)
{
    this -> background -> setFirstPos(window);
    this -> setText(window);
    while(this -> isRunning(window)){
        this -> update(window);
        this -> render(window);
        if(isReturn) break;
    }
}
void Score::setText(sf::RenderWindow *window)
{
    this -> setString();
    this -> setPos(window);
    this -> setScale();
    this -> setColor();
}
void Score::setString()
{
    this -> title.setString("Highest Score");
}
void Score::setPos(sf::RenderWindow *window)
{
    this -> title.setPosition(window->getSize().x/2 - 200.f, 0.f);
    this -> highestScore[0].setPosition(300.f, title.getGlobalBounds().top + title.getGlobalBounds().height + 100.f);
    for(int i = 1; i < numOfHighestScore; i++)
    {
        highestScore[i].setPosition(300.f, highestScore[i - 1].getGlobalBounds().top + highestScore[i - 1].getGlobalBounds().height + 50.f);
    }
    this -> returnButt.setPosition(0.f, 0.f);
}
void Score::setScale()
{
    this -> title.setScale(2.f, 2.f);
    for(int i = 0; i < numOfHighestScore; i++)
    {

        highestScore[i].setScale(1.5f, 1.5f);
    }
    this -> returnButt.setScale(0.3f, 0.3f);
}
void Score::setColor()
{
    this -> title.setColor(sf::Color::Red);
}
void Score::update(sf::RenderWindow *window)
{
    this -> background -> update(window);
    this -> pollEve(window);
    this -> updateMousePos(window);

}
void Score::pollEve(sf::RenderWindow * window)
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
                if(this -> returnButt.getGlobalBounds().contains(this -> mousePosView)){
                    isReturn = true;
                }
        }

    }
}
void Score::updateMousePos(sf::RenderWindow * window)
{
    this->mousePosWindow = sf::Mouse::getPosition(*window);
	this->mousePosView = window->mapPixelToCoords(this->mousePosWindow);
}
void Score::render(sf::RenderWindow *window)
{
    window -> clear(sf::Color::Black);
    this -> background -> render(window);
    window -> draw(title);
    for(int i = 0; i < numOfHighestScore; i++)
    {
        window -> draw(highestScore[i]);
    }
    window -> draw(returnButt);
    window -> display();
}

void enterNewScore(const float &score)
{
    std::ofstream File;
    File.open("sources.txt", std::ios::app);
    if(File.is_open())
    {
        File << score << std::endl;
        File.close();
    }
    else std::cout << "Can't open file";
}
