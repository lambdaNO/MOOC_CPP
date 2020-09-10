#include <iostream>
using namespace std;
/* --- */
struct Maison {
	string adresse;
};
struct Personne {
	string nom;
	Maison* home;		// Un pointeur 
};
/* --- */
void affiche(Personne const& p);

/* --- */
int main()
{
	// Remarque : cette fois ci, on passe en paramète des adresses mémoires (ie les pointeurs vers les maisons)
	//
	Maison m1 = { "12 rue du chateau" };
	Personne p1 = { "Pierre", &m1 };				affiche(p1);
	Personne p2 = { "Paul" , &m1 };					affiche(p2);	
	//
	Maison m2 = { "13 rue du chateau" };
	Personne p3 = { "Steve", &m2 };					affiche(p3);
	Personne p4 = { "Sofia", &m2 };					affiche(p4);
	//
	// => Déménagement;
	Maison m3 = { "8 rue saint-cado" };
	p1.home = &m3;		// On change l'adresse mémoire vers laquelle pointe home;
	affiche(p1); affiche(p2);
	
	
	
}
/* --- */
void affiche(Personne const& p) {
	// Note : (*X).Y peut aussi s'écrire X->Y, par exemple ici :
	cout << p.nom << " habite " << (p.home)->adresse << "." << endl;
}
