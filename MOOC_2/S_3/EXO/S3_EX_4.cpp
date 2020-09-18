
#include <iostream>
#include <vector>
using namespace std;
/* --- */
typedef size_t Degre;
/* --- */
class Polynome {
    private :
        // attributs privés
        vector<double> p;
		void simplifie();
    public :
        Polynome(double coef = 0.0, Degre degre = 0) : p(degre+1, 0.0) {p[degre] = coef;}; // monome coef * X^deg
		//
		Degre degre() const {return p.size()-1; };
		void affiche_coef(ostream &, Degre, bool = true) const;
		double top() const {return p[degre()];};
		//	Opérateurs internes
		//		-> Booléens
		bool operator==(const Polynome&) const;
		bool operator!=(const Polynome&) const;
		//		-> Addition
		Polynome & operator+=(const Polynome&);
		Polynome operator+(const Polynome&) const;
		//		-> Soustraction
		Polynome & operator-=(const Polynome&);
		Polynome operator-(const Polynome&) const;
		//		-> Multiplication de polynomes 
		Polynome& operator*=(const Polynome&);
		//		-> Mutltiplication par un scalaire
		Polynome operator-() const;						// Opposée
		
		
		
};
Polynome operator*(const double x, const Polynome& p);
// ----------------------------------------------------------------------
// ----------------------------------------------------------------------
void Polynome::simplifie() {
	while (!p.empty() && top() == 0) {
		p.pop_back();
	}
	if (p.empty()) {
		p.push_back(0.);
	}	
}
// ----------------------------------------------------------------------
// ----------------------------------------------------------------------
bool Polynome::operator==(const Polynome& q) const{
	return p == q.p;
}
bool Polynome::operator!=(const Polynome& q) const {
	return p != q.p;
}
// ----------------------------------------------------------------------
// ----------------------------------------------------------------------
Polynome & Polynome::operator+=(const Polynome& q){
	while (degre() < q.degre()) {
		p.push_back(0.);
	}
	for (Degre i(0); i <= q.degre(); ++i) {
		p[i] += q.p[i];
	}
	return *this;
}
Polynome Polynome::operator+(const Polynome& q) const{
	return Polynome(*this)+= q;
}
// ----------------------------------------------------------------------
// ----------------------------------------------------------------------
Polynome & Polynome::operator-=(const Polynome& q){
	while (degre() < q.degre()) {
		p.push_back(0.);
	}
	for (Degre i(0); i <= q.degre(); ++i) {
		p[i] -= q.p[i];
	}
	simplifie();
	return *this;
}
Polynome Polynome::operator-(const Polynome& q) const{
	return Polynome(*this)-= q;
}
// ----------------------------------------------------------------------
// ----------------------------------------------------------------------
Polynome& Polynome::operator*=(const Polynome& q) {
	return *this = Polynome(*this) * q;
}



// ----------------------------------------------------------------------
// ----------------------------------------------------------------------
Polynome Polynome::operator-() const{
	Polynome q;
	for (Degre i(0); i <= degre(); ++i){
		q.p.push_back(-p[i]);
	} 
	return q;
}




// ----------------------------------------------------------------------
// ----------------------------------------------------------------------




// ----------------------------------------------------------------------
// ----------------------------------------------------------------------



// ----------------------------------------------------------------------
// ----------------------------------------------------------------------
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
const Polynome operator*(double x, const Polynome& p) {
    return Polynome(p) *= x;
}


// ----------------------------------------------------------------------
void Polynome::affiche_coef(ostream& out, Degre puissance, bool signe) const {
    double const c(p[puissance]);
    if (c != 0.0) {
        if (signe and (c > 0.0)) {
            out << "+";
        }
        out << c;
        if (puissance > 1) {
            out << "*X^" << puissance;
        }
        else if (puissance == 1) {
            out << "*X";
        }
      } else if (degre() == 0) {
            // degré 0 : afficher quand même le 0 si rien d'autre
            out << 0;
      }
}
// ----------------------------------------------------------------------
ostream& operator<<(ostream& sortie, const Polynome& polynome) {
    // plus haut degré : pas de signe + devant
    Degre i(polynome.degre());
    polynome.affiche_coef(sortie, i, false);
    // degré de N à 0 : +a*X^i
    if (i > 0) {
          for (--i; i > 0; --i) {
              polynome.affiche_coef(sortie, i);
          }
          polynome.affiche_coef(sortie, 0);
     }
     return sortie;
}
// ======================================================================
int main() {
    Polynome p(3.2, 4);
	
	
	
	return 0;
}
