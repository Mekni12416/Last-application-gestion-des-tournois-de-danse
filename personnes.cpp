#include <iostream>
using namespace std;
#include "personnes.h"
#include <string>
 
#define personnes_h
using namespace std;
#include <string>
#include<ios>


// constructeur personnes pour initialiser les attributs
personnes::personnes()
{
    cin_p = 0;
    nom = "modou";
    prenom = "mekni";
    nationalite = "sentun";
    date_naissance = "";
}
//const recopie
personnes::personnes(const personnes& p){
    this->cin_p = p.cin_p;
    this->nom = p.nom;
    this->prenom = p.prenom;
    this->nationalite = p.nationalite;
    this->date_naissance = p.date_naissance;

}
//destrecteur
personnes::~personnes(){}
// constructeur personnes pour saisir les attributs
personnes::personnes(int cin_p,string  nom , string prenom, string nationalite, string date_naissance)
{
    this->cin_p = cin_p;
    this->nom = nom;
    this->prenom = prenom;
    this->nationalite = nationalite;
    this->date_naissance = date_naissance;
}
// methode seter personne
void personnes::set_personne ()
{
    cout << "donner le cin " << endl;
    cin >> cin_p;
    cout << "donner le nom " << endl;
    cin >> nom;
    cout << "donner le prenom " << endl;
    cin >> prenom;
    cout << "donner le nationalite " << endl;
    cin >> nationalite;
    cout << "donner date naissance " << endl;
    cin >> date_naissance;
}
// methode geter personne
void personnes::get_personne() const 
{
    cout << "******Affichage ******" << endl;
    cout << "le cin  est :  " << cin_p << endl;
    cout << "le nom  est :  " << nom << endl;
    cout << "le prenom  est :  " << prenom << endl;
    cout << "la nationalite est :  " << nationalite << endl;
    cout << "la date de naissance  est :  " << date_naissance << endl;
}

ostream& operator<<(ostream& out, personnes& p){
    out<<"le cin est : "<<p.cin_p<<endl;
    out<<"le nom est : "<<p.nom<<endl;
    out<<"le prenom est : "<<p.prenom<<endl;
    out<<"la nationalite est : "<<p.nationalite<<endl;
    out<<"le date naissance est : "<<p.date_naissance<<endl;
    return out;

}
istream& operator>>(istream& in, personnes& p){
    cout << "donner le cin " << endl;
    in >> p.cin_p;
    cout << "donner le nom " << endl;
    in >> p.nom;
    cout << "donner le prenom " << endl;
    in >> p.prenom;
    cout << "donner le nationalite " << endl;
    in >> p.nationalite;
    cout << "donner date naissance " << endl;
    in >> p.date_naissance;
    return in;
}