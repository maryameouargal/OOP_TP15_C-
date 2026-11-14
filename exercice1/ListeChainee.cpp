#include "ListeChainee.hpp"
#include <iostream>

// Constructeur : liste vide
ListeChainee::ListeChainee() : tete(nullptr), nbElements(0) {}

// Destructeur : libere toute la memoire
ListeChainee::~ListeChainee() {
    Noeud* actuel = tete;
    while (actuel != nullptr) {
        // Sauvegarder le suivant
        Noeud* suivant = actuel->suivant; 
         // Liberer le noeud actuel
        delete actuel;    
         // Passer au suivant               
        actuel = suivant;                
    }
}

void ListeChainee::ajouterDebut(int valeur) {
    Noeud* nouveau = new Noeud(valeur);
    // Le nouveau pointe vers l'ancienne tete
    nouveau->suivant = tete; 
     // La tete devient le nouveau noeud
    tete = nouveau;         
    nbElements++;
}

void ListeChainee::ajouterFin(int valeur) {
    Noeud* nouveau = new Noeud(valeur);
    
    if (tete == nullptr) {
        // Si la liste est vide, le nouveau est la tete
        tete = nouveau;
    } else {
        // Sinon, on parcourt jusqu'au dernier
        Noeud* actuel = tete;
        while (actuel->suivant != nullptr) {
            actuel = actuel->suivant;
        }
        // On attache a la fin
        actuel->suivant = nouveau; 
    }
    nbElements++;
}

void ListeChainee::supprimer(int valeur) {
    if (tete == nullptr) return; 

    // Cas 1 : supprimer la tete
    if (tete->valeur == valeur) {
        Noeud* aSupprimer = tete;
        tete = tete->suivant;
        delete aSupprimer;
        nbElements--;
        return;
    }

    // Cas 2 : chercher au milieu / fin
    Noeud* actuel = tete;
    while (actuel->suivant != nullptr && actuel->suivant->valeur != valeur) {
        actuel = actuel->suivant;
    }

    // Si on a trouve l'element
    if (actuel->suivant != nullptr) {
        Noeud* aSupprimer = actuel->suivant;
        actuel->suivant = aSupprimer->suivant; 
        delete aSupprimer;
        nbElements--;
    }
}

void ListeChainee::afficher() const {
    std::cout << "[ ";
    Noeud* actuel = tete;
    while (actuel != nullptr) {
        std::cout << actuel->valeur << " ";
        actuel = actuel->suivant;
    }
    std::cout << "]" << std::endl;
}

int ListeChainee::taille() const {
    return nbElements;
}