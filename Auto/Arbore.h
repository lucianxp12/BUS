#ifndef ARBORE_H
#define ARBORE_H

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct noda{
	string value;
	noda *left;
	noda *right;
};



class Arbore{

    noda *root;


	void inserare(string key, noda *frunza);
	noda *search(string key, noda *frunza);
	void stergeArbore(noda *frunza);
	void inordine(noda *frunza);
	void postordine(noda *frunza);
	void preordine(noda *frunza);
    bool searchInfo(string key, noda *frunza);
    void Caut(string cuvant, noda *frunza,int&, string&);




public:
	Arbore();
	~Arbore();

	void inserare(string key);
	noda *search(string key);
	void stergeArbore();
	void inordine();
	void postordine();
	void preordine();
    bool searchInfo(string key);
    void adaugareFisiere();
    string Caut(string cuvant);




};

#endif // ARBORE_H
