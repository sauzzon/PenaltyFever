#include "Game.h"
using std::string;
Game::Game()
    :window(sf::VideoMode(sf::VideoMode::getDesktopMode().width,sf::VideoMode::getDesktopMode().height), "Penalty Fever",sf::Style::Fullscreen)
{
    music.openFromFile("Resources/Music/cl.wav");
    music.play();
    //start with home page state
    state = State::HOME_PAGE;
    newpos.x=700;
    newpos.y=580;

    //font and texts
    font.loadFromFile("Resources/Fonts/Quicksand-Regular.otf");
    titlefont.loadFromFile("Resources/Fonts/mymenu.ttf");
    suddenDeathText.setFont(titlefont);
    resume.setFont(font);
    quittomain.setFont(font);
    aboutgame.setFont(font);
    howtoplay.setFont(font);
    title.setFont(titlefont);
    teamRed.setFont(titlefont);
    teamBlue.setFont(titlefont);

    //string
    resume.setString(L"RESUME");
    quittomain.setString(L"MAINMENU");
    aboutgame.setString(L"Penalty Fever is a fun\ngame for Penalty Practice in football.\nIt was created by\nSaujan, Sandeep , Sangam\nfor CPP project\n\nENJOY IT !!!!");
    howtoplay.setString(L"Use arrow keys to position target\nUse spacebar to shoot\nUse Q,W,E,A,S,D,F,Z,X,C to dive");
    title.setString(L"PENALTY  FEVER");
    suddenDeathText.setString("You Entered the Sudden Death Mode");
    teamRed.setString("Team Red:");
    teamBlue.setString("Team Blue:");

    resume.setPosition(600,350);
    quittomain.setPosition(600,500);
    aboutgame.setPosition(530,250);
    howtoplay.setPosition(530,250);
    title.setPosition(250,0);
    teamRed.setPosition(20,90);
    teamBlue.setPosition(1100,90);
    suddenDeathText.setPosition(window.getSize().x/8, window.getSize().y/2);

    suddenDeathText.setCharacterSize(60);
    teamRed.setCharacterSize(35);
    teamBlue.setCharacterSize(35);
    resume.setCharacterSize(50);
    aboutgame.setCharacterSize(25);
    howtoplay.setCharacterSize(25);
    quittomain.setCharacterSize(50);
    title.setCharacterSize(75);

    resume.setFillColor(sf::Color::White);
    quittomain.setFillColor(sf::Color::White);
    howtoplay.setFillColor(sf::Color::White);
    aboutgame.setFillColor(sf::Color::White);
    title.setFillColor(sf::Color::Black);
    teamRed.setFillColor(sf::Color::Red);
    teamBlue.setFillColor(sf::Color::Blue);

    //hill background
    hillTexture.loadFromFile("Resources/Images/cartoonhill.png");
    hillSprite.setTexture(hillTexture);

    //goal text
    goalTextTexture.loadFromFile("Resources/Images/goalText.png");
    goalTextSprite.setTexture(goalTextTexture);
    goalTextSprite.setPosition(450,280);
    goalTextSprite.scale(0.5,0.5);

    //what a save text
    whataSaveTexture.loadFromFile("Resources/Images/whataSave.png");
    whataSaveSprite.setTexture(whataSaveTexture);
    whataSaveSprite.setPosition(500,350);
    whataSaveSprite.setScale(0.6,0.6);

    close1.loadFromFile("Resources/Images/closeit.png");

    //about
    rectangle.setSize(sf::Vector2f(500,500));
    rectangle.setOutlineThickness(20);
    rectangle.setOutlineColor(sf::Color::White);
    rectangle.setPosition(500,200);
    rectangle.setFillColor(sf::Color::Black);
    rectangle2.setSize(sf::Vector2f(20,20));
    rectangle2.setPosition(1000,180);
    rectangle2.setTexture(&close1);

    //homepage
    menu0.setstring("SINGLE PLAYER");
    menu0.setpos(500,300);
    menu1.setstring("MULTI PLAYER");
    menu1.setpos(500,350);
    menu2.setstring("HOW TO PLAY");
    menu2.setpos(500,400);
    menu3.setstring("ABOUT");
    menu3.setpos(500,450);
    menu4.setstring("QUIT");
    menu4.setpos(500,500);

}

void Game::run()
{
    while (window.isOpen())
    {
        processEvents();
        update();
        render();
    }
}
void Game::processEvents()
{
    sf::Vector2i globalposition=sf::Mouse::getPosition();
    while (window.pollEvent(event))
    {
        //pause the game in single player mode
        if(event.key.code==sf::Keyboard::Escape && state == State::SINGLE_PLAYER)
        {
            state=State::SPAUSED;
        }

        if(event.key.code==sf::Keyboard::Escape && state == State::MULTI_PLAYER)
        {
            state=State::MPAUSED;
        }
        //restart while pause

        if(event.key.code==sf::Mouse::Left && state==State::SPAUSED && resume.getGlobalBounds().contains(globalposition.x,globalposition.y))
        {
            state=State::SINGLE_PLAYER;
            clock.restart();
        }

        if(event.key.code==sf::Mouse::Left && state==State::MPAUSED && resume.getGlobalBounds().contains(globalposition.x,globalposition.y))
        {
            state=State::MULTI_PLAYER;
            clock.restart();
        }

        //quit when paused
        if(event.key.code==sf::Mouse::Left && (state==State::SPAUSED || state == State::MPAUSED) && rectangle2.getGlobalBounds().contains(globalposition.x,globalposition.y))
        {
            window.close();
        }
        //quit to main menu when paused
        if(event.key.code==sf::Mouse::Left && (state==State::SPAUSED || state== State::MPAUSED) && quittomain.getGlobalBounds().contains(globalposition.x,globalposition.y))
        {
            resetScore();
            clock.restart();
            tooglePlayer=true;
            timeToRespawn=true;
            roleExchange=false;
            state=State::HOME_PAGE;
            fromHome = true;
        }
        //start new game
        if(event.key.code==sf::Mouse::Left && state==State::HOME_PAGE && menu0.checker()==true)
        {
            state=State::SINGLE_PLAYER;
        }
        //start new game
        if(event.key.code==sf::Mouse::Left && state==State::HOME_PAGE && menu1.checker()==true)
        {
            state=State::MULTI_PLAYER;
        }
        //How to play
        if(event.key.code==sf::Mouse::Left && state==State::HOME_PAGE && menu2.checker()==true)
        {
            state=State::HOWTOPLAY;
        }
        //about
        if(event.key.code==sf::Mouse::Left && state==State::HOME_PAGE && menu3.checker()==true)
        {
            state=State::ABOUT;
        }

        if(event.key.code==sf::Mouse::Left && state==State::ABOUT && rectangle2.getGlobalBounds().contains(globalposition.x,globalposition.y))
        {
            state=State::HOME_PAGE;
        }

        //return from how to play
        if(event.key.code==sf::Mouse::Left && state==State::HOWTOPLAY && rectangle2.getGlobalBounds().contains(globalposition.x,globalposition.y))
        {
            state=State::HOME_PAGE;
        }
        //quit the game
        if(event.key.code==sf::Mouse::Left && state==State::HOME_PAGE && menu4.checker()==true)
        {
            window.close();
        }
    } //end event pooling

    //handle input while playing
    if(state == State::SINGLE_PLAYER || state == State::MULTI_PLAYER)
    {
        if(suddenDeath)
        {
            if(shots==shots1)
            {
                if(score1!=score)
                {
                    suddenDeath=false;
                    timeForSuddenDeath=0;
                    state=State::GAME_OVER;
                }
            }
        }

        if((shots1==5)&&(shots==5))
        {
            if(score1!=score)
                state=State::GAME_OVER;
            else
            {
                suddenDeath=true;
                timeForSuddenDeath++;
            }
        }

        if(timeToRespawn)
        {
            if(!fromHome)
                Sleep(2500);
            fromHome = false;
            newpos.x=700;
            newpos.y=580;

            football.spawn();
            goalkeeper.spawn();
            target.spawn();
            shooter.spawn();
            hitstarget = false;
            hitskeeper=false;

            if(!tooglePlayer)
            {
                goalkeeper.setToRed();
                shooter.setToBlue();
                tooglePlayer = true;
            }
            else
            {
                goalkeeper.setToBlue();
                shooter.setToRed();
                tooglePlayer = false;
            }
            timeToRespawn=false;
        }

//without exchanging role
        if(state == State::SINGLE_PLAYER)
        {
            if(!roleExchange)
            {
                target.handle_input();

                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
                {
                    football.whistleSound();
                    shooter.kick();
                    holdButtonO = true;
                }
                if( holdButtonO)
                {
                    int dive=goalkeeper.divePosition();
                    //implement ball animation after kicking
                    isBallShoot=football.kick(target.getPosition(),newpos);

                    if(isBallShoot)
                    {
                        holdButtonO=false;
                        goalkeeper.kick(dive,target.getPosition().x);
                        timeToRespawn=true;
                        shots++;
                        Detection();
                        roleExchange=true;
                    }
                }
            }//end of one role

            if(roleExchange)

            {
                target.setSpritePosition(2000,2000);

                if(goalkeeper.handle_input())
                {
                    football.whistleSound();
                    shooter.kick();
                    holdButtonO=true;
                }

                goalkeeper.update();
                if(holdButtonO)
                {
                    isBallShoot=football.kick(shooter.shootPosition(),newpos);
                    if(isBallShoot)
                    {
                        holdButtonO=false;
                        timeToRespawn=true;
                        shots1++;
                        Detection();
                        roleExchange=false;
                    }
                }
            }//end of next role
        }

        if(state == State::MULTI_PLAYER)
        {
            target.handle_input();
            goalkeeper.handle_input();
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
            {
                football.whistleSound();
                shooter.kick();
                holdButtonO = true;
            }
            if(holdButtonO)
            {
                isBallShoot=football.kick(target.getPosition(),newpos);

                if(isBallShoot)
                {
                    holdButtonO=false;
                    goalkeeper.update();
                    timeToRespawn=true;
                    Detection();
                    if(!roleExchange)
                    {
                        shots++;
                        roleExchange = true;
                    }
                    else
                    {
                        shots1++;
                        roleExchange = false;
                    }
                }
            }
        }
    }
}

void Game::Detection()
{
    if(Collision::PixelPerfectTest(football.getSprite(),goalkeeper.getSprite()))
    {
        hitskeeper = true;
        football.missSound();
        hitstarget = false;
        if(!roleExchange)
            saved++;
        else
            saved1++;
    }
    else
    {
        hitskeeper=false;
        hitstarget=true;
        football.goalSound();
        if(!roleExchange)
            score++;
        else
            score1++;
    }
}

void Game::resetScore()
{
    shots=0;
    score=0;
    saved=0;
    shots1=0;
    score1=0;
    saved1=0;
}

void Game::update()
{
    if(state ==State::SINGLE_PLAYER || state == State::MULTI_PLAYER)
    {
        sf::Time dt=clock.restart();
        //update total game time
        gameTimeTotal+=dt;
        target.update(dt);
    }

}

void Game::render()
{
    if(state==State::SINGLE_PLAYER || state == State::MULTI_PLAYER)
    {
        window.setMouseCursorVisible(false);
        window.clear();
        window.draw(hillSprite);
        goalpost.draw(window);
        window.draw(shooter.getSprite());
        window.draw(goalkeeper.getSprite());
        football.draw(window);
        window.draw(teamRed);
        window.draw(teamBlue);


        if(!roleExchange && state == State::SINGLE_PLAYER)
            window.draw(target.getSprite());

        football.draw(window,score,score1,saved,saved1);
        if(hitstarget)
            window.draw(goalTextSprite);
        if(hitskeeper)
            window.draw(whataSaveSprite);
        if(timeForSuddenDeath==1)
        {
            window.clear();
            window.draw(hillSprite);
            window.draw(suddenDeathText);
            window.display();
            Sleep(3000);
        }
        window.display();
    }

    if(state==State::HOME_PAGE)
    {
        window.setMouseCursorVisible(true);
        if(menu0.checker()==true)
            menu0.setcolor();
        else if(menu1.checker()==true)
            menu1.setcolor();
        else if(menu2.checker()==true)
            menu2.setcolor();
        else if(menu3.checker()==true)
            menu3.setcolor();
        else if(menu4.checker()==true)
            menu4.setcolor();
        else
        {
            menu0.resetcolor();
            menu1.resetcolor();
            menu2.resetcolor();
            menu3.resetcolor();
            menu4.resetcolor();
            window.clear();
        }
        window.draw(menu0.getsprite());
        window.draw(title);
        window.draw(menu0.gettext());
        window.draw(menu1.gettext());
        window.draw(menu2.gettext());
        window.draw(menu3.gettext());
        window.draw(menu4.gettext());
        window.display();
    }
    if(state==State::ABOUT)
    {
        window.setMouseCursorVisible(true);
        window.clear();
        window.draw(menu0.getsprite());
        window.draw(rectangle);
        window.draw(rectangle2);
        window.draw(aboutgame);
        window.display();
    }
    if(state==State::HOWTOPLAY)
    {
        window.setMouseCursorVisible(true);
        window.clear();
        window.draw(menu0.getsprite());
        window.draw(rectangle);
        window.draw(rectangle2);
        window.draw(howtoplay);
        window.display();
    }

    if(state==State::SPAUSED || state== State::MPAUSED)
    {
        window.setMouseCursorVisible(true);
        window.clear();
        window.draw(hillSprite);
        window.draw(rectangle);
        window.draw(rectangle2);
        window.draw(resume);
        window.draw(quittomain);
        window.display();
    }

    if(state == State::GAME_OVER)
    {
        window.setMouseCursorVisible(false);
        window.clear();
        window.draw(hillSprite);
        main_menu.drawGameOver(window,score,score1);
        Sleep(6000);

        resetScore();
        state= State::HOME_PAGE;
    }
}
