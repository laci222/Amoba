#include "application.hpp"
#include "graphics.hpp"
#include "widgets.hpp"
#include "button.hpp"
#include <vector>

using namespace genv;
using namespace std;

jatekmester::jatekmester(int _SX, int _SY): SX(_SX), SY(_SY)
{}




void jatekmester::matrix(int i, int j)
{

}

void grafikus::rajzol(vector<Widgets*> & w)
{
    for(unsigned int i=0; i<w.size(); i++)
    {
        w[i]->draw();
    }

    gout << refresh;
}

void jatekmester::start()
{

    gout.open(SX,SY);
    gout.set_title("LACI amőba");
    event ev;

    for(int i=0; i<50; i++)
    {
        for(int j=0; j<50; j++)
        {
            Button *b=new Button(j*15,i*15,14,14,"x", [&](){matrix(i, j);});
            w.push_back(b);
        }
    }

    while( gin >> ev && ev.keycode != key_escape )
    {
        grafikus.rajzol(w);
    }
}



