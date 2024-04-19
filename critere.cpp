 
#include<iostream>
//#include "critere.h"

#include <string>
#include<ios>
using namespace std;
class Critere
{
private:
    /* data */
    int poids;
    string description;
public:
    Critere(int=0, string=" ");
    Critere(const Critere&);
    void saisirCritere();
    friend ostream& operator<<(ostream&, Critere&);
    friend istream& operator>>(istream&, Critere&);
    void afficher();
    int getPoids(){return poids;}
    string getDescription(){return description;}

    ~Critere(){} 
};

 


Critere::Critere(int poid, string descrip)
{
    this->poids= poid;
    this->description= descrip;
}


Critere::Critere(const Critere& c)
{
    poids=c.poids;
    description=c.description;
}
void Critere::afficher()
{
    cout<<"Le poids est: "<<poids<<"\n la description est: "<<description<<endl;
}

void Critere::saisirCritere()
{
    cout<<"Donner le poids: ";
    cin>>poids;
    cout<<"Donner la description: ";
    cin>>description;
}

ostream& operator<<(ostream& out, Critere& c)
{
    out<<"\nLe poids est: "<<c.poids;
    out<<"\nla description est:"<<c.description;
    return out;
}

istream& operator>>(istream& in , Critere& c)
{
    cout<<"Donner le poids: ";
    in>>c.poids;
    cout<<"Donner la description: ";
    in>>c.description;
    return in;
 
}