#include <iostream>
using namespace std;
/* --- */
struct Maison {
	string adresse;
};
struct Personne {
	string nom;
	Maison& home;
};
/* --- */
void affiche(Personne const& p);

/* --- */
int main()
{
	//
	Maison m1 = { "12 rue du chateau" };
	Personne p1 = { "Pierre", m1 };				affiche(p1);
	Personne p2 = { "Paul" , m1 };				affiche(p2);	
	//
	Maison m2 = { "13 rue du chateau" };
	Personne p3 = { "Steve", m2 };				affiche(p3);
	Personne p4 = { "Sofia", m2 };				affiche(p4);
}
/* --- */
void affiche(Personne const& p) {
	cout << p.nom << " habite " << p.home.adresse << "." << endl;
}
