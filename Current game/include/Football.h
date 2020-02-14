#ifndef FOOTBALL_H
#define FOOTBALL_H
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include"windows.h"

class Football
{
public:
    Football();
    virtual ~Football();

    sf::Sprite getSprite();
    bool kick(sf::Vector2f,sf::Vector2f &newpos);
    void spawn();
    sf::Vector2f getPosition();

    void goalSound();
    void missSound();
    void whistleSound();
    void draw(sf::RenderWindow &window);
    void draw(sf::RenderWindow &window,int,int,int,int);


protected:

private:
    sf::Texture m_texture;
    sf::Sprite m_sprite;
    sf::SoundBuffer goalbuffer;
    sf::Sound gsound;
    sf::SoundBuffer missbuffer;
    sf::Sound msound;
    sf::SoundBuffer whistlebuffer;
    sf::Sound wsound;
    sf::CircleShape ballpos;

    sf::Sprite scoregoal;
    sf::Sprite scoregoal1;
    sf::Texture scoregoaltexture;
    sf::Sprite scoremiss;
    sf::Sprite scoremiss1;
    sf::Texture scoremisstexture;
};

#endif // FOOTBALL_H
