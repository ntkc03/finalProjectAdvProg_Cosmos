#include "Hello.h"

void Hello::render(sf::RenderWindow *window)
{
    window-> clear(sf::Color::Black);
    this -> background -> render(window);
    this -> renderHightLight1(window);
    window -> draw(this -> welcome);
    window -> draw(this -> name);
    window -> draw(this -> demand);
    window -> draw(this -> choice1);
    window -> draw(this -> choice2);
    window -> draw(this -> choice3);
    window -> draw(this -> choice4);
    window -> display();
}
void Hello::renderHightLight1(sf::RenderWindow *window)
{
    if(this -> choice1.getGlobalBounds().contains(this -> mousePosView)){
        sf::Vector2f Size = sf::Vector2(this -> choice1.getGlobalBounds().width + 20.f, this -> choice1.getGlobalBounds().height + 10.f);
        sf::Vector2f pos = sf::Vector2(this -> choice1.getPosition().x, this -> choice1.getPosition().y + 5.f);
        this -> createHightLight(&Size, &pos);
        window -> draw(this -> rec);
    }
    else if(this -> choice2.getGlobalBounds().contains(this -> mousePosView)){
        sf::Vector2f Size = sf::Vector2(this -> choice2.getGlobalBounds().width + 20.f, this -> choice2.getGlobalBounds().height + 10.f);
        sf::Vector2f pos = sf::Vector2(this -> choice2.getPosition().x, this -> choice2.getPosition().y+5.f);
        this -> createHightLight(&Size, &pos);
        window -> draw(this -> rec);
    }
    else if(this -> choice3.getGlobalBounds().contains(this -> mousePosView))
    {
        sf::Vector2f Size = sf::Vector2(this -> choice3.getGlobalBounds().width + 20.f, this -> choice3.getGlobalBounds().height + 15.f);
        sf::Vector2f pos = sf::Vector2(this -> choice3.getPosition().x, this -> choice3.getPosition().y + 5.f);
        this -> createHightLight(&Size, &pos);
        window -> draw(this -> rec);
    }
    else if(this -> choice4.getGlobalBounds().contains(this -> mousePosView))
    {
        sf::Vector2f Size = sf::Vector2(this -> choice4.getGlobalBounds().width + 20.f, this -> choice4.getGlobalBounds().height + 15.f);
        sf::Vector2f pos = sf::Vector2(this -> choice4.getPosition().x, this -> choice4.getPosition().y + 5.f);
        this -> createHightLight(&Size, &pos);
        window -> draw(this -> rec);
    }

}
void Hello::createHightLight(sf::Vector2f *Size, sf::Vector2f *pos)
{
    this -> rec.setSize(*Size);
    this -> rec.setFillColor(sf::Color(255,255,255,100));
    this -> rec.setPosition(*pos);
}


//choose player part
void Hello::renderChoosePlayer(sf::RenderWindow *window)
{
    window-> clear(sf::Color::Black);
    this -> background -> render(window);
    this -> renderHightLight2(window);
    this -> playerRange -> renderChoosePlayer(window);
    window -> draw(this -> textOfchoice);
    window -> draw(this -> returnButton);
    window -> display();
}
void Hello::renderHightLight2(sf::RenderWindow *window)
{
    if(this -> playerRange -> getBounds(1).contains(this -> mousePosView)){
        sf::Vector2f Size = sf::Vector2(this -> playerRange -> getBounds(1).width + 10.f, this -> playerRange -> getBounds(1).height + 50.f);
        sf::Vector2f pos = sf::Vector2(this -> playerRange -> getPos(1).x - 5.f, this -> playerRange -> getPos(1).y - 3.f);
        this -> createHightLight(&Size, &pos);
        window -> draw(this -> rec);
    }
    else if(this -> playerRange -> getBounds(2).contains(this -> mousePosView)){
        sf::Vector2f Size = sf::Vector2(this -> playerRange -> getBounds(2).width + 10.f, this -> playerRange -> getBounds(2).height + 60.f);
        sf::Vector2f pos = sf::Vector2(this -> playerRange -> getPos(2).x - 5.f, this -> playerRange -> getPos(2).y - 3.f);
        this -> createHightLight(&Size, &pos);
        window -> draw(this -> rec);
    }
    else if(this -> playerRange -> getBounds(3).contains(this -> mousePosView))
    {
        sf::Vector2f Size = sf::Vector2(this -> playerRange -> getBounds(3).width + 10.f, this -> playerRange -> getBounds(3).height + 50.f);
        sf::Vector2f pos = sf::Vector2(this -> playerRange -> getPos(3).x - 5.f, this -> playerRange -> getPos(3).y - 3.f);
        this -> createHightLight(&Size, &pos);
        window -> draw(this -> rec);
    }
}
