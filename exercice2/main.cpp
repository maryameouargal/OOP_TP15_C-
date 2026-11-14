#include <iostream>
#include "File.hpp"

using namespace std;

int main() {
    cout << " Gestion d'une file d'attente (FIFO first in, first out) " << endl;

    // On cree une file avec une capacite maximale de 5
    File maFile(5);
    int choix, valeur;

    do {
        cout << "\n MENU" << endl;
        cout << "1. Enfiler (ajouter) un element" << endl;
        cout << "2. Defiler (retirer) le premier element" << endl;
        cout << "3. Afficher la file" << endl;
        cout << "0. Quitter" << endl;
        cout << "Votre choix : ";
        cin >> choix;

        switch (choix) {
            case 1:
                cout << "Valeur a enfiler : ";
                cin >> valeur;
                maFile.enfiler(valeur);
                break;
            case 2:
                try {
                    maFile.defiler();
                    cout << "Element est retire avec succes." << endl;
                } 
                catch (const FileVideException& e) {
                    cout << "ERREUR !!! " << e.what() << endl;
                }
                break;
            case 3:
                cout << "Etat de la file : ";
                maFile.afficher();
                cout << "Taille : " << maFile.taille() << " / Capacite max" << endl;
                break;
            case 0:
                cout << "Au revoir !" << endl;
                break;
            default:
                cout << "Choix invalide." << endl;
        }
    } while (choix != 0);

    return 0;
}