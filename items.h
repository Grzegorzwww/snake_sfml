#ifndef ITEMS_H
#define ITEMS_H
#include <iostream>
#include "SFML/Graphics.hpp"
//#include "qsfml_widget.h"

static const int CIRCLE_RADIOUS =  10;

typedef enum {Head, Tail} ItemType_t;


class Item
{
public:
    Item(int _x, int _y, ItemType_t _type);
    virtual ~Item() {}

    virtual void move(int _x, int _y);
    virtual void show() {}
    virtual void setX(int _x) {x = _x;}
    virtual void setY(int _y) {y = _y;}

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
    sf::CircleShape getShape() {return *shape;}

    virtual void move(int _x, int _y);



private:

    sf::CircleShape *shape;
    sf::Texture *m_tex;


};
class SnakeTail : public Item
{

   public:
    SnakeTail(int _x, int _y, ItemType_t type);
    virtual ~SnakeTail();
    sf::CircleShape getShape() {return *shape;}

    virtual void move(int _x, int _y);



private:
     sf::Texture *m_tex;
     sf::CircleShape *shape;

};



#endif // ITEMS_H
