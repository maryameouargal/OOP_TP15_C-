#ifndef LISTECHAINEE_HPP
#define LISTECHAINEE_HPP

#include "Noeud.hpp"

class ListeChainee {
private:
    Noeud* tete; // Pointeur vers le premier element
    int nbElements;

public:
    // Constructeur / Destructeur
    ListeChainee();
    ~ListeChainee();

    // Methodes demandees
    void ajouterDebut(int valeur);
    void ajouterFin(int valeur);
    void supprimer(int valeur);
    void afficher() const;
    int taille() const;
};

#endif