#ifndef AMOBA_HPP_INCLUDED
#define AMOBA_HPP_INCLUDED

#include "widgets.hpp"
#include <vector>

class Amoba : public Widgets
{
protected:
    std::vector<Widgets*> w;
    std::vector< std::vector<int> > v;


public:
    Amoba();
    void matrix(int i, int j);
    void draw();
    //void handle();
};



#endif // AMOBA_HPP_INCLUDED
