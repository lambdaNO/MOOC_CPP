#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*******************************************
 * Completez le programme a partir d'ici.
 *******************************************/
class Auteur {
	private : 
		string nom;
		bool prix;
	public : 
		Auteur(string n, bool p = false ) : nom(n), prix(p) {}
		Auteur(Auteur const &  a) : nom(a.getNom()), prix(a.getPrix()) {}
		string getNom() const {return nom;}
		bool getPrix() const {return prix;}
		
}; 
class Oeuvre{
	private : 
		string titre;
		Auteur * auteur;
		string langue;
	public : 
		Oeuvre(string t, Auteur & a, string l) : titre(t), auteur(&a), langue(l){}
		Oeuvre(Auteur const &) = delete;
		~Oeuvre(){ cout << "L'oeuvre \""<<titre<<", "<<auteur->getNom()<<", en "<<langue<<"\" n'est plus disponible."<<endl; }
		string getTitre() const {return titre;}
		Auteur& getAuteur() const {return *auteur;}
		string getLangue() const {return langue;}
		void affiche() const {cout <<titre<<", "<<auteur->getNom()<<", en "<<langue<<endl;}
	
};
class Exemplaire{
	private : 
		Oeuvre * oeuvre;
	public : 
		Exemplaire(Oeuvre & o) : oeuvre(&o) {cout << "Nouvel exemplaire de : "<<oeuvre->getTitre()<<", "<<oeuvre->getAuteur().getNom()<<", en "<<oeuvre->getLangue()<<endl;}
		Exemplaire(Exemplaire const & o) : oeuvre(o.oeuvre){cout << "Copie d'un exemplaire de : "<<oeuvre->getTitre()<<", "<<oeuvre->getAuteur().getNom()<< " en " << oeuvre->getLangue()<<endl;}
		~Exemplaire() {cout << "Un exemplaire de \""<<oeuvre->getTitre()<<", "<<oeuvre->getAuteur().getNom()<<", en "<< oeuvre->getLangue()<<"\" a été jeté !"<<endl;}
		Oeuvre& getOeuvre() const {return *oeuvre;}
		void affiche() const {cout << "Exemplaire de : " << oeuvre->getTitre()<<", "<<oeuvre->getAuteur().getNom()<<", en "<<oeuvre->getLangue()<<endl;}
};
class Bibliotheque {
	private : 
		vector<Exemplaire*> exemplaires;
		string nom;
	public : 
		Bibliotheque(string n) : nom(n) {cout << "La bibliothèque "<<nom<<" est ouverte !" << endl;}
		~Bibliotheque() {cout << "La bibliothèque "<<nom<<" ferme ses portes,"<<endl<<"et détruit ses exemplaires :" << endl;
			for (size_t i(0) ; i < exemplaires.size() ; ++i) {
				delete exemplaires[i]; exemplaires[i] = nullptr; 
			}
		}
		
		string getNom() const {return nom;}
		void stocker(Exemplaire ex, int n = 1);
		void lister_exemplaires(string lang = "") const; 
		unsigned int compter_exemplaires(Oeuvre & o) const;	
		void afficher_auteurs(bool s = false) const;
};
 
void Bibliotheque::stocker(Exemplaire ex, int n ){
	for (size_t i(0); i < n ; ++i ){
		Exemplaire * e = new Exemplaire(ex);
		exemplaires.push_back(e);
	} 
} 
void Bibliotheque::lister_exemplaires(string lang) const {
	for (size_t i(0); i < exemplaires.size(); ++i){
		if (lang == "" || lang == exemplaires[i]->getOeuvre().getLangue() ){
			exemplaires[i]->affiche();
		}
	}
} 
unsigned int Bibliotheque::compter_exemplaires(Oeuvre & o) const {
	unsigned int nb(0);
	for (size_t i(0); i < exemplaires.size(); ++i) {
		if (o.getTitre() == exemplaires[i]->getOeuvre().getTitre()) {
			++nb;
		}
	}
	return nb;
}	
void Bibliotheque::afficher_auteurs(bool s) const{
	for (size_t i(0); i < exemplaires.size(); ++i) {
		if (!s) {
			cout << exemplaires[i]->getOeuvre().getAuteur().getNom() << endl;
		} else {
			if (exemplaires[i] -> getOeuvre().getAuteur().getPrix() ) {
				cout << exemplaires[i]->getOeuvre().getAuteur().getNom() << endl;
			}
		}
	}
}

/*******************************************
 * Ne rien modifier apres cette ligne.
 *******************************************/

int main()
{
  Auteur a1("Victor Hugo"),
         a2("Alexandre Dumas"),
         a3("Raymond Queneau", true);

  Oeuvre o1("Les Misérables"           , a1, "français" ),
         o2("L'Homme qui rit"          , a1, "français" ),
         o3("Le Comte de Monte-Cristo" , a2, "français" ),
         o4("Zazie dans le métro"      , a3, "français" ),
         o5("The Count of Monte-Cristo", a2, "anglais" );

  Bibliotheque biblio("municipale");
  biblio.stocker(o1, 2);
  biblio.stocker(o2);
  biblio.stocker(o3, 3);
  biblio.stocker(o4);
  biblio.stocker(o5);

  cout << "La bibliothèque " << biblio.getNom()
       << " offre les exemplaires suivants :" << endl;
  biblio.lister_exemplaires();

  const string langue("anglais");
  cout << " Les exemplaires en "<< langue << " sont :" << endl;
  biblio.lister_exemplaires(langue);

  cout << " Les auteurs à succès sont :" << endl;
  biblio.afficher_auteurs(true);

  cout << " Il y a " << biblio.compter_exemplaires(o3) << " exemplaires de "
       << o3.getTitre() << endl;

  return 0;
}
