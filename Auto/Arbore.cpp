#include "Arbore.h"

Arbore::Arbore(){
	root = NULL;
}

Arbore::~Arbore(){
	stergeArbore();
}

void Arbore::stergeArbore(noda *frunza){
	if(frunza != NULL){
		stergeArbore(frunza->left);
		stergeArbore(frunza->right);
		delete frunza;
	}
}

void Arbore::inserare(string key, noda *frunza){

	if(key < frunza->value){
		if(frunza->left != NULL){
			inserare(key, frunza->left);
		}else{
			frunza->left = new noda;
			frunza->left->value = key;
			frunza->left->left = NULL;
			frunza->left->right = NULL;
		}
	}else if(key >= frunza->value){
		if(frunza->right != NULL){
			inserare(key, frunza->right);
		}else{
			frunza->right = new noda;
			frunza->right->value = key;
			frunza->right->right = NULL;
			frunza->right->left = NULL;
		}
	}

}

void Arbore::inserare(string key){
	if(root != NULL){
		inserare(key, root);
	}else{
		root = new noda;
		root->value = key;
		root->left = NULL;
		root->right = NULL;
	}
}

noda *Arbore::search(string key, noda *frunza){
	if(frunza != NULL){
		if(key == frunza->value){
			return frunza;
		}
		if(key < frunza->value){
			return search(key, frunza->left);
		}else{
			return search(key, frunza->right);
		}
	}else{
		return NULL;
	}
}

bool Arbore::searchInfo(string key, noda *frunza){
	if(frunza != NULL){
		if(key == frunza->value){
			return true;
		}
		if(key < frunza->value){
			return search(key, frunza->left);
		}else{
			return search(key, frunza->right);
		}
	}else{
		return false;
	}
}

bool Arbore::searchInfo(string key)
{
    return searchInfo(key, root);
}


noda *Arbore::search(string key){
	return search(key, root);
}

void Arbore::stergeArbore(){
	stergeArbore(root);
}

void Arbore::inordine(){
	inordine(root);
	cout << "\n";
}

void Arbore::inordine(noda *frunza){
	if(frunza != NULL){
		inordine(frunza->left);
		cout << frunza->value << endl;
		inordine(frunza->right);
	}
}

void Arbore::postordine(){
	postordine(root);
	cout << "\n";
}

void Arbore::postordine(noda *frunza){
	if(frunza != NULL){
		inordine(frunza->left);
		inordine(frunza->right);
		cout << frunza->value << ",";
	}
}

void Arbore::preordine(){
	preordine(root);
	cout << "\n";
}

void Arbore::preordine(noda *frunza){
	if(frunza != NULL){
		cout << frunza->value << ",";
		inordine(frunza->left);
		inordine(frunza->right);
	}
}

string Arbore::Caut(string cuvant)
{
    int mini = 50;
    string miniC = "Salut";

    if(cuvant == "Poli")
    {
        miniC = "UVT";
    }
    else
    {
        Caut(cuvant, root , mini, miniC);

        if(mini > 3)
        {
            miniC = "Inexistent";
        }

    }
    return miniC;
}

int YouMean(string y, string x)
{
    //cout<<"Compar: "<<y<<" cu " <<x;
    int d[100][100];
    int i,j,min;

    for(i = 0; i<= y.length() ; i++)
    {
        d[0][i] = i;
    }

    for(i = 0; i<= x.length() ; i++)
    {
        d[i][0] = i;
    }


    for(i = 1; i<= x.length(); i++)
    {
        for(j = 1; j<= y.length(); j++)
        {
            if(x[i-1] == y[j-1])
            {
                d[i][j] = d[i-1][j-1];
            }

            else
            {
             min = d[i][j-1];
            if(min > d[i-1][j-1])
                min = d[i-1][j-1];
            if(min > d[i-1][j])
                min = d[i-1][j];

            d[i][j] = 1+min;

            }
        }

    }
    //cout<<" "<<d[x.length()][y.length()]<<endl;;
    return d[x.length()][y.length()];
}






void Arbore::Caut(string cuvant, noda *frunza,int&mini,string&miniC ){
	if(frunza != NULL){

		Caut(cuvant,frunza->left,mini,miniC);

        int h = YouMean(cuvant, frunza->value);
		if(h< mini )
        {
            mini = h;
            //cout<<"Am fost aici";
            miniC = frunza->value;
        }

		Caut(cuvant,frunza->right,mini,miniC);

        int z = YouMean(cuvant, frunza->value);
		if(z< mini )
        {
            mini = z;
            //cout<<"Am fost aici";
            miniC = frunza->value;
        }
        //cout<<"Aici minimul e: " <<miniC<<endl;

	}
}
