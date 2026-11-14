#include <iostream>
#include "TableHachage.hpp"

using namespace std;

int main() {
    cout << " Test de la Table de Hachage" << endl;

    // On cree une table de taille 5 pour provoquer des collisions
    TableHachage table(5);

    // 1. Insertion
    cout << "\n Insertion " << endl;
    table.inserer(1, "Rina");
    table.inserer(2, "Preston");
    table.inserer(6, "Marcus"); 
    table.inserer(11, "Brandon");  
    table.inserer(3, "Nikolai");
    table.inserer(12, "Landon");  

    // 2. Affichage
    table.afficher();

    // 3. Recherche
    cout << "\nRecherche" << endl;
    cout << "Recherche cle 6 : " << table.rechercher(6) << endl;
    cout << "Recherche cle 12: " << table.rechercher(12) << endl;
    cout << "Recherche cle 99: " << (table.rechercher(99) == "" ? "(non trouve)" : table.rechercher(99)) << endl;

    // 4. Suppression
    cout << "\n Suppression " << endl;
    cout << "Suppression de la cle 6 (Marcus )" << endl;
    table.supprimer(6);
    
    cout << "Suppression de la cle 2 (Preston)" << endl;
    table.supprimer(2);

    cout << "\n Etat final de la table " << endl;
    table.afficher();

    return 0;
}