#ifndef MAINMENU_H
#define MAINMENU_H
#include<SFML/Graphics.hpp>
#include "windows.h"
#include<string.h>
class mainmenu
{
public:
    mainmenu();
    virtual ~mainmenu();
    sf::Sprite getsprite();
    sf::Text gettext();
    void setcolor();
    void resetcolor();
    bool checker();
    void setstring(std::string);
    void setpos(float,float);
private:
    sf::Texture m_texture;
    sf::Sprite m_sprite;
    sf::Font m_font;
    sf::Text m_textstart;
    sf::Text m_textabout;
    sf::Text m_texthow;
    sf::Text m_textquit;

};

#endif // MENU_hpp

