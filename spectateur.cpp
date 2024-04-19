#include <iostream>
using namespace std;
//#include "spectateur.h"

#include <string>
#include "iterator"

#ifndef spectateur_h
#define spectateur_h
#include "personnes.h"
#include "Ticket.cpp"
#include <string>
#include <map>
#include <ios>
class spectateur : public personnes
{
  int age;
 multimap<spectateur, Ticket> Mymap;

public:
  spectateur();
  spectateur(const spectateur &);
  ~spectateur();
  spectateur(int, string, string, string, string, int = 0);
  void ajouter_ticket(spectateur s, Ticket *t)
  {
    Mymap.insert(pair<spectateur, Ticket>(s, *t));
  }
  void get_spectateur();
  friend ostream &operator<<(ostream &, spectateur &);
  friend istream &operator>>(istream &, spectateur &);
  spectateur &operator=(spectateur &);
  bool operator<(const spectateur &other) const { return nom < other.nom; }
 
};

#endif
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
spectateur::spectateur(const spectateur &r):personnes(r)
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
