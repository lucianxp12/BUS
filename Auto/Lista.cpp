#include <iostream>
#include <string>
#include <string.h>

#include "Lista.h"


using namespace std;


Lista::Lista()
{
    inceput = NULL;
    sfarsit = NULL;
}

Lista::~Lista()
{
 cout<<"Am sters singur"<<endl;
}

void Lista::addLaSpate(char* v)
{
    nod *aux = new nod;
    if(v != NULL)
    {


    strcpy(aux->data,v);
    aux->next = NULL;
    if(inceput == NULL)
    {
        inceput = aux;
        sfarsit = aux;
        aux = NULL;
    }
    else
    {
        sfarsit->next = aux;
        sfarsit = aux;
    }

    }
}

void Lista::afisare()
{
    nod *aux = new nod;
    aux = inceput;
    while(aux != NULL)
    {
        cout<<aux->data<<endl;
        aux = aux->next;
    }
}


void Lista::addLaFata(char* v)
{
    if(v != NULL)
    {
    nod *aux = new nod;
    strcpy(aux->data,v);
    aux->next = inceput;
    inceput = aux;
    }
}

void Lista::addLaPoz(int poz, char* v)//insereaza valoarea la pozitia poz;
{
    if(v != NULL)
    {
        if(poz == 1)
        {
            addLaFata(v);
        }
        else if(poz == 400)
        {
            addLaSpate(v);
        }
        else
        {
        nod *inainte = new nod;
        nod *acum = new nod;
        nod *aux = new nod;
        acum = inceput;
        for(int i=1;i<poz;i++)
        {
            inainte = acum;
            acum = acum->next;
        }
        strcpy(aux->data,v);
        inainte->next = aux;
        aux->next = acum;
        }
    }
}

void Lista::stergeInceput()
{
    nod *aux = new nod;
    aux = inceput;
    inceput = inceput->next;
    delete aux;
}


bool Lista::Search(char* a)
{
    bool ok = false;
    nod *aux = new nod;
    char p[200];
    //strcpy(p,taieSpatiiSiMareste(a));
    aux = inceput;

    while( (ok==false) && (aux!=NULL) )
    {
        if(strcmp(a,aux->data) == 0)
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
        cout<<"Nu am gasit"<<endl;
        return false;
    }
}




