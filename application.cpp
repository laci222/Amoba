#include "application.hpp"
#include "graphics.hpp"
#include "widgets.hpp"
#include "button.hpp"
#include <vector>

using namespace genv;
using namespace std;

jatekmester::jatekmester()
{
    Amoba *a=new Amoba();
    amoba=a;
}





/*void grafikus::rajzol(vector<Widgets*> & w)
{
    for(unsigned int i=0; i<w.size(); i++)
    {
        w[i]->draw();
    }

    gout << refresh;
}*/

void jatekmester::start()
{
    event ev;

    while( gin >> ev && ev.keycode != key_escape )
    {
        amoba->draw();
    }
}



