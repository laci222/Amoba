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
            Button *b=new Button(j*17,i*17,16,16," ", [=]()
            {
                matrix(i, j);
            });
            buttons.push_back(b);
        }
    }
    Text *t=new Text(730,20, 118, 22);
    texts.push_back(t);

}

void jatekmester::matrix(int i, int j)
{
    if(v[i][j]==0 && !nyert)
    {
        string kiir=" X kovetkezik";
        v[i][j]=jatekos;
        /// találat vizsgálat///

        nyert=vizsgal(i,j);
        if(nyert)
        {
            string nyertel=" X nyert";
            if(jatekos==2)
            {
                nyertel=" O nyert";
            }

            Text *t=new Text(730,60, 118, 22);
            texts.push_back(t);
            texts[1]->UjFelirat(nyertel);
        }

        /// gombba jel berakása  ///
        if(jatekos==1)
        {
            buttons[i*40+j]->UjFelirat("X");
            jatekos=2;
            kiir=" O kovetkezik";
        }
        else
        {
            buttons[i*40+j]->UjFelirat("O");
            jatekos=1;
        }
        texts[0]->UjFelirat(kiir);
    }


}


bool jatekmester::vizsgal(int ei, int ej)
{
    bool egyik=false;
    bool masik=false;
    int i=ei;
    int j=ej;
    int szamlalo=1;
    /// jobbrabalra ///
    while(!egyik)
    {
        j++;
        if(v[i][j]==jatekos)
        {
            szamlalo++;
        }
        else
        {
            egyik=true;
        }
    }

    j=ej;

    while(!masik)
    {
        j--;
        if(v[i][j]==jatekos)
        {
            szamlalo++;
        }
        else
        {
            masik=true;
        }
    }

    if(szamlalo>4)
    {
        cout<<"nyertel";
        return true;
    }

    ///fel-le ///

    egyik=false;
    masik=false;
    i=ei;
    j=ej;
    szamlalo=1;

    while(!egyik)
    {
        i++;
        if(v[i][j]==jatekos)
        {
            szamlalo++;
        }
        else
        {
            egyik=true;
        }
    }

    i=ei;

    while(!masik)
    {
        i--;
        if(v[i][j]==jatekos)
        {
            szamlalo++;
        }
        else
        {
            masik=true;
        }
    }

    if(szamlalo>4)
    {
        cout<<"nyertel";
        return true;
    }

    ///jobbra le átló ///

    egyik=false;
    masik=false;
    i=ei;
    j=ej;
    szamlalo=1;

    while(!egyik)
    {
        i++;
        j++;
        if(v[i][j]==jatekos)
        {
            szamlalo++;
        }
        else
        {
            egyik=true;
        }
    }

    i=ei;
    j=ej;

    while(!masik)
    {
        i--;
        j--;
        if(v[i][j]==jatekos)
        {
            szamlalo++;
        }
        else
        {
            masik=true;
        }
    }

    if(szamlalo>4)
    {
        cout<<"nyertel";
        return true;
    }

    ///balra le átló ///

    egyik=false;
    masik=false;
    i=ei;
    j=ej;
    szamlalo=1;

    while(!egyik)
    {
        i--;
        j++;
        if(v[i][j]==jatekos)
        {
            szamlalo++;
        }
        else
        {
            egyik=true;
        }
    }

    i=ei;
    j=ej;

    while(!masik)
    {
        i++;
        j--;
        if(v[i][j]==jatekos)
        {
            szamlalo++;
        }
        else
        {
            masik=true;
        }
    }

    if(szamlalo>4)
    {
        cout<<"nyertel";
        return true;
    }

    return false;

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
        texts[0]->draw();

        gout << refresh;
    }
}



