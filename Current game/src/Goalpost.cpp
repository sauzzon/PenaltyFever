#include "Goalpost.h"

Goalpost::Goalpost()
{
    m_texture.loadFromFile("Resources/Images/goalpost5.png");
    m_sprite.setTexture(m_texture);
    m_sprite.setPosition(500,100);

    //dbox lines
    line.setSize(sf::Vector2f(1366,3));
    line.setPosition(sf::Vector2f(0,290));
    line.setFillColor(sf::Color::White);
    line1.setSize(sf::Vector2f(183,3));
    line1.setRotation(90);
    line1.setPosition(sf::Vector2f(400,290));
    line2.setSize(sf::Vector2f(640,3));
    line2.setPosition(sf::Vector2f(400,470));
    line2.setFillColor(sf::Color::White);
    line3.setSize(sf::Vector2f(180,3));
    line3.setRotation(90);
    line3.setPosition(sf::Vector2f(1040,290));
    line4.setSize(sf::Vector2f(433,3));
    line4.setRotation(90);
    line4.setPosition(sf::Vector2f(170,290));
    line5.setSize(sf::Vector2f(430,3));
    line5.setRotation(90);
    line5.setPosition(sf::Vector2f(1270,290));
    line6.setSize(sf::Vector2f(1100,3));
    line6.setPosition(sf::Vector2f(170,720));
    line6.setFillColor(sf::Color::White);

     //
    dboxSemiTexture.loadFromFile("Resources/Images/dbox.png");
    dboxSemiSprite.setTexture(dboxSemiTexture);
    dboxSemiSprite.setPosition(sf::Vector2f(580,720));
    dboxSemiSprite.setScale(2.0f,2.0f);
}

Goalpost::~Goalpost()
{
    //dtor
}

sf::Sprite Goalpost::getSprite()
{
    return m_sprite;
}
void Goalpost::draw(sf::RenderWindow &window)
{

        window.draw(m_sprite);
        window.draw(line);
        window.draw(line1);
        window.draw(line2);
        window.draw(line3);
        window.draw(line4);
        window.draw(line5);
        window.draw(line6);
        window.draw(dboxSemiSprite);

}
