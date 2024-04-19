
#include<string>
#include<list>
#include "Resultat.h"
#include "iterator"
#include<ios>
#include <fstream>
using namespace std;
class Epreuves
{
private:
    /* data */
    int num_epreuves;
    string heure_epreuves;
    string nom, lieu, date;
    int nbre_danseur;
    list<Resultat *> listRsultat;
public:
    //Constructeur par defaut
    Epreuves(int=0,string=" ",string=" ",string=" ",string=" ",int=0);
    //Constructeur par recopie
    Epreuves(const Epreuves &e);
    //AFFICHAGE EPREUVE
    void afficher_epreuves();
    //SURCHARGE OPERATEUR =
    Epreuves& operator=(Epreuves&);
    //SURCHARGE OPERATEUR << ET >> POUR SAISIR ET AFFICHER
    friend ostream& operator<<(ostream&, Epreuves&);
    friend istream& operator>>(istream&, Epreuves&);
    //SURCHARGE OPERATEUR << ET >> POUR LIRE ET ECRIRE UN FICHIER
    friend istream &operator>>(istream &in, Epreuves *e);
    friend ostream &operator<<(ostream &out, Epreuves *e);
    void ajouter_resultat(Resultat);
    void afficher_Liste_Resultat();

    //PARTIE FICIHER POUR METTRE TOUS LES RESULTATS DANS UN FICHIER
    void creerFichier(fstream& f);
    void remplirFiciher(fstream& f);
    void afficherFiciher(fstream& f);

    //PARTIE FICIHER POUR remplir EPREUVES
    void creerFichierEpreuve(fstream& f);
    void remplirFiciherEpreuve(fstream& f);
    void afficherFiciherEpreuve(fstream& f);



    ~Epreuves();
};


 
