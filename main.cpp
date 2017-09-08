#include <SFML/Graphics.hpp>

#include <TGUI/TGUI.hpp>
#include "items.h"
#include "game.h"
#include <list>


using namespace std;

void game_init(Item **snake_body);
void game_display(Item **snake_body ,  sf::RenderWindow *window);


int main()
{
    sf::RenderWindow app(sf::VideoMode(800, 600), "SFML Snake");
    tgui::Gui gui{app};


    //list <Item> snake_body;
    //Item *snake_body[10];



    game_init(snake_body);



    Game *game = new Game(snake_body, &app);







	// Start the game loop
    while (app.isOpen())
    {








        game->control_keboard_events();

        game->control_timer();




        gui.draw();

        game->game_display();


    }


    delete game;
    return EXIT_SUCCESS;
}


void game_init(Item **snake_body)
{
    snake_body[0] = new SnakeHead(10, 10, Head);
    snake_body[1] = new SnakeTail(10, 10, Tail);
    snake_body[0]->move(35,0);
}

