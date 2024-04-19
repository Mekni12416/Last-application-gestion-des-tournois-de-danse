#ifndef danseur_h
#define danseur_h
#include "personnes.h"
#include <string>
#include <ios>
class danseur : public personnes
{
protected:
    string style_danse;

public:
    danseur();
    ~danseur();
    danseur(int, string, string, string, string, string);
    void enregistrer_danseur();
 
    void get_danseur() const;
    friend ostream& operator<<(ostream& , danseur&);
    bool operator<(const  danseur& other)const { return nom < other.nom;}
    friend istream& operator>>(istream& , danseur&);

    friend ostream& operator<<(ostream& , danseur*);
     friend istream& operator>>(istream& , danseur*);

 
};

#endif