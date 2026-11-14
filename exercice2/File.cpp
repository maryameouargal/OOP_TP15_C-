#include "File.hpp"
#include <iostream>

File::File(int capacite) {
    capaciteMax = capacite;
    elements = new int[capaciteMax];
    debut = 0;
    fin = 0;
    nbElements = 0;
}

File::~File() {
    delete[] elements; 
}

bool File::estVide() const {
    return nbElements == 0;
}

bool File::estPleine() const {
    return nbElements == capaciteMax;
}

void File::enfiler(int valeur) {
    if (estPleine()) {
        std::cout << "Attention !!!  la file est pleine, impossible d'enfiler " << valeur << std::endl;
        return;
    }
    elements[fin] = valeur;
    // Avance circulaire
    fin = (fin + 1) % capaciteMax; 
    nbElements++;
}

void File::defiler() {
    if (estVide()) {
        // On lance notre exception personnalisee
        throw FileVideException(" il est Impossible de defiler : la file est vide !");
    }
    // Avance circulaire
    debut = (debut + 1) % capaciteMax; 
    nbElements--;
}

int File::taille() const {
    return nbElements;
}

void File::afficher() const {
    if (estVide()) {
        std::cout << "(la file est vide)" << std::endl;
        return;
    }
    std::cout << "[ ";
    int index = debut;
    for (int i = 0; i < nbElements; i++) {
        std::cout << elements[index] << " ";
        index = (index + 1) % capaciteMax;
    }
    std::cout << "]" << std::endl;
}