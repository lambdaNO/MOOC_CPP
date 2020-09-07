#include <iostream>
using namespace std;
/* --- */
// Prototypes
void etoiles(int n) ;
void espaces(int n) ;
void triangle(int n);
void triangle_decale(int n, int m);
void trapeze_decale(int n,int m, int o);
void beau_sapin(int n);
/* --- */
// Main
int main() {
  triangle(10);
  beau_sapin(10);
  
  
  return 0;
}
// Implem des fonctions

void etoiles(int nb_etoiles)  {
  for(int i(0); i < nb_etoiles; ++i) {
    cout << '*';
  }
}
void espaces(int nb_espaces)  {
  for(int i(0); i < nb_espaces; ++i) {
    cout << ' ';
  }
}

void triangle(int nb_lignes){
	for(int i(0); i < nb_lignes; ++i) {
		espaces(nb_lignes - i);
		etoiles(2 * i + 1);
		cout << endl;
	}
}
void triangle_decale(int nb_lignes, int nb_espaces) {
	for(int i(0); i < nb_lignes; ++i) {
		espaces(nb_espaces + nb_lignes - i);
		etoiles(2 * i + 1);
		cout << endl;
	}
}
void trapeze_decale(int no_ligne_debut, int no_ligne_fin, int nb_espaces){
	for(int i(no_ligne_debut); i < no_ligne_fin; ++i) {
		espaces(nb_espaces + no_ligne_fin - i);
		etoiles(2 * i + 1);
		cout << endl;
	}
}
void beau_sapin(int nb_etages){
	for(int i(0); i < nb_etages; ++i) {
		trapeze_decale(i, 3 + i, nb_etages - i);
	}
	espaces(2 + nb_etages);
	cout << "|||" << endl;
}


