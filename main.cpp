#include <SFML/Graphics.hpp>
#include <TGUI/TGUI.hpp>
#include "items.h"
#include "game.h"



using namespace std;

void game_init(Item **snake_body);
void game_display(Item **snake_body ,  sf::RenderWindow *window);


int main()
{
    sf::RenderWindow app(sf::VideoMode(800, 600), "SFML Snake");
    tgui::Gui gui{app};

    Item *snake_body[10];
    game_init(snake_body);



    Game *game = new Game(snake_body, &app);







	// Start the game loop
    while (app.isOpen())
    {




        sf::Event zdarzenie;
        while( app.pollEvent( zdarzenie ) )
        {
            if( zdarzenie.type == sf::Event::Closed )
                 app.close();

            if( zdarzenie.type == sf::Event::KeyPressed && zdarzenie.key.code == sf::Keyboard::Escape )
                 app.close();

            if( zdarzenie.type == sf::Event::MouseButtonPressed && zdarzenie.mouseButton.button == sf::Mouse::Middle )
                 app.close();

        }

        game->control_keboard_events();







        gui.draw();
        game_display(snake_body, &app);



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
void game_display(Item **snake_body ,  sf::RenderWindow *window)
{
    int i;
    window->clear();

    SnakeHead *h;
    SnakeTail *b;

    for(i = 0; i < 2 ; i++)
    {
        if(h = dynamic_cast<SnakeHead *> ( snake_body[i]))
        {

            window->draw(h->getShape());
        }
        if(b = dynamic_cast<SnakeTail *> ( snake_body[i]))
        {

            window->draw(b->getShape());
        }
    }
    window->display();


}
