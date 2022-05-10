#include "GameOver.h"

void GameOver::initVariable()
{
    this -> choices = 0;
}
void GameOver::initFontsandText()
{
    this -> font.loadFromFile("fonts/ConnectionIi.otf");
    this -> gameOverFont.loadFromFile("fonts/04B.TTF");
    this -> yourScore.setFont(this -> font);
    this -> Score.setFont(this -> font);
    this -> gameOver.setFont(this -> gameOverFont);
    this -> playAgain.setFont(this -> font);
    this -> choice1.setFont(this -> font);
    this -> choice2.setFont(this -> font);

}
GameOver::GameOver()
{
    this -> initFontsandText();

}
GameOver::~GameOver()
{

}
int GameOver::choice()
{
    return choices;
}
void GameOver::update(sf::Vector2f windowSize)
{
    this -> pollEv();
    this -> updateTexts(windowSize);
}
void GameOver::pollEv()
{

    if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
        if(this -> choice1.getGlobalBounds().contains(this -> mousePosView)){
            choices = 1;
        }
        else if(this -> choice2.getGlobalBounds().contains(this -> mousePosView)){
            choices = 2;
        }
    }

}
void GameOver::updateTexts(sf::Vector2f windowSize)
{
    this -> setStringTexts();
    this -> setScaleTexts();
    this -> setPos(windowSize);
    this -> SetColor();

}
void GameOver::updateMousePos(sf::Vector2f mousePosView_)
{
    this -> mousePosView = mousePosView_;
}
void GameOver::updatePoint(float point_)
{
    this -> score = point_;
}
void GameOver::setStringTexts()
{
    this -> yourScore.setString("Your Score is:");
    std::stringstream ss;
    ss << score;
    this -> Score.setString(ss.str());
    this -> gameOver.setString("GAME OVER");
    this -> playAgain.setString("Play Again?");
    this -> choice1.setString("Yes");
    this -> choice2.setString("No");
}
void GameOver::setScaleTexts()
{
    this -> yourScore.setScale(1.f, 1.f);
    this -> Score.setScale(1.5f, 1.5f);
    this -> gameOver.setScale(2.f, 2.f);
    this -> playAgain.setScale(1.f, 1.f);
    this -> choice1.setScale(1.f, 1.f);
    this -> choice2.setScale(1.f, 1.f);

}
void GameOver::setPos(sf::Vector2f windowSize)
{

    this -> gameOver.setPosition(windowSize.x / 2 - 250.f,windowSize.y / 2 - 100.f);
    this -> yourScore.setPosition(this -> gameOver.getGlobalBounds().left + 100.f, this -> gameOver.getGlobalBounds().top + this -> gameOver.getGlobalBounds().height + 10.f);
    this -> Score.setPosition(this -> yourScore.getGlobalBounds().left + this -> yourScore.getGlobalBounds().width + 20.f, this -> yourScore.getPosition().y - 5.f);
    this -> playAgain.setPosition(this -> yourScore.getGlobalBounds().left + 70.f, this -> yourScore.getGlobalBounds().top + this -> yourScore.getGlobalBounds().height + 50.f);
    this -> choice1.setPosition(this -> playAgain.getGlobalBounds(). left + 20.f, this -> playAgain.getGlobalBounds().top + this -> playAgain.getGlobalBounds().height + 10.f);
    this -> choice2.setPosition(this -> choice1.getGlobalBounds(). left + this -> choice1.getGlobalBounds().width + 20.f,this -> playAgain.getGlobalBounds().top + this -> playAgain.getGlobalBounds().height + 10.f);

}
void GameOver::SetColor()
{

    this -> yourScore.setColor(sf::Color::White);
    this -> Score.setColor(sf::Color::Yellow);
    this -> gameOver.setColor(sf::Color::Red);
    this -> playAgain.setColor(sf::Color::White);
    this -> choice1.setColor(sf::Color::White);
    this -> choice2.setColor(sf::Color::White);

}
void GameOver::render(sf::RenderTarget *target)
{
    target ->draw(this -> yourScore);
    target ->draw(this -> Score);
    target ->draw(this -> gameOver);
    target ->draw(this -> playAgain);
    target ->draw(this -> choice1);
    target ->draw(this -> choice2);
}
