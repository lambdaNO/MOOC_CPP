#include <iostream>
#include <cmath>
using namespace std;
/* --- */
// Fonction : 3 aspects
//  - Resumé (Prototype)
//  - Construction (Définition)
//  - Utilisation (appel)
//------------------------------
// Processus d'appel à fonction
// 1) Les expression passées en argument sont évaluées
// 2) les valeurs correspondantes sont affectuées aux paramètres de la fonction
// 3) le corps de la fonction est executé
// 4) l'expression suivant la première commande return rencontrée est évaluée
// 5) et retournée comme résultat de l'appel : cette valeur replace l'expression d'appel
// ** pour des fonctions sans arguments -> étapes 1 et 2 inutiles
// ** pour des fonctions sans retour (i.e. type void) -> étape 4 et 5 n'ont pas lieu d'être
// ** Passage par référence -> Etape 2 n'a pas lieu d'être
//
// -> Passage par valeur (int x) : la fonction travaille sur une copie du paramètre passé dans le fonction et n'impacte pas la valeur globale (elle n'effectue des modification qu'en local i.e. dans l'environnement de la fonction)
// -> Passage par référence (int& x) : & indique que l'opération va se réaliser sur l'objet passé en paramètre et va modifier sont état (le passage par référence indique que le nom passé en paramètre est une référence à l'objet (et donc est le même objet))
// Pourquoi le passage par référence est utile ? 
//	-> Retour multiple (eg passage coordonnées carthésienne en polaire (x,y,&angle,&distance), swap de deux variables (&i,&j))
//	-> Eviter les return (exemple int i(0), saisir_entier(int& i) -> saisir_entier(i) va directement modififer la donnée en mémoire
// 	-> !!!!!!! C++, retours multiples impossibles; 
//
// Prototype : déclaration de la fonction sans définir le corps {nom, paramèters, type de retour}
//				=> type nom (type_1 id_1, type_2 id_2, ...)
// Définition (du corps) d'un fonction  type nom(parms) { bloc_instruction; return expression} rmq : expression doit être de "type" type 
// Remarque : on peut placer plusieurs return dans une fonction (voir max2)
// !!!! Un compilateur doit toujours être capable d'évaluer un RETURN (si le type de retour est un double, int, bool, ...)
//		=> mettre des VOID si pas de type de retour (on parle de procédure et non de fonction)
//		=> On peut cependant mettre un return dans une fonction pour stoper son execution dans certains cas (exemple affiche_sqrt)
// main est une fonction spéciale dont le prototype est imposé et où la valeur 0 retournée signifie que le code s'est bien déroulé 
/* --- */
// Classe main (appels aux fonctions)



int main(){
  int val(1);
  cout << "val(init) =" << val << endl;
  f_val(val);
  cout <<" val = " << val << endl;
  cout << "val(init) =" << val << endl;
  f_ref(val);
  cout <<" val = " << val << endl;
  /* --- */
  int x(3), y(5);
  cout << x << y << " ";
  m1(x, y);
  cout << x << y << " ";
  m2(x, y);
  cout << x << y << endl;
  

  return 0;
}
/* --- */
// Implem des fonctions - Définitions
void f_val(int x){
  x = x + 1; cout << "FV -> x=" << x;

void f_ref(int& x){
  x = x + 1; cout << "FR -> x=" << x;
}

void m1(int i, int j) {
  int tmp(i); i = j; j = tmp;
}

void m2(int& i, int& j) {
  int tmp(i); i = j; j = tmp;
}

double max2(double a,double b){
	if (a > b) {return a;}
	else if (a< b) {return b;}
	else {return a;}
}

void aff_sqrt(double a){
	if (a<0.) { return;}
	cout << sqrt(a);
}
