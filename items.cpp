#include "items.h"
using namespace std;


Item::Item(int _x, int _y, ItemType_t _type) : x(_x), y(_y), item_type(_type)
{

}
void Item::move(int _x, int _y) {x = _x, y = _y;}

/*
void Item::position(int _x, int _y)
{


}*/






SnakeHead::SnakeHead(int _x, int _y, ItemType_t type) : Item(_x, _y, type)
{


    shape = new sf::CircleShape(20, 20);
    m_tex = new sf::Texture();
    if(!m_tex->loadFromFile("graphics/_snake_tex.png")){

         std::cerr << "Fail to load texture: _snake_tex.png"<<std::endl;
    }
    shape->setTexture(m_tex);
    //m_tex->setSmooth(true);



}
SnakeHead::~SnakeHead(){
    delete shape;
    delete m_tex;
}

void SnakeHead::move(int _x, int _y) {
    shape->move(_x, _y);

}
void SnakeHead::set_position(sf::Vector2f &pos)
{
    shape->setPosition(pos);
   // cout << "snake head pos" <<endl;
}
sf::Vector2f SnakeHead::get_position()
{
    return shape->getPosition();

}




SnakeTail::SnakeTail(int _x, int _y, ItemType_t type) : Item(_x, _y, type)
{


    shape = new sf::CircleShape(20, 20);
    m_tex = new sf::Texture();
    if(!m_tex->loadFromFile("graphics/snake_body_tex.png")){

         std::cerr << "Fail to load texture: _snake_tex.png"<<std::endl;
    }
    shape->setTexture(m_tex);




}
SnakeTail::~SnakeTail(){
    delete shape;
    delete m_tex;
}

void SnakeTail::move(int _x, int _y) {
    shape->setPosition(_x, _y);

}
void SnakeTail::set_position(sf::Vector2f &pos)
{
//cout << "snake tail pos" <<endl;
    shape->setPosition(pos);
}
sf::Vector2f SnakeTail::get_position()
{

    return shape->getPosition();

}



SnakeFood::SnakeFood(int _x, int _y, ItemType_t type) : Item(_x, _y, type)
{
    shape = new sf::CircleShape(20, 20);
    m_tex = new sf::Texture();

    string path_to_icon;

    if(type == Strawberry) path_to_icon = "graphics/3.png";
    else if(type == Raspberry) path_to_icon = "graphics/4.png";
    else if (type == Apple) path_to_icon = "graphics/5.png";
    else path_to_icon = "graphics/5.png";


    if(!m_tex->loadFromFile(path_to_icon)){

         std::cerr << "Fail to load texture: "<<path_to_icon<<std::endl;
    }
    shape->setTexture(m_tex);
    shape->setPosition(sf::Vector2f(_x, _y));
}
SnakeFood::~SnakeFood(){
    delete shape;
    delete m_tex;
}

void SnakeFood::move(int _x, int _y) {
    shape->move(_x, _y);

}
void SnakeFood::set_position(sf::Vector2f &pos)
{
//cout << "snake tail pos" <<endl;
    shape->setPosition(pos);
}
sf::Vector2f SnakeFood::get_position()
{


    return shape->getPosition();

}


SnakePoison::SnakePoison(int _x, int _y, ItemType_t type) : Item(_x, _y, type)
{
    shape = new sf::CircleShape(20, 20);
    m_tex = new sf::Texture();

    string path_to_icon;



    switch(type){
    case Beer: path_to_icon = "graphics/6.png"; cout <<"Beer"<<endl;   break;
    case Syringe: path_to_icon = "graphics/7.png"; cout <<"Syringe"<<endl; break;
    case Mushroom: path_to_icon = "graphics/8.png"; cout <<"Mushroom"<<endl;break;
    }


    if(!m_tex->loadFromFile(path_to_icon)){

         std::cerr << "Fail to load texture: "<<path_to_icon<<std::endl;
    }
    shape->setTexture(m_tex);
    shape->setPosition(sf::Vector2f(_x, _y));
}

SnakePoison::~SnakePoison(){
    delete shape;
    delete m_tex;
}

void SnakePoison::move(int _x, int _y) {
    shape->move(_x, _y);

}
void SnakePoison::set_position(sf::Vector2f &pos)
{
//cout << "snake tail pos" <<endl;
    shape->setPosition(pos);
}
sf::Vector2f SnakePoison::get_position()
{

    return shape->getPosition();

}


