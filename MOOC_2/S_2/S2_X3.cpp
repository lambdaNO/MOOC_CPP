#include <iostream>
using namespace std;
/* --- */
// Les Constructeurs de classe
//        => Ne pas utiliser les setter/manipulateurs pour initialiser les valeurs d'attributs (perte de l'encapsulation)
// Mantra : * Constructeur invoqué automatiqiement lors de la déclaration d'un objets
//          * Chargé d'effectuer toutes les opération d'initialisation des attributs pour chaque nouvelle instance
//          rmq : jusqu'ici, on implemntait les méthodes init() mais c'était nul
// Syntaxe :
//        Nom_class(liste_paramètres) {                             // Une méthode qui a le même nom que la classe
//            /* initialisation des attributs avec liste_paramètres */
//        }
// Syntaxe : Liste d'intialisation du constructeur
//     Nom_class(liste_paramètres): attribut_1(...), attribut_2(...),...,attribut_N(...){
//           /* initialisation des attributs avec liste_paramètres (autres paramètres)*/
//     }
//    attribut_1(...), attribut_2(...),...,attribut_N(...) est la liste d'initialisation
//
// Constructeur par défaut :
//        Rectangle() : hauteur(1.), largeur(2.){}                    // Constructeur par défaut ex 1
//        Rectangle(double c) : hauteur(c), largeur(2.*c) {}          // Constructeur par défaut ex 2
//        Rectangle(double c,double d) : hauteur(c), largeur(d) {}    // Constructeur par défaut ex 3 (ce n'est pas un constructeur par défaut)
// Constructeur de copie :
//  Rectangle r1(12.3,24.5);
//  Rectangle r2(r1);
//  Syntaxe :
//    nom_classe (nom_classe const & autre) { ... }
//    ATTENTION : passage par référence constante (eviter les copie de copie de ...)
//  Remarque : le constructeur de copie est automatiquement générée par le compilateur s'il n'est pas explicitement définit
//            -> Il fait une copie membre à membre des attributs (si l'attribut est un objet, le constructeur de cet objet est appelé)
//            -> Copie en surface
//  => il n'est donc pas nécessaire de l'écrire pour des copie superficielle
//
//   Remarque : Si l'on ne veut pas activer le constructeur de copie avec delete;
//  class PasCompiable { ... PasCompiable(PasCompiable & const) = delete}
/* --- */
class Rectangle {
    private :
        double hauteur;
        double largeur;
    public :
        //Rectangle() : hauteur(1.), largeur(2.){}                    // Constructeur par défaut ex 1
        //Rectangle(double c) : hauteur(c), largeur(2.*c) {}          // Constructeur par défaut ex 2
        Rectangle(double c,double d) : hauteur(c), largeur(d) {}    // Constructeur ex 3 (ce n'est pas un constructeur par défaut) // Constructeur explicite
        Rectangle(double c = 1.) : hauteur(c), largeur(2.*c) {}
        // Constructeur de recopie :
        Rectangle(Rectangle const & autre) : hauteur(autre.hauteur), largeur(autre.largeur) {}

        //
        double surface() const;
        double getHauteur() const;
        double getLargeur() const;
        void setHauteur(double h);
        void setLargeur(double l);
};
double Rectangle::surface() const { return hauteur*largeur;}
double Rectangle::getHauteur() const { return hauteur; }
double Rectangle::getLargeur() const { return largeur; }
void Rectangle::setHauteur(double h) {hauteur = h;}
void Rectangle::setLargeur(double l) {largeur = l;}


/* --- */
int main() {
    // Appel au constructeur (invoqué autamatiquement à chaque appel)
    Rectangle r1(3.,4.8);
    Rectangle r2(r1);

    return 0;
}
