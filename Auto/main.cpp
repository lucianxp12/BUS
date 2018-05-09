#include <iostream>
#include "Lista.h"
#include "Bus.h"
#include "Functii.h"
#include <fstream>
#include <string.h>
#include <stdlib.h>
#include "UserLogged.h"
#define L 10

using namespace std;




int main()
{
// cititre numa de utilizatori din baza de date;

int nr;
ifstream numarInitial("nr.txt");
numarInitial>>nr;
numarInitial.close();
char* userLogged; userLogged = new char[40];
char* userLoggedFav; userLoggedFav = new char[40];
char* userLoggedPass; userLoggedPass = new char[40];
bool userLoggedRight;


//declaratie tablou de bussuri
    Bus **t;
    t = new Bus*[10];

//declaratie utilizatori si adaugare in lista din baza de date

    Lista a;

    adaugareTotiUseri(a, nr);

// meniu
    int alegere = 0;


    liniar(" ",L); liniar("-",L); cout<<"  Buna !  ";  liniar("-",L); cout<<endl;
    liniar(" ",Lf); cout<<"Ora ["<<getTimeHour()<<":"<<getTimeMin()<<"]"<<endl;
    cout<<endl;

    liniar(" ",L);cout<< "Trebuie sa ne logam !" <<endl;
    liniar(" ",L);cout<<"1. Sunt utilizator existent "<<endl;
    liniar(" ",L);cout<<"2. Vreau sa imi fac cont "<<endl;
    liniar(" ",L);cout<<"3. Iesire "<<endl;

    do{
    if((alegere != 1) && (alegere != 2)){ liniar(" ",L);cout<< "Rasuns: "; cin>>alegere; }

    if(alegere == 1)
    {
            userLogged = loginUserExistent(a);
            a.setUserLogat(userLogged);

    }

    else if(alegere == 2){userLogged = loginUserNou(a, nr);}
    else if(alegere == 0){ }
    else if(alegere == 3){liniar(" ",L); cout<<"La revedere !!";}
        else{liniar(" ",L); cout<<"Te rugam sa alegi un raspuns valid"<<endl;}

    }while ( (alegere != 1) && (alegere != 2) && (alegere != 3));

    if(alegere != 3)
    {

    system("cls");

    cout<<"Ceva"<<endl;

    a.afisare();cout<<a.getNumeUserLogatos();

    cout<<"Ceva"<<endl;

    UserLogged U(a);
    U.afisare();
    liniar(" ",L); liniar("-",L); cout<<"  Buna "<<U.getNume()<<" !";   liniar("-",L); cout<<endl;
    liniar(" ",Lf); cout<<"Ora ["<<getTimeHour()<<":"<<getTimeMin()<<"]"<<endl;
    liniar(" ",Lf); cout<<"Autobuzul tau preferat este: "<< U.getFav() <<endl;

    int numarBusuri = 2;
    adaugareBussGeneral(t,0,"E2.txt", "E2" , "Dorian CiMolan");
    adaugareBussGeneral(t,1,"16.txt", "16", "Pardon Nisipescu");
    char* fav;
    fav = new char[strlen(U.getFav())+1];
    strcpy(fav, U.getFav());
    cautareDupaBus(t,1,fav);

    cout<<endl;

    }





















//---------- EXPERIMENTS (curiosity killed the cat ) -------------

char* cap;
cap = new char[21];
cap = spunebuna();

/*
cout<<"Wtf:/?:"<<endl;
cout<<cap<<endl;
/*
    /*
    Lista op;
    //op.addLaSpate("Luci","cmfCmz");
    //op.addLaSpate("Alex");
    op.addLaFata("Catalina","vorbareata400");
    op.addLaFata("Oana","BebeleMeu");
    //op.addLaPoz(400,"Nu vreau", "Shumudica");
    //op.addLaPoz(2,"DobreDobrescu","MustarulEViataMea");

    //op.stergeInceput();

    Bus e2("E2","Demian Soferescu");
    //e2.addLaFata("Bd. Sudului", 1200);
    e2.addLaSpate("Ceva", 1522);
    cout<<"afisare e2"<<endl;
    cout<<e2;

    //op.Search("Salutare");

    //char c[200]="    Cev aaaa       ";
    //cout<<taieSpatiiSiMareste(c);

    cout<<endl;
    */
}
