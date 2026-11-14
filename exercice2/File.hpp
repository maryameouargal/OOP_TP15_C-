#ifndef FILE_HPP
#define FILE_HPP

#include "FileVideException.hpp"

class File {
private:
// Tableau dynamique
    int* elements;  
    // Taille maximale     
    int capaciteMax; 
     // Indice du premier element    
    int debut;         
    // Indice du prochain emplacement libre 
    int fin;      
    // Nombre actuel d'elements
       
    int nbElements;      
public:
    // Constructeur / Destructeur
    File(int capacite);
    ~File();

    // Methodes de base
    void enfiler(int valeur);
    void defiler();
    bool estVide() const;
    bool estPleine() const;
    int taille() const;
    
    // Bonus pour l'affichage
    void afficher() const;
};

#endif