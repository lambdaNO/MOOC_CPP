#include <iostream>
#include <array>
using namespace std;
/* --- */
enum CouleurCase {VIDE,ROND,CROIX};
typedef array<array<CouleurCase,3>,3> Grille;
/* --- */
class Morpion {
    private :
      Grille grille;
      bool placer_pion(size_t i, size_t j, CouleurCase c);		// Méthode utilitaire - Appelée par des méthodes publiques - Mais qui n'a pas besoin d'être accessible (niveau d'abstraction)
    public :
      void initialise();
      void affiche();
      bool placer_rond(size_t i, size_t j);
      bool placer_croix(size_t i, size_t j);
      //[...]
};

void Morpion::initialise(){
    for (auto & lig : grille){
        for (auto & cas : lig) {
            cas = VIDE;
        }
    }
}
void Morpion::affiche() {
    for (auto lig : grille) {
        for (auto cas : lig) {
            if (cas == ROND) {cout << " O ";}
            else if (cas == CROIX) { cout << " X ";}
            else { cout << "  ";};
        }
        cout << endl;
    }
}

bool Morpion::placer_rond(size_t i, size_t j){
	return placer_pion(i,j,ROND);
}
bool Morpion::placer_croix(size_t i, size_t j){
	return placer_pion(i,j,CROIX);
}
bool Morpion::placer_pion(size_t i, size_t j, CouleurCase c){
	if (i >= grille.size() || j >= grille[i].size()) {
		// Traiter le cas d'erreur - Mauvaises dims
		return false;
	}
	if (grille[i][j] == VIDE) {
		grille[i][j] = c;
		return true;
	} else {
		// Traiter cas d'erreur - Non vide
		return false;
	}
}
//[...]


/* --- */
int main(){
    Morpion jeu;
    jeu.initialise();
    jeu.affiche();
    bool valide = jeu.placer_croix(1,1);
    jeu.affiche();
    //[...]

    return 0;
}
