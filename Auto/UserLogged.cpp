#include <iostream>
#include "UserLogged.h"
#include <string.h>

using namespace std;
UserLogged::UserLogged(Lista& a)
{
    if(a.getNumeUserLogatos() != NULL)
    {
        this->data = new char[strlen(a.getNumeUserLogatos())+1];
        strcpy(this->data, a.getNumeUserLogatos());
    }

    if(a.getPassUserLogatos() != NULL)
    {
        this->pass = new char[strlen(a.getPassUserLogatos())+1];
        strcpy(this->pass, a.getPassUserLogatos());
    }

    if(a.getFavUserLogatos() != NULL)
    {
        this->fav = new char[strlen(a.getFavUserLogatos())+1];
        strcpy(this->fav, a.getFavUserLogatos());
    }

    this->adminRights = a.getAdminRight();

    logged = true;
}

UserLogged::~UserLogged()
{
    if(this->data != NULL)
    {
        delete []this->data;

    }

    if(this->fav != NULL)
    {
        delete []this->fav;

    }

    if(this->pass != NULL)
    {
        delete []this->pass;
    }
}

void UserLogged::afisare()
{
    cout<<data;
}

char* UserLogged::getNume()
{
    return this->data;
}

char* UserLogged::getFav()
{
    return this->fav;
}

char* UserLogged::getPass()
{
    return this->fav;
}

bool UserLogged::isAdmin()
{
    return this->adminRights;
}
