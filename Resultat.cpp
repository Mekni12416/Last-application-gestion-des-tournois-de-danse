
//#include "Resultat.h"
#include <iostream>
using namespace std;
using namespace std;
#include <ios>
#include <map>

#include "danseur.h"
#include "score.cpp"
class Resultat
{
protected:
    /* data */
    int num_res;
    multimap<danseur,score>  myMap;
    
public:
     
    Resultat(int=2);
    Resultat(const Resultat&);
    Resultat& operator=(Resultat&);
    int getNum_res() {return num_res;}
    const multimap<danseur, score>& getMyMap()  const{return myMap;}
    friend ostream& operator<<(ostream&, Resultat&);
    friend istream& operator>>(istream&, Resultat&);
      void affichResulat();
      void ajout_score(danseur d, score *s);
    //PARTIE FICIHIER
     
     
     ~Resultat();
};

/*
Resultat::Resultat(int num)
{
    this->num_res = num;
}

Resultat::~Resultat()
{
}

Resultat::Resultat(const Resultat &r)
{
    this->num_res = r.num_res;
}

Resultat &Resultat::operator=(const Resultat &r)
{
    if (this != &r)
    {
        this->num_res = r.num_res;
    }
    return *this;
}

istream &operator>>(istream &in, Resultat &r)
{
    cout << "Donner le numero du resultat:";
    in >> r.num_res;

    return in;
}

ostream &operator<<(ostream &out, const Resultat &r)
{
 
    out<<"numero du resultat:"<<r.num_res<<endl;
    multimap<danseur,score>::iterator  it;
    for(it=r.myMap.begin();it!=r.myMap.end();++it)
    {
        
        //out<<(it*)->first.getNom();
        out<<"Le nom du danseur est:"<<it->first.getNom()<<endl;
        out<<"Le resultat sur 20 est:";
        out<<it->second.calculScore();
 
   
    }
    return out;
}
/*for(it=r.myMap.begin();it!=r.myMap.end();++it)
{

   //out<<(*it).first;
    out<<"Le resultat sur 20 est:\n";
    out<<it->second.calculScore();
}*/
/*
void Resultat::ajout_score(danseur d, score *s){
    myMap.insert(pair<danseur,score>(d,*s));

}

void Resultat::affichResulat()
{
 
    multimap<danseur,score>::iterator  it;
    for(it=myMap.begin();it!=myMap.end();++it)
    {
        
        //cout<< it->first;
        it->first.get_danseur();
        cout<<"Le resultat sur 20 est:\n";
        cout<<it->second.calculScore()<<endl;
    }


 }
    
 */   
    
     


Resultat::Resultat(int num)
{
    this->num_res = num;
}

Resultat::~Resultat()
{
}

Resultat::Resultat(const Resultat &r)
{
    this->num_res = r.num_res;
}

Resultat& Resultat::operator=( Resultat &r)
{
    if (this != &r)
    {
        this->num_res = r.num_res;
    }
    return *this;
}

istream &operator>>(istream &in, Resultat &r)
{
    cout << "Donner le numero du resultat:";
    in >> r.num_res;

    return in;
}

ostream& operator<<(ostream& out,  Resultat &r)
{
 
    out<<"numero du resultat:"<<r.num_res<<endl;
    multimap<danseur,score>::iterator  it;
    for(it=r.myMap.begin();it!=r.myMap.end();++it)
    {
        
        //out<<(it*)->first.getNom();
        out<<"Le nom du danseur est:"<<it->first.getNom()<<endl;
        out<<"Le resultat sur 20 est:";
        out<<it->second.calculScore();
 
   
    }
    return out;
}
/*for(it=r.myMap.begin();it!=r.myMap.end();++it)
{

   //out<<(*it).first;
    out<<"Le resultat sur 20 est:\n";
    out<<it->second.calculScore();
}*/

void Resultat::ajout_score(danseur d, score *s){
    myMap.insert(pair<danseur,score>(d,*s));

}

void Resultat::affichResulat()
{
 
    multimap<danseur,score>::iterator  it;
    for(it=myMap.begin();it!=myMap.end();++it)
    {
        
        //cout<< it->first;
        it->first.get_danseur();
        cout<<"Le resultat sur 20 est:\n";
        cout<<it->second.calculScore()<<endl;
    }


 }
    
    
    
     
