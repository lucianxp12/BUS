#ifndef LISTA_H
#define LISTA_H


struct nod
{
    char data[100];
    nod *next;
    nod *prev;
};

class Lista
{
    private:
        nod *inceput, *sfarsit;
    public:
        Lista();
        ~Lista();

        void addLaSpate(char* );
        void afisare();

        void addLaFata(char*  );

        void addLaPoz(int , char* );


        void stergeInceput();

        void stergeSpate();
        void stergePozitie();

        bool Search(char*);


};

#endif // LISTA_H
