#include "text.hpp"
#include "fstream"

using namespace genv;
using namespace std;

Text::Text(int px, int py, int sx, int sy)
: Widgets(px, py, sx, sy){}



void Text::draw()
{
    gout<<color(40,40,40)<<move_to(x,y)<<box(size_x, size_y)<<move_to(x+2, y+2)<<color(255,255,255)<<box(size_x-4, size_y-4);

    for(unsigned int i=0; i<szoveg.size(); i++)
    {
        if((i*gout.twidth("A")+2)<size_x)
        {
            gout<<color(0,0,0)<<move_to(x+i*gout.twidth("A")+2,y+size_y-6)<<text(szoveg[i]);
        }

    }

}

string Text::getter()
{
    return szoveg;
}

void Text::UjFelirat(std::string s)
{
    szoveg=s;
}

void Text::handle(event ev)
{
   /* if(ev.type == ev_key&&ev.keycode!=key_backspace)
    {
      szoveg.push_back(ev.keycode);
    }
    else if(ev.keycode==key_backspace&&szoveg.size()!=0)
    {
        szoveg.pop_back();
    }
    */
}
