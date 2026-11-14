#include "TableHachage.hpp"
#include <iostream>

// Constructeur
TableHachage::TableHachage(int taille) {
    tailleTable = taille;
    table = new NoeudHachage*[tailleTable];
    
    // Initialisation 
    for (int i = 0; i < tailleTable; i++) {
        table[i] = nullptr;
    }
}

// Destructeur
TableHachage::~TableHachage() {
    for (int i = 0; i < tailleTable; i++) {
        NoeudHachage* actuel = table[i];
        while (actuel != nullptr) {
            NoeudHachage* suivant = actuel->suivant;
            delete actuel;
            actuel = suivant;
        }
    }
    delete[] table; 
}

// Hachage : le reste de la division par la taille
int TableHachage::hachage(int cle) const {
    // On utilise abs() pour eviter les index negatifs si la cle est negative
    int index = cle % tailleTable;
    if (index < 0) index += tailleTable;
    return index;
}

void TableHachage::inserer(int cle, const std::string& valeur) {
    int index = hachage(cle);
    NoeudHachage* actuel = table[index];

    // 1. On regarde si la cle existe deja pour mettre a jour
    while (actuel != nullptr) {
        if (actuel->cle == cle) {
            actuel->valeur = valeur;
            return;
        }
        actuel = actuel->suivant;
    }

    // 2. Si elle n'existe pas, on ajoute en tete de la liste
    NoeudHachage* nouveau = new NoeudHachage(cle, valeur);
    nouveau->suivant = table[index];
    table[index] = nouveau;
}

std::string TableHachage::rechercher(int cle) {
    int index = hachage(cle);
    NoeudHachage* actuel = table[index];

    while (actuel != nullptr) {
        if (actuel->cle == cle) {
            return actuel->valeur; 
        }
        actuel = actuel->suivant;
    }
    return ""; 
}

void TableHachage::supprimer(int cle) {
    int index = hachage(cle);
    NoeudHachage* actuel = table[index];
    NoeudHachage* precedent = nullptr;

    while (actuel != nullptr) {
        if (actuel->cle == cle) {
            // On a trouve le noeud a supprimer
            if (precedent == nullptr) {
                // C'est la tete de la liste
                table[index] = actuel->suivant;
            } else {
                // C'est au milieu
                precedent->suivant = actuel->suivant;
            }
            delete actuel;
            return;
        }
        precedent = actuel;
        actuel = actuel->suivant;
    }
    // Si on arrive ici, la cle n'etait pas dans la table
}

void TableHachage::afficher() const {
    std::cout << "Contenu de la table de hachage " << std::endl;
    for (int i = 0; i < tailleTable; i++) {
        std::cout << "Case [" << i << "] : ";
        
        if (table[i] == nullptr) {
            std::cout << "(vide)" << std::endl;
        } else {
            NoeudHachage* actuel = table[i];
            while (actuel != nullptr) {
                std::cout << "(" << actuel->cle << " -> " << actuel->valeur << ") ";
                actuel = actuel->suivant;
            }
            std::cout << std::endl;
        }
    }
}