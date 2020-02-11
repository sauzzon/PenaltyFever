#include "Game.h"
using std::string;
Game::Game()
:window(sf::VideoMode(sf::VideoMode::getDesktopMode().width,sf::VideoMode::getDesktopMode().height), "Penalty Fever",sf::Style::Fullscreen)
{

    music.openFromFile("cl.wav");
    music.play();

    //start with home page state
    state = State::HOME_PAGE;

    //initialize temporary position to initial position
    newpos.x=700;
    newpos.y=580;



    //font and texts
    gameOverfont.loadFromFile("LobsterTwo-Bold.otf");
    font.loadFromFile("Quicksand-Regular.otf");
    titlefont.loadFromFile("mymenu.ttf");

//    goalText.setFont(font);
//    whataSaveText.setFont(font);

    AttemptText.setFont(font);
    saveText.setFont(font);
    scoreText.setFont(font);
    suddenDeathText.setFont(gameOverfont);



    Attempt1Text.setFont(font);
    save1Text.setFont(font);
    score1Text.setFont(font);
    resume.setFont(font);
    quittomain.setFont(font);
    aboutgame.setFont(font);
    howtoplay.setFont(font);
    title.setFont(titlefont);

    //string
    resume.setString(L"RESUME");
    quittomain.setString(L"MAINMENU");
    aboutgame.setString(L"Penalty Fever is a fun\ngame for Penalty Practice in football.\nIt was created by\nSaujann, Sandeep , Sangam\nfor CPP project\n\nENJOY IT !!!!");
    howtoplay.setString(L"Use arrow keys to position target\nUse spacebar to shoot\nUse Q,W,E,A,S,D,F,Z,X,C to dive");
    title.setString(L"PENALTY  FEVER");
    suddenDeathText.setString("You Entered the Sudden Death Mode");





//    goalText.setString("Goal!!!");
//    whataSaveText.setString("What a Save!!!");

//    goalText.setPosition (600,300);
//    whataSaveText.setPosition (420,300);

    score1Text.setPosition (1100,5);
    Attempt1Text.setPosition(1100,120);
    save1Text.setPosition(1100,60);

     scoreText.setPosition (20,5);
    AttemptText.setPosition(20,120);
    saveText.setPosition(20,60);
    resume.setPosition(600,350);
    quittomain.setPosition(600,500);
    aboutgame.setPosition(530,250);
    howtoplay.setPosition(530,250);
    title.setPosition(250,0);
    suddenDeathText.setPosition(window.getSize().x/8, window.getSize().y/2);

    scoreText.setStyle(sf::Text::Bold);
    AttemptText.setStyle(sf::Text::Bold);
    saveText.setStyle(sf::Text::Bold);

    score1Text.setStyle(sf::Text::Bold);
    Attempt1Text.setStyle(sf::Text::Bold);
    save1Text.setStyle(sf::Text::Bold);


    goalText.setCharacterSize(90);
    whataSaveText.setCharacterSize(80);

    scoreText.setCharacterSize(25);
    AttemptText.setCharacterSize(25);
    saveText.setCharacterSize(25);
     suddenDeathText.setCharacterSize(80);


    score1Text.setCharacterSize(25);
    Attempt1Text.setCharacterSize(25);
    save1Text.setCharacterSize(25);
    resume.setCharacterSize(50);
    aboutgame.setCharacterSize(25);
    howtoplay.setCharacterSize(25);
    quittomain.setCharacterSize(50);
    title.setCharacterSize(75);

//    goalText.setFillColor(sf::Color::Blue);
//    whataSaveText.setFillColor(sf::Color::Blue);

    scoreText.setFillColor(sf::Color::Red);
    saveText.setFillColor(sf::Color::Red);
    AttemptText.setFillColor(sf::Color::Red);

    score1Text.setFillColor(sf::Color::Blue);
    save1Text.setFillColor(sf::Color::Blue);
    Attempt1Text.setFillColor(sf::Color::Blue);
    resume.setFillColor(sf::Color::White);
    quittomain.setFillColor(sf::Color::White);
    howtoplay.setFillColor(sf::Color::White);
    aboutgame.setFillColor(sf::Color::White);
    title.setFillColor(sf::Color::Black);



    //hill background
    hillTexture.loadFromFile("cartoonhill.png");
    hillSprite.setTexture(hillTexture);



    //goaltext
    goalTextTexture.loadFromFile("goalText.png");
    goalTextSprite.setTexture(goalTextTexture);
    goalTextSprite.setPosition(450,280);
    goalTextSprite.scale(0.5,0.5);




    //whatasavetext
    whataSaveTexture.loadFromFile("whataSave.png");
    whataSaveSprite.setTexture(whataSaveTexture);
    whataSaveSprite.setPosition(380,300);

    //score sprites
    scoregoaltexture.loadFromFile("scoregoal.png");
    scoregoal.setTexture(scoregoaltexture);
    scoregoal1.setTexture(scoregoaltexture);

    //scoregoal.setPosition(sf::Vector2f(20,85));
    //scoregoal1.setPosition(sf::Vector2f(1100,85));

    scoregoal.setScale(0.03f,0.03f);
    scoregoal1.setScale(0.03f,0.03f);


    scoremisstexture.loadFromFile("scoremiss.png");
    scoremiss.setTexture(scoremisstexture);
    scoremiss1.setTexture(scoremisstexture);

    //scoremiss.setPosition(sf::Vector2f(20,185));
    //scoremiss1.setPosition(sf::Vector2f(1100,185));

    scoremiss.setScale(0.05f,0.05f);
    scoremiss1.setScale(0.05f,0.05f);


     //dbox line
    line.setSize(sf::Vector2f(window.getSize().x,3));
    line.setPosition(sf::Vector2f(0,290));
    line.setFillColor(sf::Color::White);

    line1.setSize(sf::Vector2f(183,3));
    line1.setRotation(90);
    line1.setPosition(sf::Vector2f(400,290));

    line2.setSize(sf::Vector2f(640,3));
    line2.setPosition(sf::Vector2f(400,470));
    line2.setFillColor(sf::Color::White);

    line3.setSize(sf::Vector2f(180,3));
    line3.setRotation(90);
    line3.setPosition(sf::Vector2f(1040,290));

    //
    line4.setSize(sf::Vector2f(433,3));
    line4.setRotation(90);
    line4.setPosition(sf::Vector2f(170,290));

    line5.setSize(sf::Vector2f(430,3));
    line5.setRotation(90);
    line5.setPosition(sf::Vector2f(1270,290));

    line6.setSize(sf::Vector2f(1100,3));
    line6.setPosition(sf::Vector2f(170,720));
    line6.setFillColor(sf::Color::White);

    close1.loadFromFile("closeit.png");

    //about
          rectangle.setSize(sf::Vector2f(500,500));
          rectangle.setOutlineThickness(20);
          rectangle.setOutlineColor(sf::Color::White);
          rectangle.setPosition(500,200);
          rectangle.setFillColor(sf::Color::Black);


          rectangle2.setSize(sf::Vector2f(20,20));
          rectangle2.setPosition(1000,180);
          rectangle2.setTexture(&close1);
          //rectangle2.setFillColor(sf::Color::Blue);





    //
    dboxSemiTexture.loadFromFile("dbox.png");
    dboxSemiSprite.setTexture(dboxSemiTexture);
    dboxSemiSprite.setPosition(sf::Vector2f(580,720));
    dboxSemiSprite.setScale(2.0f,2.0f);

    //
    ballpos.setRadius(6.0f);
    //ballpos.setOutlineThickness(2);
    //ballpos.setOutlineColor(sf::Color::White);
    ballpos.setFillColor(sf::Color::White);
    ballpos.setPosition(717,590);





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
            if (event.type == sf::Event::KeyPressed)

                //pause the game
                if(event.key.code==sf::Keyboard::Escape && (state == State::SINGLE_PLAYER || state == State::MULTI_PLAYER))
                {
                    state=State::PAUSED;
                }
                //restart while pause
                if(state == State::PAUSED)
                {
                    if(event.key.code==sf::Mouse::Left && state==State::PAUSED && resume.getGlobalBounds().contains(globalposition.x,globalposition.y))
                    {
                        state=State::SINGLE_PLAYER;
                        //restart clock so there is not a frame jump
                        clock.restart();
                    }
                }

                if(state == State::PAUSED)
                {
                    if(event.key.code==sf::Mouse::Left && state==State::PAUSED && resume.getGlobalBounds().contains(globalposition.x,globalposition.y))
                    {
                        state=State::MULTI_PLAYER;
                        //restart clock so there is not a frame jump
                        clock.restart();
                    }
                }

                //quit when paused
                if(event.key.code==sf::Mouse::Left && state==State::PAUSED && rectangle2.getGlobalBounds().contains(globalposition.x,globalposition.y))
                {
                    window.close();

                }


                //quit to main menu when paused

                if(event.key.code==sf::Mouse::Left && state==State::PAUSED && quittomain.getGlobalBounds().contains(globalposition.x,globalposition.y))
                {
                    resetScore();
                    clock.restart();
                    tooglePlayer=true;
                    timeToRespawn=true;
                    roleExchange=false;



                    state=State::HOME_PAGE;

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

                //returnfromabout
                //sf::Vector2i globalposition=sf::Mouse::getPosition();

                if(event.key.code==sf::Mouse::Left && state==State::ABOUT && rectangle2.getGlobalBounds().contains(globalposition.x,globalposition.y))
                {
                     state=State::HOME_PAGE;
                }

                //returnfromhowtoplay
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
                Sleep(2500);

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

             if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && target.getPosition().y>120 )
                target.moveUp();

            else
                    target.stopUp();

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)&& target.getPosition().y < 250)
                target.moveDown();

                else
                    target.stopDown();

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && target.getPosition().x > 550)
                target.moveLeft();

                else
                    target.stopLeft();

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)&& target.getPosition().x <890)
                target.moveRight();
                else
                    target.stopRight();


            //

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

            //after exchanging role


            if(roleExchange)

            {
                target.setSpritePosition(2000,2000);

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            {
                 football.whistleSound();
                shooter.kick();
                holdButtonO=true;
                goalkeeper.dive0();

            }
            else
            {
                goalkeeper.nodive0();

            }


            if(sf::Keyboard::isKeyPressed(sf::Keyboard::C))
            {
                 football.whistleSound();
                shooter.kick();
                holdButtonO=true;
                goalkeeper.dive1();
            }
             else
            {
                goalkeeper.nodive1();

            }

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::X))
            {
                 football.whistleSound();
                shooter.kick();
                 holdButtonO=true;
                 goalkeeper.dive2();


            }
             else
            {
                goalkeeper.nodive2();
            }

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::E))
            {
                 football.whistleSound();
                shooter.kick();
                 holdButtonO=true;
                 goalkeeper.dive3();
            }
             else
            {
                goalkeeper.nodive3();
            }

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
            {
                 football.whistleSound();
                shooter.kick();
                 holdButtonO=true;
                 goalkeeper.dive4();
            }
             else
            {
                goalkeeper.nodive4();
            }

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            {
                 football.whistleSound();
                shooter.kick();
                 holdButtonO=true;
                 goalkeeper.dive5();

            }
             else
            {
                goalkeeper.nodive5();
            }

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
            {
                 football.whistleSound();
                shooter.kick();
                 holdButtonO=true;
                 goalkeeper.dive6();

            }
             else
            {
                goalkeeper.nodive6();
            }

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            {
                 football.whistleSound();
                shooter.kick();
                 holdButtonO=true;
                 goalkeeper.dive7();
            }
             else
            {
                goalkeeper.nodive7();
            }

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::F))
            {
                 football.whistleSound();
                shooter.kick();
                 holdButtonO=true;
                 goalkeeper.dive8();

            }
             else
            {
                goalkeeper.nodive8();
            }

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            {
                 football.whistleSound();
                shooter.kick();
                 holdButtonO=true;
                 goalkeeper.dive9();
            }
             else
            {
                goalkeeper.nodive9();
            }


            goalkeeper.update();

            if(holdButtonO)
            {

                isBallShoot=football.kick(shooter.shootPosition(),newpos);


                   if(isBallShoot)
                    {
                        holdButtonO=false;

                        //goalkeeper.update();
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

             if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && target.getPosition().y>120 )
                target.moveUp();

            else
                    target.stopUp();

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)&& target.getPosition().y < 250)
                target.moveDown();

                else
                    target.stopDown();

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && target.getPosition().x > 550)
                target.moveLeft();

                else
                    target.stopLeft();

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)&& target.getPosition().x <890)
                target.moveRight();
                else
                    target.stopRight();


            //

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
            {

                football.whistleSound();
                shooter.kick();
                holdButtonO = true;
            }


            if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            {
                goalkeeper.dive0();

            }
            else
            {
                goalkeeper.nodive0();

            }


            if(sf::Keyboard::isKeyPressed(sf::Keyboard::C))
            {

                goalkeeper.dive1();
            }
             else
            {
                goalkeeper.nodive1();

            }

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::X))
            {


                 goalkeeper.dive2();


            }
             else
            {
                goalkeeper.nodive2();
            }

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::E))
            {

                 goalkeeper.dive3();
            }
             else
            {
                goalkeeper.nodive3();
            }

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
            {


                 goalkeeper.dive4();
            }
             else
            {
                goalkeeper.nodive4();
            }

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            {


                 goalkeeper.dive5();

            }
             else
            {
                goalkeeper.nodive5();
            }

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
            {


                 goalkeeper.dive6();

            }
             else
            {
                goalkeeper.nodive6();
            }

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            {


                 goalkeeper.dive7();
            }
             else
            {
                goalkeeper.nodive7();
            }

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::F))
            {


                 goalkeeper.dive8();

            }
             else
            {
                goalkeeper.nodive8();
            }

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            {

                 goalkeeper.dive9();
            }
             else
            {
                goalkeeper.nodive9();
            }
            //goalkeeper.update();

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


//end of playing state

  //end of process event

 void Game::update()
 {
 if(state ==State::SINGLE_PLAYER || state == State::MULTI_PLAYER)
   {
       //update delta time
       sf::Time dt=clock.restart();
       //update total game time
       gameTimeTotal+=dt;
        //update the target
       target.update(dt);


       //update score
        std::stringstream s,s1,s2;


        s1<<"Total Shots: "<<shots;
        s<<"Goals Scored: ";
        s2<<"Goals Missed: ";

        scoreText.setString(s.str());
        AttemptText.setString(s1.str());
        saveText.setString(s2.str());

         std::stringstream s3,s4,s5;

        s4<<"Total Shots: "<<shots1;
        s3<<"Goals Scored: ";
        s5<<"Goals Missed: ";

        score1Text.setString(s3.str());
        Attempt1Text.setString(s4.str());
        save1Text.setString(s5.str());




   }//end updating scene

 }

 void Game::render()
 {
     if(state==State::SINGLE_PLAYER || state == State::MULTI_PLAYER)
        {

            window.clear(sf::Color::Green);

            window.draw(hillSprite);
            window.draw(dboxSemiSprite);

            window.draw(line);
            window.draw(line1);
            window.draw(line2);
            window.draw(line3);
            window.draw(line4);
            window.draw(line5);
            window.draw(line6);

            window.draw(ballpos);

            window.draw(shooter.getSprite());
            window.draw(goalpost.getSprite());
            window.draw(goalkeeper.getSprite());

            if(!roleExchange && state == State::SINGLE_PLAYER)
                window.draw(target.getSprite());

            window.draw(football.getSprite());
            window.draw(AttemptText);
            window.draw(scoreText);
            window.draw(saveText);
            if(score>0)
            {
                int j=20;
                for(int i=1;i<=score;i++)
                {

                     scoregoal.setPosition(sf::Vector2f(j,35));
                     window.draw(scoregoal);
                     j=j+35;
                }
            }

            if(saved>0)
            {
                int j=20;
                for(int i=1;i<=saved;i++)
                {

                     scoremiss.setPosition(sf::Vector2f(j,80));
                     window.draw(scoremiss);
                     j=j+35;
                }
            }
            if(score1>0)
            {
                int j=1100;
                for(int i=1;i<=score1;i++)
                {

                     scoregoal1.setPosition(sf::Vector2f(j,35));
                     window.draw(scoregoal1);
                     j=j+35;
                }
            }
            if(saved1>0)
            {
                int j=1100;
                for(int i=1;i<=saved1;i++)
                {

                     scoremiss1.setPosition(sf::Vector2f(j,80));
                     window.draw(scoremiss1);
                     j=j+35;
                }
            }

             //window.draw(scoremiss);

            window.draw(Attempt1Text);
            window.draw(score1Text);
            window.draw(save1Text);
            //window.draw(scoregoal1);
            //window.draw(scoremiss1);


             if(hitstarget)
             {

                window.draw(goalTextSprite);
             }
             if(hitskeeper)
             {

                 window.draw(whataSaveSprite);

             }
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


            if(menu0.checker()==true)
            {
                menu0.setcolor();
                //window.clear();
                window.draw(menu0.getsprite());
                window.draw(title);
                window.draw(menu0.gettext());
                window.draw(menu1.gettext());
                window.draw(menu2.gettext());
                window.draw(menu3.gettext());
                window.draw(menu4.gettext());
                window.display();
            }

            else if(menu1.checker()==true)
            {
                menu1.setcolor();
                //window.clear();
                window.draw(menu0.getsprite());
                window.draw(title);
                window.draw(menu0.gettext());
                window.draw(menu1.gettext());
                window.draw(menu2.gettext());
                window.draw(menu3.gettext());
                window.draw(menu4.gettext());
                window.display();
            }

            else if(menu2.checker()==true)
            {
                 menu2.setcolor();
                //window.clear();
                window.draw(menu0.getsprite());

                window.draw(title);
                window.draw(menu0.gettext());
                window.draw(menu1.gettext());
                window.draw(menu2.gettext());
                window.draw(menu3.gettext());
                window.draw(menu4.gettext());
                window.display();
            }
            else if(menu3.checker()==true)
            {
                 menu3.setcolor();
                //window.clear();
                window.draw(menu0.getsprite());
                window.draw(title);
                window.draw(menu0.gettext());
                window.draw(menu1.gettext());
                window.draw(menu2.gettext());
                window.draw(menu3.gettext());
                window.draw(menu4.gettext());
                window.display();
            }
            else if(menu4.checker()==true)
            {
                 menu4.setcolor();
                //window.clear();
                window.draw(menu0.getsprite());
                window.draw(title);
                window.draw(menu0.gettext());
                window.draw(menu1.gettext());
                window.draw(menu2.gettext());
                window.draw(menu3.gettext());
                window.draw(menu4.gettext());
                window.display();
            }
            else{
                    menu0.resetcolor();
                    menu1.resetcolor();
                    menu2.resetcolor();
                    menu3.resetcolor();
                    menu4.resetcolor();
                    window.clear();
            window.draw(menu0.getsprite());
            window.draw(title);
            window.draw(menu0.gettext());
            window.draw(menu1.gettext());
            window.draw(menu2.gettext());
            window.draw(menu3.gettext());
            window.draw(menu4.gettext());
            window.display();
            }

        }
        if(state==State::ABOUT)
        {

          window.clear();
          window.draw(menu0.getsprite());
          window.draw(rectangle);
          window.draw(rectangle2);
          window.draw(aboutgame);
          window.display();
        }
        if(state==State::HOWTOPLAY)
        {

          window.clear();
          window.draw(menu0.getsprite());
          window.draw(rectangle);
          window.draw(rectangle2);
          window.draw(howtoplay);
          window.display();
        }

        if(state==State::PAUSED)
        {


          window.clear(sf::Color::Blue);

            window.clear(sf::Color::Blue);
            window.draw(hillSprite);

          window.draw(rectangle);
          window.draw(rectangle2);
          window.draw(resume);
          window.draw(quittomain);
          window.display();
        }

        if(state == State::GAME_OVER)
        {

            window.clear();
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
            window.draw(hillSprite);

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
//                winnerTextDisplay.setFillColor(sf::Color(245,20,20));
                winnerText<<"Congratulations, Team Red";
                winnerTextDisplay.setPosition(sf::Vector2f(window.getSize().x/6,window.getSize().y/1.3));

            }
            else if(score < score1)
            {
//                winnerTextDisplay.setFillColor(sf::Color(0,50,245));
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
            Sleep(6000);
            resetScore();
            state= State::HOME_PAGE;

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




