#include <iostream>
#include <string>
#include <string.h>

#include "Lista.h"


using namespace std;


Lista::Lista()
{
    //cout<<"----- S-a creat lista de useri ------"<<endl;
    inceput = NULL;
    sfarsit = NULL;
}

Lista::~Lista()
{
    //cout<<"Am sters singur"<<endl;
    //delete inceput;

    //ar trebuie sa fac cu un while si sa stearga tot pe rand ???;

    delete sfarsit;

    delete inceput;

}

void Lista::addLaSpate(char* v,char* p)
{
    nod *aux = new nod;

    bool gasit = true;

    if(v != NULL)
    {
        if(v != NULL)
            strcpy(aux->data,v);
        else strcpy(aux->data,"Inexistent");


        if(p != NULL)
            strcpy(aux->pass,p);
        else strcpy(aux->pass,"Inexistent");

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
        cout<<"User:"<<aux->data<<" | Pass:"<<aux->pass<<endl;
        aux = aux->next;
    }
}


void Lista::addLaFata(char* v,char* p)
{
    if(v != NULL)
    {
    nod *aux = new nod;

        if(v != NULL)
            strcpy(aux->data,v);
        else strcpy(aux->data,"Inexistent");

        if(p != NULL)
            strcpy(aux->pass,p);
        else strcpy(aux->pass,"Inexistent");

    aux->next = inceput;
    inceput = aux;
    }
}

void Lista::addLaPoz(int poz, char* v,char* p) //insereaza valoarea v la pozitia poz;
{
    int ok = 1;

    if(v != NULL)
    {
        if(poz == 1)
        {
            addLaFata(v,p);
        }
        else if(poz == 400) //400 e un fel de santinela
        {
            addLaSpate(v,p);
        }
        else
        {
        nod *inainte = new nod;
        nod *acum = new nod;
        nod *aux = new nod;
        acum = inceput;
        for(int i=1;i<poz;i++)//cautare pozitie cu 2 noduri [inainte]->[acum] pentru a insera intre ele
        {
            inainte = acum;
            if(acum->next == NULL)
            {
                ok = 0; //nu e ok sa ajungi aici
            }
            else acum = acum->next;
        }

        if(ok == 1)//daca nu se strica programul la cautare pozitie
        {
            if(v != NULL)
                strcpy(aux->data,v);
            else strcpy(aux->data,"Inexistent");

            if(p != NULL)
                strcpy(aux->pass,p);
            else strcpy(aux->pass,"Inexistent");

            inainte->next = aux;
            aux->next = acum;
        }
        else{cout<<"Nu exista pozitia data";}
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


bool Lista::Search(char* a,char* s)
{
    bool ok = false;
    nod *aux = new nod;
    char p[200];
    //strcpy(p,taieSpatiiSiMareste(a));
    aux = inceput;

    while( (ok==false) && (aux!=NULL) )
    {
        if( (strcmp(a,aux->data) == 0) && (strcmp(s,aux->pass) == 0) )
        {
            ok = true;
        }
        aux = aux->next;
    }

    if(ok == true)
    {
        //cout<<"Am gasit"<<endl;
        return true;
    }
    else
    {
        //cout<<"User sau parola gresita"<<endl;
        return false;
    }
}

bool Lista::SearchUser(char* a)
{
    bool ok = false;
    nod *aux = new nod;
    char p[200];
    //strcpy(p,taieSpatiiSiMareste(a));
    aux = inceput;

    while( (ok==false) && (aux!=NULL) )
    {
        if( strcmp(a,aux->data) == 0 )
        {
            ok = true;
        }
        aux = aux->next;
    }

    return ok;
}

bool Lista::SearchInterior(char* a)
{
    bool ok = false;
    nod *aux = new nod;
    char p[200];
    //strcpy(p,taieSpatiiSiMareste(a));
    aux = inceput;

    while( (ok==false) && (aux!=NULL) )
    {
        if( strcmp(a,aux->data) == 0)
        {
            ok = true;
        }
        aux = aux->next;
    }

    if(ok == true)
    {
        //cout<<"Am gasit"<<endl;
        return true;
    }
    else
    {
        //cout<<"User sau parola gresita"<<endl;
        return false;
    }
}

void Lista::setUserLogat(char* a)
{
    bool ok = false;
    nod *aux = new nod;
    char p[200];
    //strcpy(p,taieSpatiiSiMareste(a));
    aux = inceput;

    while( (ok==false) && (aux!=NULL) )
    {
        if( strcmp(a,aux->data) == 0 )
        {
            aux->logged = true;
            ok = true;

        }
        aux = aux->next;
    }


}


char* Lista::getNumeUserLogatos() const //Erriareeeeeeeeeeeee
{
    bool ok = false;
    nod *aux = new nod;
    char p[200];
    //strcpy(p,taieSpatiiSiMareste(a));
    aux = inceput;

    while( (ok==false) && (aux!=NULL) )
    {
        if( aux->logged == true )
        {
            ok = true;


        }
        aux = aux->next;
    }


}

void Lista::getNumeUserLogat() const
{
    bool ok = false;
    nod *aux = new nod;
    char p[200];
    //strcpy(p,taieSpatiiSiMareste(a));
    aux = inceput;

    while( (ok==false) && (aux!=NULL) )
    {
        if( aux->logged == true )
        {
            ok = true;
            cout<<"Am gasit";


        }
        if(ok == false){ aux = aux->next;}
    }

    cout<<aux->data;
}

 ostream & operator<<(ostream & os,const Lista &c)
 {
    nod *aux = new nod;
    aux = c.inceput;
    while(aux != NULL)
    {
        os<<"User:"<<aux->data<<" | Pass:"<<aux->pass<<endl;
        aux = aux->next;
    }

    return os;
 }
