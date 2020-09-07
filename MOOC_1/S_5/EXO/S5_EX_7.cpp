#include <iostream>
#include <array>
#include <string>
using namespace std;
constexpr unsigned int DIM(10);
/* --- */
void initGrille(array<array<bool, DIM>, DIM>& grille);
void afficheGrille(const array<array<bool, DIM>, DIM>& grille);
void ajouterElements(array<array<bool, DIM>, DIM>& grille);
bool remplitGrille(array<array<bool, DIM>, DIM>& grille, unsigned int ligne, unsigned int colonne,char direction, unsigned int longueur);
/* ---------------------------------------------- */
int main(){
	array<array<bool,DIM>, DIM> grille;
	initGrille(grille);
	ajouterElements(grille);
	afficheGrille(grille);

	return 0;
}
/* --- */
void initGrille(array<array<bool, DIM>, DIM>& grille){
	for (auto l : grille){
		for (auto & e : l){
			e = false;
		}
	}
}
/* --- */
bool remplitGrille(array<array<bool, DIM>, DIM>& grille, unsigned int ligne, unsigned int colonne,char direction, unsigned int longueur){
	int dirX(0),dirY(0);
	unsigned int i(ligne),j(colonne), l;
	bool ok(true);
	// Lecture de la direction
	switch (direction) {
		case 'N' : dirX = -1; dirY = 0; break;
		case 'S' : dirX = 1; dirY = 0; break;
		case 'E' : dirX = 0; dirY = 1; break;
		case 'O' : dirX = 0; dirY = -1; break;
	}
	for (l=0; ok && i < grille.size() && j < grille[0].size() && l < longueur; ++l, i+=dirX, j+=dirY){
		if (grille[i][j]){ok=false;}
	}
	ok = ok && (l==longueur);
	if (ok){
		for (l = 0, i =ligne, j = colonne; l < longueur; ++l, i+= dirX, j+= dirY){
			grille[i][j] = true;
		}
	}
	return ok;
}
/* --- */
void afficheGrille(const array<array<bool, DIM>, DIM>& grille){
	for (auto ligne : grille) {
		for (auto cell : ligne) {
			if (cell){ cout << '#';}
			else {cout << '.';}
		}
		cout << endl;
	}
}
/* --- */
void ajouterElements(array<array<bool, DIM>, DIM>& grille){
	int x, y;
	do {
		cout << "Entrez coord. x : "; cin >> x;
		if (x >= 0) {
			cout << "Entrez coord. y : "; cin >> y;
			if (y >= 0) {
				char dir;
				do {
					cout << "Entrez direction (N,S,E,O) : "; cin >> dir;
				} while ((dir != 'N') and (dir != 'S') and (dir != 'E') and (dir != 'O'));
				cout << "Entrez taille : ";
				unsigned int l; cin >> l;
				cout << "Placement en (" << x << "," << y << ") direction " << dir << " longueur " << l << " -> ";
				if (remplitGrille(grille, x, y, dir, l)){
					cout << "succès";
				}else{
					cout << "ECHEC";
				}
				cout << endl;
			}
		}
	} while ((x >= 0) and (y >= 0));
}
