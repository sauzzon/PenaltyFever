#include "Shooter.h"
#include <windows.h>

Shooter::Shooter()
{
    m_texture.loadFromFile("Resources/Images/player2.png");
    m_sprite.setTexture(m_texture);
    m_sprite.setTextureRect(sf::IntRect(0,0,150,297));
    m_sprite.setPosition(610,430);
    m_sprite.scale(0.80f,0.80f);
    m1_texture.loadFromFile("Resources/Images/player2blue.png");



}
void Shooter::setToRed()
{
    m_sprite.setTexture(m_texture);
}
void Shooter::setToBlue()
{
    m_sprite.setTexture(m1_texture);

}


void Shooter::kick()
{

    Sleep(500);
    m_sprite.setTextureRect(sf::IntRect(150,0,150,297));

}

void Shooter::spawn()
{
    m_sprite.setTextureRect(sf::IntRect(0,0,150,297));
}

sf::Sprite Shooter::getSprite()
{
    return m_sprite;
}

Shooter::~Shooter()
{
    //dtor
}
sf::Vector2f Shooter::shootPosition()
{
    //generate random position
    sf::Vector2f randPosition;
    srand(unsigned(time(0)));

    randPosition.x= rand()%(890-550) + 550;
    randPosition.y= rand()%(250-120) + 120;

    return randPosition;


}
