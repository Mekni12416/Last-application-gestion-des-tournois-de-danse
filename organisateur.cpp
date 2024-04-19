#include <iostream>
using namespace std;
#include "organisateur.h"
#include <string>
// constructeur par deffaut pour oragnisateur
organisateur::organisateur()
{
    personnes();
    role = "";
    nombre_tournoi_organisee = 0;
}

// constructeur par recopie
 organisateur::organisateur(const organisateur &o) : personnes(o)
{
    role = o.role;
    nombre_tournoi_organisee = o.nombre_tournoi_organisee;
    // Déclaration de l'itérateur
    list<Epreuves *>::const_iterator it;
    for (it = o.list_Epreuve.begin(); it != o.list_Epreuve.end(); ++it)
    {
        // Création d'un nouvel objet Epreuves et ajout à la liste
        Epreuves *e = new Epreuves(**it); // Assurez-vous que le constructeur de copie de Epreuves est correctement défini
        list_Epreuve.push_back(e);
    }
}

// destrecteur
organisateur::~organisateur() {
    list<Epreuves *>::iterator it;
    for (it = list_Epreuve.begin(); it != list_Epreuve.end(); ++it)
    {
        delete *it;
    }
    list_Epreuve.clear();
    for(unsigned int i=0;i<list_recompenses.size();i++){
        delete list_recompenses[i];
    }
    list_recompenses.clear();

}
// constructeur pour organisateur
organisateur::organisateur(int cin_p, string nom, string prenom, string nationalite, string date_naissance, string role, int nombre_tournoi_organisee)
{
    personnes(cin_p, nom, prenom, nationalite, date_naissance);
    this->role = role;
    this->nombre_tournoi_organisee = nombre_tournoi_organisee;
}
// methode seter pour organisateur
void organisateur::set_organisateur()
{
    set_personne();
    cout << "donner le role de l organisateur" << endl;
    cin >> role;
    cout << "donner le nombre des tournois organisee par l organisateur" << endl;
    cin >> nombre_tournoi_organisee;
}
// methode geter pour organisateur
void organisateur::get_organisateur()
{
    get_personne();
    cout << " le role de l organisateur est : " << role << endl;
    cout << "le nombre des tournois organisee par l organisateur : " << nombre_tournoi_organisee << endl;
}
// methode pour creer un tournoi
void organisateur::creer_tournoi(Epreuves e)
{
    Epreuves *ep = new Epreuves(e);
    this->list_Epreuve.push_back(ep);
}
// meth afficher tournoi
void organisateur::afficher_tournoi()
{
    list<Epreuves *>::iterator it;
    for (it = list_Epreuve.begin(); it != list_Epreuve.end(); ++it)
    {
        cout << **it;
        cout << endl;
    }
}
ostream &operator<<(ostream &out, organisateur &o)
{
    out << "le cin est : " << o.cin_p << endl;
    out << "le nom est : " << o.nom << endl;
    out << "le prenom est : " << o.prenom << endl;
    out << "la nationalite est : " << o.nationalite << endl;
    out << "le date naissance est : " << o.date_naissance << endl;
    out << " le role de l organisateur est : " << o.role << endl;
    out << "le nombre des tournois organisee par l organisateur : " << o.nombre_tournoi_organisee << endl;

    return out;
}
istream &operator>>(istream &in, organisateur &o)
{
    cout << "donner le cin " << endl;
    in >> o.cin_p;
    cout << "donner le nom " << endl;
    in >> o.nom;
    cout << "donner le prenom " << endl;
    in >> o.prenom;
    cout << "donner le nationalite " << endl;
    in >> o.nationalite;
    cout << "donner date naissance " << endl;
    in >> o.date_naissance;
    cout << " donner le role de l organisateur est : " << endl;
    in >> o.role;
    cout << "donner le nombre des tournois organisee par l organisateur : " << endl;
    in >> o.nombre_tournoi_organisee;
    return in;
}

organisateur &organisateur::operator=(organisateur &o)
{
    if (this != &o)
    {
        personnes *p1 = this;
        personnes *p2 = &o;
        *p1 = *p2;
        list<Epreuves *>::iterator it;
        for (it = list_Epreuve.begin(); it != list_Epreuve.end(); ++it)
        {
            delete *it;
        }
        list_Epreuve.clear();
        Epreuves *e;
        for (it = o.list_Epreuve.begin(); it != o.list_Epreuve.end(); ++it)
        {
            e = new Epreuves(**it);
            list_Epreuve.push_back(e);
        }
    }
}