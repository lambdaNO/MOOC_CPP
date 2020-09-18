#include <iostream>
using namespace std;
/* --- */
// Variables et méthodes de classe :
//    => Les attributs définis dans une classe représentes des informations spécifiques aux objets;
//        Ici, chaque rectangle possède sa propre largeur et sa propre hauteur;
//        Mais que se passe t'il quand pls instances d'une même classe ont besoin d'accéder à la même information commune
//        Une variable globale ??
//            Non c'est laid et contraire au principe d'encapsulation (effet de bords en sup)
//        Définir l'attribut compteur pour chaque rectangle ?
//            Non car chaque instance de rectangle a son propre compteur, et ce n'est pas ce que nous souhaitons. Nous souhaitons avoir une zone commune accessible par toutes les instances.
//        Solution :
//            Définir des Attributs de classe (spécifique à une classe et non à une instance)
//            => Précédé du mot "static"
//            * accessible par toutes les instances mais créé en mémoire une seule fois.
//            * créé même lorsque qu'aucune instance n'est déclarée
//                -> Initialisé hors de la classe (car existe même lorsque qu'aucune instance n'est créée - le constructeur ne va pas pouvoir le faire)
// Exemple : Employee
//      -> La date de retraite est identique pour tous les employés
//      -> Dans le cas d'une modification de loi, on peut modifier l'initisalisation de la variable de classe (ex passage à 67 ans)
// Moralité :
//        Variable de classe utile dans le cas d'une variable (souvent constante) accessible par plusieurs instance;
//        MAIS sans duplication de l'information.
//
// Méthodes statique ?
//      Idem :
//        public :
//            static void ...
//      Mais - Elle n'ont pas le droit d'utiliser de méthode ni d'attribut d'instance (y cmpris this)
//           - Elle ne peuvent accéder seulement qu'à d'autre méthodes ou attributs de ckasse
//           => simplement des méthodes qui font appel à d'autres méthodes statiques
//    Les méthodes statiques peuvent dans la majorité des cas être avantageusement remplacées par des fonctions usuelles en C++
//    Les fonctions usuelles sont à préférer le cas échéant à des méthodes statiques. La prolifération de méthode statique va à l'encontre d'une bonne conception orientée objet.
//    Une méthode statique ne peut utiliser directement que d'autres membres statiques de la classe dans laquelle elle est définie
//    Les fonctions usuelles sont à préférer le cas échéant à des méthodes statiques. La prolifération de méthode statique va à l'encontre d'une bonne conception orientée objet.
//    Les attributs statiques sont couramment utilisés pour définir des constantes communes utiles à toutes les instances d'une classe
//    Les fonctions usuelles sont à préférer le cas échéant à des méthodes statiques. La prolifération de méthode statique va à l'encontre d'une bonne conception orientée objet.
/*
class C {

    public:
        static void m(const C& autre) {   m2();   cout << c1 << c2; cout << autre.c1;   cout << autre.c2;   cout << endl; }
    private:
        static int c1;
        int c2;
        void m2(){}
};
ne compile pas en raison de la ligne cout << c1 << c2;
    - m2(); est incorrect car on ne peut pas accéder dans une méthode statique à une méthode d'instance;
    - cout << c1 << c2; est incorrect car on ne peut pas accéder dans une méthode statique à un attribut d'instance (c2)
    - cout << autre.c1; est correct car on peut accéder aux membres statiques ou non via une instance (autre)
    - cout << autre.c2; est correct car on peut accéder aux membres statiques ou non via une instance (autre)
ne compile pas en raison de la ligne m2();
    - m2(); est incorrect car on ne peut pas accéder dans une méthode statique à une méthode d'instance;
    - cout << c1 << c2; est incorrect car on ne peut pas accéder dans une méthode statique à un attribut d'instance (c2)
    - cout << autre.c1; est correct car on peut accéder aux membres statiques ou non via une instance (autre)
    - cout << autre.c2; est correct car on peut accéder aux membres statiques ou non via une instance (autre)
*/


/* --- */
//int compteur(0);    // Non c'est moche
class Rectangle {
    private :
        double hauteur;
        double largeur;
        static unsigned int compteur;     // Attributs de classe (attribut partagé par l'ensemble des objets)
    public :
        // Constructeur par défaut;
        Rectangle(): hauteur(0.), largeur(0.) {
            ++compteur;
            aff_cpt();
        }
        // Destructeur :
        ~Rectangle() {
            --compteur;
            aff_cpt();
        }
};
// Initiation de l'attribut de classe - en dehors de la classe
unsigned int Rectangle::compteur(0);
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
class Date{
    private :
        unsigned int jour;
        unsigned int mois;
        unsigned int annee;
    public :
        Date(unsigned int j, unsigned int m, unsigned annee) : jour(j),mois(m),annee(a) {};
        ~Date(){};
        void affiche() const { cout << jour << "/"<< mois <<"/"<<annee};
};

class Employe {
    private :
        string nom;
        Date service;
        static unsigned int age_retraite;
    public :

};

unsigned int Employe::age_retraite(65);
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
class A {
    public :
        static void methode_1 const { cout << "Méthode 1"<< endl;}
        void methode_2 { cout << "Méthode 2"<< endl;}

}




/* --- */
int main() {
    //Rectangle r1;
    //Rectangle r2;
    A::methode_1();     // OK
    A::methode_2();     // ERREUR   - non static - Nécessite l'initialisation d'une instance
    A x;
    x.methode_1();      // OK
    x.methode_2();      // OK

    return 0;
}
