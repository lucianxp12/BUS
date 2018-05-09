#ifndef USERLOGGED_H
#define USERLOGGED_H

#include "Lista.h"
class UserLogged
{
    char* data;
    char* pass;
    char* fav;
    bool logged;
    bool adminRights;
    Lista b;

    public:
        UserLogged(Lista&);
        virtual ~UserLogged();
        void afisare();
        char* getNume();
        char* getFav();
        char* getPass();
        bool isAdmin();


};

#endif // USERLOGGED_H
