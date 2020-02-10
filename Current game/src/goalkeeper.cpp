#include "goalkeeper.h"
#include"windows.h"

Goalkeeper::Goalkeeper()
{
    m_texture.loadFromFile("gkspriteblue.png");
    m_sprite.setTexture(m_texture);

    m_sprite.setTextureRect(sf::IntRect(0,0,120,150));
    m_sprite.setPosition(675,180);
    m1_texture.loadFromFile("gksprite.png");
}

Goalkeeper::~Goalkeeper()
{
    //dtor
}
void Goalkeeper::setToRed()
{
    m_sprite.setTexture(m1_texture);
}
void Goalkeeper::setToBlue()
{
    m_sprite.setTexture(m_texture);
}
sf::Sprite Goalkeeper::getSprite()
{
    return m_sprite;
}

int Goalkeeper::divePosition()
{
    srand((unsigned) time(0));
    int rnum=(rand()%4);
    return rnum;
}


void Goalkeeper::kick(int n,float pos)
{
    if (pos>775)
    {
        switch(n)
        {

        case 0:
        {
             m_sprite.setTextureRect(sf::IntRect(121,0,168,140));
             m_sprite.setPosition(725,150);

             break;
        }

        case 1:
        {
            m_sprite.setTextureRect(sf::IntRect(295,0,190,160));
            m_sprite.setPosition(740,140);

            break;

        }
         case 2:
        {
            m_sprite.setTextureRect(sf::IntRect(170,690,127,160));
           m_sprite.setPosition(700,150);

            break;

        }
        case 3:
        {
           m_sprite.setTextureRect(sf::IntRect(303,660,170,127));
           m_sprite.setPosition(745,110);
            break;
        }
        }

    }

    else if(pos<675)
    {
       switch (n)
       {
            case 0:
        {
             m_sprite.setTextureRect(sf::IntRect(0,148,197,129));
             m_sprite.setPosition(510,110);
            break;

        }
         case 1:
        {
           m_sprite.setTextureRect(sf::IntRect(203,150,125,185));
          m_sprite.setPosition(600,120);

            break;
        }
         case 2:
        {
            m_sprite.setTextureRect(sf::IntRect(0,500,197,185));
           m_sprite.setPosition(510,140);

            break;

        }
        case 3:
        {
           m_sprite.setTextureRect(sf::IntRect(210,500,180,145));
           m_sprite.setPosition(550,150);

            break;

        }
       }

    }

    else
    {
        switch (n)
        {
            case 0:
        {
             m_sprite.setTextureRect(sf::IntRect(0,0,120,150));
             m_sprite.setPosition(675,180);
              break;
        }

         case 1:
        {
            m_sprite.setTextureRect(sf::IntRect(0,280,120,185));
            m_sprite.setPosition(660,110);

            break;
        }
         default:
            {
                 m_sprite.setTextureRect(sf::IntRect(0,280,120,185));
                 m_sprite.setPosition(660,110);
            }

        }
    }



    }

    void Goalkeeper::spawn()
    {
         m_sprite.setTextureRect(sf::IntRect(0,0,120,150));
         m_sprite.setPosition(675,180);
    }


void Goalkeeper::dive0()
{

    is0pressed=true;

}
void Goalkeeper::dive1()
{

is1pressed=true;
}
void Goalkeeper::dive2()
{

is2pressed=true;
}
void Goalkeeper::dive3()
{

is3pressed=true;
}
void Goalkeeper::dive4()
{

    is4pressed=true;

}
void Goalkeeper::dive5()
{

is5pressed=true;
}
void Goalkeeper::dive6()
{

is6pressed=true;
}
void Goalkeeper::dive7()
{

is7pressed=true;
}
void Goalkeeper::dive8()
{

is8pressed=true;
}
void Goalkeeper::dive9()
{

is9pressed=true;
}


void Goalkeeper::nodive0()
{

    is0pressed=false;

}
void Goalkeeper::nodive1()
{

is1pressed=false;
}
void Goalkeeper::nodive2()
{

is2pressed=false;
}
void Goalkeeper::nodive3()
{

is3pressed=false;
}
void Goalkeeper::nodive4()
{

    is4pressed=false;

}
void Goalkeeper::nodive5()
{

is5pressed=false;
}
void Goalkeeper::nodive6()
{

is6pressed=false;
}
void Goalkeeper::nodive7()
{

is7pressed=false;
}
void Goalkeeper::nodive8()
{

is8pressed=false;
}
void Goalkeeper::nodive9()
{

is9pressed=false;
}


   void Goalkeeper::update()
   {
       if(is0pressed)
       {
           m_sprite.setTextureRect(sf::IntRect(121,0,168,140));
             m_sprite.setPosition(725,150);
       }
        if(is1pressed)
       {
           m_sprite.setTextureRect(sf::IntRect(295,0,190,160));
            m_sprite.setPosition(740,140);

       }
        if(is2pressed)
       {
            m_sprite.setTextureRect(sf::IntRect(170,690,127,160));
           m_sprite.setPosition(700,150);
       }
        if(is3pressed)
       {
            m_sprite.setTextureRect(sf::IntRect(303,660,170,127));
           m_sprite.setPosition(745,110);

       }
        if(is4pressed)
       {
            m_sprite.setTextureRect(sf::IntRect(0,148,197,129));
             m_sprite.setPosition(510,110);
       }
        if(is5pressed)
       {
            m_sprite.setTextureRect(sf::IntRect(203,150,125,185));
          m_sprite.setPosition(600,120);
       }
        if(is6pressed)
       {
           m_sprite.setTextureRect(sf::IntRect(0,500,197,185));
           m_sprite.setPosition(510,140);

       }
        if(is7pressed)
       {
           m_sprite.setTextureRect(sf::IntRect(210,500,180,145));
           m_sprite.setPosition(550,150);
       }
        if(is8pressed)
       {
            m_sprite.setTextureRect(sf::IntRect(0,0,120,150));
             m_sprite.setPosition(675,180);
       }
        if(is9pressed)
       {
            m_sprite.setTextureRect(sf::IntRect(0,280,120,185));
            m_sprite.setPosition(660,110);
       }

   }

void Goalkeeper::resetPosition()
{
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
}

