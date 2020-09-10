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
//  Affectation possible
//    Personne p1({...}),p2;  p2 = p1; licite et équivaut à l'affectation de l'ensemble des champs
//  !!!!!!!!!!!!!! Comparaisons impossible (pas de ==,<=,..) -> Voir surcharche opérateur
/* --- */
struct Date{
  int jour;
  int mois;
  int annees;
};
struct Cours{
  string nom;
  string enseignant;
  unsigned int identificateur;
};
struct Etudiant {
  string nom;
  string section;
  double moyenne;
  vector<Cours> inscriptions;
};
struct Particule {
  array<double, 3> vitesse;
  array<double, 3> position;
  double masse;
  double charge;
};
struct Personne {
    string nom;
    string prenom;
    double taille;
    unsigned int age;
    char sexe;
};
struct Complexe {
  double x;
  double y;
};

struct Simple {
  int x,y;
};
struct Complique {
  vector<int> v1;
  vector<int> v2;
  double w;
  vector<Simple> comp;
};

/* --- */
void print_personne(Personne p);
/* --- */
int main()
{
	Complexe z({2,1});									// <=> z = {2,1};
	Personne quidam({"Dupont","Regis",1.85,22,'M'});		// <=> quidam = {"Dupont","Regis",1.85,22,'M'};
	print_personne(quidam);
	// Modification externe
	quidam.taille = 1.75;
	++(quidam.age);						// Parenthèse nécessaire car l'opérateur ++ est prioritaire par rapport à l'opérateur d'appel ('.');
	cout << "---" << endl;
	print_personne(quidam);

  return 0;
}

void print_personne(Personne p){
  cout << "Nom,Prenom = " << p.nom << " , " << p.prenom << endl << "Sexe = " << p.sexe << endl << "Age, Taille = "<< p.age << " , " << p.taille << endl;
}
