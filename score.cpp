 
#include<iostream>
//#include "score.h"
#include<vector>
#include "critere.cpp"
#include <ios>
using namespace std;
class score
{
private:
    /* data */
    int numScore;
    int valeur;
    vector<Critere *>  listCrit;

public:
    score(int=0,int=0);
    score(const score&);
    void enregistrerScore();
    score& operator=(const score&);
    float calculScore();
    friend istream& operator>>(istream&, score&);
    friend ostream& operator<<(ostream&, score&);
    
    ~score();
};

score::score(int num, int val)
{
    this->valeur=val;
    this->numScore=num;
}

score::~score()
{
    for(unsigned int i=0;i<listCrit.size();i++)
    {
        delete listCrit[i];
    }
    listCrit.clear();
}
score::score(const score&s)
{
    this->numScore=s.numScore;
    this->valeur= s.valeur;
    Critere *c;
    for(unsigned  int i=0;i<s.listCrit.size();i++)
    {
        c= new Critere(*s.listCrit[i]);
        listCrit.push_back(c);
    }
}


void score::enregistrerScore()
{
    cout<<"Donner le numero score: ";
    cin>>numScore;
    cout<<"Donner la valeur: ";
    cin>>valeur;
    cout<<"Donner les criteres "<<endl;
    Critere *c;
    int choix;
    do{
        c=new Critere;
         c->saisirCritere();
        listCrit.push_back(c);
       
        cout<<"Voulez vous ajouter d autres critere: Tapez 1 pour continuer ou autres pour arreter: ";
        cin>>choix;
        
    }while(choix==1);
}
score& score::operator=(const score& s)
{
    cout<<"\n DEBUT DE LA SURDEFINITION\n";
    if(this!=&s)
    {
        this->numScore= s.numScore;
        this->valeur=s.valeur;
         for(unsigned int i=0;i<listCrit.size();i++)
        {
            delete listCrit[i];
        }
        listCrit.clear();
        for (unsigned int i=0; i<s.listCrit.size();i++)
        {
            listCrit[i]=s.listCrit[i];
        }

    }
    cout<<"\n FIN DE LA SURDEFINITION\n";
    return *this;
}

istream& operator>>(istream& in, score& s) {
    cout << "Donner le numero de score : ";
    in >> s.numScore;
    cout << "Donner la valeur du score : ";
    in >> s.valeur;

    // Saisie des critères
    int nbCrit;
    cout << "Donner le nombre de critères : ";
    in >> nbCrit;
    s.listCrit.clear();
    for (int i = 0; i < nbCrit; ++i) {
        Critere* critere = new Critere();
        in >> *critere;
        s.listCrit.push_back(critere);
    }

    return in;
}

ostream& operator<<(ostream& out, score& s)
{
    out<<"Numero score: "<<s.numScore<<endl;
    out<<"valeur de score:"<<s.valeur<<endl;
    out<<"La liste des criteres est:\n";
    for(unsigned int i=0;i<s.listCrit.size();i++)
    {
        out<<*s.listCrit[i]<<endl;

    }
    return out;
}

float score::calculScore()
{
    float res=0.0;
    res+= valeur *0.65;
    int n= listCrit.size();
    float rcri=0;
    for(unsigned int  i=0;i<listCrit.size();i++)
    {
        if(listCrit[i]->getDescription()=="faible")
            rcri+=4;
            else
            if(listCrit[i]->getDescription()=="moyen")
                rcri+=7;
                else if(listCrit[i]->getDescription()=="fort")
                     rcri+=9;
                     else
                     rcri+=2;
        
        if(listCrit[i]->getPoids() > 50)
             rcri+=4;
             else
             rcri+=8;
    }
    float rescri=0.35*( rcri /n);

    res+=rescri;


    return res; 
 
}