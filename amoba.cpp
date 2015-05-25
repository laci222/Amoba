#include "amoba.hpp"
#include "button.hpp"


using namespace genv;
using namespace std;


Amoba::Amoba( )
{
    gout.open(600,600);
    gout.set_title("LACI amőba");

    for(int i=0; i<50; i++)
    {
        for(int j=0; j<50; j++)
        {
            Button *b=new Button(j*15,i*15,14,14,"x", [&](){matrix(i, j);});
            w.push_back(b);
        }
    }
}


void Amoba::matrix(int i, int j)
{

}
