#include <iostream>
#include <string>
#include <string.h>
#include <random>
#include <ctime>
#include <fstream>
#include <stdlib.h>

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

void adaugareTotiUseri(Lista& a, int nr)
{
    ifstream f("BazaDeDate.txt");

    char *u; u = new char[20];
    char *p; p = new char[20];

    for(int i=0; i<nr ; i++)
    {
        f>>u;
        f>>p;

        if( a.SearchUser(u) == false)
        {
            a.addLaSpate(u,p);
        }
        else
        {
            cout<<"USER \""<< u << "\" EXISTENT "<<endl;
        }
    }
}

char* loginUserNou(Lista& a,int& nr)
{
    system("cls");

    liniar(" ",Lf); liniar("-",Lf); cout<<"  Buna !  ";  liniar("-",Lf); cout<<endl;
    liniar(" ",Lf); cout<<"Ora ["<<getTimeHour()<<":"<<getTimeMin()<<"]"<<endl;
     cout<<endl;

    bool loginOk = false;
    char* userName; userName = new char[80];
    char* userPass; userPass = new char[80];


    do{
    cout<<"Introdu un user:"; cin>>userName;

    if( a.SearchUser(userName) == true)
    {
        cout<<"Numele de utilizator: \"" << userName << "\" este a fost deja ales :( "<<endl;


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
            {   cout<<"ATENTIE !!! "<<endl;
                if (CIFRE < 2) {liniar(" ", Lf); cout<<"Introdu o parola care are cel putin 2 cifre"<<endl; }
                if (MARE == 0) { liniar(" ", Lf); cout<<"Introdu o parola care are cel putin o litera MARE"<<endl; }
            }

        } while (loginOk == false);



        ofstream baza("BazaDeDate.txt", ios::app);

        baza << userName << " " << userPass <<endl;

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

    liniar(" ",Lf); liniar("-",Lf); cout<<"  Buna !  ";  liniar("-",Lf); cout<<endl;
    liniar(" ",Lf); cout<<"Ora ["<<getTimeHour()<<":"<<getTimeMin()<<"]"<<endl;
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

    int timpPrincipal = Hour*100 + Min;
    //E2
    {
    t[0] = new Bus("E2","Domilos Ciocolos");

     t[0]->addLaSpate("Bd. Sudului");
     t[0]->addLaSpate("Cvartarul Sudului");
     t[0]->addLaSpate("Spitalul Judetean");
     t[0]->addLaSpate("Cluj");
     t[0]->addLaSpate("Complex Studentesc");
     t[0]->addLaSpate("Traian Grozavescu");

     for(i = 0; i< t[0]->getNrStatiiCuren() ; i++)
     {
        r +=  (rand() %100)/6;
        if(timpPrincipal%100 + r >= 60){r = r + 100 - 60; }
        if(timpPrincipal + r > 2400 ){ timpPrincipal-= 2400 ;}
        t[0]->setTime(timpPrincipal + r, i);
     }

     t[0]->afisarePtUser();
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


char* spunebuna()
{
    char* buna;
    buna = new char[20];
    strcpy(buna ,"xxx");
    return buna;
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
