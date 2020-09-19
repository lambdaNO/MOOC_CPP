#include <iostream>
#include <cmath>
using namespace std;
/* --- */
class Forme {
	protected : 
	
	private : 
	
	public : 
		virtual void description() const{cout << "ceci est une forme " << endl;};
		virtual double aire() const = 0;
};
/* --- */
class Cercle : public Forme {
	protected : 
	
	private : 
		double rayon;
	public : 
		Cercle(double r = 0) : rayon(r) {};
		void description() const override {cout<<"ceci est un cercle"<< endl;};
		double aire() const override {return M_PI*pow(rayon,2);}
};
class Triangle : public Forme {
	protected : 
	
	private : 
		double base;
		double hauteur;
	public : 
		Triangle(double b, double h) : base(b), hauteur(h) {};
		void description() const override {cout<<"ceci est un triangle"<< endl;};
		double aire() const override { return .5*base*hauteur;}
};


void afficheDesc(Forme& f) {
	f.description();
	cout << " son aire est " << f.aire() << endl;
}	



/* --- */
int main() {
	Cercle c(5); Triangle t(10, 2); afficheDesc(t); afficheDesc(c);
	
	return 0;
}
