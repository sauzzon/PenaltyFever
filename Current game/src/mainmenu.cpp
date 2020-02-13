#include "mainmenu.h"
mainmenu::mainmenu()
{
    m_texture.loadFromFile("Resources/Images/background.png");
    m_sprite.setTexture(m_texture);
    m_font.loadFromFile("Resources/Fonts/mymenu.ttf");

    m_textstart.setFont(m_font);
    m_textstart.setCharacterSize(50);

}

mainmenu::~ mainmenu()
{
    //dtor
}
void mainmenu::setstring(std::string start)
{
    m_textstart.setString(start);
}
sf::Sprite mainmenu::getsprite()
{
    return m_sprite;
}
sf::Text mainmenu::gettext()
{
    return m_textstart;
}
void mainmenu::setcolor()
{
    m_textstart.setFillColor(sf::Color::White);
}
void mainmenu::resetcolor()
{
    m_textstart.setFillColor(sf::Color::Black);
}
bool mainmenu::checker()
{
    sf::Vector2i globalposition=sf::Mouse::getPosition();
    if(m_textstart.getGlobalBounds().contains(globalposition.x,globalposition.y))
    {
        return true;
    }
    else
    {
        return false;
    }
}
void mainmenu::setpos(float x,float y)
{
    m_textstart.setPosition(x,y);
}



