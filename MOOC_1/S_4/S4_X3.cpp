#include <iostream>
#include <cmath>
using namespace std;
/* --- */
// Valeurs par défauts dans le prototypage (qui doivent obligatoirement apparaitre en fin de liste des paramètres)
// Stipulé par un égal (=) dans la déclaration du prototype (ET PAS DANS LA DEFINITION de la fonction)
// les arguments par défauts 
// SURCHARGE DE FONCTION -> ex : fonction affiche 
// Définir plusieurs fonctions de même nom qui diffère seulement du type des attributs !!  ATTENTION le type de retour doit être identique 
/* --- */
void affiche_ligne(char elt,int nb = 5);

int main(){
	affiche_ligne('*');
	affiche_ligne('-',8);
	return 0;
}

void affiche_ligne(char elt, int nb){
	cout << "nb = " << nb << endl;
	for (int i(0); i<nb;++i) {cout << elt;}
	cout << endl;
}

void affiche(int x){
	cout << "Int" << x << endl;
}
void affiche(double x){
	cout << "Double" << x << endl;
}
void affiche(int x,int y){
	cout << "Int(s)" << x <<","<< y << endl;
}
