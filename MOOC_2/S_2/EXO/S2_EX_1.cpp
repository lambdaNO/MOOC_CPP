#include <iostream>
using namespace std;
/* ---- */
class Peluche {
	private :
		string nom;
		string espece;
		double prix;
	public : 
		// Constructeur explicite
		Peluche(string n, string e, double p) : nom(n), espece(e), prix(p) {cout << "[FABRICATION -> PELUCHE("<<nom<<")] "<< endl;};
		// Constructeur de copie
		Peluche(Peluche	const & x) : nom(x.nom+"-copie"), espece(x.espece), prix(x.prix) {cout << "[FABRICATION -> COPIE -> PELUCHE("<<nom<<")] "<< endl;};
		// Destructeur
		~Peluche() {cout << "[DESTRUCTION -> PELUCHE("<<nom<<")] "<< endl;};
		
		// Getter & Setter
		string getNom() const {return nom;}
		string getEspece() const {return espece;}
		double getPrix() const {return prix;}
		void setPrix(double p) {prix = p;}
	
	
};
/* --- */
void etiquette(Peluche const & p) {
	cout << "[ETIQUETTE -> PELUCHE] nom = " << p.getNom() << "\t espece = " << p.getEspece() << "\t prix = " << p.getPrix() << "."<< endl;
}







/* ---- */
int main(){
	Peluche bobo("Bobo", "ours",  14.95);
	Peluche baba(bobo);
	etiquette(bobo);
	Peluche* bello; { // pas encore d'objet, juste un pointeur 
		Peluche ssss("cobra", "Ssss", 10.00);
		bello = new Peluche("toucan", "Bello", 20.00);
	}
	Peluche bello_clone(*bello); 
	etiquette(bello_clone); 
	delete bello;
	
	return 0;
}
