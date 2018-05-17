#ifndef BUS_H
#define BUS_H

#include <iostream>
#define Lb 10
using namespace std;

struct node
{
    char info[4000];
    int timp;
    int timpm;

    int timpI;
    int timpmI;


    bool suntAiciDus;
    bool suntAiciIntors;
    node *next;
    node *prev;
};

class Bus
{
    node *inceput, *sfarsit;
    char* numeSofer;
    char* numeBus;
    int nrStatiiCurent;

    public:
//----- necesare clasa
        Bus(char* =NULL, char* =NULL);
        Bus(const Bus& );
        friend ostream& operator<<(ostream& , const Bus&);
        ~Bus();

//----- necesare modelare
        char* getNume();
        char* getSofer();
        void setTime(int =0, int =0 , int =0);
        void setTimeI(int =0, int =0 , int =0);
        int getNrStatiiCuren() const;
        void setSuntAiciIntors(int =0);
        void setSuntAiciDus(int =0);
        bool cautareStatie(char* =NULL);


//------pt lista dubla
        void addLaSpate(char* =NULL,int =0);
        void addLaSpate(string ,int =0);
        void afisare();// afisare pt Admin
        void afisarePtUser();
        void afisareDus();
        void afisareIntors();

        void addLaFata(char* =NULL, int =0);

        void addLaPoz(int , char* =NULL,  int =0);

        bool searchBus(char* c);

        void stergeInceput();

        //void stergeSpate();
        //void stergePozitie();
};


#endif // BUS_H
