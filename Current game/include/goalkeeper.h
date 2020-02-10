#ifndef GOALKEEPER_H
#define GOALKEEPER_H

#include<SFML/Graphics.hpp>

class Goalkeeper
{
    public:
        Goalkeeper();
        virtual ~Goalkeeper();
        sf::Sprite getSprite();
        void kick(int,float);
        void spawn();
         sf::Vector2f getPosition();
         void goalSound();
         int divePosition();
         void setToBlue();
         void setToRed();

         void dive0();
         void dive1();
         void dive2();
         void dive3();
         void dive4();
         void dive5();
         void dive6();
         void dive7();
         void dive8();
         void dive9();

         void nodive0();
         void nodive1();
         void nodive2();
         void nodive3();
         void nodive4();
         void nodive5();
         void nodive6();
         void nodive7();
         void nodive8();
         void nodive9();



         void update();

         void resetPosition();




    protected:

    private:
        sf::Texture m_texture;
        sf::Texture m1_texture;
        sf::Sprite m_sprite;

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


};

#endif // GOALKEEPER_H
