#ifndef SHOOTER_H
#define SHOOTER_H
#include<SFML/Graphics.hpp>


class Shooter
{
public:
    Shooter();
    virtual ~Shooter();
    sf::Sprite getSprite();
    void spawn();
    void kick();
    void setToBlue();
    void setToRed();
    sf::Vector2f shootPosition();

protected:

private:
    sf::Texture m_texture;
    sf::Texture m1_texture;
    sf::Sprite m_sprite;
};

#endif // SHOOTER_H
