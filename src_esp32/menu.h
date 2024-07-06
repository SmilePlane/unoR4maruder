#include <Arduino.h>
#ifndef MENU_H
#define MENU_H
class menu{
    public:
    void main(); //unused
    void input(std::__cxx11::string); //called when user input and run once with user input
    void sett_append(); //calls in loop to user input
};
//int pick_sett;
#endif