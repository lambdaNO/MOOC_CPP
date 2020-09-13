#include <iostream>
#include <string>
using namespace std;

class Souris
{
  /*****************************************************
    ComplÃ©ter le code Ã  partir d'ici
  *******************************************************/
	private : 
		double poids;
		string couleur;
		unsigned int age;
		unsigned int esperance_vie;
		bool clonee;
	public : 
		Souris(double p, string c, unsigned int a = 0, unsigned int e = 36, bool cl = false) : poids(p), couleur(c), age(a), esperance_vie(e), clonee(cl) {cout << "Une nouvelle souris !" << endl;};
		Souris(Souris const & s) : poids(s.poids), couleur(s.couleur), age(s.age), esperance_vie(s.esperance_vie*4/5), clonee(true){cout << "Clonage d'une souris !" << endl;};
		~Souris() {cout << "Fin d'une souris..." << endl;}
		void afficher() const {
			// Une souris <couleur> [, clonee,] de <age> mois et pesant <poids> grammes(suruneseuleligne)
			cout <<"Une souris "<<couleur;
			if (clonee) {cout<< ", clonee,";}
			cout << " de " << age << " mois et pesant " << poids << " grammes"<<endl;
		}
		void vieillir() {
			++age;
			if (clonee && age > 0.5*esperance_vie) {
				couleur = "verte";
			}
		}
		void evolue() {
			while (age < esperance_vie) {
				vieillir();
			}
		}
  /*******************************************
   * Ne rien modifier aprÃ¨s cette ligne.
   *******************************************/

}; // fin de la classe Souris

int main()
{
  Souris s1(50.0, "blanche", 2);
  Souris s2(45.0, "grise");
  Souris s3(s2);
  // ... un tableau peut-être...
  s1.afficher();
  s2.afficher();
  s3.afficher();
  s1.evolue();
  s2.evolue();
  s3.evolue();
  s1.afficher();
  s2.afficher();
  s3.afficher();
  return 0;
}
