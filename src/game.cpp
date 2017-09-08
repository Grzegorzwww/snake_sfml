#include "game.h"


using namespace std;

Game::Game()
{
    std::cerr << "EMPTY CTOR: NO SNAKE BODY"<<std::endl;
}

Game::Game(Item **snake, sf::RenderWindow *app_instance) : items_ptr(snake), app_ptr(app_instance)
{
    //ctor

}




Game::~Game()
{
    //dtor
}

void Game::control_keboard_events()
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

