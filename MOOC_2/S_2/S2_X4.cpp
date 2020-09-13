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
//    nom_classe (nom_classe const & autre) { ... }
//  class PasCompiable { ... PasCompiable(PasCompiable & const) = delete}
//
//  Destructeur :
//        dans le cas d'un rectangle où les attributs sont des pointeurs, il faut les désalloués après utilisation
//        par respect de la propriété d'encapsulation, il faut éviter d'écrire des delete dans le main.
//        C++ implémente les Destructeur qui sont appelés autamatiquement en fin de vie de l'objet;
//        MAIS il faut l'implémenter :
//
//   Remarque : il faut également le faire pour d'autres types d'attributs que les pointeurs hein !!!
//   Syntaxe : ~nomClasse() { /*  Opération de libération de mémoire  */}
//   Remarque : - Il est unique (pas de surchage)
//              - Si non écrit, le compilateur va en générer un par défaut de type minimal


/* --- */
long compteur(0);
class Rectangle {
    private :
        double * hauteur;
        double * largeur;
    public :
        Rectangle(): hauteur(new double(20)), largeur(new double(40)){++compteur;};
        // Sans l'implémentation du constructeur de copie, la construction est minimale et ne permet pas de suivre l'execution du compteur.
        Rectangle(Rectangle const & r):hauteur(r.hauteur),largeur(r.largeur){++compteur;}
        ~Rectangle() { delete largeur; delete hauteur;--compteur;}



};
/* --- */
int main() {
    // Appel au constructeur (invoqué autamatiquement à chaque appel)
    Rectangle r1;
    cout << "CPT = "<< compteur << endl;
    {
      Rectangle r2;
      cout << "CPT = "<< compteur << endl;
      Rectangle r3(r2);
      cout << "CPT = "<< compteur << endl;
    }
    cout << "CPT = "<< compteur << endl;



    // Ici, est appelé le Destructeur;
    return 0;
}
