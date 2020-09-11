#include <iostream>
using namespace std;
/* --- */
// Mantras :
//    -> Classe (catégorie d'objets) : Résultats des processus d'encapsulation et d'abstraction
//    -> Classe définit un type
//    -> Instance/Objet : Réalisation particulière d'une classe
//    -> Objet : variable
//
// * Déclaration de classe :
//  class X {...};
// * Déclaration d'attributs de classe
//  class X { type_1 nom_attribut_1 ; type_2 nom_attribut_2 ; ...};
// * Déclaration d'une méthode de classe
//  class X { ...; type_retour nom_methode(type_param_1 nom_param_1, ... ){...corps_méthode...} };
// * Déclaration d'une méthode de classe hors de la classe :
//  Rmq : Le prototype est laissé dans la classe
//  class X { ...; type_retour nom_methode(type_param_1 nom_param_1, ... ); ...};     // Définition du prototype dans la classe
//  [...]
//  Implémentation de méthode
//  type_retour X::nom_methode(type_param_1 nom_param_1, ... ){...corps_méthode...}
//  Notation '::' est appelée opérateur de résolution de portée
// * Types de méthodes :
//    - Actions : Modifient l'état de l'objet
//    - Prédicat : Ne changement rien à l'objet
//      Pour spéficier qu'une méthode est de type prédicat, on ajoute 'const' après la définition du prototype **ET** de la méthode
//          class X { ...; type_retour nom_methode(type_param_1 nom_param_1, ... ) const ; ...};
//      e.g. pour surface (voir plus bas)
//      Rmq : Si on ajoute const à une méthode qui modifie l'objet, l'erreur suivante va s'afficher :
//            " assignment of data-member '...' is read-only structure "
//  ------------------------------------------------------------------------------------------------
// * Déclaration d'instance :
//  nom_class nom_instance();
// * Accès a un attribut d'instance :
//  nom_instance.nom_attribut_x
// * Appel à une méthode
//  nom_instance.nom_methode(arg_1, arg_2, ...)
//  ------------------------------------------------------------------------------------------------
// * Private et Public
//     Private (attribut ou méthode) : Inacessible depuis l'exterieur de la classe;
//     Public : Accessible depuis l'exterieur de la classe
//     => Toujours spéficier les méthodes
//     Mantra :
//        - Tout est passé en privé
//        - hormis quelques méthodes définissant l'interface (méthodes nécessaire)
//        - Mettre en place des getter et setter coupler aux privates pour assurer l'encapsulation
//            -> Getter : Ce sont des prédicats (qui ne modifient pas la structure de l'objet) -> const !
//            -> Setter : Ce sont des actions qui vont modifier les valeurs des attributs dans les objets
//                       MAIS qui ne renvoie rien (en théorie) -> void !
//     Mantra masquage :
//        Si dans une méthode un attribut est masqué, alors la valeur de l'attribution peut quand même être référencée à l'aide de "this"
//        this est un "pointeur sur l'instance courante"
//        this ~~ mon adresse
//        Syntaxe : this-> nom_attribut_x
//        Exemple : Moche mais fonctionnel :
//            void setHauteur(double hauteur) { this-> hauteur = hauteur;}
//        Exemple : Comparaison de rectangle :
//
//      Synthèse exemple :
//      Classe Rectangle :
//      [Attributs]
//            [Public: aka Inteface]
//            [Private : aka Implementation]
//                couleur , largeur, hauteur;
//      [Méthodes]
//            [Public: aka Inteface]
//                surface, setCouleur, setLargeur, setHauteur, getCouleur, getLargeur, getHauteur;
//            [Private : aka Implementation]




/* --- */
// Déclaration de classe :
class Rectangle {

    //
    /*
    double surface(){
        return hauteur*largeur;     // Portée de classe (pas besoin de spécifer les appels aux attributs)
    }
    */
    // Moralité : Une méthode est une fonction propre à la classe qui a accès aux attributs de cette classe -> NE PAS PASSER les attributs comme arguements de méthodes de classe;
    // SAUF si la méthode a besoin d'un argument passé depuis l'exterieur
    /*
    void setCouleur(char c){
      couleur = c;
    }
    */
    // Externalisation des implémentations des méthodes de classe :
    //    -> Déclaration du prototype de la méthode
    public :
      // Prototypes
      double surface() const;
      bool compareHauteur(Rectangle r);
      // Getter - Prédicats
      double getHauteur() const {return hauteur;}
      double getLargeur() const {return largeur;}
      char getCouleur() const {return couleur;}
      // Setter - Actions
      void setHauteur(double h) {hauteur = h;}
      void setLargeur(double l) {largeur = l;}
      void setCouleur(char c) {couleur = c;}
    // ------
    // Déclaration des attributs
    private :
      double hauteur;
      double largeur;
      char couleur;


};

// Externalisation des implémentations des méthodes de classe :
//    -> Implémentation de la méthode prototypé dans la classe
double Rectangle::surface() const {
    return hauteur*largeur;
}
bool Rectangle::compareHauteur(Rectangle r) {
    if (this-> hauteur > r.hauteur){
      return true;
    }
    return false;
}





/* --- */
int main(){
  Rectangle r1;
  r1.setHauteur(3.);
  r1.setLargeur(4.);
  r1.setCouleur('r');
  cout << "Rectangle : "<< r1.getHauteur() << " x " << r1.getLargeur() << " | surface = " << r1.surface() << " | couleur = " << r1.getCouleur() << endl;
  Rectangle r2;
  r2.setHauteur(4.);
  r2.setLargeur(5.);
  r2.setCouleur('r');
  cout << "hauteur(r1) > hauteur de (r2) ? -> " << r1.compareHauteur(r2) << endl;


  return 0;
}
/* --- */
