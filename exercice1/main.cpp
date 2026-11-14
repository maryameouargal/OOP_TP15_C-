#include <iostream>
#include "ListeChainee.hpp"

using namespace std;

int main() {
    cout << "Test de la Liste Chainee" << endl;

    ListeChainee liste;

    // 1. Ajouts
    cout << "\nAjouts" << endl;
    liste.ajouterFin(10);
    liste.ajouterFin(18);
    liste.ajouterFin(30);
    cout << "Apres ajouts en fin (10, 18, 30) : ";
    liste.afficher();

    liste.ajouterDebut(5);
    liste.ajouterDebut(1);
    cout << "Apres ajouts en debut (5, 1) :     ";
    liste.afficher();

    cout << "Taille actuelle : " << liste.taille() << endl;

    // 2. Suppressions
    cout << "\n Suppressions " << endl;
    
    cout << "Supprimer 18 (milieu)" << endl;
    liste.supprimer(18);
    liste.afficher();

    cout << "Supprimer 1 (tete)" << endl;
    liste.supprimer(1);
    liste.afficher();

    cout << "Supprimer 30 (fin)" << endl;
    liste.supprimer(30);
    liste.afficher();

    cout << "Supprimer 999 (inexistant)" << endl;
    liste.supprimer(999);
    liste.afficher();

    cout << "Taille finale : " << liste.taille() << endl;

    // Le destructeur libere automatiquement a la fin du main
    cout << "\n[Fin du programme, et appel du destructeur]" << endl;
    return 0;
}