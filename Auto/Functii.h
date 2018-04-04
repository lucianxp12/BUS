#include <iostream>
#include <string>
#include <string.h>

using namespace std;

char* taieSpatiiSiMareste(char *c)
{   int ok = 0;
    int i = 0;
    while(c[0]==' ')
    {

        strcpy(c,c+1);

    }

    i = strlen(c);
    while(c[i-1]==' ')
    {
        i--;
    }
    cout<<"Uite"<<c[i]<<"*"<<endl;


    while(c[i]==' ')
    {

        strcpy(c+i,c+i+1);
        ok++;
    }

    for(i=0; i<strlen(c); i++)
    {
        c[i]=toupper(c[i]);
    }
    return c;

}

void spunebuna()
{
    cout<<"Buna"<<endl;
}
