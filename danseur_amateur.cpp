#include <iostream>
using namespace std;
#include "danseur_amateur.h"
#include <string>
#include"fstream"
// constructeur par deffaut pour danseur amateur
danseur_amateur::danseur_amateur()
{
    danseur();
    niveau_entrenement = "";
}
// constructeur pour danseur amateur
danseur_amateur::danseur_amateur(int cin_p, string nom, string prenom, string nationalite, string date_naissance, string style_danse, string niveau_entrenement)
{
    danseur(cin_p, nom, prenom, nationalite, date_naissance, style_danse);
    this->niveau_entrenement = niveau_entrenement;
}
//destrecteur
danseur_amateur::~danseur_amateur(){}
// methode pour enregistrer danseur amateur
void danseur_amateur::enregistrer_danseur_amateur()
{
    danseur::enregistrer_danseur();
    cout << "donner le niveau_entrenement" << endl;
    cin >> niveau_entrenement;
}
//methode pour affichage d un danseur amateur
void danseur_amateur::afficher_danseur_amateur(){
    get_danseur();
    cout << "le niveau d entrainement est :" << niveau_entrenement << endl;
}
//surchager l operateur <<
ostream& operator<<(ostream& out,danseur_amateur& d){
    out<<"le cin est : "<<d.cin_p<<endl;
    out<<"le nom est : "<<d.nom<<endl;
    out<<"le prenom est : "<<d.prenom<<endl;
    out<<"la nationalite est : "<<d.nationalite<<endl;
    out<<"le date naissance est : "<<d.date_naissance<<endl;
    out<<"le style de danse est :"<<d.style_danse<<endl;
    out<<"le niveau entrenement : "<<d.niveau_entrenement<<endl;
    return out;


}
//surcharger l operator >>
istream& operator>>(istream& in, danseur_amateur& d){
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
    cout << "donner niveau entrenement " << endl;
    in >> d.niveau_entrenement;
    return in;
}
void danseur_amateur::creer_fichier(fstream& f){
    f.open("C:\\Users\\mekni\\Desktop\\version finale poo\\danseur_amateur.txt",ios::in|ios::out|ios::trunc);
    if(! f.is_open()) {
        exit(-1);
    }
}
/*
void danseur_amateur::remplir_fichier(fstream& f){
    danseur_amateur d();
    int n;
    cout<<"donner le nombre de danseurs amateurs a remplir"<<endl;
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<"saisir un danseur amateur"<<endl;
        cin>>d;
        f<<d<<endl;
    }
}*/
/*void danseur_amateur::afficher_fichier(fstream& f){
    danseur_amateur d();
    f.seekg(0);
    
    int arret=0;
    do
    {
        
        f>>d;
        if(f.eof()) {
            arret=1; break;
        }
        cout<<d<<endl;
    } while (arret==0);
    
        
    
    
}
*/
ostream& operator<<(ostream& out,danseur_amateur* d){
    out<<"le cin est : "<<d->cin_p<<endl;
    out<<"le nom est : "<<d->nom<<endl;
    out<<"le prenom est : "<<d->prenom<<endl;
    out<<"la nationalite est : "<<d->nationalite<<endl;
    out<<"le date naissance est : "<<d->date_naissance<<endl;
    out<<"le style de danse est :"<<d->style_danse<<endl;
    out<<"le niveau entrenement : "<<d->niveau_entrenement<<endl;
    return out;


}
istream& operator>>(istream& in, danseur_amateur* d){
    cout << "donner le cin " << endl;
    in >> d->cin_p;
    cout << "donner le nom " << endl;
    in >> d->nom;
    cout << "donner le prenom " << endl;
    in >> d->prenom;
    cout << "donner le nationalite " << endl;
    in >> d->nationalite;
    cout << "donner date naissance " << endl;
    in >> d->date_naissance;
    cout << "donner style danse " << endl;
    in >> d->style_danse;
    cout << "donner niveau entrenement " << endl;
    in >> d->niveau_entrenement;
    return in;
}