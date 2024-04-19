#include <iostream>
using namespace std;
#include "danseur_pro.h"
#include <string>
#include"fstream"
// constructeur par deffaut pour danseur pro
danseur_pro::danseur_pro()
{
    danseur();
    annee_experience = 0;
    palmares = "";
}
//destrecteur
danseur_pro::~danseur_pro(){};
// constructeur pour danseur pro
danseur_pro::danseur_pro(int cin_p, string nom, string prenom, string nationalite, string date_naissance, string style_danse, int annee_experience, string palmares)
{    danseur(cin_p,nom,prenom,nationalite,date_naissance,style_danse);
    this->annee_experience = annee_experience;
    this->palmares = palmares;
}
void danseur_pro::enregistrer_danseur_pro()
{
    danseur::enregistrer_danseur();
    cout << "donner les annee d experience" << endl;
    cin >> annee_experience;
    cout << "donner le palmares" << endl;
    cin >> palmares;
}
// methode afficher danseur_pro
void danseur_pro::afficher_danseur_pro()
{
    danseur::get_danseur();
    cout << "les annees d experience sont :" << annee_experience << endl;
    cout << "le palmares est :" << palmares << endl;
}
//surchager l operateur <<
ostream& operator<<(ostream& out,danseur_pro& d){
    out<<"le cin est : "<<d.cin_p<<endl;
    out<<"le nom est : "<<d.nom<<endl;
    out<<"le prenom est : "<<d.prenom<<endl;
    out<<"la nationalite est : "<<d.nationalite<<endl;
    out<<"le date naissance est : "<<d.date_naissance<<endl;
    out<<"le style de danse est :"<<d.style_danse<<endl;
    out<<"les annees experience : "<<d.annee_experience<<endl;
    out<<"les palmares : "<<d.palmares<<endl;
    
    return out;


}
//surcharger l operator >>
istream& operator>>(istream& in, danseur_pro& d){
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
    cout << "donner les annees experience " << endl;
    in >> d.annee_experience;
    cout << "donner les palmares " << endl;
    in >> d.palmares;
    return in;
}
void danseur_pro::creer_fichier(fstream& f){
    f.open("C:\\Users\\mekni\\Desktop\\version finale poo\\danseur_pro.txt",ios::in|ios::out|ios::trunc);
    if(! f.is_open()) {
        exit(-1);
    }
}
void danseur_pro::remplir_fichier(fstream& f){
    danseur_pro d;
    int n;
    cout<<"donner le nombre de danseurs pro a remplir"<<endl;
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<"saisir un danseur pro"<<endl;
        cin>>d;
        f<<d<<endl;
    }
}
void danseur_pro::afficher_fichier(fstream& f){
    danseur_pro d;
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
ostream& operator<<(ostream& out,danseur_pro* d){
    out<<"le cin est : "<<d->cin_p<<endl;
    out<<"le nom est : "<<d->nom<<endl;
    out<<"le prenom est : "<<d->prenom<<endl;
    out<<"la nationalite est : "<<d->nationalite<<endl;
    out<<"le date naissance est : "<<d->date_naissance<<endl;
    out<<"le style de danse est :"<<d->style_danse<<endl;
    out<<"les annees experience : "<<d->annee_experience<<endl;
    out<<"les palmares : "<<d->palmares<<endl;
    return out;


}
istream& operator>>(istream& in, danseur_pro* d){
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
    cout << "donner les annees experience " << endl;
    in >> d->annee_experience;
    cout << "donner les palmares " << endl;
    in >> d->palmares;
    return in;
}