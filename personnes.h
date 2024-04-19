#ifndef personnes_h
#define personnes_h
using namespace std;
#include <string>
#include<ios>

class personnes
{
protected:
    int cin_p;
    string nom;
    string prenom;
    string nationalite;
    string date_naissance;


public:
   personnes();
   personnes(const personnes&);
   ~personnes();
   personnes(int,string,string,string,string);
   virtual  void set_personne();
   virtual  void  get_personne() const ;
   string getNom() const {return nom;}
   friend ostream& operator<<(ostream& , personnes&);
   friend istream& operator>>(istream& , personnes&);



};
#endif