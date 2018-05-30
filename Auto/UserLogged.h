#ifndef USERLOGGED_H
#define USERLOGGED_H

#include "Lista.h"
class UserLogged
{
    string data;
    string pass;
    string fav;
    bool logged;
    bool adminRights;
    Lista b;

    public:
        UserLogged(Lista&);
        virtual ~UserLogged();
        void afisare();
        string getNume();
        string getFav();
        string getPass();
        bool isAdmin();


};

#endif // USERLOGGED_H
