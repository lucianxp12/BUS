#ifndef BUS_H
#define BUS_H

#include <iostream>

using namespace std;

struct node
{
    char info[100];
    int timp;
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
        const char* getNume();
        char* getSofer();
        void setTime(int =0, int =0);
        int getNrStatiiCuren() const;



//------pt lista dubla
        void addLaSpate(char* =NULL,int =0);
        void afisare();// afisare pt Admin
        void afisarePtUser();

        void addLaFata(char* =NULL, int =0);

        void addLaPoz(int , char* =NULL,  int =0);

        bool searchBus(char* c);

        void stergeInceput();

        //void stergeSpate();
        //void stergePozitie();
};


#endif // BUS_H
