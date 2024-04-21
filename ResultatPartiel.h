 
#include "Resultat.h"
#include <string>
#include<vector>
using namespace std;
#pragma once 
class ResultatPartiel:public Resultat
{
private:
    /* data */
    string commentairePartiel;
    vector<score *> scorePartiel;

public:
    ResultatPartiel(){}
    ResultatPartiel(int,  string=" ");
    ResultatPartiel& operator=(  ResultatPartiel&);
    friend ostream& operator<<(ostream&, ResultatPartiel&);
    friend istream& operator>>(istream&, ResultatPartiel&);
    ResultatPartiel(const ResultatPartiel&);

    void affichResulat();
    void ajout_score(danseur d, score *s);
    ~ResultatPartiel();
};


