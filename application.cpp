#include "application.hpp"
#include "graphics.hpp"
#include "widgets.hpp"
#include "button.hpp"
#include "text.hpp"

#include <vector>
#include <iostream>

using namespace genv;
using namespace std;

jatekmester::jatekmester(std::vector< std::vector< int> > _v): v(_v)
{

    gout.open(900,681);
    gout.set_title("LACI amőba");

    for(unsigned int i=0; i<40; i++)
    {
        for(int j=0; j<40; j++)
        {
            Button *b=new Button(j*17,i*17,16,16," ", [=](){matrix(i, j);});
            buttons.push_back(b);
        }
    }
    Text *t=new Text(730,20, 118, 22);
    texts.push_back(t);

}

void jatekmester::matrix(int i, int j)
{
    if(v[i][j]==0)
    {
        string kiir=" X kovetkezik";
        v[i][j]=jatekos;
        if(jatekos==1)
        {
            buttons[i*40+j]->UjFelirat("X");
            jatekos=2;
            cout<<"1"<<endl;
            kiir=" O kovetkezik";
        }
        else
        {
            buttons[i*40+j]->UjFelirat("O");
            jatekos=1;
            cout<<"2"<<endl;
        }
        texts[0]->UjFelirat(kiir);
    }

}


void jatekmester::start()
{
    event ev;
    gin.timer(30);

    while( gin >> ev && ev.keycode != key_escape )
    {
        for(unsigned int i=0; i<buttons.size(); i++)
        {
            buttons[i]->handle(ev);
            buttons[i]->draw();
        }
        texts[0]->handle(ev);
        texts[0]->draw();

        gout << refresh;
    }
}



