#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
/* --- */
class Forme {
	protected : 
	
	private : 
	
	public : 
		virtual ~Forme(){};
		virtual Forme* copie() const = 0;
		virtual double aire() const = 0;
		virtual void affiche() const = 0;

};
/* --- */
class Cercle : public Forme {
	protected : 
	
	private : 
		double rayon;
	public : 
		Cercle(double r = 0) : rayon(r) {};
		~Cercle(){};
		double aire() const override {return M_PI*pow(rayon,2);}
		void affiche() const override {cout<<"C | r = " << rayon << endl;}
		Cercle(Cercle const & o) : Forme(o), rayon(o.rayon) {};
		Cercle * copie() const override { return new Cercle(*this);}

};
class Triangle : public Forme {
	protected : 
	
	private : 
		double base;
		double hauteur;
	public : 
		Triangle(double b, double h) : base(b), hauteur(h) {};
		~Triangle(){};
		double aire() const override { return .5*base*hauteur;}
		void affiche() const override {cout<<"T | b = "<<base<<" , h = "<< hauteur << endl;}
		Triangle(Triangle const & o) : Forme(o), base(o.base), hauteur(o.hauteur) {};
		Triangle * copie() const override { return new Triangle(*this);}
};
class Carre : public Forme {
	protected : 
	
	private : 
		double cote;
	public : 
		Carre(double c) : cote(c) {}; 
		~Carre(){};
		double aire() const override { return pow(cote,2);}
		void affiche() const override {cout << "C | c = " <<cote << endl;}
		Carre(Carre const & o) : Forme(o), cote(o.cote) {};
		Carre * copie() const override { return new Carre(*this);}
};

class Dessin {
	private : 
		vector<Forme *> formes;
	public : 
		~Dessin(){for (auto f : formes) {delete f; f = nullptr;}};
		void ajoute_forme(Forme const & f) { formes.push_back(f.copie());}
		void affiche_dessin() const { for (auto const & f : formes) { f->affiche();}}
		
};

//void unCercleDePlus(Dessin const& img) { Dessin tmp(img); tmp.ajouteFigure(Cercle(1));cout << "Affichage de 'tmp': " << endl; tmp.affiche();}


/* --- */
int main() {
	Dessin dessin;
	dessin.ajoute_forme(Triangle(3,4)); dessin.ajoute_forme(Carre(2)); dessin.ajoute_forme(Triangle(6,1)); dessin.ajoute_forme(Cercle(12));
	dessin.affiche_dessin();
	//unCercleDePlus(dessin);		// Impossible : Problème de mémoire par passage de référence constante -> Passer par des uniques ptr 
	return 0;
}
