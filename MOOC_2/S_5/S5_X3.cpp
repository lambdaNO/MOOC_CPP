#include <iostream>
#include <cmath>
using namespace std;
/*
    classe abstraite
        => Problème :
            Au sommet d'une hierarchie de classe, il n'est pas toujours possible de :
            1) donner une définition générale de certaines méthodes compatibles avec toutes les sous-classes;
               même si l'on sait que toutes sous-classes vont implémenter ces méthodes;
               Eg : Classe figure fermée -> On souhaite définir une méthode surface
                                         -> mais le calcule diffère fonction des figures (carré, cercles, losanges, ...)
                                         -> On ne sait pas définir cette méthode au niveau de la superclasse
                    Rmq : On pourrait quand même utiliser cette méthode virtuelle pure dans les fonctions de la super-classe
                          Eg : calcul du volume à partir de la surace dans la super classe
               Eg : Classe personnage    -> Modification de la méthode d'affichage fonction du type de personnage;
                                         -> la méthode si elle veut être appelée doit être virtuelle pure, existe au niveau de la super-classe et redéfinie dans les sous classe;
      Méthode virtuelle pure/abstraite = doit exister dans la super classe ET doit être redéfinie dans les sous classes

      Syntaxe :
          virtual type nom_methode(liste_params) = 0;

          Exemple :
                  class Personnage {
                      public :
                          virtual void afficher() const = 0;
                      ...
                  };
                  class FigureFermee {
                      public :
                          virtual double surface() const = 0;
                          virtual double perimetre() const = 0;
                          // ATTENTION on a le droit d'utiliser une méthode virtuelle pur dans la super classe // Elle sera juste implémentée fonction de la sous-classe
                          double volume(double hauteur) const {
                              return hauteur*surface();   // même chose que hauteur*this->surface(); Le pointeur est implicite
                          }
                  };

        Notation :
            une classe abstraite est une classe contenant au moins une virtuelle pure;
                -> Elle ne peut être instanciée
                -> Les sous classes restent abstraites tant qu'elles ne fournissent pas les définitions de toutes les méthodes virtuelles pures dont elles héritent

        Remarque :
            La classe polygone hérite de la classe figure fermée + Implémente la méthode périmètre
            On ne peut pas créer d'instance de la classe Polygone car elle est toujours une classe abstraite (elle n'implémente pas la méthode surface)
            Polygone* p;    // Peut-on créer des pointeurs sur des Polygone ?
            oui on peut : un pointeur n'est pas une instance, juste une adresse
                -> un pointeur n'est pas une instance, juste une adresse vers une future possible instance... ...de sous-classe non abstraite bien sûr. Par exemple si Triangle est une sous-classe non abstraite de Polygone alors on peut tout à fait en avoir une instance et par exemple faire :
                Polygone* p = new Triangle();

*/
int main() {
    return 0;
};
