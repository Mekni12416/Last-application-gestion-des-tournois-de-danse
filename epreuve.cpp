#include "epreuve.h"
#include <iostream>

Epreuves::Epreuves(int num, string heure, string nom, string lieu, string date, int nbr)
{
    this->num_epreuves = num;
    this->heure_epreuves = heure;
    this->nom = nom;
    this->lieu = lieu;
    this->date = date;
    this->nbre_danseur = nbr;
}
/*
Epreuves::Epreuves(const Epreuves &e)
{
    this->num_epreuves=e.num_epreuves;
    this->heure_epreuves=e.heure_epreuves;
    this->nom= e.nom;
    this->lieu = e.lieu;
    this->date=e.date;
    this->nbre_danseur= e.nbre_danseur;
    list<Resultat>::iterator it;
    for(it=e.listRsultat.begin();it!=e.listRsultat.end();++it)
    {
        it->affichResulat();
        cout<<"\n";
    }

}
 */
void Epreuves::afficher_epreuves()
{
    cout << "numero epreuve:" << this->num_epreuves << "\n heure epreuves: " << this->heure_epreuves << endl;
    cout << "Nom de l epreuve:" << nom << endl;
    cout << "Lieu de l epreuve:" << lieu << endl;
    cout << "Date de l epreuve:" << date << endl;
    cout << "nombre de danseur:" << nbre_danseur << endl;
   
}

ostream &operator<<(ostream &out, Epreuves &e)
{
    out << "\nnumero epreuve:" << e.num_epreuves;
    out << "\n heure epreuves: " << e.heure_epreuves<<endl;
    out << "Nom de l epreuve:" << e.nom << endl;
    out << "Lieu de l epreuve:" << e.lieu << endl;
    out << "Date de l epreuve:" << e.date << endl;
    out << "nombre de danseur:" << e.nbre_danseur << endl;

    return out;
}

ostream &operator<<(ostream &out, Epreuves *e)
{
    out << "\nnumero epreuve:" << e->num_epreuves;
    out << "\n heure epreuves: " << e->heure_epreuves<<endl;
    out << "Nom de l epreuve:" << e->nom << endl;
    out << "Lieu de l epreuve:" << e->lieu << endl;
    out << "Date de l epreuve:" << e->date << endl;
    out << "nombre de danseur:" << e->nbre_danseur << endl;

    return out;
}

istream &operator>>(istream &in, Epreuves &e)
{
    cout << "Donner le numero d epreuves:";
    in >> e.num_epreuves;
    cout << "Donner l heure d epreuves:";
    in >> e.heure_epreuves;
    cout << "Donner le nom d epreuves:";
    in >> e.nom;
    cout << "Donner le lieu d epreuves:";
    in >> e.lieu;
    cout << "Donner la date d epreuves:";
    in >> e.date;
    cout << "Donner le nombre de danseur :";
    in >> e.nbre_danseur;



    return in;
}

istream &operator>>(istream &in, Epreuves *e)
{
    in.seekg(0);
    cout << "Donner le numero d epreuves:";
    in >> e->num_epreuves;
    cout << "Donner l heure d epreuves:";
    in >> e->heure_epreuves;
    cout << "Donner le nom d epreuves:";
    in >> e->nom;
    cout << "Donner le lieu d epreuves:";
    in >> e->lieu;
    cout << "Donner la date d epreuves:";
    in >> e->date;
    cout << "Donner le nombre de danseur :";
    in >> e->nbre_danseur;
    return in;
}

Epreuves &Epreuves::operator=(Epreuves &e)
{
    if (this != &e)
    {
        this->num_epreuves = e.num_epreuves;
        this->heure_epreuves = e.heure_epreuves;
        this->nom = e.nom;
        this->lieu = e.lieu;
        this->date = e.date;
        this->nbre_danseur = e.nbre_danseur;
        list<Resultat *>::iterator it;
        for ( auto it =listRsultat.begin(); it!=listRsultat.end(); ++it)
        {
            delete *it;
        }

        listRsultat.clear();
        Resultat *r;
        for ( auto it = e.listRsultat.begin(); it != e.listRsultat.end(); ++it)
        {
            r = new Resultat(**it);
            listRsultat.push_back(r);
        }
        delete [] r;

     }
     return *this;   
}

void Epreuves::ajouter_resultat(Resultat r)
{
    Resultat *res= new Resultat(r);
    listRsultat.push_back(res);

}

Epreuves::~Epreuves()
{
     list<Resultat *>::iterator it;
        for ( auto it =listRsultat.begin(); it!=listRsultat.end(); ++it)
        {
            delete *it;
        }

        listRsultat.clear();
}

void Epreuves::afficher_Liste_Resultat()
{
     cout << "\n-------AFFICHAGE DE LA LISTE DES RESULTATS-------\n";
    list<Resultat *>::const_iterator it;
    for (auto it = listRsultat.begin(); it!= listRsultat.end(); ++it)
    {
       // (*it)->affichResulat();
       cout<<**it;
        cout << "\n";
    }
}

void Epreuves::creerFichier(fstream& f)
{
    f.open("C:\\Users\\DELL\\Desktop\\ProjetC++2024\\Application-de-gestion-des-tournoi-de-danse\\FiciheRresultats.txt" , ios::out | ios::trunc);
    if (!f.is_open()) {
        cerr << "Erreur : Impossible d'ouvrir le fichier." << endl;
        exit(-1);// Quitter le programme avec un code d'erreur
    }
}  

void Epreuves::remplirFiciher(fstream& f)
{
    list<Resultat *>::iterator it;
    /* 
    for(it=listRsultat.begin();it!=listRsultat.end();++it)
    {
        f<<**it;
         f << "---------------------------------------" << endl;
    }*/

    for ( it = listRsultat.begin(); it != listRsultat.end(); ++it) {
        Resultat* resultat = *it;
          const multimap<danseur, score>& myMap = resultat->getMyMap(); // Obtenir la multimap du résultat

        multimap<danseur, score>::iterator mapIt;
        for (auto mapIt = myMap.begin(); mapIt != myMap.end(); ++mapIt) {
            //danseur& d = mapIt->first;
            score s = mapIt->second;

            // Écrire les données dans le fichier
            f << "Numero de resultat: " << resultat->getNum_res() << endl;
            f << "Nom du danseur: " <<  mapIt->first.getNom() << endl;
            f << "Score: " << s.calculScore() << endl;
            f << "-------------------" << endl; // Marquer la fin des données pour chaque paire
        }
        f << "-------------------" << endl;
    }

   
}

void Epreuves::creerFichierEpreuve(fstream& f)
{
    f.open("C:\\Users\\DELL\\Desktop\\ProjetC++2024\\Application-de-gestion-des-tournoi-de-danse\\FiciheEpreuves.txt" ,ios::in | ios::out | ios::trunc);
    if (!f.is_open()) {
        cerr << "Erreur : Impossible d'ouvrir le fichier." << endl;
        exit(-1);// Quitter le programme avec un code d'erreur
    }
}

void Epreuves::remplirFiciherEpreuve(fstream& f)
{
    Epreuves e;
    int nbr;
    cout<<"Donner le nombre epreuves enregister:";
    cin>>nbr;
    for(int i=0;i<nbr;i++)
    {
        cout<<"\nSaisir Epreuves"<<endl;
        cin>>e;
        f<<&e;
    }
}

void Epreuves::afficherFiciherEpreuve(fstream& f)
{
    Epreuves e;
    f.seekg(0);
    while (1) 
    {
        f>>&e;
        if(f.eof()) break;
        cout<<e<<endl;

    }
    
}
