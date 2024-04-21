/*#include <iostream>
#include "personnes.cpp"
#include "danseur.cpp"
#include "danseur_amateur.h"
#include "danseur_pro.h"
#include "template_danseur.h"
#include "Resultat.h"
#include "ResultTotal.h"
#include "ResultatPartiel.h"
#include "template_resultat.h"
  
using namespace std;

int main() {
    // Instanciation d'un danseur amateur avec la classe template
    cout<<"-------TESTER CLASSE TEMPLATE---------\n";
    
    cout<<"Saisir danseur amateur\n";
    DanseurAmateurTemplate amateur;
    cin>>amateur;
     // Affichage des informations du danseur amateur
    cout<<amateur;
    // Instanciation d'un danseur professionnel avec la classe template
    DanseurProTemplate pro;
    cout<<"Saisir danseur amateur\n";
    cin>>pro;
    // Affichage des informations du danseur professionnel
    cout<<pro;

   
    // Création d'un résultat partiel
    ResultatPartielTemplate<Resultat> resultatPartiel(1, "Commentaire sur le resultat partiel");
    // Ajout d'un score au résultat partiel
    danseur d1;
    score s1;
    resultatPartiel.ajout_score(d1, &s1);
    // Affichage du numéro de résultat et du commentaire du résultat partiel
    cout << "Commentaire du resultat partiel : " << resultatPartiel.getCommentairePartiel() << endl;
    // Création d'un résultat total
    ResultatTotalTemplate<Resultat> resultatTotal(2);
    // Ajout d'un score au résultat total
    danseur d2 ;
    score s2 ;
    resultatTotal.ajout_score(d2, &s2);
    // Affichage du numéro de résultat total
    cout << "Numéro de resultat total : " << resultatTotal.getNum_res() << endl;


 

   

    return 0;
}

*/

#include <iostream>
#include <algorithm> // Pour la fonction sort()
#include<typeinfo> //pour le casting 
#include <vector>
#include <string>
#include "personnes.cpp"
#include "danseur_amateur.cpp"
#include "danseur_pro.cpp" 
#include "Resultat.h"
#include "danseur.cpp"
#include "epreuve.cpp"
#include "spectateur.cpp"
#include "Recompenses.cpp" //  le fichier d'en-tête des récompenses


using namespace std;

vector<danseur*> listDanseur;
vector<spectateur*> listSpectateur;
vector<Epreuves*> listEpreuves;
vector<Recompenses*> listRecompenses;

void organiserEpreuves() {
    // Création d'un objet pour gérer les épreuves
    Epreuves epreuves;

    int choix;
    do {
        cout << "\nOrganisation des epreuves :" << endl;
        cout << "1. Creer une nouvelle epreuve" << endl;
        cout << "2. Afficher les epreuves existantes" << endl;
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
    do{
    cout << "Choisissez le type de danseur à enregistrer : " << endl;
    cout << "1. Danseur " << endl;
     cout << "2.Danseur Amateur" << endl;
    cout << "3. Danseur Professionnel" << endl;
    cout<< "4: Afficher la liste de tous les danseurs"<<endl;
    cout<< "0: Retour au menu principal"<<endl;
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
                        danseur *d;
                    sort(listDanseur.begin(),listDanseur.end());
                    for(unsigned int i=0;i<listDanseur.size();i++)
                    {
                        if(typeid(*listDanseur[i])==typeid(danseur))
                            cout<<*listDanseur[i];
                        else
                        if(typeid(*listDanseur[i])==typeid(danseur_amateur))
                        {
                                d=new danseur_amateur(static_cast<const danseur_amateur&>(*listDanseur[i]));
                                cout<<d;
                                
                        }
                        else
                        {
                            d=new danseur_pro(static_cast<const danseur_pro&>(*listDanseur[i]));
                            cout<<d;
                        }
                        cout<<"-----------------\n";
                    }
        default:
            cout << "Choix invalide. Veuillez entrer un chiffre de 1 a 4." << endl;
            break;
    }
    }while (choixType!=0);
   
    
}


void enregistrerSpectateur() {
    int choixType;
    spectateur s;
     do{
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
    }while(choixType!=0);
}

void gestionCategories() {
    vector<string> categories;

    int choix;
    do {
        cout << "\nGestion des categories de danse :" << endl;
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

//Fonction pour afficher le classe des danseurs dans une epreuve
void afficherClassementDanseur( Epreuves e,int indiceResultat) {
    // Créer une copie de la multimap pour pouvoir la trier
    multimap<int, danseur> classement;
     multimap<danseur,score>::iterator it;
     multimap<danseur,score> mp;
     list<Resultat *>::iterator it1;
    // Remplir la copie avec les scores totaux et les danseurs
    
        list<Resultat *> lr=e.getListResultat();
    
        int arret=0;
        for(it1=lr.begin();it1!=lr.end();++it1)
        {
            if(indiceResultat==arret) break;
            arret++;
        }
        Resultat *r=new Resultat(**it1);
       mp=r->getMyMap();
    for (auto it = mp.begin(); it !=mp.end(); ++it) {
        int totalScore = it->second.calculScore();
        classement.insert({ totalScore, it->first });
    } 

    // Afficher le classement des danseurs
    int rank = 1;
    cout << "Classement des danseurs :" << endl;
    for (auto it = classement.rbegin(); it != classement.rend(); ++it) {
        cout << "Position " << rank++ << " : " << it->second << " - Score total : " << it->first << endl;
    }
}   

void gestionRecompense(vector<Recompenses*>& listeRecompenses, const vector<Epreuves*>& listeEpreuves,  const vector<danseur*>& listeDanseurs) {
    int choix;
    do {
        // Afficher le sous-menu de gestion des récompenses
        std::cout << "\n===== GESTION DES RECOMPENSES =====" << std::endl;
        std::cout << "1. Ajouter une recompense" << std::endl;
        std::cout << "2. Afficher les recompenses" << std::endl;
        std::cout << "3. Afficher le classement des danseur d une epreuve" << std::endl;
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
            case 3:{
                //AFFICHAGE DU CLASSEMENT DES DANSEURS 
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
                    unsigned int  indexresultat;
                    std::cout << "Choisissez lequel des resultats voulez vous afficher son classement: " << std::endl;
                     cout << "Indice du resultat : ";
                     cin >> indexresultat;
                    if (indexresultat >= 1 ) {
                        afficherClassementDanseur(*listeEpreuves[index],indexresultat);
                    } else {
                        std::cout << "Indice resultats invalide." << std::endl;
                    }
                }
                          
                    } else {
                        std::cout << "Indice resultat invalide." << std::endl;
                    }
                }
                
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




int main()
{

  
     int choix;
    do {
        // Affichage du menu principal 
        cout << "\nMenu de l application de gestion de tournoi de danse" << endl;
        cout << "1. Gestion des epreuves" << endl;
        cout << "2. Gestion des categories" << endl;
        cout << "3. Gestion des danseurs " << endl;
        cout<<  "4. Gestion des  spectateur"<<endl;
        cout << "5. Attribution des resultats" << endl;
        cout << "6. Gestion des recompenses" << endl;
        cout << "0. Quitter l application" << endl;
        cout << "Votre choix : ";
        cin >> choix;

        
        switch (choix) {
            case 1:
                // Organisation des épreuves
                organiserEpreuves() ;
                
                break;
            case 2:
                gestionCategories();
                break;
            case 3:
                //Gestion des danseurs 
                enregistrerDanseur();
                
                break;
            case 4:
                     //Gestion des spectateurs
                    enregistrerSpectateur();
                break;
            case 5:
                    // Attribution des scores
                    gestionScores(listEpreuves, listDanseur);

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
