#ifndef BUTTON_HPP_INCLUDED
#define BUTTON_HPP_INCLUDED

#include "widgets.hpp"
#include <functional>

class Button : public Widgets
{
protected:
    std::function<void()> fgv;
    std::string felirat;


public:
    Button(int px, int py, int sx, int sy, std::string _felirat, std::function<void()> fv);
    void draw();
    void handle(genv::event ev);
    void UjFelirat(std::string s);
   // void kiir();
};

#endif // BUTTON_HPP_INCLUDED
