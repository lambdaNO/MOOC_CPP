#include <iostream>
using namespace std;
/* --- */
class Complexe{
	private : 
		double Re;
		double Im;
		void setRe(double r) {Re = r;}
		void setIm(double i) {Im = i;}
		//
		
	
	public : 
		Complexe(double r = 0., double i = 0.) : Re(r), Im(i) {};
		~Complexe(){};
		double getRe() const {return Re;}
		double getIm() const {return Im;}
		//
		ostream & affiche(ostream & out) const;
		//
		bool operator==(Complexe const & c) const;
		//
		Complexe & operator+=(Complexe const & c);						// Retourne le complexe modifié par +=
		Complexe operator+(Complexe const & c);							// Fait appel à l'opérateur += retournant le complexe modifié
		Complexe & operator-=(Complexe const & c);						// Retourne le complexe modifié par -=
		Complexe operator-(Complexe const & c);							// Fait appel à l'opérateur -= retournant le complexe modifié
		Complexe & operator*=(Complexe const & c);						// Retourne le complexe modifié par *=
		Complexe operator*(Complexe const & c);							// Fait appel à l'opérateur *= retournant le complexe modifié
		Complexe & operator /=(Complexe const & c);
		Complexe operator /(Complexe const & c);
		
		
	
};
ostream & Complexe::affiche(ostream & out) const {
	return out <<"( " << Re << " + " << Im << " * i ) ";
}
ostream & operator <<(ostream & out, Complexe const & c) {
	return c.affiche(out);
}
bool Complexe::operator ==(Complexe const & c) const {
	return (getRe() == c.getRe() && getIm() == c.getIm());
}
//
Complexe & Complexe::operator +=(Complexe const & c) {
	setRe(getRe() + c.getRe());
	setIm(getIm() + c.getIm());
	return *this;
}
Complexe Complexe::operator +(Complexe const & c) {
	return *this+=c;
	//return Complexe(*this)+=c;
}
//
Complexe & Complexe::operator -=(Complexe const & c) {
	setRe(getRe() - c.getRe());
	setIm(getIm() - c.getIm());
	return *this;
}
Complexe Complexe::operator -(Complexe const & c) {
	return *this-= c;
	//return Complexe(*this)-=c;
}
//
Complexe & Complexe::operator *=(Complexe const & c) {
	double tmp_Re(getRe());
	setRe(getRe() * c.getRe() - getIm() * c.getIm());
	setIm(tmp_Re*c.getIm() + getIm()*c.getRe());
	return *this;
}
Complexe Complexe::operator *(Complexe const & c) {
	return *this*=c;
	//return Complexe(*this)*=c;
}
//
Complexe & Complexe::operator /=(Complexe const & c) {
	double tmp_Re(getRe());
	double tmp_Cr(c.getRe()*c.getRe()+ c.getIm()*c.getIm());
	setRe(( getRe() * c.getRe() + getIm() * c.getIm() ) / tmp_Cr); 
	setIm(( getIm() * c.getRe() - tmp_Re * c.getIm() ) / tmp_Cr); 
	return *this;
}
Complexe Complexe::operator /(Complexe const & c) {
	return *this/=c;
	//return Complexe(*this)/=c;
}



//	OPERATEUR EXTERNE :  DOUBLE COMPLEXE
//		-> Transformation de double en complexe à l'aide du constructeur;
Complexe operator-(double const d, Complexe const & c) {
	return (Complexe(d) - c);
}
Complexe operator+(double const d, Complexe const & c) {
	return (Complexe(d) + c);
}
Complexe operator *(double const d, Complexe const & c) {
	return (Complexe(d) * c);
}
Complexe operator /(double const d, Complexe const & c) {
	return (Complexe(d) / c);
}





/* --- */
int main() {
	Complexe defaut;
	Complexe zero(0.0, 0.0);
	Complexe un(1.0, 0.0);
	Complexe i(0.0, 1.0);
	Complexe j;
	/* --- */
	cout <<"Defaut = "<< defaut << endl;
	cout <<"Zero = "<< zero << endl;
	cout <<"Un = " << un << endl;
	cout <<"i = " << i << endl;
	cout <<"j = " << j << endl;
	cout << zero << " ==? " << defaut;
	if (zero == defaut) cout << " oui" << endl; else cout << " non" << endl;
	cout << zero << " ==? " << i;
	if (zero == i) cout << " oui" << endl; else cout << " non" << endl;
	j = un + i;
	cout << un << " + " << i << " = " << j << endl;
	Complexe trois(un);
	trois += un;
	trois += 1.0;
	cout << un << " + " << un << " + 1.0 = " << trois << endl;
	Complexe deux(trois);
	deux -= un;
	cout << trois << " - " << un << " = " << deux << endl;
	trois = 1.0 + deux;
	cout << "1.0 + " << deux << " = " << trois << endl;
	Complexe z(i*i);
	cout << i << " * " << i << " = " << z << endl; 
	cout << z << " / " << i << " = " << z/i << " = "; 
	cout << (z/=i) << endl;
	Complexe k(2.0,-3.0); z = k;
	z *= 2.0;
	z *= i;
	cout << k << " * 2.0 * " << i << " = " << z << endl;
	z = 2.0 * k * i / 1.0;
	cout << " 2.0 * " << k << " * " << i << " / 1 = " << z << endl;
	
	return 0;
}

