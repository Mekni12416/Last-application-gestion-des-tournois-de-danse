#include <iostream>
using namespace std;
#include "spectateur.h"

#include <string>
#include "iterator"
// constructeur par deffaut pour spectateur
spectateur::spectateur()
{
    personnes();
}
// constructeur pour spectateur
spectateur::spectateur(int cin_p, string nom, string prenom, string nationalite, string date_naissance, int a)
{
    personnes(cin_p, nom, prenom, nationalite, date_naissance);
    age = a;
}
// destrecteur
spectateur::~spectateur() {}
spectateur::spectateur(const spectateur &r)
{
    this->age = r.age;
}

// methode geter pour spectateur
void spectateur::get_spectateur()
{
    personnes::get_personne();
}
ostream &operator<<(ostream &out, spectateur &s)
{
    out << "le cin est : " << s.cin_p << endl;
    out << "le nom est : " << s.nom << endl;
    out << "le prenom est : " << s.prenom << endl;
    out << "la nationalite est : " << s.nationalite << endl;
    out << "le date naissance est : " << s.date_naissance << endl;
    out << "age : " << s.age<<endl;
    /*for (auto &pair : s.Mymap)
    {

        auto x = pair.first;
        out << x;
        auto s = pair.second;
        out << s;
    }*/

    return out;
}
istream &operator>>(istream &in, spectateur &s)
{
    personnes *p = &s;
    in >> *p;
    cout << "Donner age :";
    in >> s.age;

    return in;
}

spectateur &spectateur::operator=(spectateur &s)
{
    if (this != &s)
    {
        this->cin_p = s.cin_p;
    }
    return *this;
}
