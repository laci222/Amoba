#include "application.hpp"
#include "graphics.hpp"
#include "widgets.hpp"
#include "button.hpp"
#include <vector>

using namespace genv;
using namespace std;

jatekmester::jatekmester(int _SX, int _SY): SX(_SX), SY(_SY)
{}




void jatekmester::matrix()
{

}

void jatekmester::start()
{
    gout.open(SX,SY);
    gout.set_title("LACI amőba");

    for(int i=0; i<50; i++)
    {
        for(int j=0; j<50; j++)
        {
            Button *b=new Button(j*15,i*15,14,14," ", [&](){jatekmester.matrix();});
            w.push_back(b);
        }
    }
}


