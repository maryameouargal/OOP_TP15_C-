#ifndef PILE_HPP
#define PILE_HPP

#include <vector>
#include <algorithm> 
#include "PileVideException.hpp"

template <typename T>
class Pile {
private:
    std::vector<T> elements; 
public:
    // 1. Empiler (ajouter au sommet)
    void empiler(T element) {
        elements.push_back(element);
    }

    // 2. Depiler (retirer le sommet)
    T depiler() {
        if (estVide()) {
            throw PileVideException("Impossible de depiler : la pile est vide !");
        }
        T sommet = elements.back(); // On recupere le dernier
        elements.pop_back();        // On le retire
        return sommet;
    }

    // 3. Sommet (regarder sans retirer)
    T sommet() const {
        if (estVide()) {
            throw PileVideException("Impossible de lire le sommet : la pile est vide !");
        }
        return elements.back();
    }

    // 4. Est-ce vide ?
    bool estVide() const {
        return elements.empty();
    }

    // 5. Taille de la pile
    int taille() const {
        return elements.size();
    }

    // 6. Extension : Inverser la pile
    void inverser() {
        std::reverse(elements.begin(), elements.end());
    }

    // 7. Bonus : Afficher la pile (pour les tests)
    void afficher() const {
        std::cout << "[ ";
        for (const T& e : elements) {
            std::cout << e << " ";
        }
        std::cout << "]" << std::endl;
    }
};

#endif