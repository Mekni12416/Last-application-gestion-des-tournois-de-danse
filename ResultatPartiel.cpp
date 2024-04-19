 
#include "ResultatPartiel.h"
#include<iostream>
#include<ios>
ResultatPartiel::ResultatPartiel(int num,  string com):Resultat(num)
{
    this->commentairePartiel = com;
    int choix;
    score *s;
    do{
        //s=new score(*scorePartiel[i]);
        s->enregistrerScore();
        this->scorePartiel.push_back(s);
        cout<<"Tapez 1 pour continuer ou autre pour arreter";
        cin>>choix; 
    }while (choix==1);
  
}

ResultatPartiel::~ResultatPartiel()
{
     
    for(unsigned int i=0;i<scorePartiel.size();i++)
    {
        delete scorePartiel[i];
    }
    scorePartiel.clear();
}

ResultatPartiel::ResultatPartiel(const ResultatPartiel& r):Resultat(r)
{
    this->commentairePartiel= r.commentairePartiel;
    score *s;
    for(unsigned int i=0;i<r.scorePartiel.size();i++)
    {
        s=new score(*r.scorePartiel[i]);
        this->scorePartiel.push_back(s);
    }
}

istream& operator>>(istream& in , ResultatPartiel& r)
{
    unsigned int nbr;
    Resultat *re= &r;
    in>>*re;
    cout<<"Donnez le commentaire partiel:\n";
    in>>r.commentairePartiel;
    cout<<"\n Donner le nombre de scores partiels: ";
    in>>nbr;
    for(unsigned int i=0;i<nbr;i++)
    {
        score *s = new score();
        in>>*s;
        r.scorePartiel.push_back(s);
    }
    cout<<"\n";

    return in;
}

ostream& operator<<(ostream& out, ResultatPartiel& r)
{
    Resultat *re=&r;
    out<<*re;
    out<<"Commentaire partiel: "<<r.commentairePartiel<<endl;

    out<<"\n Les scores partiels sont: "<<endl;
    for(unsigned int i=0;i<r.scorePartiel.size();i++)
    {
        out<<*r.scorePartiel[i]<<"\t";
    }
    out<<"\n";

    return out; 
}

ResultatPartiel& ResultatPartiel::operator=(  ResultatPartiel& rp)
{
    if(this!=&rp)
    {
        Resultat *r1=this;
        Resultat *r2= &rp;
        *r1= *r2;

        for(unsigned int i=0;i<scorePartiel.size();i++)
        {
            delete scorePartiel[i];
        }
        scorePartiel.clear();
        score *s;
        for(unsigned int i=0;i<scorePartiel.size();i++)
        {
            s= new score(*rp.scorePartiel[i]);
            scorePartiel.push_back(s);
        }
    }
    return *this;
}


void ResultatPartiel::ajout_score(danseur d, score *s) {
    // Ajouter le score au tableau de scores
    scorePartiel.push_back(s);

    // Ajouter le couple (danseur, score) à la map dans la classe de base Resultat
    this->Resultat::ajout_score(d, s);
}

void ResultatPartiel::affichResulat()
{
    Resultat *re=this;
    cout<<*re;
    cout<<"Commentaire partiel: "<<commentairePartiel<<endl;

    cout<<"\n Les scores partiels sont: "<<endl;
    for(unsigned int i=0;i<scorePartiel.size();i++)
    {
        cout<<*scorePartiel[i]<<"\t";
    }
    cout<<"\n";
}