#ifndef ARCHIVE_H
#define ARCHIVE_H

#include "danseur_amateur.cpp"
#include "danseur_pro.cpp"

using namespace std;
// Classe template de base
template <typename T>
class DanseurTemplate : public T {
public:
    DanseurTemplate() : T() {}
    DanseurTemplate(int cin,  string nom, string prenom,
                    string nationalite,  string date_naissance,string style)
        : T(cin, nom, prenom, nationalite, date_naissance,style) {}

};

// Spécialisation pour les danseurs amateurs
class DanseurAmateurTemplate : public DanseurTemplate<danseur_amateur> {
public:
    DanseurAmateurTemplate() : DanseurTemplate<danseur_amateur>() {}
    DanseurAmateurTemplate(int cin, string nom,  string prenom,
                            string nationalite, string date_naissance,
                            string style, string niveau_entrenement="")
        : DanseurTemplate<danseur_amateur>(cin, nom, prenom, nationalite, date_naissance,style) {
            //this->niveau_entrenement = niveau_entrenement;
            
        }
};

// Spécialisation pour les danseurs professionnels
class DanseurProTemplate : public DanseurTemplate<danseur_pro> {
public:
    DanseurProTemplate() : DanseurTemplate<danseur_pro>() {}
    DanseurProTemplate(int cin, string nom,string prenom,
                       string nationalite, string date_naissance,string style,
                       int annee_experience=5, string palmares="")
        : DanseurTemplate<danseur_pro>(cin, nom, prenom, nationalite, date_naissance,style) {
            //this->annee_experience = annee_experience;
            //this->palmares = palmares;
        }
};

#endif // ARCHIVE_H
