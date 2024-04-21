#include "Resultat.h"
#include <string>
#include<vector>
using namespace std;
#pragma once 
class ResultatTotal:public Resultat
{
private:
    /* data */
     
    vector<score *> scoretotal;

public:
    ResultatTotal(){}
    ResultatTotal(int);
    ResultatTotal& operator=(  ResultatTotal&);
    friend ostream& operator<<(ostream&, ResultatTotal&);
    friend istream& operator>>(istream&, ResultatTotal&);
    ResultatTotal(const ResultatTotal&);

    void affichResulat();
    void ajout_score(danseur d, score *s);
    void afficherClassementDanseur();
    ~ResultatTotal();
};


