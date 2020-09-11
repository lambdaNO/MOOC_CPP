#include <iostream>

/*---*/
using namespace std;
/*---*/
class Papier {
	private : 
		unsigned int age_;
		unsigned int somme_;
	public :
		unsigned int age() const ;
		unsigned int somme() const ;
		void lire(unsigned int a, unsigned int s);
};
//
class Assistant {
	private : 
		unsigned int age_lu_;
		unsigned int somme_lu_;
		unsigned int calcul_;
	public : 
		void lire(Papier const & p);
		void calculer();
		unsigned int annoncer() const;
};
//
class Spectateur {
	private :
		unsigned int age_;
		unsigned int somme_;
		Papier papier_;
	public :
		void arriver();
		void ecrire();
		Papier montrer();
};
//
class Magicien {
	private :
		unsigned int age_devine_;
		unsigned int somme_devine_;
		void annoncer() const;
		void calculer(unsigned int resultat);
	public : 
		void tour(Assistant & a, Spectateur & s);
};



/*---*/
unsigned int Papier::age() const {
	return age_;
}
unsigned int Papier::somme() const {
	return somme_;
}
void Papier::lire(unsigned int a, unsigned int s) {
	age_ = a; somme_ = s;
}
//
void Assistant::lire(Papier const & p){
	cout << "[ASSISTANT] - Lecture " << endl;
	age_lu_	= p.age();
	somme_lu_ = p.somme();
}
void Assistant::calculer() {
	cout << "[ASSISTANT] - Calcul " << endl;
	calcul_ += age_lu_*2 +5;
	calcul_ *= 50;
	calcul_ += somme_lu_;
	calcul_ -= 365;
}
unsigned int Assistant::annoncer() const {
	cout << "[ASSISTANT] - Annonce " << calcul_ << endl;
	return calcul_;
}
//
void Spectateur::arriver() {
	cout << "[SPECTATEUR] - Arrive "<< endl;
	cout << "Age ? " << endl;
	cin >> age_;
	do {
		cout << "Somme en poche ? " << endl;
		cin >> somme_;
	} while (!(somme_ >= 0 && somme_ <= 99));
}
Papier Spectateur::montrer() {
	cout << "[SPECTATEUR] - Montrer "<< endl;
	return papier_;
}
void Spectateur::ecrire() {
	papier_.lire(age_,somme_);
}
//
void Magicien::annoncer() const{
	cout << "[MAGICIEN] "<< endl << "\t Age = " << age_devine_ << " ans." << endl<< "\t Somme = " << somme_devine_ << "." << endl;
}
void Magicien::calculer(unsigned int resultat) {
	resultat += 115;
	age_devine_ = resultat / 100;
	somme_devine_ = resultat % 100; 
}
void Magicien::tour(Assistant & a, Spectateur & s){
	cout << "[MAGICIEN] - Tour "<< endl;
	s.ecrire();
	a.lire(s.montrer());
	a.calculer();
	calculer(a.annoncer());
	annoncer();
}



/*---*/
int main() {
	Spectateur s;
	
	Assistant a; 
	Magicien m;
	s.arriver();
	m.tour(a,s);
	
	
	return 0;
}
