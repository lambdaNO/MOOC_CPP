#include <iostream>
#include <cmath>
using namespace std;
class Figure {
	protected :
		double x;
		double y;
	public :
		Figure(double a=0.,double b=0.) : x(a), y(b) {};
		void setPoint(double a, double b) { x = a; y = b;};
		void getPoint(double & abs, double & ord) const { abs = x; ord = y;};
		void afficher(ostream & sortie) {sortie <<"C = ("<<x<<","<<y<<")";}
};


class Cercle : public Figure {
    protected :
        double rayon;
    public :
        Cercle(double r=0.,double x=0., double y=0.) : Figure(x,y), rayon(r)  {};
        //~Cercle();
        void setRayon(double r) { if (r<0.) {r = 0.;} rayon = r;}
        double getRayon() const { return rayon;}
        double surface() const { return M_PI*pow(rayon,2);}
        void afficher(ostream & sortie) { Figure::afficher(sortie); sortie << " r = " << rayon << endl;}
};
class Rectangle : public Figure {
    protected :
        double largeur;
        double hauteur;
    public :
        Rectangle(double l, double h, double x=0., double y=0.) : Figure(x,y), largeur(l), hauteur(h) {};
        //~Rectangle();
        void setLargeur(double l) {largeur = l;}
        void setHauteur(double h) {hauteur = h;}
        double getLargeur() const { return largeur;}
        double getHauteur() const { return hauteur;}
        double surface() const {return largeur*hauteur;}
        void afficher(ostream & sortie) { Figure::afficher(sortie); sortie << " l = " << largeur <<" h = "<< hauteur <<endl;}
};
class RectangleColore : public Rectangle {
    protected :
        unsigned int couleur;
    public :
        RectangleColore(double l, double h, unsigned int c) : Rectangle(l,h), couleur(c) {};
        //~RectangleColore();

};



int main() {
	RectangleColore r(4.3, 12.5, 4);
	cout << r.getLargeur() << endl;
	r.afficher(cout);
	cout << endl;
	/*
	Cercle c;
	c.setPoint(2.3, 4.5);
	c.setRayon(12.2);
	c.afficher(cout);
	cout << endl;
	*/
	Cercle c(12.2, 2.3, 4.5);
	c.afficher(cout);
	cout << endl;
	Rectangle r2(1.2, 3.4, 12.3, 43.2);
	r2.afficher(cout);
	cout << endl;


    return 0;
}
