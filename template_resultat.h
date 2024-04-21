// Classe template de base
#include "Resultat.h"
#include<string>
#include <vector>
using namespace std;

template <typename T>
class ResultatTemplate  {
protected:
    int num_res;
    multimap<danseur, score> myMap;

public:
    ResultatTemplate(int = 2) : num_res(2) {}
    ResultatTemplate(const ResultatTemplate &) {}
    ResultatTemplate &operator=(const ResultatTemplate &) { return *this; }
     
    virtual void affichResulat() = 0;
    virtual void ajout_score(danseur d, score *s) = 0;
    virtual ~ResultatTemplate() {}
};

// Spécialisation pour les résultats partiels
template <typename T>
class ResultatPartielTemplate : public ResultatTemplate<T> {
private:
    string commentairePartiel;
    vector<score *> scorePartiel;

public:
    ResultatPartielTemplate(int num_res, string commentaire = "")
        : ResultatTemplate<T>(num_res), commentairePartiel(commentaire) {}
    ResultatPartielTemplate(const ResultatPartielTemplate &) {}
    string getCommentairePartiel() {return commentairePartiel;}
    ResultatPartielTemplate &operator=(const ResultatPartielTemplate &) { return *this; }
    void affichResulat() override {}
    void ajout_score(danseur d, score *s) override {}
    ~ResultatPartielTemplate() {}
};

// Spécialisation pour les résultats totaux
template <typename T>
class ResultatTotalTemplate : public ResultatTemplate<T> {
private:
    vector<score *> scoretotal;

public:
    ResultatTotalTemplate(int num_res) : ResultatTemplate<T>(num_res) {}
    ResultatTotalTemplate(const ResultatTotalTemplate &) {}
    ResultatTotalTemplate &operator=(const ResultatTotalTemplate &) { return *this; }
    void affichResulat() override {}
    void ajout_score(danseur d, score *s) override {}
    ~ResultatTotalTemplate() {}
    int getNum_res(){return this->num_res;}
};
