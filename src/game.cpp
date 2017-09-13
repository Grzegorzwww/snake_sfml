#include "game.h"
#include "../items.h"


using namespace std;

Game::Game()
{
    std::cerr << "EMPTY CTOR: NO SNAKE BODY"<<std::endl;
}

Game::Game(Item **snake, sf::RenderWindow *app_instance) : items_ptr(snake), app_ptr(app_instance)
{
    //ctor

    elapsed  = clock.restart();
    direction = Right;
    snake_length = 0;
    score = 0;

    window_heigh = app_ptr->getSize().y;
    window_width = app_ptr->getSize().x;

    snake_step_speed_ms =  DEFAULT_SNAKE_SPEED_MS;
    snake_stop_flag = true;
    let_create_new_snake_food = true;
    let_create_new_snake_poison = true;

    food_time_to_wait = 0;
    poison_time_to_wait = 0;


    prev_position = sf::Vector2f(0,0);
    prev_position_temp = sf::Vector2f(0,0);





}




Game::~Game()
{
    //dtor
}



void Game::do_move()
{


    int i;
    SnakeHead *h = nullptr;
    SnakeTail *b = nullptr;

    switch(direction)
    {
    case Up:

        for(i = 0; i < snake_length; i++)
        {
           // cout <<"obieg petli nr: "<<i<<endl;
            if(h = dynamic_cast<SnakeHead *> ( items_ptr[i]))
            {
                prev_position  = h->getShape().getPosition();
                items_ptr[i]->move(0,-SIGNLE_SNAKE_STEP);
                h = dynamic_cast<SnakeHead *> ( items_ptr[i]);
                control_window_range(h);

            }
            if(b = dynamic_cast<SnakeTail *>( items_ptr[i]))
            {
                prev_position_temp = b->get_position();
                items_ptr[i]->set_position( prev_position);
                prev_position = prev_position_temp;
            }
        }


        break;
    case Down:
        for(i = 0; i <= snake_length; i++)
        {

          //  cout <<"obieg petli nr: "<<i<<endl;
            if(h = dynamic_cast<SnakeHead *> ( items_ptr[i]))
            {
                prev_position  = h->getShape().getPosition();
                items_ptr[i]->move(0,SIGNLE_SNAKE_STEP);
                h = dynamic_cast<SnakeHead *> ( items_ptr[i]);
                control_window_range(h);

            }
            if(b = dynamic_cast<SnakeTail *>( items_ptr[i]))
            {
                prev_position_temp = b->get_position();
                items_ptr[i]->set_position( prev_position);
                prev_position = prev_position_temp;

            }
        }


        break;
    case Left:

        for(i = 0; i < snake_length; i++)
        {
             // cout <<"obieg petli nr: "<<i<<endl;
            if(h = dynamic_cast<SnakeHead *> ( items_ptr[i]))
            {
                prev_position  = h->getShape().getPosition();
                items_ptr[i]->move(-SIGNLE_SNAKE_STEP,0);
                h = dynamic_cast<SnakeHead *> ( items_ptr[i]);
                control_window_range(h);

            }
            if(b = dynamic_cast<SnakeTail *>( items_ptr[i]))
            {
                prev_position_temp = b->get_position();
                items_ptr[i]->set_position( prev_position);
                prev_position = prev_position_temp;
            }
        }

        break;
    case Right:

        for(i = 0; i < snake_length; i++)
        {
               //    cout <<"obieg petli nr: "<<i<<endl;
            if(h = dynamic_cast<SnakeHead *> ( items_ptr[i]))
            {

                prev_position  = h->getShape().getPosition();
                items_ptr[i]->move(SIGNLE_SNAKE_STEP,0);
                h = dynamic_cast<SnakeHead *> ( items_ptr[i]);
                control_window_range(h);


            }
            if(b = dynamic_cast<SnakeTail *>( items_ptr[i]))
            {

                prev_position_temp = b->get_position();
                items_ptr[i]->set_position( prev_position);
                prev_position = prev_position_temp;
            }
        }
        break;
    }
}

void Game::control_timer()
{

    elapsed = clock.getElapsedTime();
    if(elapsed > sf::milliseconds(snake_step_speed_ms))
    {
       // cout <<"tick"<<endl;
       if(!snake_stop_flag)
            do_move();
       clock.restart();
      // elapsed = 0;
    }

     elapsed = food_clock.getElapsedTime();
    if(elapsed.asSeconds() >= sf::seconds(food_time_to_wait).asSeconds() &&  let_create_new_snake_food == false)
    {
       // cout <<"tick"<<endl;
       if(item_eat == nullptr)
            let_create_new_snake_food = true;

        food_clock.restart();
        cout <<"elapsed food"<<endl;
       // elapsed = 0;

    }

     elapsed = poison_clock.getElapsedTime();
    if(elapsed.asSeconds() >= sf::seconds(poison_time_to_wait).asSeconds() && let_create_new_snake_poison == false)
    {
       // cout <<"tick"<<endl;
        if(item_posion == nullptr)
            let_create_new_snake_poison = true;

        poison_clock.restart();
        cout <<"elapsed poison"<<endl;
         //elapsed = 0;
    }
}

void Game::control_events()
{
    /*cout <<"x = "<< window_width <<endl;
    cout <<"y = "<<   window_heigh<<endl;*/

    sf::Event zdarzenie;
    while( app_ptr->pollEvent( zdarzenie ) )
    {
        if( zdarzenie.type == sf::Event::Closed )
            app_ptr->close();

        if( zdarzenie.type == sf::Event::KeyPressed && zdarzenie.key.code == sf::Keyboard::Escape )
            app_ptr->close();

        if( zdarzenie.type == sf::Event::MouseButtonPressed && zdarzenie.mouseButton.button == sf::Mouse::Middle )
            app_ptr->close();

        if (zdarzenie.type == sf::Event::Resized)
        {
            window_width = zdarzenie.size.width;
            window_heigh = zdarzenie.size.height;
        }


        if( zdarzenie.type == sf::Event::KeyPressed)
        {
             if( sf::Keyboard::isKeyPressed( sf::Keyboard::P ) )
            {
              snake_stop_flag = true;
            }
             if( sf::Keyboard::isKeyPressed( sf::Keyboard::C) )
            {
              snake_stop_flag = false;
            }




            if( sf::Keyboard::isKeyPressed( sf::Keyboard::Right ) )
            {
              //  cout << "Right"<<endl;
                if(direction != Left)
                    direction = Right;
            }

            if( sf::Keyboard::isKeyPressed( sf::Keyboard::Left ) )
            {
               // cout << "Left"<<endl;
                if(direction != Right){
                    direction = Left;
                    if(acual_effect == Beer){
                        direction = Right;
                    }
                }
            }

            if( sf::Keyboard::isKeyPressed( sf::Keyboard::Up) )
            {
               // cout << "Up"<<endl;
                if(direction != Down)
                    direction = Up;

            }

            if( sf::Keyboard::isKeyPressed( sf::Keyboard::Down) )
            {
               // cout << "Down"<<endl;
                if(direction != Up)
                    direction = Down;
            }


        }
    }
}


void Game::game_display()
{
    int i;
    //"graphics/background_psy.jpg"
    //app_ptr->clear(sf::Color::Red);
    app_ptr->clear();

    SnakeHead *h;
    SnakeTail *b;
    SnakeFood *f;
    SnakePoison *p;

    if(acual_effect == Mushroom){
        sf::Texture tex;
        if(!tex.loadFromFile("graphics/background_psy.jpg")){
         std::cerr << "Fail to load texture: graphics/background_psy.jpg"<<std::endl;
        }
        sf::RectangleShape background;
        background.setTexture(&tex);
        background.setSize(sf::Vector2f(window_width, window_heigh));
        app_ptr->draw(background);
    }



    for(i = 0; i < snake_length ; i++)
    {
        if(h = dynamic_cast<SnakeHead *> ( items_ptr[i]))
        {
            app_ptr->draw(h->getShape());
        }
        if(b = dynamic_cast<SnakeTail *> ( items_ptr[i]))
        {
            app_ptr->draw(b->getShape());
        }

        if(item_eat != nullptr)
        {
            if(f = dynamic_cast<SnakeFood *> ( item_eat))
            {
                app_ptr->draw(f->getShape());
            }
        }
        if(item_posion != nullptr)
        {
            if(p = dynamic_cast<SnakePoison *> ( item_posion))
            {
                app_ptr->draw(p->getShape());
            }
        }

    }






    app_ptr->display();


}

void Game::game_init()
{
    items_ptr[0] = new SnakeHead(10, 10, Head);
    items_ptr[1] = new SnakeTail(10, 10, Tail);
    items_ptr[2] = new SnakeTail(10, 10, Tail);
    items_ptr[3] = new SnakeTail(10, 10, Tail);
    //  items_ptr[0]->move(35,0);
    snake_length = 4;
    snake_stop_flag = false;
}

void Game::create_new_snake_item()
{

    items_ptr[snake_length] = new SnakeTail(10, 10, Tail);
    items_ptr[snake_length]->set_position(prev_position);
    snake_length++;
}

void Game::control_window_range(SnakeHead *head){
    sf::Vector2f temp_pos = head->get_position();

    if(temp_pos.x > window_width - SIGNLE_SNAKE_STEP)
    {
        temp_pos = sf::Vector2f(0, temp_pos.y);
        head->set_position(temp_pos);
    }else if(temp_pos.x < 0){
        temp_pos = sf::Vector2f(window_width, temp_pos.y);
        head->set_position(temp_pos);
    }


    if(temp_pos.y > window_heigh - SIGNLE_SNAKE_STEP)
    {
        temp_pos = sf::Vector2f(temp_pos.x, 0);
        head->set_position(temp_pos);
    }else if(temp_pos.y < 0){
        temp_pos = sf::Vector2f(temp_pos.x, window_heigh);
        head->set_position(temp_pos);
    }


}
void Game::collision_detect()
{
    SnakeHead *h = nullptr;
    SnakeTail *b = nullptr;
    SnakeFood *f = nullptr;
    SnakePoison *p = nullptr;

    if(!(h = dynamic_cast<SnakeHead *> ( items_ptr[0])))
    {
        cerr << "Blad"<<endl;
    }


    for(int i = 1; i < snake_length; i++)
    {
        if(b = dynamic_cast<SnakeTail *> ( items_ptr[i]))
        {

            if(h->getShape().getGlobalBounds().intersects(b->getShape().getGlobalBounds()))
            {
                cout << "kolizja"<<endl;
                snake_stop_flag = true;
            }
            else
            {



            }
            if(f = dynamic_cast<SnakeFood *> ( item_eat))
            {

                if(h->getShape().getGlobalBounds().intersects(f->getShape().getGlobalBounds()))
                {
                    cout << "zabranie jedzenia"<<endl;
                    score++;
                    cout <<"score = "<<score<<endl;
                    create_new_snake_item();
                    delete item_eat;
                    item_eat = nullptr;
                    srand( time( NULL ) );
                    food_time_to_wait = (std::rand() % 7) + 2;
                    food_clock.restart();
                    if(acual_effect == Syringe){
                        snake_step_speed_ms = DEFAULT_SNAKE_SPEED_MS;
                        acual_effect = VOID;
                        clock.restart();
                    }else if(acual_effect == Mushroom){
                        acual_effect = VOID;
                    }
                    else if(acual_effect == Beer){
                        acual_effect = VOID;
                    }
                    //snake_stop_flag = true;
                }
                else
                {

                }
            }
            if(p = dynamic_cast<SnakePoison *> ( item_posion))
            {

                if(h->getShape().getGlobalBounds().intersects(p->getShape().getGlobalBounds()))
                {
                    cout << "zabrana trucizna"<<endl;
                    if(item_posion->get_item_type() == Beer ){
                         acual_effect = Beer;

                    }else if(item_posion->get_item_type() == Syringe) {
                        acual_effect = Syringe;
                        snake_step_speed_ms = DEFAULT_SNAKE_SPEED_MS / 2;

                    }else if(item_posion->get_item_type() == Mushroom) {
                        //app_ptr->set
                        acual_effect = Mushroom;
                    }
                    else if(item_posion->get_item_type() == Beer) {
                        //app_ptr->set
                        acual_effect = Beer;

                    }
                    delete item_posion;
                    item_posion = nullptr;
                    poison_time_to_wait = (std::rand() % 10) + 3;
                    poison_clock.restart();
                }
                else
                {

                }
            }
        }
    }
}
void Game::make_item_to_eat()
{
    srand( time( NULL ) );
    if(let_create_new_snake_food)
    {

        int x = std::rand() % window_width - SIGNLE_SNAKE_STEP;
        int y = std::rand() % window_heigh - SIGNLE_SNAKE_STEP;

        int food = std::rand() % 3;
        food += 2;
        item_eat = new SnakeFood(x, y, (ItemType_t)food);
        let_create_new_snake_food = false;
    }
    if(let_create_new_snake_poison)
    {
        int xp = std::rand() % window_width - SIGNLE_SNAKE_STEP;
        int yp = std::rand() % window_heigh - SIGNLE_SNAKE_STEP;
        int posion = std::rand() % 3;
        posion += 5;

        item_posion = new SnakePoison(xp, yp, (ItemType_t)posion);
        let_create_new_snake_poison = false;

    }
    //item_to_eat = new SnakeFood(10,10, Food);
}



void Game::new_game(){
    for(int i = 0 ; i < snake_length; i++){
        delete items_ptr[i];
    }

    game_init();

}

