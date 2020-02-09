#include "Football.h"


Football::Football()
{
    m_texture.loadFromFile("ball.png");
    m_sprite.setTexture(m_texture);
    m_sprite.setPosition(700,580);

    goalbuffer.loadFromFile("goalmusic.wav");
    missbuffer.loadFromFile("misssound.wav");
    whistlebuffer.loadFromFile("whistle.wav");

    gsound.setBuffer(goalbuffer);
    msound.setBuffer(missbuffer);
    wsound.setBuffer(whistlebuffer);
}

Football::~Football()
{
    //dtor
}
sf::Sprite Football::getSprite()
{
    return m_sprite;
}
//ss

sf::Vector2f Football::getPosition()
{
    return m_sprite.getPosition();
}

bool Football::kick(sf::Vector2f targetPosition,sf::Vector2f &newpos)
{

    if(newpos.x!=static_cast<int>(targetPosition.x))

                    {
                        float u;
                        u=((580-targetPosition.y)/(targetPosition.x-700));
                        if(u<0)
                            u*=(-1);



                        if(newpos.x < targetPosition.x)
                            newpos.x +=1;
                        else if(newpos.x > targetPosition.x)
                            newpos.x -=1;
                        if(newpos.y > targetPosition.y)
                            newpos.y -=u;
                        else if(newpos.y < targetPosition.y)
                            newpos.y +=u;

                        m_sprite.setPosition(newpos);
                        return 0;


                    }

                   else
                    {
                        return 1;
                    }


}

void Football::goalSound()
{

    gsound.play();
}
void Football::missSound()
{
   msound.play();
}
void Football::whistleSound()
{
    wsound.play();
    Sleep(750);
}
void Football::spawn()
{
     m_sprite.setPosition(700,580);
}
