#include "amoba.hpp"
#include "button.hpp"

#include <vector>


using namespace genv;
using namespace std;


Amoba::Amoba( )
{
    gout.open(800,720);
    gout.set_title("LACI amőba");

    for(int i=0; i<40; i++)
    {
        for(int j=0; j<40; j++)
        {
            Button *b=new Button(j*17,i*17,16,16,"O", [&](){matrix(i, j);});
            w.push_back(b);
        }
    }
}


void Amoba::matrix(int i, int j)
{

}

void Amoba::draw()
{
    for(unsigned int i=0; i<w.size(); i++)
    {
        w[i]->draw();
    }

    gout << refresh;
}
