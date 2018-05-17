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

    liniar(" ",Lf); liniar("-",Lf); cout<<"  Buna !  ";  liniar("-",Lf); cout<<endl;
    liniar(" ",Lf); cout<<"Ora"; spuneTimp(); cout<<endl;
     cout<<endl;

    bool loginOk = false;
    char* userName; userName = new char[80];
    char* userPass; userPass = new char[80];
    char* decr; decr = new char[80];


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

        strcpy(decr, encriptareDecriptare(userPass));

        baza << userName << " " << decr <<endl;

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


char* spunebuna()
{
    char* buna;
    buna = new char[20];
    strcpy(buna ,"xxx");
    return buna;
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
