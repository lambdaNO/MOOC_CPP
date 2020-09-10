#include <iostream>
#include <array>
#include <vector>
#include <string>
using namespace std;
/* --- */
// STRUCTURES :
//    Besoins de stocker des données structures.
//          Les tableaux : stockage de données homogènes
//          Les structures : stockages des données hétérogènes
//    Structure : type composé -> Regroupement conceptuel;
// Déclaration :
//    struct Nom_type {
//        // Liste des champs
//        type_1 identificateur_1;
//        type_2 identificateur_2;
//        ...
//        type_n identificateur_n;
//    };
//
//  Déclaration d'une variable à partir d'une structure :
//    nom_structure identificateur_struct;
//  Déclaration et initialisation :
//    nom_structure identificateur_struct(val_1,val_2, ..., val_n); où val_i est associée au champ i (type_i et identificateur_i)
//  Accès à un champs (attribut) de la structure;
//    Nom_type x; x.identificateur_i
/* --- */
struct Personne {
    string nom;
    double taille;
    unsigned int age;
    char sexe;
};
/* --- */
Personne naissance();
void anniversaire(Personne & p);
void affiche(Personne const & p);		// const & => Optimisation permettant d'éviter de réaliser une copie de l'objet

/* --- */
int main()
{
  Personne quidam(naissance());
  anniversaire(quidam);
  affiche(quidam);
  vector<Personne> classe;
  classe = {
    {"Dupont", 1.85, 22, 'X'},
    {"Charles", 1.25,55,'F'},
    {"Lama",1.58,45,'H'},
    {"Fabian",1.69,58,'F'},
    {"Erlat",1.56,25,'F'},
  };
  for (auto ind : classe){
    affiche(ind);
  }
  return 0;
}

Personne naissance(){
  Personne p;
  cout << "Nouvelle personne : "<< endl,
  cout << "Nom = "; cin >> p.nom;
  cout << "Taille (m) = "; cin >> p.taille;
  cout << "Age = "; cin >> p.age;
  do {
    cout << "Sexe (H/F) = "; cin >> p.sexe;
  } while (p.sexe != 'F' && p.sexe != 'H');
  return p;
}

void anniversaire(Personne & p){
  ++(p.age);
}

void affiche(Personne const & p){
	cout << p.nom << ", ";
	switch (p.sexe) {
		case 'H': cout << "homme"; break;
		case 'F': cout << "femme"; break;
		default : cout << "??"; break;
	}
	cout << ", " << p.taille*100 << " cm, " << p.age << "an";
	if (p.age >1){
		cout << 's';
	}
	cout << endl;
}
