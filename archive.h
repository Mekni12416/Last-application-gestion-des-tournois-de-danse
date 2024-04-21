#ifndef ARCHIVE_H
#define ARCHIVE_H

#include "danseur_amateur.h"
#include "danseur_pro.h"

using namespace std;
// Classe template de base
template <typename T>
class DanseurTemplate : public T {
public:
    DanseurTemplate() : T() {}
    DanseurTemplate(int cin, const string& nom, const string& prenom,
                    const std::string& nationalite, const string& date_naissance)
        : T(cin, nom, prenom, nationalite, date_naissance) {}

};

// Spécialisation pour les danseurs amateurs
class DanseurAmateurTemplate : public DanseurTemplate<danseur_amateur> {
public:
    DanseurAmateurTemplate() : DanseurTemplate<danseur_amateur>() {}
    DanseurAmateurTemplate(int cin, string& nom, const string& prenom,
                           const string& nationalite, const std::string& date_naissance,
                           const string& niveau_entrenement)
        : DanseurTemplate<danseur_amateur>(cin, nom, prenom, nationalite, date_naissance) {
            //this->niveau_entrenement = niveau_entrenement;
            
        }
};

// Spécialisation pour les danseurs professionnels
class DanseurProTemplate : public DanseurTemplate<danseur_pro> {
public:
    DanseurProTemplate() : DanseurTemplate<danseur_pro>() {}
    DanseurProTemplate(int cin, const std::string& nom, const std::string& prenom,
                       const std::string& nationalite, const std::string& date_naissance,
                       int annee_experience, const std::string& palmares)
        : DanseurTemplate<danseur_pro>(cin, nom, prenom, nationalite, date_naissance) {
            //this->annee_experience = annee_experience;
            //this->palmares = palmares;
        }
};


#endif // ARCHIVE_H
