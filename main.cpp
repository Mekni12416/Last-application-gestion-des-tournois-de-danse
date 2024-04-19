
#include <iostream>
#include "personnes.cpp"
#include "danseur_amateur.cpp"
#include "danseur_pro.cpp" 
#include "Resultat.cpp"
#include "danseur.cpp"

//#include "score.cpp"
//#include "critere.cpp"
#include <iostream>
#include <vector>
#include <string>
#include "epreuve.cpp"
#include "spectateur.cpp"

using namespace std;

vector<danseur*> listDanseur;
vector<spectateur*> listSpectateur;
vector<Epreuves*> listEpreuves;
Resultat r;

void organiserEpreuves() {
    // Création d'un objet pour gérer les épreuves
    Epreuves epreuves;

    int choix;
    do {
        cout << "\nOrganisation des épreuves :" << endl;
        cout << "1. Créer une nouvelle épreuve" << endl;
        cout << "2. Afficher les épreuves existantes" << endl;
        cout << "0. Retour au menu principal" << endl;
        cout << "Votre choix : ";
        cin >> choix;

        switch (choix) {
            case 1:
                {
                    cin.ignore(); // Pour éviter les problèmes avec getline()
                    cout << "Entrez les détails de la nouvelle épreuve :" << endl;
                    cin >> epreuves; // Utilisation de l'opérateur de saisie surchargé
                    
                    Epreuves *e=new Epreuves(epreuves);
                    listEpreuves.push_back(e);
                    cout << "Épreuve créée avec succès !" << endl;
                }
                break;
            case 2:
                {
                    cout << "Épreuves existantes :" << endl;
                    for(unsigned int i=0;i<listEpreuves.size();i++)
                    {
                        cout<<*listEpreuves[i];
                        cout<<"------------------------------\n";
                    }
                }
                break;
            case 0:
                cout << "Retour au menu principal." << endl;
                break;
            default:
                cout << "Choix invalide. Veuillez entrer un nombre entre 0 et 2." << endl;
                break;
        }
    } while (choix != 0);
}


void enregistrerDanseur() {
    int choixType;
    cout << "Choisissez le type de danseur à enregistrer : " << endl;
    cout << "1. Danseur " << endl;
     cout << "2. Danseur Amateur" << endl;
    cout << "3. Danseur Professionnel" << endl;
    cout<< " 4:Afficher la liste de tous les danseurs"<<endl;
    cout << "Votre choix : ";
    cin >> choixType;

    switch (choixType) {
        case 1:
           {
                danseur d1;
                d1.enregistrer_danseur();
                danseur *d=new danseur(d1);
                listDanseur.push_back(d);
                cout << "Danseur amateur enregistre avec succes !" << endl;
            }
            break;
        case 2:
            {
                danseur_amateur nouveauDanseurAmateur;
                nouveauDanseurAmateur.enregistrer_danseur_amateur();
                danseur_amateur *da=new danseur_amateur(nouveauDanseurAmateur);
                listDanseur.push_back(da);

                cout << "Danseur amateur enregistre avec succes !" << endl;
            }
            break;
        case 3:
                {
                danseur_pro nouveauDanseurPro;
                nouveauDanseurPro.enregistrer_danseur_pro();
                danseur_pro *dp=new danseur_pro(nouveauDanseurPro);
                listDanseur.push_back(dp);
                cout << "Danseur professionnel enregistré avec succès !" << endl;
            } 
            break;
        case 4:
                    for(unsigned int i=0;i<listDanseur.size();i++)
                    {
                        cout<<*listDanseur[i];
                        cout<<"-----------------\n";
                    }
        default:
            cout << "Choix invalide. Veuillez entrer 1 ou 2." << endl;
            break;
    }
}


void enregistrerSpectateur() {
    int choixType;
    spectateur s;
    cout << "1. enregistrer spectateur " << endl;
     cout << "2. Acheter ticket" << endl;
    cout<< "3. Affichage de tous les spectateurs"<<endl;
    cout << "Votre choix : ";
    cin >> choixType;

    switch (choixType) {
        case 1:
           {

                
                cin>>s;
                spectateur *s1=new spectateur(s);
                listSpectateur.push_back(s1);
                cout << "Spectateur enregistre avec succes !" << endl;
            }
            break;
        case 2:
            {
                 Ticket t;
                 cin>>t;
                 s.ajouter_ticket(s,&t);
            }
            break;
        case 3:
            for(unsigned int i=0;i<listSpectateur.size();i++)
            {
                cout<<*listSpectateur[i];
                cout<<"-----------------\n";
            }
        default:
            cout << "Choix invalide. Veuillez entrer 1 ou 2." << endl;
            break;
    }
}

using namespace std;

void gestionCategories() {
    vector<string> categories;

    int choix;
    do {
        cout << "\nGestion des catégories de danse :" << endl;
        cout << "1. Ajouter une categorie" << endl;
        cout << "2. Afficher les categories existantes" << endl;
        cout << "0. Retour au menu principal" << endl;
        cout << "Votre choix : ";
        cin >> choix;

        switch (choix) {
            case 1:
                {
                    string nouvelleCategorie;
                    cout << "Entrez le nom de la nouvelle categorie : ";
                    cin >> nouvelleCategorie;
                    categories.push_back(nouvelleCategorie);
                    cout << "Catégorie ajoutee avec succes !" << endl;
                }
                break;
            case 2:
                {
                    if (categories.empty()) {
                        cout << "Aucune catégorie n'a été ajoutée pour le moment." << endl;
                    } else {
                        cout << "Catégories existantes :" << endl;
                        for (const auto& categorie : categories) {
                            cout << "- " << categorie << endl;
                        }
                    }
                }
                break;
            case 0:
                cout << "Retour au menu principal." << endl;
                break;
            default:
                cout << "Choix invalide. Veuillez entrer un nombre entre 0 et 2." << endl;
                break;
        }
    } while (choix != 0);
}



// Définition de la fonction gestionScores
void gestionScores(Resultat& resultat, const std::vector<danseur*>& listeDanseurs) {
    int choix;
    do {
        // Afficher le sous-menu de gestion des scores
        std::cout << "\n===== GESTION DES SCORES =====" << std::endl;
        std::cout << "1. Attribuer un score à un danseur" << std::endl;
        std::cout << "2. Afficher les résultats" << std::endl;
        std::cout << "0. Retour au menu principal" << std::endl;
        std::cout << "Choix : ";
        std::cin >> choix;

        // Effectuer une action en fonction du choix de l'utilisateur
        switch (choix) {
            case 1: {
                // Attribuer un score à un danseur
                if (listeDanseurs.empty()) {
                    std::cout << "Aucun danseur enregistré. Veuillez enregistrer un danseur avant d'attribuer un score." << std::endl;
                } else {
                    unsigned int  indexDanseur;
                    std::cout << "Choisissez le danseur auquel attribuer un score : " << std::endl;
                    for (size_t i = 0; i < listeDanseurs.size(); ++i) {
                        std::cout << i+1 << ". " << listeDanseurs[i]->getNom() << std::endl;
                    }
                     cout << "Indice du danseur : ";
                     cin >> indexDanseur;
                    if (indexDanseur >= 1 && indexDanseur <= listeDanseurs.size()) {
                        score s;
                        cin>>s;
                        
                        /*int valeurScore;
                        std::cout << "Entrez la valeur du score : ";
                        std::cin >> valeurScore;*/
                        score *nouveauScore = new score(s);
                        resultat.ajout_score(*listeDanseurs[indexDanseur - 1], nouveauScore);
                        delete nouveauScore;
                        std::cout << "Score attribue avec succes au danseur : " << listeDanseurs[indexDanseur - 1]->getNom() << std::endl;
                    } else {
                        std::cout << "Indice invalide." << std::endl;
                    }
                }
                break;
            }
            case 2: {
                // Afficher les résultats
                resultat.affichResulat();
                break;
            }
            case 0:
                std::cout << "Retour au menu principal." << std::endl;
                break;
            default:
                std::cout << "Choix invalide. Veuillez reessayer." << std::endl;
                break;
        }
    } while (choix != 0);
}



int main()
{

  
     int choix;
    do {
        // Affichage du menu
        cout << "Menu de l application de gestion de tournoi de danse" << endl;
        cout << "1. Gestion des danseurs " << endl;
        cout << "2. Gestion des categories" << endl;
        cout << "3. Gestion des epreuves" << endl;
        cout << "4. Attribution des scores" << endl;
        cout<<  "5. Gestion des  spectateur"<<endl;
        cout << "7. Gestion des recompenses" << endl;
        cout << "0. Quitter l application" << endl;
        cout << "Votre choix : ";
        cin >> choix;

        
        switch (choix) {
            case 1:
                enregistrerDanseur();
                break;
            case 2:
                gestionCategories();
                break;
            case 3:
                // Organisation des épreuves
                organiserEpreuves() ;
                
                break;
            case 4:
                // Attribution des scores
                    gestionScores(r, listDanseur);
                // Vous pouvez appeler la fonction correspondante ici
                break;
            case 5:
                    enregistrerSpectateur();
                // Calcul des résultats
                // Vous pouvez appeler la fonction correspondante ici
                break;
            case 6:
                // Affichage des résultats
                // Vous pouvez appeler la fonction correspondante ici
                for(unsigned int i=0;i<listDanseur.size();i++)
                {
                    //cout<<*listDanseur[i];
                    listDanseur[i]->get_danseur();
                    cout<<"\n---------------------\n";
                }
                break;
            case 7:
                // Gestion des récompenses
                // Vous pouvez appeler la fonction correspondante ici
                break;
            case 0:
                cout << "Merci d'avoir utilisé l'application. Au revoir !" << endl;
                break;
            default:
                cout << "Choix invalide. Veuillez entrer un nombre entre 0 et 7." << endl;
                break;
        }
    } while (choix != 0);

    for(unsigned int i=0;i<listDanseur.size();i++)
    {
        delete listDanseur[i];
    }
    listDanseur.clear();

    for(unsigned int i=0;i<listSpectateur.size();i++)
    {
        delete listSpectateur[i];
    }
    listSpectateur.clear();

    for(unsigned int i=0;i<listEpreuves.size();i++)
    {
        delete listEpreuves[i];
    }
    listEpreuves.clear();
    return 0;
}




