#include <iostream>
#include "Lista.h"
//#include "Functii.h"

using namespace std;



int main()
{
    Lista op;
    op.addLaSpate("Salutare");
    op.addLaSpate("Buna");
    op.addLaFata("Hei !");
    op.addLaPoz(400,"Nu vreau");
    op.addLaPoz(1,"Nu vreau");

    op.stergeInceput();
    op.afisare();
    cout<<endl;

    op.Search("Nu vreau");

    //char c[200]="    Cev aaaa       ";
    //cout<<taieSpatiiSiMareste(c);

    cout<<endl;

}
