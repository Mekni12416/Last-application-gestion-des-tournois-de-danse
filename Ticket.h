#include<ios>
#include <random>
class Ticket
{
private:
    
    int num_ticket;
    float prix;
public:
    Ticket(int=0,float=100);
    ~Ticket();
    Ticket(const Ticket&);
    Ticket& operator=(const Ticket&);
    friend istream& operator>>(istream& in , Ticket&);
    friend ostream& operator<<(ostream& , Ticket&);
};

