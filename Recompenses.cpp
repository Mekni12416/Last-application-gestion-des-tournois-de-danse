#include "Recompenses.h"
#include <iostream>
Recompenses::Recompenses(int num, string med, string trop)
{
    this->num_recom= num;
    this->medailles=med;
    this->trophee=trop;
}

Recompenses::~Recompenses()
{
}

Recompenses::Recompenses(const Recompenses& r)
{
    num_recom=r.num_recom;
    medailles= r.medailles;
    trophee= r.trophee;
}
Recompenses& Recompenses::operator=(const Recompenses& r)
{
    if(this!=&r)
    {
        num_recom=r.num_recom;
        medailles=r.medailles;
        trophee=r.trophee;
    }
    return *this;
}
ostream& operator<<(ostream& out, Recompenses& r)
{
    out<<"\nLe numero de recompense est: "<<r.num_recom;
    out<<"\n La medaille est: "<<r.medailles;
    out<<"\n Le trophee est: "<<r.trophee;
    return out;
}

istream& operator>>(istream& in , Recompenses& r)
{
    cout<<"\nLe numero de recompense est: ";
    in>>r.num_recom;
    cout<<"\n La medaille est: ";
    in>>r.medailles;
    cout<<"\n Le trophee est: ";
    in>>r.trophee;
    return in;

}