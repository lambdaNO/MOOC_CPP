#include <iostream>
using namespace std;

/*****************************************************
 * Compléter le code à partir d'ici
 *****************************************************/
class Patient {
	private :
		double masse;
		double hauteur;
	public :
		void init(double const& m, double const& h);
		void afficher() const;
		double poids() const;
		double taille() const;
		double imc() const;
		
};

void Patient::init(double const& m, double const& h) {
	masse = 0.;
	hauteur = 0.;
	if (m >= 0 && h >= 0) {
		masse = m; hauteur = h;
	} 
}
void Patient::afficher() const {
	cout << "Patient : " << masse << " kg pour " << hauteur << " m" << endl;
}
double Patient::poids() const {
	return masse;
}
double Patient::taille() const {
	return hauteur;
}
double Patient::imc() const {
	double imc_res(0.);
	if (hauteur != 0) {
		imc_res = masse/(hauteur*hauteur);
	}
	return imc_res;
	
}


/*******************************************
 * Ne rien modifier après cette ligne.
 *******************************************/

int main()
{
  Patient quidam;
  double poids, taille;
  do {
    cout << "Entrez un poids (kg) et une taille (m) : ";
    cin >> poids >> taille;
    quidam.init(poids, taille);
    quidam.afficher();
    cout << "IMC : " << quidam.imc() << endl;
  } while (poids * taille != 0.0);
  return 0;
}
