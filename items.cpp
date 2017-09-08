#include "items.h"



Item::Item(int _x, int _y, ItemType_t _type) : x(_x), y(_y), item_type(_type)
{

}
void Item::move(int _x, int _y) {x = _x, y = _y;}




SnakeHead::SnakeHead(int _x, int _y, ItemType_t type) : Item(_x, _y, type)
{


    shape = new sf::CircleShape(20, 20);
    m_tex = new sf::Texture();
    if(!m_tex->loadFromFile("_snake_tex.png")){

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
    shape->setPosition(_x, _y);
    setX(_x);
    setX(_y);
}



SnakeTail::SnakeTail(int _x, int _y, ItemType_t type) : Item(_x, _y, type)
{


    shape = new sf::CircleShape(20, 20);
    m_tex = new sf::Texture();
    if(!m_tex->loadFromFile("snake_body_tex.png")){

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
    setX(_x);
    setX(_y);
}

