#include <iostream>
#include <vector>
#include <array>
using namespace std;
/* --- */
enum Couleur {vide = 0,rouge, jaune};
/* --- */
class Jeu {
	private :
		unsigned int compte(Couleur,size_t,size_t,int,int) const ;
	protected : 
		vector<vector<Couleur>> grille;
	
	public : 
		Jeu(size_t taille = 8);
		size_t get_taille() const {return grille.size();};
		bool jouer(size_t,Couleur); 
		Couleur gagnant() const ;
		bool fini(Couleur &) const;
		ostream & affiche(ostream &) const;


};

Jeu::Jeu(size_t taille) : grille(taille, vector<Couleur>(taille, vide)) {}
bool Jeu::jouer(size_t c, Couleur col) {
	if (col == vide) {return false;}		// Cas de couleur vide - erreur de saisie;
	if (c >= get_taille()) {return false;}	// On commence à 0 + colonne pleine;
	//
	size_t i(0); 
	while (i<get_taille() && grille[c][i] != vide) {++i;} 	// On récupère la dernière ligne non vide (la position la plus basse)
	if (i>= get_taille()) {return false;}					// la colonne est pleine 
	grille[c][i] = col;										// si on ne s'est pas arrêté avant, on rempli la cellule;
	return true;											// si aucun cas d'arret n'a été détecté avant -> on a pu joueur;
}
Couleur Jeu::gagnant() const {
	Couleur win(vide);
	for (size_t i(0); i < grille.size(); ++i) {
		for (size_t j(0); j < grille[i].size(); j++) {
			if (grille[i][j] != vide) {
				win = grille[i][j];	
				for (int di(0); di <= 1; ++di) {
					for (int dj(0); dj <= 1; ++dj) {
						if (compte(win,i,j,di,dj) >= 4) {
							return win;
						}
					}
				}	
			}
	
		}
	}
	return vide;			// On a rien trouvé avant;
}
unsigned int Jeu::compte(Couleur c,size_t i,size_t j,int di,int dj) const {
	unsigned int n(0);
	if (di != 0 && dj != 0) {
		for (i+= di, j+=dj; i < get_taille() && j < get_taille() && grille[i][j] == c; i+= di, j+= dj) {
			++n;
		}
	}
	return n;
	
}
bool Jeu::fini(Couleur & res) const {
	res = gagnant();
	if (res == vide) {
		for (auto l : grille) {
			for (auto c : l) {
				if (c == vide) {
					return false;
				}
			}
		}
	}
	return true;
}

ostream & Jeu::affiche(ostream & out) const {
	if (get_taille() > 0) { 
		size_t j(get_taille()-1); 
		do {
			for (size_t i(0); i < get_taille(); ++i) { 
				switch (grille[i][j]) {
					case vide 	: out << ' '; break;
					case rouge  : out << '#'; break;
					case jaune  : out << 'O'; break;
				}
			}
			out << endl;
		} while (j-- != 0); 
		for (size_t i(0); i < get_taille(); ++i) {out << '-';} out << endl;
		for (size_t i(1); i <= get_taille(); ++i) {out << i;} out << endl;
	}
	return out;
}
ostream & operator <<(ostream & out, Jeu const & j) {
	return j.affiche(out);
}

/* --- */
class Joueur {
	
	private : 

	protected :
		string nom;
		Couleur col;
	public :
		Joueur(string n, Couleur c = rouge) : nom(n), col(c) {}
		virtual ~Joueur() {cout << "A+ " << nom << endl; }
		virtual void jouer(Jeu &) const = 0;
		string get_Nom() const {return nom;}
		Couleur get_Couleur() const {return col;} 
};
class Humain : public Joueur {
	private : 
	
	protected : 
	
	public : 
		Humain(Couleur c = rouge) : Joueur("x",c) {
			cout << "Votre nom ? "; cin >> nom;
			char pion = get_Couleur() == 1 ? '#':'O';
			cout << "Bienvenu " << get_Nom() << ", tu auras les pions " << pion << endl;
		}
		void jouer(Jeu&) const override;
	
};

void Humain::jouer(Jeu & j) const {
	cout << j << endl;
	size_t lu;
	bool valide(false);
	do {
		cout <<"-> " << get_Nom() << " : saisir un numéro de colonne entre 1 et " << j.get_taille();	cin >> lu; --lu;
		valide = j.jouer(lu,col);
		if (!valide) {cout << "\t recommencer."<<endl;}
	} while (!valide);
};

class Ordi : public Joueur {
	private : 
	protected :
	public : 
		Ordi (Couleur c = jaune) : Joueur ("Ava", c) {};
		void jouer(Jeu&) const override;
};

void Ordi::jouer(Jeu & j) const {
	// Mieux implémenter cette méthode
	for (size_t i(0); i < j.get_taille(); ++i) {
		if (j.jouer(i, col)) {
			cout << nom << " a joué en " << i+1 << endl; 
			return;
		} 
	}
}

/* --- */
class Partie {
	protected : 
		array<Joueur const *,2> joueurs;
		Jeu jeu;
	public : 
		Partie(Joueur const * j1, Joueur const * j2) {joueurs[0] = j1; joueurs[1] = j2;}
		~Partie() {vider();}
		void lancer();
		void vider();
};

void Partie::vider() {
	for (auto j : joueurs) {delete j; j = nullptr;}
}

void Partie::lancer() {
	unsigned int tour(0); Couleur vainqueur;
	do {
		joueurs[tour]->jouer(jeu);
		tour=1-tour; 
	} while (not jeu.fini(vainqueur));
	cout << "La partie est finie." << endl;
	cout << jeu << endl;
	if (vainqueur == joueurs[0]->get_Couleur()) {
		cout << "Le vainqueur est " << joueurs[0]->get_Nom() << endl; 
	} else if (vainqueur == joueurs[1]->get_Couleur()) {
		cout << "Le vainqueur est " << joueurs[1]->get_Nom() << endl; 
	} else {
		cout << "Match nul." << endl; 
	}
}




int main() {
    Partie p(new Ordi(rouge), new Humain(jaune)); 
    p.lancer();
	p.vider();
}
