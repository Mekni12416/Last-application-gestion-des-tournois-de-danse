#ifndef danseur_pro_h
#define danseur_pro_h
#include"danseur.h"
#include <string>


class danseur_pro:public danseur
{
    int annee_experience;
    string palmares;

public:
    danseur_pro();
    ~danseur_pro();
    danseur_pro(int, string, string, string, string, string, int=0, string="champion");
    void enregistrer_danseur_pro();
    void afficher_danseur_pro();
    friend ostream& operator<<(ostream& , danseur_pro&);
    friend istream& operator>>(istream& , danseur_pro&);
    static void creer_fichier(fstream&);
    static void remplir_fichier(fstream&);
    static void afficher_fichier(fstream&);
    friend ostream& operator<<(ostream& , danseur_pro*);
    friend istream& operator>>(istream& , danseur_pro*);
};

#endif