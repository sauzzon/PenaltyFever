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

bool Goalkeeper::handle_input()
{
    diveKeyPressed=false;

     if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            {
                is0pressed=true;
                diveKeyPressed=true;

            }
            else
            {
                is0pressed=false;

            }


            if(sf::Keyboard::isKeyPressed(sf::Keyboard::C))
            {

                is1pressed=true;
                 diveKeyPressed=true;
            }
             else
            {
                is1pressed=false;

            }

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::X))
            {
                 is2pressed=true;
                  diveKeyPressed=true;

            }
             else
            {
                is2pressed=false;
            }

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::E))
            {
                 is3pressed=true;
                  diveKeyPressed=true;
            }
             else
            {
                is3pressed=false;
            }

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
            {
                 is4pressed=true;
                  diveKeyPressed=true;
            }
             else
            {
                is4pressed=false;
            }

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            {
                 is5pressed=true;
                  diveKeyPressed=true;

            }
             else
            {
              is5pressed=false;
            }

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
            {
                 is6pressed=true;
                  diveKeyPressed=true;

            }
             else
            {
                is6pressed=false;
            }

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            {
                 is7pressed=true;
                  diveKeyPressed=true;
            }
             else
            {
                is7pressed=false;
            }

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::F))
            {

                 is8pressed=true;
                  diveKeyPressed=true;

            }
             else
            {
                is8pressed=false;
            }

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            {
                 is9pressed=true;
                  diveKeyPressed=true;
            }
             else
            {
                is9pressed=false;
            }

            if(diveKeyPressed)
            {
                return 1;
            }
            else
                return 0;

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
    is0pressed=false;
         is1pressed=false;
          is2pressed=false;
           is3pressed=false;
            is4pressed=false;
             is5pressed=false;
              is6pressed=false;
               is7pressed=false;
                is8pressed=false;
                 is9pressed=false;
}

