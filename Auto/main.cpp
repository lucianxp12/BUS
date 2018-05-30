#include <iostream>
#include "Lista.h"
#include "Bus.h"
#include "Arbore.h"
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


//Loading Bussess

    int numarBusuri = 4;
    adaugareBussGeneral(t,0,"E2.txt", "E2" , "Dorian CiMolan");
    adaugareBussGeneral(t,1,"16.txt", "16", "Pardon Nisipescu");
    adaugareBussGeneral(t,2,"ETREI.txt", "E3", "Pardon Nisipescu");
    adaugareBussGeneral(t,3,"9.txt", "9", "Pardon Bisipescu");
    system("cls");
// meniu


    int alegere = 0;

    afisareLogo();

    liniar(" ",L); liniar("-",L); spuneBuna(0);  liniar("-",L); cout<<endl;
    liniar(" ",Lf); cout<<"Ora: "; spuneTimp(); cout<<endl;
    cout<<endl;

    liniar(" ",L);cout<< "Trebuie sa ne logam !" <<endl;
    liniar(" ",L);cout<<"1. Sunt utilizator existent "<<endl;
    liniar(" ",L);cout<<"2. Vreau sa imi fac cont "<<endl;
    liniar(" ",L);cout<<"3. Cheama un taxi "<<endl;
    liniar(" ",L);cout<<"4. Iesire "<<endl;

    do{
    if((alegere != 1) && (alegere != 2)){ liniar(" ",L);cout<< "Rasuns: "; cin>>alegere; }

    if(alegere == 1)
    {
            userLogged = loginUserExistent(a);
            a.setUserLogat(userLogged);

    }

    else if(alegere == 2){userLogged = loginUserNou(a, nr);}
    else if(alegere == 0){ }
    else if(alegere == 3){ system("cls"); vreauTaxi();}
    else if(alegere == 4){cout<<endl; liniar(" ",L); cout<<"Aplicatia se va inchide"<<endl; liniar(" ",L); cout<<"La revedere !!\n";}
        else{liniar(" ",L); cout<<"Te rugam sa alegi un raspuns valid"<<endl;}

    }while ( (alegere != 1) && (alegere != 2) && (alegere != 4) && (alegere != 3));

    if(alegere != 4 && alegere != 3)
    {

    system("cls");

    cout<<"Ceva"<<endl;

    a.afisare();cout<<a.getNumeUserLogatos();

    cout<<"Ceva"<<endl;

    Arbore *A1 = new Arbore();


    liniar(" ",L); cout<<"Totul a fost incarcat ! Apasa \"ENTER\" pentru a continua\n\n" <<endl;
    cin.get();
    cin.get();
bool okInchidere = false;
do{
    UserLogged U(a);
    U.afisare();
    system("cls");
    afisareAsciiBus();
    liniar(" ",L); liniar("-",L); cout<<"  Buna "<<U.getNume()<<" !";   liniar("-",L); cout<<endl;
    liniar(" ",Lf); cout<<"Ora"; spuneTimp(); cout<<endl;

    string busFavorit = U.getFav();
    bool setatBusFavorit = true;
    if( busFavorit == "Inexistent" || busFavorit == "NU")
    {
        int selectFav;
        liniar(" ",L);cout<<"Se pare ca nu ti-ai adaugat un mijloc de transport favorit."<<endl;
        liniar(" ",L);cout<<"Vrei sa il adaugi acum ?"<<endl;
        liniar(" ",L);cout<<"1) Da        2) NU"<<endl;

        do{
            liniar(" ",L);cout<<"Raspuns: "; cin>>selectFav;cout<<endl;

            if( selectFav != 1 && selectFav != 2){
                cout<<"Te rugam sa introduci un raspuns valid"<<endl;
            }

        }while( selectFav != 1 && selectFav != 2);


        if(selectFav == 1)
        {
            liniar(" ",L);cout<<"Care este statie ta favorita ?"<<endl;
        }
        else{
            liniar(" ",L);cout<<"Vom seta statia favorita data viitoate."<<endl;
            setatBusFavorit = false;
        }




    }

    if( setatBusFavorit == true)
    {
        liniar(" ",Lf); cout<<"Autobuzul tau preferat este: "<< U.getFav() <<endl;
        cout<<endl;



        string fav;
        fav =U.getFav();


        char *favc = new char[fav.length() + 1];
        strcpy(favc, fav.c_str());

        cautareAfisareDupaBus(t,4,favc);
        cout<<endl;
    }


    adaugareArboreFisiere(A1);


    int alegereUserLogat;


    liniar(" ",L);cout<<"1) Alege un mijloc de transport"<<endl;
    liniar(" ",L);cout<<"2) Cauta o statie"<<endl;
    liniar(" ",L);cout<<"3) Sunt la statia X si vreau sa ajung la Y "<<endl;
    liniar(" ",L);cout<<"4) Case de Bilete"<<endl;
    liniar(" ",L);cout<<"5) Comanda un taxi"<<endl;
    liniar(" ",L);cout<<"6) Iesire"<<endl;

    do{
        liniar(" ", Lf);cout<<"Raspuns:";cin>>alegereUserLogat;

        if( alegereUserLogat<1 || alegereUserLogat>6)
        {
            cout<<"Te rugam sa alegi un raspuns valid"<<endl;
        }
    }while(alegereUserLogat<1 || alegereUserLogat>6);

    switch(alegereUserLogat)
    {
        case(1):{
            system("cls");
            spuneTot(U);
            string alegereUnBus;
            liniar(" ",L); cout<<"Ne dorim sa stim ruta unui mijloc de transport "<<endl;

            liniar(" ",L);cout<<"Alege un mijloc de transport "<<endl;
            liniar(" ", L);cout<<"Mijloacele de transport disponibile sunt: "<<endl;
            afisareNumeBusuri(t,numarBusuri);


            bool alegereUnBusBool;
            do{
                liniar(" ",L);cout<<"Introduceti numele mijlocului de transport: ";
                cin>>alegereUnBus;
                char *alegereUnBus2 = new char[alegereUnBus.length() + 1];
                strcpy(alegereUnBus2, alegereUnBus.c_str());
                alegereUnBusBool = cautareDupaBus(t,4,alegereUnBus2);
                if( alegereUnBusBool )
                    {
                        system("cls");
                        spuneTot(U);
                        cautareAfisareDupaBus(t,4,alegereUnBus2);
                    }
                else
                    {
                        liniar(" ",L);cout<<alegereUnBus<<" nu exista !"<<endl;
                    }
                }while(alegereUnBusBool == false);
            break;
            }
        case(2):{
            system("cls");
            spuneTot(U);
            cout<<endl;
            liniar(" ",L); cout<<"Ne aflam la o statie si ne dorim sa stim ce mijloace de "<<endl;
            liniar(" ",L); cout<<"transport vin in statia in care ne aflam"<<endl;
            cautaStatieCuDoYouMean(A1,t);
            break;
            }
        case(3):{
            system("cls");
            cout<<endl;
            spuneTot(U);
            liniar(" ",L);cout<<"--- Sunt la statia X si vreau sa ajung la Y ---"<<endl;
            busOptim(A1,t,4);

            break;
            }
        case(4):{
            system("cls");
            cout<<endl;
            spuneTot(U);
            liniar(" ",L);cout<<"--- Casele de bilete RATT disponibile --- \n"<<endl;

            afisareBilet(t,4);
            break;
            }
        case(5):{
            system("cls");
            vreauTaxi();
            break;
            }
        case(6):{
            liniar(" ",L);cout<<"Aplicatia se va inchide !"<<endl;
            liniar(" ",L);cout<<"La revedere !"<<endl;
            okInchidere = true;
            break;
            }
    }




cin.get();
    cin.get();
}while(okInchidere == false);
    }





















//---------- EXPERIMENTS (curiosity killed the cat ) -------------


/*
cout<<"Wtf:/?:"<<endl;
cout<<cap<<endl;
/*
    /*
    Lista op;
    //op.addLaSpate("Luci","cmfCmz");
    //op.addLaSpate("Alex");
    op.addLaFata("Catalina","vorbareata400");
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

    cin.get();
    cin.get();
}
