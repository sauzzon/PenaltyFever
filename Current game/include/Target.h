#ifndef TARGET_H
#define TARGET_H
#include<SFML/Graphics.hpp>

class Target
{
public:
    Target();
    virtual ~Target();
    sf::Sprite getSprite();


    void handle_input();

    void moveUp();
    void stopUp();
    void moveDown();
    void stopDown();
    void moveLeft();
    void stopLeft();
    void moveRight();
    void stopRight();
    void spawn();
    void setSpritePosition(int,int);
    void setSpritePosition(sf::Vector2f);





    sf::Vector2f getPosition();

    void update(sf::Time);

protected:

private:
    sf::Texture m_texture;
    sf::Sprite m_sprite;


    bool upPressed=false;
    bool downPressed=false;
    bool leftPressed=false;
    bool rightPressed=false;
};

#endif // TARGET_H
