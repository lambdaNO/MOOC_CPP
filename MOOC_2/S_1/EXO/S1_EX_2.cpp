#include <iostream>
#include <array>
#include <cmath>
using namespace std;
struct Point {
	double x_;
	double y_;
};
//
class Cercle {
	private:
		double r_;
		Point centre_;
	public:
		void init();
		Point centre() const;
		void centre(Point const & p);
		double rayon() const;
		void rayon(double r);
		void affiche() const;
		double surface() const;
		bool estInterieur(Point const & p) const;
		bool compareSurface(Cercle const & c) const; 
		
};

void Cercle::init() {r_ =0.; centre_.x_ =0.; centre_.y_ = 0.;}
Point Cercle::centre() const {return centre_;}
void Cercle::centre(Point const & p) {centre_ = p;}
double Cercle::rayon() const {return r_;}
void Cercle::rayon(double r) { if (r<0.) {r= 0.;}	r_ = r;}
void Cercle::affiche() const {cout<<"C("<<centre_.x_<<","<<centre_.y_<<") avec r = " << r_ << " de surface " << surface() << endl;}		// Pas besoin du this
double Cercle::surface() const {return M_PI*pow(r_,2);}
bool Cercle::estInterieur(Point const & p) const {
	return pow(centre_.x_ - p.x_,2) + pow(centre_.y_ - p.y_,2) <= pow(r_,2);
}
bool Cercle::compareSurface(Cercle const & c) const {
	if (this->surface() >= c.surface()) {
		return true;
	}
	return false;
}
//
int main() {
	Cercle c1, c2;
	c1.init(); c2.init();
	c1.centre(Point({1.0, 2.0}));
	c1.rayon(sqrt(5.0)); // passe par (0, 0)
	c2.centre(Point({-2.0, 1.0}));
	c2.rayon(2.25); // 2.25 > sqrt(5) => inclus le point (0, 0)
	c1.affiche(); c2.affiche();
	cout << "surface(c1) >= surface(c2) ? " << c1.compareSurface(c2) << endl;
	cout << "surface(c2) >= surface(c1) ? " << c2.compareSurface(c1) << endl;
	cout << "centre(c1) in cercle(c2) ? " << c2.estInterieur(c1.centre()) << endl; 
	cout << "centre(c2) in cercle(c1) ? " << c1.estInterieur(c2.centre()) << endl; 
	cout << "(0,0) in cercle(c1) ? " << c1.estInterieur(Point({0,0})) << endl;
	cout << "(0,0) in cercle(c2) ? " << c2.estInterieur(Point({0,0})) << endl;
	
	return 0;
}
