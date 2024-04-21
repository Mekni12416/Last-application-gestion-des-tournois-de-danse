
#include <string>
#include<ios>
using namespace std;
class Critere
{
private:
    
    int poids;
    string description;
public:
    Critere(int=0, string=" ");
    Critere(const Critere&);
    void saisirCritere();
    friend ostream& operator<<(ostream&, Critere&);
    friend istream& operator>>(istream&, Critere&);
    void afficher();
    int getPoids(){return poids;}
    string getDescription(){return description;}

    ~Critere(){} 
};

 
