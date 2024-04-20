
#include <iostream>
#include <algorithm> // Pour la fonction sort()
#include <vector>
#include <string>
#include "personnes.cpp"
#include "danseur_amateur.cpp"
#include "danseur_pro.cpp" 
#include "Resultat.cpp"
#include "danseur.cpp"
#include "epreuve.cpp"
#include "spectateur.cpp"
#include "Recompenses.cpp" //  le fichier d'en-tête des récompenses


using namespace std;

vector<danseur*> listDanseur;
vector<spectateur*> listSpectateur;
vector<Epreuves*> listEpreuves;
vector<Recompenses*> listRecompenses;


void gestionRecompense(vector<Recompenses*>& listeRecompenses, const vector<Epreuves*>& listeEpreuves,  const vector<danseur*>& listeDanseurs) {
    int choix;
    do {
        // Afficher le sous-menu de gestion des récompenses
        std::cout << "\n===== GESTION DES RECOMPENSES =====" << std::endl;
        std::cout << "1. Ajouter une recompense" << std::endl;
        std::cout << "2. Afficher les recompenses" << std::endl;
        std::cout << "3. Attribuer une recompense au meilleur danseur" << std::endl;
        std::cout << "0. Retour au menu principal" << std::endl;
        std::cout << "Choix : ";
        std::cin >> choix;

        // Effectuer une action en fonction du choix de l'utilisateur
        switch (choix) {
            case 1: {
                // Ajouter une récompense
                
                Recompenses r;
                cin>>r;
                Recompenses* nouvelleRecompense = new Recompenses(r);
                listeRecompenses.push_back(nouvelleRecompense);

                std::cout << "Recompense ajoutee avec succes." << std::endl;
                break;
            }
            case 2: {
                // Afficher les récompenses
                std::cout << "Liste des récompenses :" << std::endl;
                for (size_t i = 0; i < listeRecompenses.size(); ++i) {
                    std::cout << "Recompense " << i+1 << ": " << *listeRecompenses[i] << std::endl;
                }
                break;
            }
            case 3: {
                // Attribuer une récompense au meilleur danseur
                /*
                if (listeDanseurs.empty()) {
                    std::cout << "Aucun danseur enregistre." << std::endl;
                } else {
                    danseur* meilleurDanseur = nullptr;
                    float meilleurScore = -1.0;

                    // Trouver le danseur avec le meilleur score
                    for (const auto& entry : resultat.getMyMap()) {
                        //float scores = entry.second.calculScore();
                        float scores;
                        cin>>scores;
                        if (scores > meilleurScore) {
                            meilleurScore = scores;
                            meilleurDanseur = const_cast<danseur*>(&entry.first);
                        }
                    }

                    // Attribuer une récompense au meilleur danseur
                    if (meilleurDanseur != nullptr) {
                        if (!listeRecompenses.empty()) {
                            std::cout << "Attribution d'une récompense au meilleur danseur : " << meilleurDanseur->getNom() << std::endl;
                            // Supposons que la première récompense de la liste est attribuée au meilleur danseur
                            std::cout << "Récompense attribuée : " << *listeRecompenses[0] << std::endl;
                        } else {
                            std::cout << "Aucune récompense disponible. Veuillez d'abord ajouter des récompenses." << std::endl;
                        }
                    } else {
                        std::cout << "Aucun danseur trouvé." << std::endl;
                    }
                }*/

                 if (listeEpreuves.empty()) {
                    std::cout << "Aucune epreuve enregistree. Veuillez enregistrer une epreuve avant d'ajouter un resultat." << std::endl;
                } else {
                    unsigned int  index;
                    std::cout << "Choisissez l epreuve auquel afficher le classement : " << std::endl;
                    for (size_t i = 0; i < listeEpreuves.size(); ++i) {
                        std::cout << i+1 << ". " << listeEpreuves[i]->getNom() << std::endl;
                    }
                     cout << "Indice de l epreuve : ";
                     cin >> index;
                    if (index >= 1 && index <= listeEpreuves.size()) {
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
                        Resultat resultat;
                        cin>>resultat;
                        score s;
                        cin>>s;
                        score *nouveauScore = new score(s);
                        resultat.ajout_score(*listeDanseurs[indexDanseur - 1], nouveauScore);
                        delete nouveauScore;
                         listeEpreuves[index-1]->ajouter_resultat(resultat);
                        
                        
                        std::cout << "Score attribue avec succes au danseur : " << listeDanseurs[indexDanseur - 1]->getNom() << std::endl;
                        std::cout << "Resultat ajouter avec succes a l epreuve : " << listeEpreuves[index - 1]->getNom() << std::endl;
                    } else {
                        std::cout << "Indice danseur invalide." << std::endl;
                    }
                }
                          
                    } else {
                        std::cout << "Indice resultat invalide." << std::endl;
                    }
                }

                
                break;
            }
            case 0:
                std::cout << "Retour au menu principal." << std::endl;
                break;
            default:
                std::cout << "Choix invalide. Veuillez réessayer." << std::endl;
                break;
        }
    } while (choix != 0);
}




void organiserEpreuves() {
    // Création d'un objet pour gérer les épreuves
    Epreuves epreuves;

    int choix;
    do {
        cout << "\nOrganisation des epreuves :" << endl;
        cout << "1. Creer une nouvelle epreuve" << endl;
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
                    //Trier la liste des epreuves pour afficher en ordre alphabetique
                    sort(listEpreuves.begin(), listEpreuves.end(), Epreuves::compareNomsEpreuves);
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
                        //Trier la liste des danseurs 
                    sort(listDanseur.begin(),listDanseur.end());
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
    cout << "0. Retour au menu principal" << endl;
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
            break;
        case 0:
                cout << "Retour au menu principal." << endl;
                break;
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
void gestionScores(const std::vector<Epreuves*>& listeEpreuves, const std::vector<danseur*>& listeDanseurs) {
    int choix;
    do {
        // Afficher le sous-menu de gestion des scores
        std::cout << "\n===== GESTION DES SCORES =====" << std::endl;
        std::cout << "1. Attribuer un score à un danseur" << std::endl;
        std::cout << "2. Afficher les résultats des danseurs d'une epreuve" << std::endl;
        std::cout << "0. Retour au menu principal" << std::endl;
        std::cout << "Choix : ";
        std::cin >> choix;

        // Effectuer une action en fonction du choix de l'utilisateur
        switch (choix) {
            case 1: {
                // Attribuer un score à un danseur
                if (listeEpreuves.empty()) {
                    std::cout << "Aucune epreuve enregistree. Veuillez enregistrer une epreuve avant d'ajouter un resultat." << std::endl;
                } else {
                    unsigned int  index;
                    std::cout << "Choisissez l epreuve auquel attribuer un resultat : " << std::endl;
                    for (size_t i = 0; i < listeEpreuves.size(); ++i) {
                        std::cout << i+1 << ". " << listeEpreuves[i]->getNom() << std::endl;
                    }
                     cout << "Indice de l epreuve : ";
                     cin >> index;
                    if (index >= 1 && index <= listeEpreuves.size()) {
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
                        Resultat resultat;
                        cin>>resultat;
                        score s;
                        cin>>s;
                        score *nouveauScore = new score(s);
                        resultat.ajout_score(*listeDanseurs[indexDanseur - 1], nouveauScore);
                        delete nouveauScore;
                         listeEpreuves[index-1]->ajouter_resultat(resultat);
                        
                        std::cout << "Score attribue avec succes au danseur : " << listeDanseurs[indexDanseur - 1]->getNom() << std::endl;
                        std::cout << "Resultat ajouter avec succes a l epreuve : " << listeEpreuves[index - 1]->getNom() << std::endl;
                    } else {
                        std::cout << "Indice danseur invalide." << std::endl;
                    }
                }
                          
                    } else {
                        std::cout << "Indice resultat invalide." << std::endl;
                    }
                }

                break;
            }
            case 2: {
                // Afficher les résultats de chaque danseureur
                unsigned int  index;
                    std::cout << "Choisissez l epreuve auquel vous voulez afficher ces resultats : " << std::endl;
                    for (size_t i = 0; i < listeEpreuves.size(); ++i) {
                        std::cout << i+1 << ". " << listeEpreuves[i]->getNom() << std::endl;
                    }
                     cout << "Indice de l epreuve : ";
                     cin >> index;
                     if (index >= 1 && index <= listeEpreuves.size()) {
    
                        listeEpreuves[index-1]->afficher_Liste_Resultat();
                           
                    } else {
                        std::cout << "Indice invalide." << std::endl;
                    }
                 
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
        cout << "4. Attribution des resultats" << endl;
        cout<<  "5. Gestion des  spectateur"<<endl;
       
        cout << "6. Gestion des recompenses" << endl;
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
                    gestionScores(listEpreuves, listDanseur);
               
                break;
            case 5:
                    enregistrerSpectateur();
                
                break;
            case 6:
                // Gestion des récompenses
                gestionRecompense( listRecompenses,listEpreuves,  listDanseur);
                break;
            case 0:
                cout << "Merci d'avoir utilise l'application. Au revoir !" << endl;
                break;
            default:
                cout << "Choix invalide. Veuillez entrer un nombre entre 0 et 6." << endl;
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


void afficherClassementDanseur(Epreuves& e,int index) {
    // Créer une copie de la multimap pour pouvoir la trier
    multimap<int, danseur> classement;
     multimap<danseur,score>::iterator it;
    // Remplir la copie avec les scores totaux et les danseurs
    
    list<Resultat *> lr=e.getListResultat();
    //Resultat r=lr[index];
   
    //for (auto it = this->myMap.begin(); it != myMap.end(); ++it) {
        int totalScore = it->second.calculScore();
         
        classement.insert({ totalScore, it->first });
    //} 

    // Afficher le classement des danseurs
    int rank = 1;
    cout << "Classement des danseurs :" << endl;
    for (auto it = classement.rbegin(); it != classement.rend(); ++it) {
        cout << "Position " << rank++ << " : " << it->second << " - Score total : " << it->first << endl;
    }
}   
/*
void gestionResultat(  const std::vector<Epreuves*>& listeEpreuves)
{
        int choix;
    do {
        // Afficher le sous-menu de gestion des scores
        std::cout << "\n===== GESTION DES RESULTATS =====" << std::endl;
        std::cout << "1. AJOUTER UN RESULTAT " << std::endl;
        std::cout << "2. Afficher la liste des resultats d une epreuve" << std::endl;
        std::cout << "0. Retour au menu principal" << std::endl;
        std::cout << "Choix : ";
        std::cin >> choix;

        // Effectuer une action en fonction du choix de l'utilisateur
        switch (choix) {
            case 1: {
                // Attribuer un score à un danseur
                if (listeEpreuves.empty()) {
                    std::cout << "Aucune epreuve enregistree. Veuillez enregistrer une epreuve avant d'ajouter un resultat." << std::endl;
                } else {
                    unsigned int  index;
                    std::cout << "Choisissez l epreuve auquel attribuer un resultat : " << std::endl;
                    for (size_t i = 0; i < listeEpreuves.size(); ++i) {
                        std::cout << i+1 << ". " << listeEpreuves[i]->getNom() << std::endl;
                    }
                     cout << "Indice de l epreuve : ";
                     cin >> index;
                    if (index >= 1 && index <= listeEpreuves.size()) {
                         
                        Resultat r;
                        cin>>r;
                        listeEpreuves[index-1]->ajouter_resultat(r);
                        std::cout << "Resultat ajouter avec succes a l epreuve : " << listeEpreuves[index - 1]->getNom() << std::endl;
                    } else {
                        std::cout << "Indice invalide." << std::endl;
                    }
                }
                break;
            }
            case 2: {
                // Afficher les résultats
                 unsigned int  index;
                    std::cout << "Choisissez l epreuve auquel vous voulez afficher ces resultats : " << std::endl;
                    for (size_t i = 0; i < listeEpreuves.size(); ++i) {
                        std::cout << i+1 << ". " << listeEpreuves[i]->getNom() << std::endl;
                    }
                     cout << "Indice de l epreuve : ";
                     cin >> index;
                     if (index >= 1 && index <= listeEpreuves.size()) {
                        
                        listeEpreuves[index-1]->afficher_Liste_Resultat();
                       
                    } else {
                        std::cout << "Indice invalide." << std::endl;
                    }
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
*/


