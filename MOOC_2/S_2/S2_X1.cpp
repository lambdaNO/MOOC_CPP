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
//
// Remarque :
//          - Plusieurs type de Constructeurs (par défaut, de copie, d'attributs)
//          - Le constructeur doit être public (car appelé depuis l'interface)
//          - Pas de void ou autre nom; juste le nom de la classe
//  ------
//  Appel aux constructeurs d'attributs (voir après dans le cas de l'héritage)
//    * Liste d'intialisation du constructeur
//     Nom_class(liste_paramètres): attribut_1(...), attribut_2(...),...,attribut_N(...){
//           /* initialisation des attributs avec liste_paramètres (autres paramètres)*/
//     }
//    attribut_1(...), attribut_2(...),...,attribut_N(...) est la liste d'initialisation
//   Ex : Rectangles colorés
//   class Couleur { Couleur(char c); // ...}
//   class Rectangle { Rectangle(double h,double l); //...     }
//   class RectangleColore {
//        public :
//            RectangleColore(double h,double l,Couleur c) : rectangle(h,l), couleur(c) {      // La liste d'initialisation est rectangle(h,l), couleur(c) correspondants aux constructeurs appelés
//              // Autres opérations
//            }
//        private :
//            Rectangle rectangle;
//            Couleur c;
//    };
//    Appel au constructeur : RectangleColore r(3.5,4.5,rouge);     --> 3.5,4.5 passent dans le constructeur de rectangle de la liste d'initisalition; rouge passe dans le constructeur de Couleur de la liste d'initisalition;
//
//    Ex : Rectangle avec liste d'initialisation partielle :
//        Rectangle(double h,double l) : hauteur(h) { largeur = 2* l + h;}    // La largeur est définie en dehors de la liste d'initialisation;


/* --- */
class Rectangle {
    private :
        double hauteur;
        double largeur;
    public :
        // Constructeur (avec paramètres)
        //Rectangle(double h, double l) { hauteur = h; largeur = l;}
        // Constructeur (avec paramètres et liste d'initialisation)
        Rectangle(double h, double l) : hauteur(h),largeur(l) {};       // Le bloc d'opération est vide (et c'est normal) car les attributs sont initalisés dans la liste (après les ":")
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
