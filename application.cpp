#include "application.hpp"
#include "graphics.hpp"
#include "widgets.hpp"
#include "button.hpp"
#include <vector>
#include <iostream>

using namespace genv;
using namespace std;

jatekmester::jatekmester(std::vector< std::vector< int> > _v): v(_v)
{

    gout.open(681,681);
    gout.set_title("LACI amőba");

    for(int i=0; i<40; i++)
    {
        for(int j=0; j<40; j++)
        {
            Button *b=new Button(j*17,i*17,16,16," ", [=](){matrix(i, j);});
            w.push_back(b);
        }
    }


}

void jatekmester::matrix(int i, int j)
{


    v[i][j]=jatekos;
    if(jatekos==1)
    {
        w[i*40+j]->UjFelirat("X");
        jatekos=2;
        cout<<"1"<<endl;
    }
    else
    {
        w[i*40+j]->UjFelirat("O");
        jatekos=1;
        cout<<"2"<<endl;
    }

}


void jatekmester::start()
{
    event ev;
    gin.timer(30);

    while( gin >> ev && ev.keycode != key_escape )
    {
        for(unsigned int i=0; i<w.size(); i++)
        {
            w[i]->handle(ev);
            w[i]->draw();
        }

    gout << refresh;
    }
}



