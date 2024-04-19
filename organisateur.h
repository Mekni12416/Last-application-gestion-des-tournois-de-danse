#ifndef organisateur_h
#define organisateur_h
#include <string>
#include "personnes.h"
#include <list>
#include<vector>
#include "epreuve.cpp"
#include"Recompenses.cpp"
#include "iterator"
class organisateur : public personnes
{
    string role;
    int nombre_tournoi_organisee;
    list<Epreuves *> list_Epreuve;
    vector<Recompenses*> list_recompenses;
    

public:
    organisateur();
    organisateur(const organisateur &);
    ~organisateur();
    organisateur(int, string, string, string, string, string, int);
    void set_organisateur();
    void get_organisateur();
    void creer_tournoi(Epreuves);
    void afficher_tournoi();
    friend ostream &operator<<(ostream &, organisateur &);
    friend istream &operator>>(istream &, organisateur &);
    organisateur &operator=(organisateur &);
};

#endif