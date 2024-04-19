
#include "ResultTotal.h"
#include<iostream>
#include<ios>
ResultatTotal::ResultatTotal(int num):Resultat(num)
{
     
    int choix;
    score *s;
    do{
        //s=new score(*scorePartiel[i]);
        s->enregistrerScore();
        this->scoretotal.push_back(s);
        cout<<"Tapez 1 pour continuer ou autre pour arreter";
        cin>>choix; 
    }while (choix==1);
  
}

ResultatTotal::~ResultatTotal()
{
    for(unsigned int i=0;i<scoretotal.size();i++)
    {
        delete scoretotal[i];
    }
    scoretotal.clear();
}

ResultatTotal::ResultatTotal(const ResultatTotal& r):Resultat(r)
{
    
    score *s;
    for(unsigned int i=0;i<r.scoretotal.size();i++)
    {
        s=new score(*r.scoretotal[i]);
        this->scoretotal.push_back(s);
    }
}

istream& operator>>(istream& in , ResultatTotal& r)
{
    int nbr;
    Resultat *re= &r;
    in>>*re;
     
    cout<<"\n Donner le nombre de scores partiels: ";
    in>>nbr;
    for(  int i=0;i<nbr;i++)
    {
        score *s = new score();
        in>>*s;
        r.scoretotal.push_back(s);
    }
    cout<<"\n";

    return in;
}

ostream& operator<<(ostream& out, ResultatTotal& r)
{
    Resultat *re=&r;
    out<<*re;
    

    out<<"\n Les scores partiels sont: "<<endl;
    for(unsigned int i=0;i<r.scoretotal.size();i++)
    {
        out<<*r.scoretotal[i]<<"\t";
    }
    out<<"\n";

    return out; 
}

ResultatTotal& ResultatTotal::operator=(  ResultatTotal& rp)
{
    if(this!=&rp)
    {
        Resultat *r1=this;
        Resultat *r2= &rp;
        *r1= *r2;

        for(unsigned int i=0;i<scoretotal.size();i++)
        {
            delete scoretotal[i];
        }
        scoretotal.clear();
        score *s;
        for(unsigned int i=0;i<rp.scoretotal.size();i++)
        {
            s= new score(*rp.scoretotal[i]);
            scoretotal.push_back(s);
        }
    }
    return *this;
}


void ResultatTotal::ajout_score(danseur d, score *s) {
    // Ajouter le score au tableau de scores
    scoretotal.push_back(s);

    // Ajouter le couple (danseur, score) à la map dans la classe de base Resultat
    this->Resultat::ajout_score(d, s);
}



void ResultatTotal::afficherClassementDanseur() {
    // Créer une copie de la multimap pour pouvoir la trier
    multimap<int, danseur> classement;
     multimap<danseur,score>::iterator it;
    // Remplir la copie avec les scores totaux et les danseurs
    for (auto it = this->myMap.begin(); it != myMap.end(); ++it) {
        int totalScore = 0;
        // Calculer le score total du danseur
        for (score* s : scoretotal) {
            totalScore += s->calculScore() ;
        }
        classement.insert({ totalScore, it->first });
    }

    // Afficher le classement des danseurs
    int rank = 1;
    cout << "Classement des danseurs :" << endl;
    for (auto it = classement.rbegin(); it != classement.rend(); ++it) {
        cout << "Position " << rank++ << " : " << it->second << " - Score total : " << it->first << endl;
    }
}

void ResultatTotal::affichResulat()
{
    Resultat::affichResulat();
}