#ifndef ITEMS_H
#define ITEMS_H
#include <iostream>
#include "SFML/Graphics.hpp"
//#include "qsfml_widget.h"
using namespace std;
static const int CIRCLE_RADIOUS =  10;

typedef enum {Head = 0, Tail = 1, Strawberry = 2 , Raspberry = 3,  Apple = 4, Beer = 5, Syringe = 6, Mushroom = 7, VOID = 8} ItemType_t;





class Item
{
public:
    Item(int _x, int _y, ItemType_t _type);
    virtual ~Item() {}
    virtual void move(int _x, int _y);
    virtual void set_position(sf::Vector2f &pos)=0;
    sf::Vector2f get_position() {}
    virtual void show() {cout <<"show of item"<<endl;}
    virtual ItemType_t get_item_type() {return item_type;}



private:

    ItemType_t item_type;
    int x;
    int y;


};


class SnakeHead : public Item
{

public:
    SnakeHead(int _x, int _y, ItemType_t type);
    virtual ~SnakeHead();
    sf::CircleShape getShape(){ return *shape; }
    void set_position(sf::Vector2f &pos);
    sf::Vector2f get_position();
    void move(int _x, int _y);
    void show() {  cout <<"show of SnakeHead"<<endl; }

private:
    sf::Texture *m_tex;
    sf::CircleShape *shape;

};

class SnakeTail : public Item
{

public:
    SnakeTail(int _x, int _y, ItemType_t type);
    virtual ~SnakeTail();
    sf::CircleShape getShape() {  return *shape; }
    void set_position(sf::Vector2f &pos);
    sf::Vector2f get_position();
    void move(int _x, int _y);
    void show()  {cout <<"show of SnakeTail"<<endl; }


private:
    sf::Texture *m_tex;
    sf::CircleShape *shape;
};



class SnakeFood : public Item
{

public:
    SnakeFood(int _x, int _y, ItemType_t type);
    virtual ~SnakeFood();
    sf::CircleShape getShape() {  return *shape; }
    void set_position(sf::Vector2f &pos);
    sf::Vector2f get_position();
    void move(int _x, int _y);
    void show()  {cout <<"show of SnakeTail"<<endl; }


private:
    sf::Texture *m_tex;
    sf::CircleShape *shape;
};

class SnakePoison : public Item
{

public:
    SnakePoison(int _x, int _y, ItemType_t type);
    virtual ~SnakePoison();
    sf::CircleShape getShape() {  return *shape; }
    void set_position(sf::Vector2f &pos);
    sf::Vector2f get_position();
    void move(int _x, int _y);
    void show()  {cout <<"show of SnakeTail"<<endl; }
    ItemType_t get_posion_type() {return get_item_type();}


private:
    sf::Texture *m_tex;
    sf::CircleShape *shape;
};



#endif // ITEMS_H
