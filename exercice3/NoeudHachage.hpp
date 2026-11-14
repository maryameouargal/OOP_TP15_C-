#ifndef NOEUDHACHAGE_HPP
#define NOEUDHACHAGE_HPP

#include <string>

class NoeudHachage {
public:
    int cle;
    std::string valeur;
    NoeudHachage* suivant;

    // Constructeur
    NoeudHachage(int k, const std::string& v) 
        : cle(k), valeur(v), suivant(nullptr) {}
};

#endif