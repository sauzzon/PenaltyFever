#include "Football.h"


Football::Football()
{
    m_texture.loadFromFile("Resources/Images/ball.png");
    m_sprite.setTexture(m_texture);
    m_sprite.setPosition(700,580);


     //score sprites
    scoregoaltexture.loadFromFile("Resources/Images/scoregoal.png");
    scoregoal.setTexture(scoregoaltexture);
    scoregoal1.setTexture(scoregoaltexture);
    scoregoal.setScale(0.03f,0.03f);
    scoregoal1.setScale(0.03f,0.03f);
    scoremisstexture.loadFromFile("Resources/Images/scoremiss.png");
    scoremiss.setTexture(scoremisstexture);
    scoremiss1.setTexture(scoremisstexture);
    scoremiss.setScale(0.05f,0.05f);
    scoremiss1.setScale(0.05f,0.05f);

    ballpos.setRadius(6.0f);
    ballpos.setFillColor(sf::Color::White);
    ballpos.setPosition(717,590);

    goalbuffer.loadFromFile("Resources/Music/goalmusic.wav");
    missbuffer.loadFromFile("Resources/Music/misssound.wav");
    whistlebuffer.loadFromFile("Resources/Music/whistle.wav");

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

void Football::draw(sf::RenderWindow &window)
{
    window.draw(ballpos);
    window.draw(m_sprite);
}
void Football::draw(sf::RenderWindow &window,int score,int score1,int saved,int saved1)
{
if(score>0)
        {
            int j=20;
            for(int i=1; i<=score; i++)
            {
                scoregoal.setPosition(sf::Vector2f(j,130));
                window.draw(scoregoal);
                j=j+35;
            }
        }
        if(saved>0)
        {
            int j=20;
            for(int i=1; i<=saved; i++)
            {
                scoremiss.setPosition(sf::Vector2f(j,150));
                window.draw(scoremiss);
                j=j+35;
            }
        }
        if(score1>0)
        {
            int j=1100;
            for(int i=1; i<=score1; i++)
            {
                scoregoal1.setPosition(sf::Vector2f(j,130));
                window.draw(scoregoal1);
                j=j+35;
            }
        }
        if(saved1>0)
        {
            int j=1100;
            for(int i=1; i<=saved1; i++)
            {
                scoremiss1.setPosition(sf::Vector2f(j,150));
                window.draw(scoremiss1);
                j=j+35;
            }
        }
}
