#ifndef NOEUD_HPP
#define NOEUD_HPP

class Noeud {
public:
    int valeur;
    Noeud* suivant;

    // Constructeur
    Noeud(int v) : valeur(v), suivant(nullptr) {}
};

#endif