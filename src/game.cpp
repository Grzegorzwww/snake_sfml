#include "game.h"


using namespace std;

Game::Game()
{
    std::cerr << "EMPTY CTOR: NO SNAKE BODY"<<std::endl;
}

Game::Game(Item **snake, sf::RenderWindow *app_instance) : items_ptr(snake), app_ptr(app_instance)
{
    //ctor

    elapsed  = clock.restart();
    direction = Right


}




Game::~Game()
{
    //dtor
}

void run(bool flag){

    if(flag){





    }
}


void Game::do_move(){



}


void Game::control_timer()
{

    elapsed = clock.getElapsedTime();
    if(elapsed > sf::milliseconds(500))
    {

        cout <<"tick"<<endl;
        clock.restart();
    }


}

void Game::control_keboard_events()
{

    sf::Event zdarzenie;
    while( app_ptr->pollEvent( zdarzenie ) )
    {
        if( zdarzenie.type == sf::Event::Closed )
            app_ptr->close();

        if( zdarzenie.type == sf::Event::KeyPressed && zdarzenie.key.code == sf::Keyboard::Escape )
            app_ptr->close();

        if( zdarzenie.type == sf::Event::MouseButtonPressed && zdarzenie.mouseButton.button == sf::Mouse::Middle )
            app_ptr->close();

        if( zdarzenie.type == sf::Event::KeyPressed)
        {
            if( sf::Keyboard::isKeyPressed( sf::Keyboard::Right ) )
            {
                cout << "Right"<<endl;
            }

            if( sf::Keyboard::isKeyPressed( sf::Keyboard::Left ) )
            {
                cout << "Left"<<endl;
            }

            if( sf::Keyboard::isKeyPressed( sf::Keyboard::Up) )
            {
                cout << "Up"<<endl;
            }

            if( sf::Keyboard::isKeyPressed( sf::Keyboard::Down) )
            {
                cout << "Down"<<endl;
            }
        }
    }
}


void Game::game_display()
{
    int i;
    app_ptr->clear();

    SnakeHead *h;
    SnakeTail *b;

    for(i = 0; i < 2 ; i++)
    {
        if(h = dynamic_cast<SnakeHead *> ( items_ptr[i]))
        {

            app_ptr->draw(h->getShape());
        }
        if(b = dynamic_cast<SnakeTail *> ( items_ptr[i]))
        {

            app_ptr->draw(b->getShape());
        }
    }
    app_ptr->display();


}

