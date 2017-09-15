#include <SFML/Graphics.hpp>

#include <TGUI/TGUI.hpp>
#include "items.h"
#include "game.h"
#include <list>
#include "Menu.h"


using namespace std;




int main()
{
    sf::RenderWindow app(sf::VideoMode(800, 600), "SFML Snake");


    tgui::Gui gui{app};


    Item *snake_body[255];
    for(int i = 0; i < 255; i++){
        snake_body[i] = nullptr;
    }


    Game *game = new Game(snake_body, &app);
    game->game_init();








	// Start the game loop
    while (app.isOpen())
    {


        game->control_events();
        game->control_timer();
        game->make_item_to_eat();
        game->collision_detect();
        game->game_display();




       // gui.draw();
    }


    delete game;


    return EXIT_SUCCESS;
}




