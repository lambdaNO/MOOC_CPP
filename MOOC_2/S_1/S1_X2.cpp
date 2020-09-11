#include <iostream>
using namespace std;
/* --- */
class Rectangle {
    // Déclaration des attributs
    private :
        double hauteur_;
        double largeur_;
    // Déclaration de l'interface
    public :
        // prototypes
        double surface() const;
        bool compareHauteur(Rectangle r);
        // Getter - Prédicats - accesseurs
        double hauteur() const;
        double largeur() const;
        // Setter - Actions - manipulateurs
        void hauteur(double h);
        void largeur(double l);
};

double Rectangle::hauteur() const {return hauteur_;}
double Rectangle::largeur() const {return largeur_;}
void Rectangle::hauteur(double h) { hauteur_ = h; }
void Rectangle::largeur(double l) { largeur_ = l; }
double Rectangle::surface() const {return hauteur_*largeur_;}
bool Rectangle::compareHauteur(Rectangle r) {
    if (this->hauteur_ > r.hauteur_){ return true;}
    return false;
}
/* --- */
int main(){
  Rectangle r1;
  r1.hauteur(3.);
  r1.largeur(4.);

  cout << "Rectangle : "<< r1.hauteur() << " x " << r1.largeur() << " | surface = " << r1.surface() << endl;
  Rectangle r2;
  r2.hauteur(4.);
  r2.largeur(5.);

  cout << "hauteur(r1) > hauteur de (r2) ? -> " << r1.compareHauteur(r2) << endl;


  return 0;
}
/* --- */
