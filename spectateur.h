#ifndef spectateur_h
#define spectateur_h
#include "personnes.cpp"
#include "Ticket.cpp"
#include <string>
#include <map>
#include <ios>
class spectateur : public personnes
{
  int age;
 multimap<spectateur, Ticket> Mymap;

public:
  spectateur();
  spectateur(const spectateur &);
  ~spectateur();
  spectateur(int, string, string, string, string, int = 0);
  void ajouter_ticket(spectateur s, Ticket *t)
  {
    Mymap.insert(pair<spectateur, Ticket>(s, *t));
  }
  void get_spectateur();
  friend ostream &operator<<(ostream &, spectateur &);
  friend istream &operator>>(istream &, spectateur &);
  spectateur &operator=(spectateur &);
  bool operator<(const spectateur &other) const { return nom < other.nom; }
 
};

#endif