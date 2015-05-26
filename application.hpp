#ifndef APPLICATION_HPP_INCLUDED
#define APPLICATION_HPP_INCLUDED

#include "graphics.hpp"
#include "widgets.hpp"
#include "button.hpp"
#include "text.hpp"

#include <vector>


struct jatekmester
{
protected:
    //Widgets *amoba;
    std::vector<Button*> buttons;
    std::vector<Text*> texts;
    bool nyert=false;
    int szamlalo=0;
    std::vector< std::vector< int> > v;
    int jatekos=1; ///x vagy o jön, x=1, o=2

public:
    jatekmester(std::vector< std::vector< int> > _v);
    void matrix(int i, int j);
    bool vizsgal(int ei, int ej);
    void elolrol();
    void start();

};


#endif // APPLICATION_HPP_INCLUDED
