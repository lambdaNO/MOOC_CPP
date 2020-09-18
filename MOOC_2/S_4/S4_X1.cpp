#include <iostream>
using namespace std;
/* --- */
/*
    Héritage :
        - Représente la relation "est-un" entre des objets
        - Permet de crée des classes plus spécialisée appelée sous-classe (méthodes et attributs en plus) à partir de classe plus générales déjà existantes appelées super classe
        [Classe]    <-     [Sous-Classe]
                    <-     [Sous-Classe]
                    <-     [Sous-Classe]
                ---------> Enrichissement/Spécialisation
                <--------- Héritage
        ATTENTION l'oriention est importante
    Exemple : Soit C1 une sous-classe de la super-classe C
            - Le type de C1 est hérité de C (notion de C1 *est-un* C)
            - C1 hérite des attributs de C et des méthodes de C SAUF DES CONSTRUCTEURS
            - Les attributs et méthodes de C vont être disponnibles pour C1 sans que l'on ait besoin de les redéfinir explicitement;
            + Des attributs et/ou méthodes supplémentaires peuvent être définis par la sous classé C1 (Enrichissement)
            + des méthodes héritées de C peuvent être redéfinie dans C1 (spécilisation)
            * L'héritage représente la relation "est-un"
            * L'encapsulation représente la relation "a-un"   // Donc pas d'héritage
            + L'héritage est transitif    super_super_classe A <- super_class B <- classe C     C hérite des méthodes et attributs de A;
    Syntaxe :
          class nom_sous_classe : public nom_super_classe {
              /* Déclaration des méthodes et attributs spécifiques à la sous-classe
          }
          [Classe : Figure (position)]    <- hérite de - [Classe : Rectangle(longueur,largeur)]  et possède une position;
    Droit protégés:
        un attribut/méthode d'une classe est :
            * public : visibilité à l'intérieur et à l'extérieur de la classe
            * private : visibilité à l'intérieur de la classe uniquement;
        un attribut private dans une super_class A n'est pas accessible dans la sous_class B (hérité de A)
        => Problème : B possède l'attribut privé par héritage mais ne peut y accéder ...
            * protected : régit l'accès aux atributs/ méthodes dans une hierarchie de classe;
            -> l'accès protégé (protected) assure la visibilité des membres (attributs/méthodes) d'une classe dans les classes déscendentes
            * protected correspond à une extension du niveau prové permettant l'accès aux sous-classes MAIS UNIQUEMENT dans leurs portées (sous classe) et non pas dans la portée de la super-classe ()

            class A {
                protected : int a;
                private : int p;
            };
            class B : public A {
                protected :
                private :
                public :
                    void f(B autreB, A autreA, int x) {
                        a = x;      // OK A::a est protected -> accès possible
                        p = x;      // NON A::p est private
                        //
                        a+= autreB.p  // NON A::p est private;
                        a+= autreB.a  // OK B:: - Dans la même portée de B::
                        //
                        a+= autreA.a  // NON this (class B) n'est pas de la même portée de autreA (class A)
                                      // INTERDIT
                    }
            };

            Private: It is an access specifier. By default the instance (member) variables or the methods of a class in c++/java are private. During inheritance, the code and the data are always inherited but is not accessible outside the class. We can declare our data members as private so that no one can make direct changes to our member variables and we can provide public getters and setters in order to change our private members. And this concept is always applied in the business rule.

            Protected: It is also an access specifier. In C++, the protected members are accessible within the class and to the inherited class but not outside the class. In Java, the protected members are accessible within the class, to the inherited class as well as to all the classes within the same package.

    Masquage :
        Cas d'une classe hérité B de A où il faut spécialiser (ou modifier) le contenu d'une méthode hérité de la super_classe A
        ex :  Classe Personnage : void rencontrer(Personnage & o) const {saluer(o);}
              Classe Guerrier:public Personnage : void rencontrer(Personnage & o) const { frapper(o); }; void frapper()
              => Les comportements diffèrent dans la hierarchie de classe;
              => Il faut redéfinir le comportement (SPECIALISATION) de la méthode recontrer dans la classe héritée guerrier;
              ---> Procédure de Masquage.
        rencontrer() est présent 2 fois dans l'arbre d'héritage avec une spécialisation dans la classe guerrier;
        la specialisation de la méthode rencontrer dans la classe guerrier va venir MASQUER la méthode hérité de la classe personnage pour redéfinir le comportement.
        Moralité : Méthode hérité -> Méthode générale (par défaut)
                   Méthode masquée (qui masque la méthode hérité) -> Méthode spécifique à la classe
        Syntaxe :
            - Pour appeller une méthode issue d'une super_class, on utilise l'opérateur de résolution de portée ::

            class Personnage {
                private :
                    string nom;
                protected :
                    int energie;
                public :
                    void rencontrer(Personage & perso)
                    void saluer(Personnage & perso)
            };
            class Guerrier : public Personnage {
                private : //  Spécialisation

                public :  // Méthodes
                    void frapper(Personnage & perso) { ... }    //
                    // Méthode qui va masquer la méthode hérité;
                    void rencontrer(personage & perso) {
                        Personnage::saluer(perso);    // Méthode hérité
                        frapper(perso);               // Méthode définie dans la classe
                    }

            };




    Construction :
        Instanciation d'une sous-classe -> initialisation =
            - des attributs propres à la sous classe
            - des attributs hérités de la super classe
        MAIS : il ne faut pas initialiser manuellement les attributs hérités
              -> Passer par le constructeur de la super_classe
        Syntaxe :
            nom_sous_classe(liste_de_param) : super_classe(liste_d_arguements), attribut_1(valeur_1), ..., atribut_N(valeur_N) {
                //Corps du constructeur
            }
            avec super_classe() le constructeur de la super_classe
        Remarque :  cet appel doit être le PREMIER dans l'appel au constructeur
        Remarque : Si une classe possède un constructeur par défaut, alors il n'est pas nécéssaire de faire un appel explicite au constructeur
                   SINON appel au constructeur explicite
        Remarque : On est pas toujours obligé d'ajouter un paramètre supplémentaire dans une classe :
        Ex :
            class Carre : public Rectangle {
                public :
                    Carre(double taille) : Rectangle(taille,taille) {};
                    // Dans le cas où il y aurait des manipulateur, il faudrait redéfinir les méthodes
                    eg : si classe Rectangle possède setHauteur et setLargeur; il faut masquer ces méthodes dans la sous classe Carré telle que :
                    setHauteur(double b) { hauteur = l; largeur = l}; // La même chose pour setLargeur()
            }
        Remarque : Dans le cas d'une construction de classe héritée, l'ordre de construction commence toujours par la construction de la super classe puis des sous classe dans l'ordre
                  eg : [A] <- [B] <- [C]
                      Construction de C : 1) Appel au constructeur de A puis de B puis de C (dans cet ordre)

                      class A {   public: A() { cout << 'A' ; }
                                          A(int a) { cout << 'A' << a ; }
                              };

                      class B : public A {public: B() { cout << 'B' ; }};
                      -> B b; affiche : AB
                      -> Le code ne compile plus si on supprime le constructeur par défaut de A
                          Les constructeurs des super-classes sont invoqués avant ceux des sous-classes.
                          Si on supprime le constructeur par défaut de A il n'y a aura pas de constructeur
                          par défaut car la classe A possède un autre constructeur explicite. La classe B ne
                          peut alors pas faire l'économie de l'invocation explicite de ce constructeur

        Remarque :
            Lorsqu'il y a besoin d'une redéfinition du constructeur de copie dans une sous classe, toujours faire appel EXPLICITEMENT aux constructeur
            de copie de la super classes
            SINON c'est le constructeur par défaut qui est appelé
            Eg :
                Rectangle(Rectangle const & o) : Figure(o), largeur(o.largeur), hauteur(o.hauteur) {};  avec  Figure(o) le constructeur de copie de la classe Figure
                Rectangle(Rectangle const & o) : largeur(o.largeur), hauteur(o.hauteur) {}; Ici, la position du rectangle est la valeur par défaut (ici position (0,0))

          Destructeur :
              Les Destructeurs sont appelés dans l'ordre inverse des constructeurs
              Remarque : Dans le cas d'une construction de classe héritée, l'ordre de construction commence toujours par la construction de la super classe puis des sous classe dans l'ordre
                        eg : [A] <- [B] <- [C]
                        Destruction de C : 1) Appel à ~C puis à ~B puis à ~A









*/
/* --- */


class Figure {
    protected : Position position;
    public :
        Figure(double x, double y) : position(x,y) {};
        // ...
}
class Rectangle : public Figure {
    protected : double largeur; double hauteur;
    public :
        Rectangle(double x, double y, double l, double h) : Figure(x,y), largeur(l), hauteur(h) {}
}


int main() {



    return 0;
}
