#include "mainmenu.h"
using std::string;
mainmenu::mainmenu()
{
    m_texture.loadFromFile("Resources/Images/background.png");
    m_sprite.setTexture(m_texture);
    m_font.loadFromFile("Resources/Fonts/mymenu.ttf");

    m_textstart.setFont(m_font);
    m_textstart.setCharacterSize(50);


    //draw gameover
     gameOverfont.loadFromFile("Resources/Fonts/LobsterTwo-Bold.otf");

}

mainmenu::~ mainmenu()
{
    //dtor
}
void mainmenu::setstring(std::string start)
{
    m_textstart.setString(start);
}
sf::Sprite mainmenu::getsprite()
{
    return m_sprite;
}
sf::Text mainmenu::gettext()
{
    return m_textstart;
}
void mainmenu::setcolor()
{
    m_textstart.setFillColor(sf::Color::White);
}
void mainmenu::resetcolor()
{
    m_textstart.setFillColor(sf::Color::Black);
}
bool mainmenu::checker()
{
    sf::Vector2i globalposition=sf::Mouse::getPosition();
    if(m_textstart.getGlobalBounds().contains(globalposition.x,globalposition.y))
    {
        return true;
    }
    else
    {
        return false;
    }
}
void mainmenu::setpos(float x,float y)
{
    m_textstart.setPosition(x,y);
}

//drawing the gameover window
void mainmenu::drawGameOver(sf::RenderWindow &window,int score,int score1)
{

        sf::Text mgameOver;
        mgameOver.setFont(gameOverfont);
        mgameOver.setCharacterSize(100);
        string s = "Game Over";
        sf::Vector2f v;
        v.x = (window.getSize().x)/3.5;
        v.y = (window.getSize().y)/4;
        mgameOver.setPosition(sf::Vector2f(v));

        sf::RectangleShape rect;
        rect.setFillColor(sf::Color(0,0,0,30));
        rect.setSize(sf::Vector2f(window.getSize()));

        mgameOver.setString(s);
        mgameOver.setFillColor(sf::Color::Black);
        window.draw(rect);
        window.draw(mgameOver);

        sf::Text winnerTextDisplay;
        sf::Text scoreDisplay;
        sf::Text score1Display;
        scoreDisplay.setFont(gameOverfont);
        winnerTextDisplay.setFont(gameOverfont);
        score1Display.setFont(gameOverfont);
        scoreDisplay.setFillColor(sf::Color(245,20,20));
        score1Display.setFillColor(sf::Color(0,50, 245));

        std::stringstream mScore;
        std::stringstream winnerText;
        std::stringstream mScore1;

        mScore<<"  Team Red : "<<score;
        mScore1<<"  Team Blue: "<<score1;
        winnerTextDisplay.setFillColor(sf::Color::Black);

        if(score>score1)
        {
            winnerText<<"Congratulations, Team Red";
            winnerTextDisplay.setPosition(sf::Vector2f(window.getSize().x/6,window.getSize().y/1.3));
        }
        else if(score < score1)
        {
            winnerText<<"Congratulations, Team Blue";
            winnerTextDisplay.setPosition(sf::Vector2f(window.getSize().x/6,window.getSize().y/1.3));
        }
        scoreDisplay.setCharacterSize(60);
        scoreDisplay.setPosition(sf::Vector2f(window.getSize().x/3,window.getSize().y/2.1));
        scoreDisplay.setString(mScore.str());
        score1Display.setCharacterSize(60);
        score1Display.setPosition(sf::Vector2f(window.getSize().x/3,window.getSize().y/1.7));
        score1Display.setString(mScore1.str());
        winnerTextDisplay.setCharacterSize(70);
        winnerTextDisplay.setString(winnerText.str());

        window.draw(score1Display);
        window.draw(scoreDisplay);
        window.draw(winnerTextDisplay);
        window.display();
}

