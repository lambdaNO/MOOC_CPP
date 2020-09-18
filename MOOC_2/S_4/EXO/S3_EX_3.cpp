#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
class Point3D {
	protected :
		double x;
		double y;
		double z;
	public :
		Point3D(Point3D const & v) : x(v.x), y(v.y), z(v.z) {};
		Point3D(double a=0., double b=0., double c=0.) : x(a), y(b), z(c) {};
		//Point3D() : x(0.), y(0.),z(0.){};
		~Point3D() {};
		bool operator==(Point3D const &) const;
		double getX() const { return x;} 
		double getY() const { return y;}
		double getZ() const { return z;}
		ostream & afficher(ostream &) const;
};
bool Point3D::operator==(Point3D const & v) const {
	return this->x==v.x && this->y == v.y && this->z == v.y;
}
ostream & Point3D::afficher(ostream & sortie) const {
	sortie << "(" << x << " , " << y << " , " << z << " )^T ";
	return sortie;
} 
ostream & operator<<(ostream & sortie, Point3D const & p) {
	return p.afficher(sortie);
}
/* ------------------------------------------------------------------ */
class Vecteur : public Point3D {
	//protected : 
	
	public : 
		Vecteur() : Point3D() {};
		Vecteur(double a, double b, double c) : Point3D(a,b,c) {};
		Vecteur& operator+=(Vecteur const &);
		Vecteur& operator-=(Vecteur const &);
		const Vecteur operator -() const ;
		Vecteur& operator*=(double);
		double norme() const;
};
/* --- */
Vecteur & Vecteur::operator+=(Vecteur const & v){
	x+=v.x; y+=v.y; z+=v.z;
	return *this;
}
const Vecteur operator + (Vecteur v, Vecteur const & u) {
	return v+=u;
}
Vecteur & Vecteur::operator-=(Vecteur const & v){
	x-=v.x; y-=v.y; z-=v.z;
	return *this;
}
const Vecteur operator - (Vecteur v, Vecteur const & u) {
	return v-=u;
}
/* --- */
const Vecteur Vecteur::operator -() const {
	return Vecteur(-x,-y,-z);
}
/* --- */
Vecteur & Vecteur::operator*=(double s) {
	x*=s; y*=s; z*=s;
	return *this;
}
const Vecteur operator*(Vecteur v, double s) {
	return v*=s;
}
const Vecteur operator*(double s, const Vecteur& v){
	return v*s;
}
double operator*(const Vecteur& u, const Vecteur& v) {
	return (u.getX()*v.getX()) + (u.getY()*v.getY()) + (u.getZ()*v.getZ());
}
/* --- */
double Vecteur::norme() const {
	return sqrt(*this * *this);
}
/* --- */
double angle(const Vecteur& v1, const Vecteur& v2)	{ 
	return acos((v1 * v2) / (v1.norme() * v2.norme())); 
}
/* ------------------------------------------------------------------ */
class Unitaire : public Vecteur {
	private :
		void normaliser() {
			const double n(Vecteur::norme());
			if (n == 0) {
				// Inutile de normaliser un vecteur -> on met un vecteur à la place
				*this = Unitaire(); // Appel au constructeur par défaut;
			} else {
				x/=n; y/=n; z/=n;
			}
		}
	public :
		Unitaire () : Vecteur(0,1,0) {};
		Unitaire (double a, double b, double c) : Vecteur(a,b,c) {normaliser();};
		Unitaire (Vecteur const & v) : Vecteur(v) {normaliser();};
		Unitaire & operator+=(Vecteur const &);
		Unitaire & operator-=(Vecteur const &);
		Unitaire & operator*=(double);
		double norme() const {return 1;}; 	
};
Unitaire & Unitaire::operator+=(Vecteur const & v){
	Vecteur::operator +=(v);
	normaliser();
	return *this;
	
}
Unitaire & Unitaire::operator-=(Vecteur const & v){
	Vecteur::operator -=(v);
	normaliser();
	return *this;
}
Unitaire & Unitaire::operator*=(double s){
	Vecteur::operator *=(s);
	normaliser();
	return *this;
	
}
double angle(const Unitaire& u, const Unitaire& b) const { return acos(u * v); }

/* ------------------------------------------------------------------ */
int main() {
	Vecteur u(1,2,-0.1);
	Vecteur v(2.6,3.5,4.1);
	cout << "u = " << u << endl;
	cout << "v = " << v << endl;
	cout << "***" << endl;
	cout << u << " + " << v << " = " << u + v << endl;
	cout << u << " - " << v << " = " <<u - v << endl;
	cout << "- " << u << " = " <<- u << endl;
	cout << "- " << u << " + " << v << " = " << - u + v << endl;
	cout << "***" << endl;
	cout << u << " x " << v << " = " << u * v << endl;
	cout << "2 x " << u << " = " << 2 * u << endl;
	cout << "***" << endl;
	cout << "||" << u << "|| = " << u.norme() << endl;
	cout << "||" << v << "|| = " << v.norme() << endl;
	cout << "||" <<u <<"+" << v << "||" <<"||" << (u+v) << "|| = " << (u+v).norme() << endl;
	cout << "***" << endl;
	cout << "angle(u,v) = " << angle(u,v) << endl;
	cout << "angle(v,u) = " << angle(v,u) << endl;
	cout << "***" << endl;
	Unitaire w(u);
	cout << "w = " << w << endl;
	cout << "||w|| = "<< w.norme() << endl;
	cout << "2*w-u = " << 2*w-u << endl;
	cout << "||2*w-u|| = "<< (2*w-u).norme() << endl;
	
    return 0;
}
