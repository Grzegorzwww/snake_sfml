#ifndef GAME_H
#define GAME_H

#include "iostream"
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include "../items.h"
#include "Menu.h"
#include <string>
#include <iomanip>

#include <sstream>




typedef enum {Up, Down, Right, Left} direction_t;

static const int SIGNLE_SNAKE_STEP = 40;
static const int DEFAULT_SNAKE_SPEED_MS = 100;

namespace sf {
        struct Timer {
                sf::Clock mC;
                float runTime;
                bool bPaused;

                Timer() {
                        bPaused = false;
                        runTime = 0;
                        mC.restart();
                }

                void Reset() {
                        mC.restart();
                        runTime = 0;
                        bPaused = false;
                }

                void Start() {
                        if (bPaused) {
                                mC.restart();
                        }
                        bPaused = false;
                }

                void Pause() {
                        if (!bPaused) {
                                runTime += mC.getElapsedTime().asSeconds();
                        }
                        bPaused = true;
                }

                float GetElapsedSeconds() {
                        if (!bPaused) {
                                return runTime + mC.getElapsedTime().asSeconds();
                        }
                        return runTime;
                }
        };
}



class Game
{
    public:
        Game();
        Game(Item **snake, sf::RenderWindow *app_instance);
        virtual ~Game();
        //void (*)(void)

        Menu *menu;


        void control_events();
        void control_timer();
        void game_display();
        void game_init();
        void do_move();
        void create_new_snake_item();
        void control_window_range(SnakeHead *head);
        void new_game();
        void collision_detect();
        void make_item_to_eat();
        void pauzeGame();
        void resumeGame();



    private:

        sf::RenderWindow *app_ptr;
        sf::Time elapsed;
        sf::Time play_time;
        sf::Clock play_clock;
        sf::Clock clock;
        sf::Clock food_clock;
        sf::Clock poison_clock;
        direction_t direction;

        Item **items_ptr;
        Item *item_eat;
        Item *item_posion;


        sf::Vector2f prev_position;
        sf::Vector2f prev_position_temp;


        int snake_length;
        int score;

        int window_heigh;
        int window_width;

        int snake_step_speed_ms;
        bool snake_stop_flag;

        bool let_create_new_snake_food;
        bool let_create_new_snake_poison;


        int food_time_to_wait;
        int poison_time_to_wait;

        ItemType_t acual_effect;








};

#endif // GAME_H
