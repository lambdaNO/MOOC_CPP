#include <iostream>
#include <vector>
#include <array>
using namespace std;
/* --- */
// Comment représenter la grille ?  Dimensions fixe (6 lignes et 7 colonnes) -> Array
//                                  -> array<array<type,7>,6> grille
// Comment représenter les pions ?
//									-> int avec Vide = 0, Rouge = 1, Jaune = 2;						
//									-> char avec Vide = ' ', 'X' = Rouge, 'O' = Jaune;
//									Problème avec les deux représentations : Rien n'empêche d'utiliser d'autres valeur (3, 4 ou 'Y', 'Z', ...)
//									=> type enum 
//										Syntaxe : enum Type {nom_1, nom_2, ...};


/* --- */
constexpr int nbL(6),nbCol(7);
enum Couleur {vide,rouge,jaune};
typedef array<array<Couleur,nbCol>,nbL> Grille; 
/* --- */
void initialise(Grille& g);
void affiche(Grille const& g);
bool joue_V1(Grille & g, size_t const & col,Couleur const &  joueur);
bool joue_V2(Grille & g, size_t const & col,Couleur const &  joueur);
bool joue_V3(Grille & g, size_t const & col,Couleur const &  joueur);
bool joue(Grille & g, size_t const & col,Couleur const &  joueur);
void demande_et_joue(Grille & g, Couleur joueur);
bool est_ce_gagne(Grille const & g,Couleur const & joueur);
unsigned int compte(Grille const & g, size_t lig_dep, size_t col_dep, int dir_lig, int dir_col);
bool plein(Grille const & g);


/* --- */
int main() {
	Grille grille;
	initialise(grille);
	affiche(grille);
	bool gagne(false);
	//
	Couleur player(jaune);
	//
	do {
		demande_et_joue(grille,player);
		affiche(grille);
		gagne = est_ce_gagne(grille,player);
		if (player == jaune) {
			player = rouge;
		} else {
			player = jaune;
		}
	} while (!gagne && ! plein(grille));
	//
	if (!plein(grille)) {
		if (player == jaune) {
			cout << "Le joueur O a gagné !" << endl;
		} else {
			cout << "Le joueur X a gagné !" << endl;
		}
	} else {
		cout << "Match nul !" << endl;
	}
	
	
	
	return 0;
};
/* --- */
void initialise(Grille & g){
	for (auto & l : g){
		for (auto & c : l) {
			c = vide;
		}
	}
}
//
void affiche(Grille const& g){
	cout << endl;
	for (auto l : g){
		cout << " |";
		for (auto c : l) {
			char p;
			switch(c) {
				case vide :  p= ' '; break;
				case rouge : p= 'O'; break;
				case jaune : p= 'X'; break;
			}
			cout << p << "|";
		}
		cout << endl;
	}
	cout << "=";
	for (size_t i(0); i < g[0].size(); ++i) {
		cout << "=" << i+1;
	}
	cout << "==";
	cout << endl << endl;
}
//
bool joue_V1(Grille & g, size_t const & col,Couleur const &  joueur){
	// Recherche première position libre dans la colonne (en partant du bas)
	size_t ligne(g.size()-1);
	bool full(false);
	while (g[ligne][col] != vide && !full) {
		if (ligne == 0) {
			full = true;
		} else {
			--ligne;
		}
	}
	if (!full){
		g[ligne][col] = joueur;
		return true;
	} else {
		return false;
	}
}
//
bool joue_V2(Grille & g, size_t const & col,Couleur const &  joueur){
	// Tester la possibilité d'un coup avant d'envisager de modifier la grille 
	if (g[0][col] != vide) {
		return false;
	} else {
		size_t ligne(g.size()-1);
		while (g[ligne][col] != vide) {
			--ligne;
		}
		g[ligne][col] = joueur;
		return true;
	}
}
//
bool joue_V3(Grille & g, size_t const & col,Couleur const &  joueur){
	size_t ligne(g.size()-1);	
	while (ligne < g.size() && g[ligne][col] != vide ) {
		--ligne;
	}
	if (ligne < g.size()){
		g[ligne][col] = joueur;
		return true;
	} else {
		return false;
	}
}
//
bool joue(Grille & g, size_t const & col,Couleur const &  joueur){
	if (col >= g[0].size()) {return false;	}
	if (g[0][col] != vide) {return false;	}
	size_t ligne(g.size() - 1);
	while (g[ligne][col] != vide) {
		--ligne;
	}
	g[ligne][col] = joueur;
	return true;
}
//
void demande_et_joue(Grille & g, Couleur player){	
	cout << "Joueur ";
	if (player == jaune) {
		cout << " X ";
	} else {
		cout << " 0 ";
	}
	cout << ": Saisir un numéro de colonne [1,7] : ";
	bool valide(false);
	do {
		size_t col; 
		cin >> col;
		col--;			// Décrément pour partir de 0;	
		valide = joue(g,col,player);
		if (!valide){
			cout << "\t=> Coup non valide !" << endl;
		}
	} while (!valide);
		
}

//
bool est_ce_gagne(Grille const & g,Couleur const & joueur){
	for (size_t lig(0); lig < g.size(); ++lig){
		for (size_t col(0); col<g[lig].size(); ++col) {
			Couleur	coul_case(g[lig][col]);
			if (coul_case == joueur) {
				if ( 
					// diagonale vers le haut vers la droite
					(lig >= 3 && col <= g[lig].size() -4 && compte(g,lig,col,-1,+1) >= 4) ||
					// horizontalement vers la droite 
					(col <= g[lig].size() -4 && compte(g,lig,col,0,+1) >= 4)	||
					// horizontalement vers le bas vers la droite 
					(lig <= g.size() -4 && col <= g[lig].size() -4 &&compte(g,lig,col,+1,+1) >= 4 ) ||
					// verticalement vers le bas
					(lig <= g.size() && compte(g,lig,col,+1,0) >= 4)
				) {
					return true;
				}
			}
		}
	}
	return false;
}


unsigned int compte(Grille const & g, size_t lig_dep, size_t col_dep, int dir_lig, int dir_col) {
	unsigned int cpt(0);
	size_t lig(lig_dep),col(col_dep);
	while(
		lig < g.size() && col < g[lig].size() && g[lig][col] == g[lig_dep][col_dep]) {
		++cpt;
		lig+= dir_lig;
		col+= dir_col;
	}
	return cpt;
}

bool plein(Grille const & g){
	for (auto c : g[0]) {
		if (c==vide) {
			return false;
		}
	}
	return true;
}
