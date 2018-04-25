#ifndef LISTA_H
#define LISTA_H

#include <iostream>

using namespace std;

struct nod
{
    char data[100];
    char pass[100];
    bool logged = false;
    nod *next;
};

class Lista
{
    private:
        nod *inceput, *sfarsit;
    public:
        //chestii pt clasa
        Lista();
        ~Lista();
        friend ostream &operator<<(ostream &, const Lista &);

        //chestii pt lista simplu inlantuita
        void addLaSpate(char* =NULL, char* =NULL);
        void afisare();

        void addLaFata(char* =NULL, char* =NULL);

        void addLaPoz(int , char* =NULL, char* =NULL);


        void stergeInceput();

        //chestii de cautare

        bool Search(char* ="Inexistent", char* ="Inexistent");
        bool SearchUser(char* ="Inexistent");
        bool SearchInterior(char* a);



        //alte tooluri

        void setUserLogat(char* =NULL);
        char* getNumeUserLogatos() const;
        void getNumeUserLogat() const;

};

#endif // LISTA_H
