#include <iostream>
#include <string>
#include "Pile.hpp"

using namespace std;

int main() {
    cout << " Test de la Pile Generique " << endl;

    //  Test 1 : Pile d'entiers (int)
    cout << "\nTest 1 : Pile de int" << endl;
    Pile<int> pileInt;
    pileInt.empiler(10);
    pileInt.empiler(20);
    pileInt.empiler(30);

    cout << "Contenu : ";
    pileInt.afficher();
    
    cout << "Sommet : " << pileInt.sommet() << endl;
    cout << "Depiler : " << pileInt.depiler() << endl;
    cout << "Contenu apres depilement : ";
    pileInt.afficher();

    //  Test 2 : Pile de chaines de caracteres (string)
    cout << "\nTest 2 : Pile de string " << endl;
    Pile<string> pileString;
    pileString.empiler("Ananse");
    pileString.empiler("Banane");
    pileString.empiler("fraise");

    cout << "Contenu : ";
    pileString.afficher();
    cout << "Sommet : " << pileString.sommet() << endl;

    // Test 3 : Pile de doubles
    cout << "\nTest 3 : Pile de double " << endl;
    Pile<double> pileDouble;
    pileDouble.empiler(1.5);
    pileDouble.empiler(2.7);
    
    cout << "Contenu : ";
    pileDouble.afficher();

    // Test 4 : Gestion de l'exception (Pile vide) 
    cout << "\n Test 4 : Exception sur pile vide " << endl;
    Pile<int> pileVide;
    try {
        pileVide.depiler();
    }
    catch (const PileVideException& e) {
        cout << "ERREUR !! " << e.what() << endl;
    }

    //  Test 5 : Extension Inverser 
    cout << "\n Test 5 : Inverser la pile " << endl;
    Pile<int> pileAInverser;
    pileAInverser.empiler(1);
    pileAInverser.empiler(2);
    pileAInverser.empiler(3);
    
    cout << "Avant inversion : ";
    pileAInverser.afficher();

    pileAInverser.inverser();
    
    cout << "Apres inversion : ";
    pileAInverser.afficher();
    cout << "Nouveau sommet : " << pileAInverser.sommet() << endl;

    return 0;
}