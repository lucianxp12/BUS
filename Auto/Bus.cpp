#include <iostream>
#include <string>
#include <string.h>
#include "Bus.h"

using namespace std;

void liniarb(char *a, int n)
{
    if(a != NULL)
    {
        for(int i = 0; i < n; i++ )
        {
            cout<<a;
        }
    }
}

Bus::Bus(char* numeBus, char* numeSofer)
{
    cout<<"--- Am creat un BUS ----"<<endl;
    if(numeBus != NULL)
    {
        this->numeBus = new char[strlen(numeBus)+1];
        strcpy(this->numeBus, numeBus);
    }

    if(numeSofer != NULL)
    {
        this->numeSofer = new char[strlen(numeSofer)+1];
        strcpy(this->numeSofer, numeSofer);
    }

    inceput = NULL;
    sfarsit = NULL;

    nrStatiiCurent = 0;
}

Bus::~Bus()
{
    if(this->numeBus != NULL)
    {
        delete [] this->numeBus;
    }

    if(this->numeSofer != NULL)
    {
        delete [] this->numeSofer;
    }
}

ostream& operator<<(ostream& os , const Bus& c)
{
    os<<" ----- BUSSUL: "<< c.numeBus <<" ----"<<endl;
    os<<" -El soferos:" << c.numeSofer <<endl;

    node *aux = new node;
    aux = c.inceput;

    int h,m;
    while(aux != NULL)
    {
        h = aux->timp/100;
        m = aux->timp%100;
        os<< aux->info <<" ---["<< h <<":"<< m <<"]"<<endl;
        aux = aux->next;
    }
}

void Bus::afisare()
{
    liniarb(" ", Lb);cout<<"  -------- "<< this->numeBus <<" -------\n"<<endl;
    liniarb(" ", Lb);cout<<"  Sofer:" << this->numeSofer <<endl;
    cout<<" Statii:" <<endl;
    node *aux = new node;
    aux = inceput;

    int h,m;
    while(aux != NULL)
    {
        h = aux->timp/100;
        m = aux->timp%100;
        liniarb(" ", Lb);cout<<"   *"<<aux->info<<"* ";
        for(int i = 0; i< 20 - strlen(aux->info); i++){cout<<"-";}
        cout<<"[";
            if(aux->timp<10){
                cout<<"0"<<aux->timp;
            }
            else{cout<<aux->timp;}
            cout<<":";

            if(aux->timpm<10){
                cout<<"0"<<aux->timpm;
            }
            else{cout<<aux->timpm;}
            cout<<"]"<<endl;

        aux = aux->next;
    }

}

void Bus::afisarePtUser()
{
    cout<<"  -------- BUSSUL: "<< this->numeBus <<" -------\n"<<endl;
    cout<<" Statii:" <<endl;
    node *aux = new node;
    aux = inceput;

    int h,m;
    while(aux != NULL)
    {

        cout<<"   "<<aux->info<<" ";
        for(int i = 0; i< 20 - strlen(aux->info); i++){cout<<"-";}
        cout<<"["<< aux->timp <<":"<< aux->timpm <<"]"<<endl;

        aux = aux->next;
    }

}

void Bus::afisareDus()
{
    liniarb(" ",Lb);cout<<"  -------- "<< this->numeBus <<" -------\n"<<endl;
    liniarb(" ",Lb);cout<<" Statii DUS:" <<endl;
    node *aux = new node;
    aux = inceput;

    int h,m;
    while(aux != NULL)
    {

        liniarb(" ",Lb);cout<<"   "<<aux->info<<" ";
        for(int i = 0; i< 20 - strlen(aux->info); i++){cout<<"-";}


        cout<<"[";
            if(aux->timp<10){
                cout<<"0"<<aux->timp;
            }
            else{cout<<aux->timp;}
            cout<<":";

            if(aux->timpm<10){
                cout<<"0"<<aux->timpm;
            }
            else{cout<<aux->timpm;}
        cout<<"]";
        if(aux->suntAiciDus) {cout << " - [AICI]";}
        cout<<endl;


        aux = aux->next;
    }

}

void Bus::afisareIntors()
{
    liniarb(" ",Lb);cout<<"  -------- "<< this->numeBus <<" -------\n"<<endl;
    liniarb(" ",Lb);cout<<" Statii INTORS:" <<endl;
    node *aux = new node;
    aux = sfarsit;

    int h,m;
    while(aux != NULL)
    {

        liniarb(" ",Lb);cout<<"   "<<aux->info<<" ";
        for(int i = 0; i< 20 - strlen(aux->info); i++){cout<<"-";}
        cout<<"[";
            if(aux->timp<10){
                cout<<"0"<<aux->timpI;
            }
            else{cout<<aux->timpI;}
            cout<<":";

            if(aux->timpmI<10){
                cout<<"0"<<aux->timpmI;
            }
            else{cout<<aux->timpmI;}
        cout<<"]";

        if(aux->suntAiciIntors) {cout << " - [AICI]";}
        cout<<endl;


        aux = aux->prev;
    }

}

void Bus::addLaFata(char* v, int t)
{

    if(v != NULL)
    {
       node *aux = new node;
        if(v != NULL)
            strcpy(aux->info,v);
        else strcpy(aux->info,"Inexistent");
        aux->timp = t;

        aux->next = inceput;
        inceput = aux;

    }

    nrStatiiCurent++;
}

void Bus::addLaSpate(char* v ,int t )//////////////////////////aici ai ramas
{
    node *aux = new node;
    if(v != NULL)
    {
        strcpy(aux->info, v);
        aux->timp = t;

        aux->next = NULL;
        if(inceput == NULL)//daca nu avem niciun nod in lista
        {
            inceput = aux;
            sfarsit = aux;
            aux = NULL;
        }
        else //avem nod in lista si il punem la spate
        {
            sfarsit->next = aux;
            aux->prev = sfarsit;

            sfarsit = aux;
        }

    }

    nrStatiiCurent++;
}

void Bus::addLaSpate(string v ,int t )
{
    node *aux = new node;

        strcpy(aux->info, v.c_str());
        //aux->info = v;
        aux->timp = t;

        aux->next = NULL;
        if(inceput == NULL)//daca nu avem niciun nod in lista
        {
            inceput = aux;
            sfarsit = aux;
            aux = NULL;
        }
        else //avem nod in lista si il punem la spate
        {
            sfarsit->next = aux;
            aux->prev = sfarsit;

            sfarsit = aux;
        }


    nrStatiiCurent++;
}


bool Bus::searchBus(char *v)
{
    if(v != NULL)
    {
        bool ok = false;
        node *aux = new node;
        aux = inceput;

        while( (ok==false) && (aux!=NULL) )
        {
            if( strcmp(v,aux->info) == 0)
            {
                ok = true;
            }
            aux = aux->next;
        }

        if(ok == true)
        {
            cout<<"Am gasit"<<endl;
            return true;
        }
        else
        {
            cout<<"User sau parola gresita"<<endl;
            return false;
        }
    }
}


void Bus::setTime(int t, int m ,int n ) // t = timp de setat | n = al catelea nod sa fie setat
{
        bool ok = false;
        node *aux = new node;
        aux = inceput;
        int i = 0;


        while( (aux!=NULL) && (i<n) )
        {
            aux = aux->next;
            i++;
        }

        aux->timp = t;
        aux->timpm = m;


}

void Bus::setTimeI(int t, int m ,int n ) // t = timp de setat | n = al catelea nod sa fie setat
{
        bool ok = false;
        node *aux = new node;
        aux = inceput;
        int i = 0;


        while( (aux!=NULL) && (i<n) )
        {
            aux = aux->next;
            i++;
        }

        aux->timpI = t;
        aux->timpmI = m;


}

void Bus::setSuntAiciDus(int p)
{
    bool ok = false;
        node *aux = new node;
        aux = inceput;
        int i = 0;


        while( (aux!=NULL) && (i<p) )
        {
            aux = aux->next;
            i++;
        }

        aux->suntAiciDus = true;
}

void Bus::setSuntAiciIntors(int p)
{
    bool ok = false;
        node *aux = new node;
        aux = inceput;
        int i = 0;


        while( (aux!=NULL) && (i<p) )
        {
            aux = aux->next;
            i++;
        }

        aux->suntAiciIntors = true;
}

int Bus::getNrStatiiCuren() const
{
    return this->nrStatiiCurent;
}

char* Bus::getNume()
{
    return this->numeBus;
}

char* Bus::getSofer()
{
    return this->numeSofer;
}

bool Bus::cautareStatie(char* statie)
{
    if(statie != NULL)
    {
        bool ok = false;
        node *aux = new node;
        aux = inceput;

        while( (ok==false) && (aux!=NULL) )
        {
            cout<<"Uite";
            if( strcmp(statie,aux->info) == 0)
            {
                ok = true;
                return ok;
            }
            aux = aux->next;
        }

        return ok;
    }


}
