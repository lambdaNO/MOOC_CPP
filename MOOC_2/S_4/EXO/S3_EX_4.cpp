#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
/* ------------------------------------------------------------------ */
class EnsembleFini {
	protected : 
		unsigned int p;
	public : 
		EnsembleFini(unsigned int p) : p(p) {};
		//~EnsembleFini();
};
/* ------------------------------------------------------------------ */
class Groupe : public EnsembleFini {
	protected :
	//
	public :
		Groupe(unsigned int p) : EnsembleFini(p) {};
		unsigned int add(unsigned int, unsigned int) const;
};
unsigned int Groupe::add(unsigned int x, unsigned int y) const{
	return (x+y)%p;
}
/* ------------------------------------------------------------------ */
class Anneau : public Groupe {
	protected :
	//
	public : 
		Anneau(unsigned int p) : Groupe(p) {};
		unsigned int mult(unsigned int, unsigned int) const;
	
};
unsigned int Anneau::mult(unsigned int x, unsigned int y) const {
	return (x*y)%p;
}
/* ------------------------------------------------------------------ */
class Corps : public Anneau {
	protected : 
	//
	public :
		Corps(unsigned int p) : Anneau(p) {};
		unsigned int inv(unsigned int) const;
		unsigned int div(unsigned int, unsigned int) const;
};
unsigned int Corps::inv(unsigned int x) const {
	
	if (x != 0) {
		int y(p);
		int p_u(1), u(0), n_u(0), q(0), r(0);
		while (y != 1) {
			q = x/y;
			r = x%y;
			x = y;	y = r;
			n_u = p_u - q*u;
			p_u = u;
			u = n_u;
		}
		return (u+p)%q;
	} else {
		return 0;
	}	
}
unsigned int Corps::div(unsigned int x, unsigned int y) const {
	return Anneau::mult(x,inv(y));
}
/* ------------------------------------------------------------------ */
int main() {
	Corps k(5); // c'est le corps Z/5Z
	cout<<"0+1="<<k.add(0,1) << endl;
	cout<<"3+3="<<k.add(3,3) << endl;
	cout << "3*2=" << k.mult(3, 2) << endl;
	cout << "1/2=" << k.inv(2) << endl;
	cout << "3*4=" << k.mult(3, 4) << endl;
    return 0;
}
