#ifndef MENU_H
#define MENU_H
#include "iostream"
#include "SFML/Graphics.hpp"

using namespace std;

static const int MAX_NUMBER_ITEMS = 3;
static const int MAX_NUMBER_ALL_ITEMS = 6;

//typedef void Menu::*mptr()

class Menu
{
    public:
        Menu(float width, float height);
        virtual ~Menu();


        void draw(sf::RenderWindow &window);
        void MoveUp();
        void MoveDown();


        int GetPresesedItem() {return selectedItemIndex;}

        void showMenu();
        void hideMenu();

        void show_hide_result(bool x) { show_result_flag = x;  show_result_flag = x;}

        void setScore(string &s, sf::Vector2f _position) {menu[3].setString(s); score_position = _position;}
        void setGameTime(string &s) {menu[4].setString(s);}
        void setResultMsg(string &s) {menu[5].setString(s);}



    protected:

    private:

        int selectedItemIndex;
        sf::Font font;
        sf::Text menu[MAX_NUMBER_ALL_ITEMS];
        sf::Vector2f score_position;
        bool show_hide_flag;
        bool show_result_flag;

};

#endif // MENU_H
