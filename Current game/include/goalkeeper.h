#ifndef GOALKEEPER_H
#define GOALKEEPER_H

#include<SFML/Graphics.hpp>

class Goalkeeper
{
public:
    Goalkeeper();
    virtual ~Goalkeeper();
    sf::Sprite getSprite();

    bool handle_input();
    void kick(int,float);
    void spawn();
    sf::Vector2f getPosition();
    void goalSound();
    int divePosition();
    void setToBlue();
    void setToRed();


    void update();

    void resetPosition();




protected:

private:
    sf::Texture m_texture;
    sf::Texture m1_texture;
    sf::Sprite m_sprite;
    bool diveKeyPressed=false;

    bool is0pressed=false;
    bool is1pressed=false;
    bool is2pressed=false;
    bool is3pressed=false;
    bool is4pressed=false;
    bool is5pressed=false;
    bool is6pressed=false;
    bool is7pressed=false;
    bool is8pressed=false;
    bool is9pressed=false;


};

#endif // GOALKEEPER_H
