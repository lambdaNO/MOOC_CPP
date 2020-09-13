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
//   - Sans paramètre OU dont tous les paramètres ont des valeurs par défaut :
//   Ex : Surcharge de constructeur :
//        Rectangle() : hauteur(1.), largeur(2.){}                    // Constructeur par défaut ex 1
//        Rectangle(double c) : hauteur(c), largeur(2.*c) {}          // Constructeur par défaut ex 2
//        Rectangle(double c,double d) : hauteur(c), largeur(d) {}    // Constructeur par défaut ex 3 (ce n'est pas un constructeur par défaut)
//   Rectangle r1;          // r1 est initialisé par hauteur = 1., largeur = 2.
//   Rectangle r2(3.);      // r2                    hauteur = 3., largeur = 6.
//   Rectangle r3(3., 2.);  // r3                    hauteur = 3., largeur = 2.   // Constructeur explicite
//
//    ATTENTION : dans le cas du constructeur par défaut, NE PAS utiliser les parenthèses
//    Rectangle r(); NON NON NON
//    Rectangle r;   OUI OUI OUI
//
//    Une alternative au constructeur par défaut -> Initialiser une variable
//        Rectangle(double c = 1.) : hauteur(c), largeur(2.*c) {}
//    Que l'on appelera par :
//        Rectangle r1;
//    OU par
//        Rectangle r1(5.);
//    => Cette méthode de construction fusition les constructeurs par défaut ex 1 et ex 2
//
//    Remarque : Dans le cas où l'on ne définit pas de constructeur par défaut dans une classe, c++ va quand même appliquer une version minimale de constructeur tq :
//        Si l'attribut est un objet (de classe) : il va l'initialiser en utilisant le constructeur par défaut de la classe
//        Si l'attribut est un type de base (int,double, ...) : cet attribut ne sera pas intialisé.
//    On appelle ces constructeur "par défaut, par défaut"
//    Dès lors que l'on implémente un constructeur; alors le constructeur par défaut par défaut n'est plus actif
//
//     Etude de cas :
//          CAS 1 : class Rectangle { private : double h; double l; ...};         // Pas de constructeur par défaut
//          CAS 2 : class Rectangle { private : double h; double l; public : Rectangle():h(0.),l(0.){} ...};
//          CAS 3 : class Rectangle { private : double h; double l; public : Rectangle(double h=0., double l = 0.){h(h); l(l);} ...};
//          CAS 4 : class Rectangle { private : double h; double l; public : Rectangle(double h, double l){h(h); l(l);} ...};
//        Les appels :
//          CAS 1 : * Rectangle r1;        -> retourne [?][?]    // Constructeur par défaut par défaut (initialisation minimale)
//                  * Rectangle r1(1.,2.)  -> illicite
//          CAS 2 : * Rectangle r1;        -> retourne [0.][0.]
//                  * Rectangle r1(1.,2.)  -> illicite
//          CAS 3 : * Rectangle r1;             -> retourne [0.][0.]    // On accepte les valeurs par défaut
//                      * Rectangle r1(1.);     -> retourne [1.][0.]    // On accepte la seconde valeur par défaut
//                  * Rectangle r1(1.,2.)  -> retourne [1.][2.]
//          CAS 4 : * Rectangle r1;             -> retourne illicite    // On a implémenté un constructeur explicite -> Desactive le constructeur par défaut par défaut;
//                  * Rectangle r1(1.,2.)  -> retourne [1.][2.]
//
//    Remarque : Il est possbile de réactiver le constructeur par défaut tel que avec la synthaxe suivante :
//              nom_class = default.
//              -> Peut être utile lorsque l'on travail avec des classe construite avec d'autres objets (auquel cas, le constructeur par défaut fait appel à leurs constructeurs par défaut)
//    Remarque : Une alternative à la réactivation du constructeur par défaut par défaut revient à faire un appel à un constructeur explicite pour définir le constructeur par défaut :
//              class Rectangle {
//                  private : double hauteur; double largeur;
//                  public :
//                      Rectangle(double h,double l) : hauteur(h), largeur(l) {}
//                      Rectangle() : Rectangle(0.,0.)
//                      ...
//              }
//    Remarque : On peut aussi faire
//              class Rectangle {
//                  private : double hauteur = 0.; double largeur = 0.;
//                  ...
//              }
//       => MAIS il vaut mieux passer par les constructeurs!
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
        //
        double surface() const;
        double getHauteur() const;
        double getLargeur() const;
        void setHauteur(double h);
        void setLargeur(double l);
}
double Rectangle::surface() const { return hauteur*largeur;}
double Rectangle::getHauteur() const { return hauteur; }
double Rectangle::getLargeur() const { return largeur; }
void Rectangle::setHauteur(double h) {hauteur = h;}
void Rectangle::setLargeur(double l) {largeur = l;}


/* --- */
int main() {
    // Appel au constructeur (invoqué autamatiquement à chaque appel)
    Rectangle r1(3.,4.8);


    return 0;
}
