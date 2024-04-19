#include <iostream>
using namespace std;
#include "danseur.h"
#include <string>
// constructeur par deffaut de danseur
danseur::danseur()
{
    personnes();
    style_danse = "";
}
//destrecteur pour danseur
danseur::~danseur(){}
// constructeur pour danseur
danseur::danseur(int cin_p, string nom, string prenom, string nationalite, string date_naissance, string style_danse)
{
    personnes(cin_p, nom, prenom, nationalite, date_naissance); 
    this->style_danse = style_danse;
}
// methode pour enregistrer danseur        
void danseur::enregistrer_danseur()
{
    cout << "*******enregistration des danseurs*********" << endl;
    personnes::set_personne();
    cout << "donner le style de danse" << endl;
    cin >> style_danse;
}
// methode geter pour danseur
void danseur::get_danseur() const 
{
     personnes::get_personne();
    cout << "le style de danse est :" << style_danse << endl;
}
//surchager l operateur <<
ostream& operator<<(ostream& out,danseur& d){
    out<<"le cin est : "<<d.cin_p<<endl;
    out<<"le nom est : "<<d.nom<<endl;
    out<<"le prenom est : "<<d.prenom<<endl;
    out<<"la nationalite est : "<<d.nationalite<<endl;
    out<<"le date naissance est : "<<d.date_naissance<<endl;
    out<<"le style de danse est :"<<d.style_danse<<endl;
    return out;


}
istream& operator>>(istream& in, danseur& d){
    cout << "donner le cin " << endl;
    in >> d.cin_p;
    cout << "donner le nom " << endl;
    in >> d.nom;
    cout << "donner le prenom " << endl;
    in >> d.prenom;
    cout << "donner le nationalite " << endl;
    in >> d.nationalite;
    cout << "donner date naissance " << endl;
    in >> d.date_naissance;
    cout << "donner style danse " << endl;
    in >> d.style_danse;
    return in;
}