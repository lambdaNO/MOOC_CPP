#include <iostream>
#include <vector>
using namespace std;
/* --- */
class Livre {
	private : 
	
	protected : 
		string titre;
		string auteur;
		unsigned int pages;
		bool bestseller;
	public :
		Livre(string t, string a, unsigned int p = 0, bool b = false) : titre(t), auteur(a), pages(p), bestseller(b) {};
		virtual ~Livre() {};
		virtual void afficher() const;
		virtual double calculer_prix() const;
};

void Livre::afficher() const {
	string is_BS = bestseller ? "oui":"non";
	cout << titre << " - " << auteur << " - #(pages) : " << pages << " - Bestseller : " << is_BS << " - " << calculer_prix() << "€" << endl;
}
double Livre::calculer_prix() const {
	double base(pages*0.3);
	base += (bestseller ? 50:0);
	return base;
}
/* --- */
class Roman : public Livre {
	private : 
	
	protected : 
		bool bibliographie;
	public : 
		Roman (string t, string a, unsigned int p, bool b, bool bib = false) : Livre(t,a,p,b), bibliographie(bib) {};
		virtual ~Roman(){};
		void afficher() const override;
};

void Roman::afficher() const {
	Livre::afficher();
	string is_Bib = bibliographie ? "oui":"non";
	cout << "\tType : roman - bibliographie = " << is_Bib <<endl;
}
/* --- */
class Policier : public Roman {
	private : 
	
	protected : 
	
	public : 
		using Roman::Roman;
		virtual ~Policier() {};
		void afficher() const override;
		double calculer_prix() const override;
};

void Policier::afficher() const {
	Livre::afficher();
	cout << "\tType : policier." <<endl;
}

double Policier::calculer_prix() const {
	double p(Livre::calculer_prix() - 10.);
	if (p<= 0) {p =1.;}
	return p;
}
/* --- */
class BeauLivre : public Livre {
	private :
	
	protected : 
		
	public : 
		using Livre::Livre;
		double calculer_prix() const override;
		void afficher() const override;
};

double BeauLivre::calculer_prix() const {
	return Livre::calculer_prix() + 30;
};
void BeauLivre::afficher() const {
	Livre::afficher();
	cout << "\tType : beau livre." <<endl;
}
/* --- */
class Librairie {
	private :
		vector<Livre *> livres;
	protected :
	
	public : 
		void ajouter_livre(Livre*);
		void vider_stock();
		void afficher() const;
	
};

void Librairie::ajouter_livre(Livre * l) {
	livres.push_back(l);
}
void Librairie::vider_stock() {
	for (auto l : livres) { delete l; l = nullptr;}
	livres.clear();
}
void Librairie::afficher() const {
	if (!livres.empty()) {
		for (auto const & l : livres) {
			l->afficher();
		}
	} else {
		cout << "Vide ! " << endl;
	}
	
}









/* --- */

int main() {
	/*
	Livre l1("Harry Potter à l'école des sorciers","J.K. Rowling",308,true);
	Livre l2("Le fou","Gogol",252,false);
	l1.afficher();
	l2.afficher();
	Roman r1("Le baron perche", "I. Calvino", 283, false, false);
	r1.afficher();
	BeauLivre b1("Fleuves d'Europe", "C. Osborne", 150, false);
	b1.afficher();
	*/
	Librairie l;
	l.ajouter_livre(new Policier("Le chien des Baskerville", "A.C.Doyle", 221, false, false));
	l.ajouter_livre(new Policier("Le Parrain ", "A.Cuso", 367, true, false));
	l.ajouter_livre(new Roman("Le baron perche", "I. Calvino", 283, false, false));
	l.ajouter_livre(new Roman ("Memoires de Geronimo", "S.M. Barrett", 173, false, true));
	l.ajouter_livre(new BeauLivre ("Fleuves d'Europe", "C. Osborne", 150, false));
	l.afficher(); l.vider_stock(); l.afficher();

    return 0;
}
