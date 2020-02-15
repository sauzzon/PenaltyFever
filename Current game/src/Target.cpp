#include "Target.h"

Target::Target()
{

    m_texture.loadFromFile("Resources/Images/crosshair1.png");
    m_sprite.setTexture(m_texture);
    m_sprite.setPosition(720,185);
}

Target::~Target()
{
    //dtor
}
sf::Sprite Target::getSprite()
{
    return m_sprite;
}

void Target::handle_input()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && getPosition().y>120 )
        moveUp();

    else
        stopUp();

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)&& getPosition().y < 250)
        moveDown();

    else
        stopDown();

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && getPosition().x > 550)
        moveLeft();

    else
        stopLeft();

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)&& getPosition().x <885)
        moveRight();
    else
        stopRight();

        checkPosition();

}

void Target::moveUp()
{
    upPressed=true;
}
void Target::stopUp()
{
    upPressed=false;
}
void Target::moveDown()
{
    downPressed=true;
}
void Target::stopDown()
{
    downPressed=false;
}
void Target::moveLeft()
{
    leftPressed=true;
}
void Target::stopLeft()
{
    leftPressed=false;
}
void Target::moveRight()
{
    rightPressed=true;
}
void Target::stopRight()
{
    rightPressed=false;
}

void Target::update(sf::Time dt)
{
    sf::Vector2f movement(0.f, 0.f);
    if (upPressed)
        movement.y -= 100.f;
    if (downPressed)
        movement.y += 100.f;
    if (leftPressed)
        movement.x -= 100.f;
    if (rightPressed)
        movement.x += 100.f;

    m_sprite.move(movement*dt.asSeconds());

}
void Target::checkPosition()
{
    if(getPosition().x>886 || getPosition().x<549 || getPosition().y>251 || getPosition().y<119)
     m_sprite.setPosition(720,185);
}

sf::Vector2f Target::getPosition()
{
    return m_sprite.getPosition();
}

void Target::spawn()
{
    m_sprite.setPosition(720,185);
}
void Target::setSpritePosition(int x,int y)
{
    m_sprite.setPosition(x,y);
}
void Target::setSpritePosition(sf::Vector2f shootpos)
{
    m_sprite.setPosition(shootpos);
}

