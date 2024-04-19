/*#include "archive.h"

template<class T>
void Archive<T>::enregistrer_danseur(const T& danseur, const std::string& nomFichier) {
    std::ofstream fichier(nomFichier, std::ios::app);
    if (fichier) {
        fichier << danseur << std::endl;
        fichier.close();
        std::cout << "Danseur enregistré avec succès dans le fichier " << nomFichier << std::endl;
    } else {
        std::cerr << "Erreur : Impossible d'ouvrir le fichier " << nomFichier << std::endl;
    }
}

template<class T>
void Archive<T>::afficher_danseurs(const std::string& nomFichier) {
    std::ifstream fichier(nomFichier);
    if (fichier) {
        T danseur;
        while (fichier >> danseur) {
            danseur.afficher();
        }
        fichier.close();
    } else {
        std::cerr << "Erreur : Impossible d'ouvrir le fichier " << nomFichier << std::endl;
    }
}*/
