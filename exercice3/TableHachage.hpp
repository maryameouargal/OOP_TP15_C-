#ifndef TABLEHACHAGE_HPP
#define TABLEHACHAGE_HPP

#include "NoeudHachage.hpp"
#include <string>

class TableHachage {
private:
// Tableau de pointeurs vers les tetes de listes
    NoeudHachage** table; 
    int tailleTable;

    // Fonction de hachage simple
    int hachage(int cle) const;

public:
    // Constructeur / Destructeur
    TableHachage(int taille = 10);
    ~TableHachage();

    // Methodes demandees
    void inserer(int cle, const std::string& valeur);
    std::string rechercher(int cle);
    void supprimer(int cle);
    void afficher() const;
};

#endif