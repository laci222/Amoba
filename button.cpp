#include "button.hpp"
#include "sstream"
#include "fstream"
using namespace genv;
using namespace std;

Button::Button(int px, int py, int sx, int sy, string _felirat, function<void()> fv)
: Widgets(px, py, sx, sy), fgv(fv), felirat(_felirat) {}


/*void Button::kiir()
{
    ofstream fajl("eredmeny.txt",ios::app);
    fajl<<szam<<"\n";
    fajl.close();
}*/

void Button::draw()
{
    gout<<color(200,200,200)<<move_to(x,y)<<box(size_x, size_y)<<move_to(x+2, y+2)<<color(40,40,40)<<box(size_x-4, size_y-4);

    if(felirat=="O")
    {
        gout<<color(0,0,255);
    }
    else
    {
        gout<<color(255,0,0);
    }
    gout<<move_to(x+4,y+(size_y/2)+5)<<text(felirat);
}

void Button::handle(event ev)
{

    if(ev.button == btn_left && ev.pos_x >= x && ev.pos_x <= x+size_x && ev.pos_y >= y && ev.pos_y <= y+size_y)
    {
      fgv();
    }
}

void Button::UjFelirat(string s)
{
    felirat=s;
}
