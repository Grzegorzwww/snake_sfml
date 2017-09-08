#ifndef GAME_H
#define GAME_H

#include "iostream"
#include "items.h""
#include <SFML/System.hpp>

typedef enum {Up, Down, Right, Left} direction_t;


class Game
{
    public:
        Game();
        Game(Item **snake, sf::RenderWindow *app_instance);
        virtual ~Game();
        void control_keboard_events();
        void control_timer();
        void game_display();
        void run(bool flag);
        void do_move();



    protected:



    private:
        Item **items_ptr;
        sf::RenderWindow *app_ptr;
        sf::Time elapsed;
        sf::Clock clock;
        direction_t direction;



};

#endif // GAME_H
