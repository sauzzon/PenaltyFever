#ifndef GOALPOST_H
#define GOALPOST_H
#include<SFML/Graphics.hpp>

class Goalpost
{
    public:
        Goalpost();
        virtual ~Goalpost();

        sf::Sprite getSprite();

    protected:

    private:
        sf::Texture m_texture;
        sf::Sprite m_sprite;
};

#endif // GOALPOST_H
