#ifndef GAME_H
#define GAME_H

#include "iostream"
#include "items.h""

class Game
{
    public:
        Game();
        Game(Item **snake, sf::RenderWindow *app_instance);
        virtual ~Game();
        void control_keboard_events();

    protected:



    private:
        Item **items_ptr;
        sf::RenderWindow *app_ptr;


};

#endif // GAME_H
