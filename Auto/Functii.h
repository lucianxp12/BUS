#include <iostream>
#include <string>
#include <string.h>
#include <random>
#include <ctime>
#include <fstream>
#include <stdlib.h>
#include "UserLogged.h"
#define Lf 10

using namespace std;



void liniar(char *a, int n)
{
    if(a != NULL)
    {
        for(int i = 0; i < n; i++ )
        {
            cout<<a;
        }
    }
}

void afisareLogo()
{

    liniar(" ",Lf); cout<<"  ____      _  _____ _____ "<<endl;
    liniar(" ",Lf);cout<<" |  _ \\    / \\|_   _|_   _|"<<endl;
    liniar(" ",Lf);cout<<" | |_) |  / _ \\ | |   | |  "<<endl;
    liniar(" ",Lf);cout<<" |  _ <  / ___ \\| |   | |  "<<endl;
    liniar(" ",Lf);cout<<" |_| \\_\\/_/   \\_\\_|   |_|  "<<endl;
    cout<<endl;
}

void afisareAsciiBus()
{
    liniar(" ",Lf);cout<< "                          __\n";
    liniar(" ",Lf);cout<<" .-------------------------  |\n";
    liniar(" ",Lf);cout<<"/| _  .---. .---. .---. .---.|\n";
    liniar(" ",Lf);cout<<"| ||| |___| |___| |___| |___||\n";
    liniar(" ",Lf);cout<<"|=|||========================|\n";
    liniar(" ",Lf);cout<<"[_|||_|(O)\\__________|(O)\\___]==\n" << endl;
    cout<<endl;
}
int getTimeHour()
{
    time_t currentTime;
    struct tm *localTime;

    time( &currentTime );                   // Get the current time
    localTime = localtime( &currentTime );  // Convert the current time to the local time

    int Hour   = localTime->tm_hour;

    return Hour;
}

int getTimeMin()
{
    time_t currentTime;
    struct tm *localTime;

    time( &currentTime );                   // Get the current time
    localTime = localtime( &currentTime );  // Convert the current time to the local time

    int Min    = localTime->tm_min;

    return Min;
}

void spuneTimp()
{
    int H = getTimeHour();
    int M = getTimeMin();

    cout<<"[";
            if(H<10){
                cout<<"0"<<H;
            }
            else{cout<<H;}
            cout<<":";

            if(M<10){
                cout<<"0"<<M;
            }
            else{cout<<M;}
        cout<<"]";
}

void spuneBuna(int ok){

    int H = getTimeHour();
    cout<<" Buna ";
    if(H >= 18)cout<<"seara";
    else if(H >= 12)cout<<"ziua";
        else cout<<"dimineata";

    if(ok == 0)
        cout<<"! ";
    else
        cout<<", ";

}

char* encriptareDecriptare(char* sir)
{
    char key = 'K';

    char* nou;
    char* tri;

    int len = strlen(sir);

    if(sir != NULL)
    {
        nou = new char[len+1];
        strcpy(nou, sir );

        tri = new char[len+1];
        strcpy(tri, sir );
    }

    for(int i=0; i<len ; i++)
    {
        tri[i] = sir[i] ^ key;
        if( (sir[i] == ' ') || (sir[i] == 9) || (tri[i] == ' ') || (tri[i] == 9) ) {}
            else nou[i] = sir[i] ^ key;

            //cout<<(int)nou[i]<<" =*"<<nou[i]<<"*"<<endl;
    }


    return nou;
}

void adaugareTotiUseri(Lista& a, int nr)
{
    ifstream f("BazaDeDate.txt");

    char *u; u = new char[20];
    char *p; p = new char[20];
    char *decr; decr = new char[20];
    char *fav; fav = new char[20];

    for(int i=0; i<nr ; i++)
    {
        f>>u;
        f>>decr;
        f>>fav;

        strcpy(p, encriptareDecriptare(decr)) ;

        if( a.SearchUser(u) == false)
        {
            a.addLaSpate(u,p,fav);
        }
        else
        {
            cout<<"USER \""<< u << "\" EXISTENT "<<endl;
        }
    }

    f.close();
}

char* loginUserNou(Lista& a,int& nr)
{
    system("cls");
    afisareLogo();
    liniar(" ",Lf); liniar("-",Lf); spuneBuna(0);  liniar("-",Lf); cout<<endl;
    liniar(" ",Lf); cout<<"Ora"; spuneTimp(); cout<<endl;
     cout<<endl;

    bool loginOk = false;
    char* userName; userName = new char[80];
    char* userPass; userPass = new char[80];
    char* decr; decr = new char[80];


    do{
    liniar(" ", Lf);cout<<"Introdu un user:"; cin>>userName;

    if( a.SearchUser(userName) == true)
    {
    liniar(" ", Lf);cout<<"Numele de utilizator: \"" << userName << "\" este a fost deja ales :( "<<endl;


    }


    else { loginOk = true; }

    }while(loginOk == false);


    if(loginOk == true)
    {

        loginOk = false;
        liniar(" ", Lf); cout<<"Introduceti o parola care contine\n-Cel putin o litera MARE\n-Cel putin 2 cifre\n";
        do{
        liniar(" ", Lf); cout<<"Introduceti parola:"; cin>>userPass;

        int MARE = 0; // counter litere mari
        int CIFRE = 0;
        for(int lit=0; lit<strlen(userPass); lit++)
        {
            if(isdigit(userPass[lit])){ CIFRE++; }
            if((userPass[lit] >= 'A') && (userPass[lit] <= 'Z') ) { MARE++; }


        }

        if( (CIFRE > 0) && (MARE > 0) ){ loginOk = true ;}
            else
            {   liniar(" ", Lf);cout<<"ATENTIE !!! "<<endl;
                if (CIFRE < 2) {liniar(" ", Lf); cout<<"Introdu o parola care are cel putin 2 cifre"<<endl; }
                if (MARE == 0) { liniar(" ", Lf); cout<<"Introdu o parola care are cel putin o litera MARE"<<endl; }
            }

        } while (loginOk == false);



        ofstream baza("BazaDeDate.txt", ios::app);

        strcpy(decr, encriptareDecriptare(userPass));

        baza << userName << " " << decr << " Inexistent\n" << endl;

        baza.close();

        nr++;

        ofstream numar("nr.txt");
        numar<<nr;
        numar.close();

        cout<<nr;


    }

    return userName;

}

char* loginUserExistent(Lista& a)
{
    system("cls");
    afisareLogo();
    liniar(" ",Lf); liniar("-",Lf); spuneBuna(0);  liniar("-",Lf); cout<<endl;
    liniar(" ",Lf); cout<<"Ora"; spuneTimp(); cout<<endl;
    cout<<endl;

    bool loginOk = false;
    char* userName; userName = new char[80];
    char* userPass; userPass = new char[80];

    do{
        liniar(" ", Lf); cout<<"Introduceti numele de utilizator:"; cin>>userName;
        liniar(" ", Lf); cout<<"Introduceti parola:"; cin>>userPass;

        loginOk = a.Search(userName, userPass);

        if(loginOk == false){liniar(" ", Lf); cout<<"Nume utilizator sau parola gresita !"<<endl;}
    }while(loginOk == false);


    return userName;
}

/*
void adaugareBussGeneral(Bus** t, int Z , char* numeFisier, char* numeAutobuz , char* numeSofer)
{
    int i;
    int r = 0;



    time_t currentTime;
    struct tm *localTime;

    time( &currentTime );                   // Get the current time
    localTime = localtime( &currentTime );  // Convert the current time to the local time

    int Hour   = localTime->tm_hour;
    int Min    = localTime->tm_min;
    int Sec    = localTime->tm_sec;


    int H = Hour;
    int M = Min;

    int HI = Hour;
    int MI = Min;
    //int timpPrincipal = Hour*100 + Min;
    //E2
    {

    t[Z] = new Bus(numeAutobuz,numeSofer);
    ifstream e2;
    e2.open(numeFisier);

    if(e2.is_open())
    {


        int counter = 0 , nr = 0;
        char curent[200] ;
        char citit[200];


        while(e2 >> counter)
        {
            strcpy(curent,"");
            for(int j= 0; j< counter ; j++)
            {
                e2>>citit;

                strcat(curent, citit);
                strcat(curent, " ");


            }
            nr++;
            t[Z]->addLaSpate(curent,0);
            //cout<< curent<<endl;

        }
        e2.close();


        int high = 4;
        int low = 1;


        srand(time(NULL)); // Seed the time

        int statieDus =  rand()%(nr+1); //genereaza random statia unde se afla buss-ul la tura dus;
        t[Z]->setSuntAiciDus(statieDus);

        int statieIntors =  rand()%(nr+1); //genereaza random statia unde se afla buss-ul la tura intors;
        t[Z]->setSuntAiciIntors(statieIntors);



        for(i = nr-1; i> -1 ; i--)
         {

            r =  rand()%(high-low+1)+low; // Generate the number, assign to variable.


            MI += r;
            if(MI>=60)
            {
                MI %=60;
                HI +=1;
            }

            if(HI>=24)
            {
                HI %=24;
            }


            t[Z]->setTimeI(HI,MI, i);
         }

        for(i = 0; i< nr ; i++)
         {

            r =  rand()%(high-low+1)+low; // Generate the number, assign to variable.


            M += r;
            if(M>=60)
            {
                M %=60;
                H +=1;
            }

            if(H>=24)
            {
                H %=24;
            }


            t[Z]->setTime(H,M, i);
         }


         //t[Z]->afisareDus();
         //t[Z]->afisareIntors();

         }else {
            cout<< "Nu am reusit sa deschid fisierul ";
            if(numeFisier != NULL)cout<<numeFisier;
            cout<<endl;
            }

    }

}
*/
void adaugareBussGeneral(Bus** t, int Z , char* numeFisier, char* numeAutobuz , char* numeSofer)
{
    int i;
    int r = 0;



    time_t currentTime;
    struct tm *localTime;

    time( &currentTime );                   // Get the current time
    localTime = localtime( &currentTime );  // Convert the current time to the local time

    int Hour   = localTime->tm_hour;
    int Min    = localTime->tm_min;
    int Sec    = localTime->tm_sec;


    int H = Hour;
    int M = Min;

    int HI = Hour;
    int MI = Min;
    //int timpPrincipal = Hour*100 + Min;
    //E2
    {

    t[Z] = new Bus(numeAutobuz,numeSofer);
    ifstream e2(numeFisier);


    if(e2.is_open())
    {


        int counter = 0 , nr = 0;
        string curent;
        string citit;


        while(e2 >> counter)
        {
            curent = "";
            for(int j= 0; j< counter ; j++)
            {
                e2>>citit;

                curent.append(citit);
                curent.append(" ");

            }

            nr++;
            t[Z]->addLaSpate(curent,0);
            //cout<< curent<<endl;

        }
        e2.close();


        int high = 4;
        int low = 1;


        srand(time(NULL)); // Seed the time

        int statieDus =  rand()%(nr+1); //genereaza random statia unde se afla buss-ul la tura dus;
        t[Z]->setSuntAiciDus(statieDus);

        int statieIntors =  rand()%(nr+1); //genereaza random statia unde se afla buss-ul la tura intors;
        t[Z]->setSuntAiciIntors(statieIntors);



        for(i = nr-1; i> -1 ; i--)
         {

            r =  rand()%(high-low+1)+low; // Generate the number, assign to variable.


            MI += r;
            if(MI>=60)
            {
                MI %=60;
                HI +=1;
            }

            if(HI>=24)
            {
                HI %=24;
            }

            if(i%6 == 0)
            {
                t[Z]->setBilet(i);
            }
            t[Z]->setTimeI(HI,MI, i);
         }

        for(i = 0; i< nr ; i++)
         {

            r =  rand()%(high-low+1)+low; // Generate the number, assign to variable.


            M += r;
            if(M>=60)
            {
                M %=60;
                H +=1;
            }

            if(H>=24)
            {
                H %=24;
            }


            t[Z]->setTime(H,M, i);
         }


         //t[Z]->afisareDus();
         //t[Z]->afisareIntors();

         }else {
            cout<< "Nu am reusit sa deschid fisierul ";
            if(numeFisier != NULL)cout<<numeFisier;
            cout<<endl;
            }

    }

}


void adaugareBussuriSiStatie(Bus **t)
{   int i;
    int r = 0;



    time_t currentTime;
    struct tm *localTime;

    time( &currentTime );                   // Get the current time
    localTime = localtime( &currentTime );  // Convert the current time to the local time

    int Hour   = localTime->tm_hour;
    int Min    = localTime->tm_min;
    int Sec    = localTime->tm_sec;


    int H = Hour;
    int M = Min;
    //int timpPrincipal = Hour*100 + Min;
    //E2
    {

    t[0] = new Bus("E2","Domilos Ciocolos");
    ifstream e2("E2.txt");
    int counter = 0 , nr = 0;
    char curent[100] ;
    char citit[20];


    while(e2 >> counter)
    {
        strcpy(curent,"");
        for(int j= 0; j< counter ; j++)
        {
            e2>>citit;

            strcat(curent, citit);
            strcat(curent, " ");


        }
        nr++;
        t[0]->addLaSpate(curent,0);
        //cout<< curent<<endl;

    }
    e2.close();
    /*
     t[0]->addLaSpate("Bd. Sudului");
     t[0]->addLaSpate("Cvartarul Sudului");
     t[0]->addLaSpate("Spitalul Judetean");
     t[0]->addLaSpate("Cluj");
     t[0]->addLaSpate("Complex Studentesc");
     t[0]->addLaSpate("Traian Grozavescu");
    */

    int high = 4;
    int low = 1;


    srand(time(NULL)); // Seed the time

    int statieDus =  rand()%(nr+1); //genereaza random statia unde se afla buss-ul la tura dus;
    t[0]->setSuntAiciDus(statieDus);

    int statieIntors =  rand()%(nr+1); //genereaza random statia unde se afla buss-ul la tura intors;
    t[0]->setSuntAiciIntors(statieIntors);



    for(i = 0; i< nr ; i++)
     {

        r =  rand()%(high-low+1)+low; // Generate the number, assign to variable.


        M += r;
        if(M>=60)
        {
            M %=60;
            H +=1;
        }

        if(H>=24)
        {
            H %=24;
        }


        t[0]->setTime(H,M, i);
     }



     t[0]->afisareDus();
     t[0]->afisareIntors();

     }
}

void cautareBus(Bus **t , int n , char* v)
{
    bool gasit = false;
    int poz = -1 ;
    for(int i = 0; i<n ; i++)
    {
        //if(strcmp( t[i]->getNume, v)) ERRRRRRROOOOOOOOOOOOOOORRRRRRRRRRRR
        {
            gasit = true;
            poz = i;
            break;
        }
    }
}



void cautareAfisareDupaBus(Bus **t, int n , char* nume)
{
    bool ok = false;
    if(nume != NULL)
    {


    for(int i=0; i<n ; i++)
    {
        if( strcmp(t[i]->getNume() , nume) == 0)
        {
            t[i]->afisareDus();
            t[i]->afisareIntors();
            ok = true;
        }
    }

    if (ok == false){ cout<<"Nu am gasit busuul\"" << nume << "\""<<endl;}

    }

}

bool cautareDupaBus(Bus **t, int n , char* nume)
{
    bool ok = false;
    if(nume != NULL)
    {


    for(int i=0; i<n ; i++)
    {
        if( strcmp(t[i]->getNume() , nume) == 0)
        {
            ok = true;
        }
    }


    }

    return ok;

}

void afisareNumeBusuri(Bus **t, int n)
{
    for(int i=0; i<n; i++)
    {
        liniar(" ",Lf);
        cout<<i<<". "<< t[i]->getNume()<<endl;;
    }
}

void adaugareArboreFisiere(Arbore *A1)
{
    ifstream e3("Depou/E2.txt");

    string u;
	string z;
	int p;
    int i;
	while(e3>>p)
    {
        u = "";
        for(i=0; i< p ;i++)
        {
            e3>>z;
            u.append(z);
            u.append(" ");

        }
        u.erase(u.end()-1);
        A1->inserare(u);
    }

	e3.close();

	ifstream f16("Depou/16.txt");

	while(f16>>p)
    {
        u = "";
        for(i=0; i< p ;i++)
        {
            f16>>z;
            u.append(z);
            u.append(" ");
        }
        u.erase(u.end()-1);
        A1->inserare(u);
    }

	f16.close();

    ifstream f9("Depou/9.txt");

	while(f9>>p)
    {
        u = "";
        for(i=0; i< p ;i++)
        {
            f9>>z;
            u.append(z);
            u.append(" ");
        }
        u.erase(u.end()-1);
        A1->inserare(u);
    }

	f9.close();


    ifstream f3("Depou/ETREI.txt");
	while(f3>>p)
    {
        u = "";
        for(i=0; i< p ;i++)
        {
            f3>>z;
            u.append(z);
            u.append(" ");
        }
        u.erase(u.end()-1);
        A1->inserare(u);
    }

	f3.close();

}

int DidYouMean(string y, string x)
{
    int d[100][100];
    int i,j,min;

    for(i = 0; i<= y.length() ; i++)
    {
        d[0][i] = i;
    }

    for(i = 0; i<= x.length() ; i++)
    {
        d[i][0] = i;
    }


    for(i = 1; i<= x.length(); i++)
    {
        for(j = 1; j<= y.length(); j++)
        {
            if(x[i-1] == y[j-1])
            {
                d[i][j] = d[i-1][j-1];
            }

            else
            {
             min = d[i][j-1];
            if(min > d[i-1][j-1])
                min = d[i-1][j-1];
            if(min > d[i-1][j])
                min = d[i-1][j];

            d[i][j] = 1+min;

            }
        }

    }

    return d[x.length()][y.length()];
}

string cautareStatie(string statie, Arbore *A1)
{
    int minimC = 0;
//    string minimC = "";


}

void logoTaxi(){
    liniar(" ",Lf);cout<<"              .----' `-----."<<endl;
    liniar(" ",Lf);cout<<"             //^^^^;;^^^^^^`\\"<<endl;
    liniar(" ",Lf);cout<<"     _______//_____||_____()_\\________"<<endl;
    liniar(" ",Lf);cout<<"    /SPEED   :      :                  `\\"<<endl;
    liniar(" ",Lf);cout<<"   |>   ____;      ;    TAXI   ____   _<)"<<endl;
    liniar(" ",Lf);cout<<"  {____/    \\_________________/    \\____}"<<endl;
    liniar(" ",Lf);cout<<"       \ '' /                 \ '' /"<<endl;
    liniar(" ",Lf);cout<<"        '--'                   '--'"<<endl;
}

void vreauTaxi(){
    logoTaxi();
    cout<<endl;
    liniar(" ",Lf); liniar("-",Lf); spuneBuna(0);  liniar("-",Lf); cout<<endl;
    liniar(" ",Lf); cout<<"Ora"; spuneTimp(); cout<<endl;
     cout<<endl;
    liniar(" ",Lf + 4); cout<<"Companie"; liniar(" ",10); cout<<"Nr. Telefon"<<endl;

    int taxi;

    liniar(" ",Lf);cout<<"1) Tudo Taxi         (0256) 940"<<endl;
    liniar(" ",Lf);cout<<"2) Radio Taxi        (0256) 945"<<endl;
    liniar(" ",Lf);cout<<"3) TAXI TIMISOARA    (0256) 946"<<endl;
    liniar(" ",Lf);cout<<"4) FAN TAXI          (0256) 946"<<endl;


    do{
    liniar(" ",Lf);cout<<"Ce taxiu doriti ?"<<endl;
    liniar(" ",Lf);cout<<"Raspuns:";
    cin>>taxi;
    cout<<endl;
    if(taxi < 1 || taxi > 4)
    {
        liniar(" ",Lf);cout<< "Va rugam sa introduceti un numar din lista data !"<<endl;
    }
    else{
        cout<<endl;
        liniar(" ",Lf);cout<<"Aplicatia se va inchide, iar numarul de taxi va fi apelat"<<endl;
        liniar(" ",Lf);cout<<"La revedere !"<<endl;
    }
    }while( taxi < 1 || taxi > 4);

}

bool cautaStatiePrintreBussuri(Bus **t, int n,char* statie)
{


    for(int i=0; i<n; i++)
    {

        if(t[i]->cautareStatie(statie))
        {   cout<<endl;
            liniar(" ",Lf);cout<<"------- "<<t[i]->getNume()<< " -------"<<endl;
            liniar(" ",Lf + 3);cout<<" dinspre "<<t[i]->getInceput()<< " la "; t[i]->getStatieTimpDus(statie); cout<<endl;
            liniar(" ",Lf + 3);cout<<" dinspre "<<t[i]->getSfarsit()<< " la "; t[i]->getStatieTimpIntors(statie); cout<<endl;
        }
    }
}


void cautaStatieCuDoYouMean(Arbore *A1,Bus **t){

    // cautare statie
    string statieCautata;

    int statieOK = 2;

    while(statieOK == 2)
    {

    liniar(" ", Lf); cout<<"Introduceti statia cautata: ";
    cin>>statieCautata;

    liniar(" ", Lf);cout<<"Ati cautat statia:"<<statieCautata<<endl;

    //A1->inordine();

    if(A1->searchInfo(statieCautata))
    {
        liniar(" ", Lf);
        char* AiVrutSaScrii2;
        AiVrutSaScrii2 = new char[statieCautata.length()+3];
        strcpy(AiVrutSaScrii2, statieCautata.c_str());


        statieCautata.append(" ");
        strcpy(AiVrutSaScrii2, statieCautata.c_str());
        cautaStatiePrintreBussuri(t, 4 ,AiVrutSaScrii2);
        statieOK = 1;

    }
    else
        {

        string AiVrutSaScrii = A1->Caut(statieCautata);

        if( AiVrutSaScrii != "Inexistent")
            {   liniar(" ", Lf); cout<<"Ai vrut sa scrii: "<< AiVrutSaScrii <<" ?"<<endl;

                liniar(" ", Lf); cout<<"1. Da"; liniar(" ", Lf); cout<<"2. NU"<<endl;
                liniar(" ", Lf);cout<<"Raspuns:";

                cin>>statieOK;

                while( statieOK!= 1 && statieOK != 2 )
                {
                    liniar(" ", Lf);cout<<"Alege variante 1 sau 2 ! "<<endl;
                    cin>>statieOK;
                }
                if(statieOK == 1)
                {       char* AiVrutSaScrii2;
                        AiVrutSaScrii2 = new char[AiVrutSaScrii.length()+3];
                        strcpy(AiVrutSaScrii2, AiVrutSaScrii.c_str());
                        AiVrutSaScrii.append(" ");
                        strcpy(AiVrutSaScrii2, AiVrutSaScrii.c_str());
                        cautaStatiePrintreBussuri(t, 4 ,AiVrutSaScrii2);

                }
                else { liniar(" ", Lf); cout<< "Of Scuze !"<<endl; }

            }
            else{
                liniar(" ", Lf); cout<<"Statia cautata NU exista ! "<<endl;
            }
        }

    }

    cout<<endl;

    }

void afisareBilet(Bus **t, int n)
{
    for(int i=0; i<n; i++)
    {
        t[i]->afisareBilet();
    }
}

void spuneTot(UserLogged&U)
{
    afisareAsciiBus();
    liniar(" ",Lf); liniar("-",Lf); cout<<"  Buna "<<U.getNume()<<" !";   liniar("-",Lf); cout<<endl;
    liniar(" ",Lf); cout<<"Ora"; spuneTimp(); cout<<endl;
}


string CautaStatie(Arbore *A1,Bus **t)
{
    // cautare statie
    string statieCautata;

    int statieOK = 2;

    while(statieOK == 2)
    {

    liniar(" ", Lf); cout<<"Introduceti statia ";
    cin>>statieCautata;

    liniar(" ", Lf);cout<<"Ati cautat statia:"<<statieCautata<<endl;

    //A1->inordine();

    if(A1->searchInfo(statieCautata))
    {
        statieCautata.append(" ");


        statieOK = 1;
        return statieCautata;
    }
    else
        {

        string AiVrutSaScrii = A1->Caut(statieCautata);

        if( AiVrutSaScrii != "Inexistent")
            {   liniar(" ", Lf); cout<<"Ai vrut sa scrii: "<< AiVrutSaScrii <<" ?"<<endl;

                liniar(" ", Lf); cout<<"1. Da"; liniar(" ", Lf); cout<<"2. NU"<<endl;
                liniar(" ", Lf);cout<<"Raspuns:";

                cin>>statieOK;

                while( statieOK!= 1 && statieOK != 2 )
                {
                    liniar(" ", Lf);cout<<"Alege variante 1 sau 2 ! "<<endl;
                    cin>>statieOK;
                }
                if(statieOK == 1)
                {
                        AiVrutSaScrii.append(" ");
                        return AiVrutSaScrii;


                }
                else { liniar(" ", Lf); cout<< "Of Scuze !"<<endl; }

            }
            else{
                liniar(" ", Lf); cout<<"Statia cautata NU exista ! "<<endl;
            }
        }

    }

}



void busOptim(Arbore *A1,Bus **t, int n){

    bool megaOk = false;

    bool OKX;
    bool OKY;

    int pozX;
    int pozY;

    int MinOra = 25;
    int MinMin = 62;
    char MinnumeStatie[100];
    char MinnumeBus[100];
    int pozMin;
   strcpy( MinnumeStatie, "Inexistent");

    int tempOraDus;
    int tempMinDus;

    int tempOraIntors;
    int tempMinIntors;

    string stringX;
    string stringY;

    char* charX;
    char* charY;

    liniar(" ", Lf);cout<<" -- Statia unde va aflati --"<<endl;
    stringX = CautaStatie(A1,t);
    charX = new char[stringX.length()+2];
    strcpy(charX, stringX.c_str());



    liniar(" ", Lf);cout<<" -- Statia unde doriti sa ajungeti --"<<endl;
    stringY = CautaStatie(A1,t);

    charY = new char[stringY.length()+2];
    strcpy(charY, stringY.c_str());



    for(int i=0; i<n; i++)
    {

        if(t[i]->cautareStatie(charX))
        {
            pozX = i;


            /*
            liniar(" ",Lf);cout<<"------- "<<t[i]->getNume()<< " -------"<<endl;
            liniar(" ",Lf + 3);cout<<" dinspre "<<t[i]->getInceput()<< " la "; t[i]->getStatieTimpDus(statie); cout<<endl;
            liniar(" ",Lf + 3);cout<<" dinspre "<<t[i]->getSfarsit()<< " la "; t[i]->getStatieTimpIntors(statie); cout<<endl;
            */
        }


        if(t[i]->cautareStatie(charY))
        {
            pozY = i;

            /*
            liniar(" ",Lf);cout<<"------- "<<t[i]->getNume()<< " -------"<<endl;
            liniar(" ",Lf + 3);cout<<" dinspre "<<t[i]->getInceput()<< " la "; t[i]->getStatieTimpDus(statie); cout<<endl;
            liniar(" ",Lf + 3);cout<<" dinspre "<<t[i]->getSfarsit()<< " la "; t[i]->getStatieTimpIntors(statie); cout<<endl;
            */
        }

        if(pozY == pozX)
        {
            tempOraDus = t[i]->getStatieOraTimpDus(charY);
            tempMinDus = t[i]->getStatieMinTimpDus(charY);

                if(tempMinDus < MinMin)
                {
                    MinOra = tempOraDus;
                    MinMin = tempMinDus;

                    pozMin = pozY;

                }


            megaOk = true;

        }
    }

    if(megaOk)
    {
        liniar(" ", Lf);cout<<"Ar trebui sa iei buss-ul: "<<t[pozMin]->getNume()<<endl;

            int tempOra1 = t[pozMin]->getStatieOraTimpDus(charX);
            int tempMin1 = t[pozMin]->getStatieMinTimpDus(charX);

            int tempOra2 = t[pozMin]->getStatieOraTimpDus(charY);
            int tempMin2 = t[pozMin]->getStatieMinTimpDus(charY);

            if(tempOra1 > tempOra2)
            {
                liniar(" ", Lf);cout<< "Din statia " << charX << " la ora "; t[pozMin]->getStatieTimpIntors(charX) ; cout<<endl;
                liniar(" ", Lf);cout<< "Vei ajunge in statia: " << charY << " la ora "; t[pozMin]->getStatieTimpIntors(charY); cout<<endl ;
            }
            else if(tempMin1 > tempMin2)
            {
                liniar(" ", Lf);cout<< "Din statia " << charX << " la ora "; t[pozMin]->getStatieTimpIntors(charX) ; cout<<endl;
                liniar(" ", Lf);cout<< "Vei ajunge in statia: " << charY << " la ora "; t[pozMin]->getStatieTimpIntors(charY); cout<<endl ;
            }
            else
            {
                liniar(" ", Lf);cout<< "Din statia " << charX << " la ora "; t[pozMin]->getStatieTimpDus(charX); ; cout<<endl;
                liniar(" ", Lf);cout<< "Vei ajunge in statia: " << charY << " la ora "; t[pozMin]->getStatieTimpDus(charY); cout<<endl ;
            }


    }
    else{liniar(" ", Lf);cout<<"Nu exista un mijloc de transport care sa contina ambele statii"<<endl;}

}

/*


char* taieSpatiiSiMareste(char *c)
{   int ok = 0;
    int i = 0;
    while(c[0]==' ')
    {

        strcpy(c,c+1);

    }

    i = strlen(c);
    while(c[i-1]==' ')
    {
        i--;
    }
    cout<<"Uite"<<c[i]<<"*"<<endl;


    while(c[i]==' ')
    {

        strcpy(c+i,c+i+1);
        ok++;
    }

    for(i=0; i<strlen(c); i++)
    {
        c[i]=toupper(c[i]);
    }
    return c;

}
*/
