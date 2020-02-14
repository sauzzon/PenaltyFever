#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include<SFML/Audio.hpp>

#include <iostream>
#include<sstream>

#include "Football.h"
#include "Shooter.h"
#include "Goalpost.h"
#include "Goalkeeper.h"
#include "Target.h"
#include "Collision.h"
#include "mainmenu.h"


#include "windows.h"




class Game
{
public:
    Game();
    void run();


private:
    void processEvents();
    void update();
    void render();
    void Detection();
    void toogle();



private:

    sf::RenderWindow window;
    sf::Event event;
    sf::Music music;
    sf::Texture hillTexture;
    sf::Sprite hillSprite;

    sf::Texture goalTextTexture;
    sf::Sprite goalTextSprite;
    sf::Sprite goalTextSprite1;

    sf::Texture whataSaveTexture;
    sf::Sprite whataSaveSprite;
    sf::Sprite whataSaveSprite1;

    sf::Texture close1;

    sf::RectangleShape rectangle2,rectangle;



    // The game will always be in one of four states
    enum class State
    {
        HOME_PAGE, SPAUSED, MPAUSED, GAME_OVER,SINGLE_PLAYER,MULTI_PLAYER,ABOUT,HOWTOPLAY, PLAYER_INPUT, NEWGAME
    };

    State state;

    sf::Vector2f resolution;

    //clock for everything
    sf::Clock clock;

    //how long has the game state been active
    sf::Time gameTimeTotal;

    // objects of the game
    Football football;
    Shooter shooter;
    Goalpost goalpost;
    Goalkeeper goalkeeper;
    Target target;
    mainmenu menu0,menu1,menu2,menu3,menu4;
    mainmenu main_menu;

    //parameters of the game
    sf::Vector2f newpos;

    bool holdButtonO = false;
    bool hitstarget = false;
    bool hitskeeper = false;
    bool timeToRespawn=false;
    bool isBallShoot=false;

    bool roleExchange=false;

    bool tooglePlayer=false;
    bool suddenDeath=false;
    int timeForSuddenDeath=0;
    bool fromHome = false;



    //scoring
    int score=0;
    int shots=0;
    int saved=0;

    int score1=0;
    int shots1=0;
    int saved1=0;

    void resetScore();


    //font
    sf::Font font;
    sf::Font titlefont;
    sf::Font gameOverfont;
    sf::Text goalText;
    sf::Text whataSaveText;
    sf::Text resume;
    sf::Text quittomain;
    sf::Text howtoplay;
    sf::Text aboutgame;
    sf::Text title;
    sf::Text teamRed;
    sf::Text teamBlue;


    sf::Text suddenDeathText;

    sf::String playerInput;
    sf::Text playerText;





};

#endif // GAME_H
