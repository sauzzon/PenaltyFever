#ifndef GOALPOST_H
#define GOALPOST_H
#include<SFML/Graphics.hpp>

class Goalpost
{
public:
    Goalpost();
    virtual ~Goalpost();
    sf::Sprite getSprite();
    void draw(sf::RenderWindow &window);

protected:

private:
    sf::Texture m_texture;
    sf::Sprite m_sprite;
     sf::Texture dboxSemiTexture;
    sf::Sprite dboxSemiSprite;
    sf::RectangleShape line,line1,line2,line3,line4,line5,line6;
};

#endif // GOALPOST_H
