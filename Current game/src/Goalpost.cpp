#include "Goalpost.h"

Goalpost::Goalpost()
{
    m_texture.loadFromFile("goalpost5.png");
    m_sprite.setTexture(m_texture);
    m_sprite.setPosition(500,100);
}

Goalpost::~Goalpost()
{
    //dtor
}

sf::Sprite Goalpost::getSprite()
{
    return m_sprite;
}
