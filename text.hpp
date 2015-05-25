#ifndef TEXT_HPP_INCLUDED
#define TEXT_HPP_INCLUDED

#include "widgets.hpp"
#include <vector>

class Text : public Widgets
{
protected:
    std::string szoveg;

public:
    Text(int px, int py, int sx, int sy);
    void draw();
    void handle(genv::event ev);
    void UjFelirat(std::string s);
    std::string getter();
   // void kiir();
};

#endif // TEXT_HPP_INCLUDED
