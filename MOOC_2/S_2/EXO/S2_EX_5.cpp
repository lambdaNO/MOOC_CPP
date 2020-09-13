#include <iostream>
#include <vector>
using namespace std;
// ======================================================================
class Article {
	private : 
		const string nom;
		double prix;
		bool solde;
	public : 
		Article(string const & n, double p, bool s = false) : nom(n), prix(p), solde(s) {};
		//~Article();
		string getNom() const {return nom;}
		double getPrix() const {return prix;}
		bool getSolde() const {return solde;}
};

class Achat {
	private : 
		const Article item;
		const unsigned int quantite;
	public : 
		Achat(Article const & a, unsigned int q = 1) : item(a), quantite(q) {};
		double prix() const {
			double prix = item.getPrix()*quantite;
			if (item.getSolde()) { prix *= 0.5;}
			return prix;
		}
		void affiche() const {
			cout << item.getNom() << " : " << item.getPrix() << " x " << quantite << " = " << prix() << "€ ";
			if (item.getSolde()) { cout << " (soldé)";}
			cout << endl;
		}	
};

class Caddie {
	private : 
		vector<Achat> achats;
	public : 
		// Constructeur minimal suffit 
		void remplir(Article const & a, unsigned int q = 1) {
			achats.push_back(Achat(a,q));
		}
		double total() const {
			double t(0.);
			for (auto const & a : achats) {
				a.affiche();
				t+= a.prix();
			}
			return t;
		}

		
		
};

class Caisse {
	private :
		double montant;
	public :
		Caisse() : montant(0.) {};
		void scanner(Caddie const & c) {
			double total_caddie(c.total());
			montant += c.total();
			cout << "-----" << endl;
			cout << "Total à payer : " << total_caddie << " €." << endl;
		}
		void afficher() {
			cout << montant <<  " €.";
		}
	
};





// ======================================================================
int main() {
	// Les articles vendus dans le supermarché
	Article choufleur ("Chou-fleur extra"      ,  3.50 );
	Article roman     ("Les malheurs de Sophie", 16.50, true );
	Article camembert ("Cremeux 100%MG"        ,  5.80 );
	Article cdrom     ("C++ en trois jours"    , 48.50 );
	Article boisson   ("Petit-lait"            ,  2.50, true);
	Article petitspois("Pois surgeles"         ,  4.35 );
	Article poisson   ("Sardines"              ,  6.50 );
	Article biscuits  ("Cookies de grand-mere" ,  3.20 );
	Article poires    ("Poires Williams"       ,  4.80 );
	Article cafe      ("100% Arabica"          ,  6.90, true);
	Article pain      ("Pain d'epautre"        ,  6.90 );	
	
	// Les caddies du supermarché, disons 3 ici
	vector<Caddie> caddies(3);

	// Les caisses du supermarché, disons 2
	vector<Caisse> caisses(2);
	// Les clients font leurs achats :
	// le second argument de la méthode remplir correspond à une quantité
	
	// remplissage du 1er caddie
	caddies[0].remplir(choufleur, 2);
	caddies[0].remplir(cdrom       );
	caddies[0].remplir(biscuits , 4);
	caddies[0].remplir(boisson  , 6);
	caddies[0].remplir(poisson  , 2);

	// remplissage du 2eme caddie
	caddies[1].remplir(roman        );
	caddies[1].remplir(camembert    );
	caddies[1].remplir(petitspois, 2);
	caddies[1].remplir(poires    , 2);

	// remplissage du 3eme caddie
	caddies[2].remplir(cafe     , 2);
	caddies[2].remplir(pain        );
	caddies[2].remplir(camembert, 2);
	
	// Les clients passent à la caisse :
	caisses[0].scanner(caddies[0]);
	cout << "=========================================" << endl;
	caisses[0].scanner(caddies[1]);
	cout << "=========================================" << endl;
	caisses[1].scanner(caddies[2]);
	cout << "=========================================" << endl;
	// Affichage du résultat des caisses
	cout << "Résultats du jour :" << endl;
	for (size_t i(0); i < caisses.size(); ++i) {
		cout << "Caisse " << i+1 << " : " ;
		caisses[i].afficher();
		cout << endl;
	}
	return 0;
}
