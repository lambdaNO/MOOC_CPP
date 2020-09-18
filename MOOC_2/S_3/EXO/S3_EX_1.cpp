#include <iostream>
#include <vector>
using namespace std;
/* --- */
typedef size_t Degre;
/* --- */
class Polynome {
	private : 
		// Vecteur des coefficient P[i] = a <-> aX^{i};
		vector<double> p;
		// la multiplication aura besoin d'accéder à p
		friend const Polynome operator*(Polynome p, const Polynome& q);
	public : 
		// Constructeur par défaut
		//Polynome() : p(1, 0.0) {}
		//Polynome(double c) : p(1, c) {}
		Polynome(double coef = 0.0, Degre degre = 0);					// P[d] = c		et 		P[d+1] = 0. (On est sûr d'avoir un polynom de degré maximal;	
		Degre degre() const;
		void affiche_coef(ostream & out, Degre degre, bool signe = true) const ;

		Polynome& operator*=(Polynome const&);
		Polynome& operator*=(double q);
	
};
/* --- */
Polynome::Polynome(double coef, Degre deg): p(deg+1, 0.0){ // garantit que le degré de p est deg

	p[deg] = coef; // change la valeur du coef de plus haut degre
}
//
Degre Polynome::degre() const {
	return p.size() - 1;
}
//
void Polynome::affiche_coef(ostream & out, Degre d, bool signe) const {
	//
	double const c(p[d]);
	if (c != 0) {
		if (c > 0 && signe) {
			out << " + ";
		}
		out << c;
		if (d > 1) {
			out << " * X^"<<d;
		} else if (d == 1) {
			out << "* X ";
		}
	} else if (degre() == 0) {
		out << 0;
	}
}
//
// la multiplication aura besoin d'accéder à p -> FRIEND
const Polynome operator*(Polynome p, const Polynome& q);
const Polynome operator*(Polynome p, const Polynome& q) {
	const Degre dp(p.degre());
	const Degre dq(q.degre());
	// Prépare la place pour le polynome résultat (de degre p.degre()+q.degre()). 
	Polynome r(0.0, dp + dq);
	// fait le calcul
	for (Degre i(0); i <= dp; ++i){
		for (Degre j(0); j <= dq; ++j) {
			r.p[i+j] += p.p[i] * q.p[j];
		}
	}
	// retourne le resultat
	return r;
}
//*this * q : fait la multiplication de l'instance courante (*this) par l'instance q en utilisant la multiplication externe précédemment définie ;
//*this = .. : affecte le résultat de cette multiplication à l'instance courante ;
//return (...) : et retourne la «valeur» (Polynome) en question.
Polynome& Polynome::operator*=(Polynome const& q) { 
	return (*this = *this * q);
}
// 
Polynome& Polynome::operator*=(double q){
	for (Degre i(0); i < degre(); ++i) {
		p[i] *= q;
	}
	return *this;
}
//
const Polynome operator*(Polynome p, double x) {
	return p *= x; 
}
//
const Polynome operator*(double x, const Polynome& p) {
	return Polynome(p) *= x; 
}
//
ostream & operator <<(ostream & out, Polynome const & P) {
	Degre i(P.degre());
	P.affiche_coef(out,i,false);
	if (i>0) {
		for (i--; i>0; i--) {
			P.affiche_coef(out,i);
		} 
		P.affiche_coef(out,0);
	}
	return out;
}



/* --- */




/* --- */
int main() {
	//Polynome p;
	Polynome p2(3.2, 4);
	cout << p2 << endl;
	cout << p2*p2 << endl;
	p2*=p2;
	cout << p2 << endl;
	Polynome p3(100*p2);
	cout << p3 << endl;
	cout << 4*p2 << endl;
	
	
	return 0;
}
