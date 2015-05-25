#ifndef APPLICATION_HPP_INCLUDED
#define APPLICATION_HPP_INCLUDED

#include "graphics.hpp"
#include "widgets.hpp"
#include "button.hpp"
#include <vector>



struct jatekmester
{
protected:
    int SX;
    int SY;
    std::vector<Widgets*> w;
    std::vector< std::vector<int> > v;

public:
    jatekmester(int _SX, int _SY);
    void start();
    void matrix(int i, int j);

};

struct grafikus
{
protected:

public:
    void rajzol(std::vector<Widgets*> & w);

};

#endif // APPLICATION_HPP_INCLUDED
