
#include "Ticket.h"
#include<iostream>
using namespace std;

Ticket::Ticket(int num ,float prix)
{
    this->num_ticket= num;
    this->prix= prix;
}

Ticket::~Ticket()
{
}

Ticket::Ticket(const Ticket& t)
{
    this->num_ticket = t.num_ticket;
    this->prix = t.prix;
}

Ticket& Ticket::operator=(const Ticket& t)
{
    if(this!=&t)
    {
        this->num_ticket=t.num_ticket;
        this->prix=t.prix;
    }
    return *this;
}
istream& operator>>(istream& in, Ticket& t)
{
    
    cout<<"voulez vous acheter une tiquet de quelle ordre si de premier ordre tapez 30si de deuxieme ordre tapez 20"<<endl;
    in>>t.prix;
    
    if(t.prix==30){
        cout<<"le prix de cette tiquet est 30 dt"<<endl;
        t.num_ticket=rand();
        cout<<"votre tiquet de premier ordre est reserver pour un numero"<<t.num_ticket<<endl;

    }
    if(t.prix==20){
        cout<<"le prix de cette tiquet est 20 dt"<<endl;
        t.num_ticket=rand();
        cout<<"votre tiquet de deuxieme ordre est reserver pour un numero"<<t.num_ticket<<endl;

    }
    return in ;
}

ostream& operator<<(ostream& out, Ticket& t)
{
    out<<"Numero ticket:"<<t.num_ticket<<endl;
    out<<"\nPrix du ticket: "<<t.prix;
    return out; 
}