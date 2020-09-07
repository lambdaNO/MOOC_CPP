#include <iostream>
#include <vector>        // Appel à la librairie
using namespace std;
/* --- */
// Tableaux : Collection de valeurs de même type (homogène)
//            -> Indicée de 0 à |elt|-1
// 2 types en c++ - Tableaux dynamiques (vector) dans les cas où les dimensions peuvent varier
//                - Tableaux statiques (array) dans les cas où les dimensions sont fixes
// Déclaration :
//      vector<type> identificateur;
//      vector<type> identificateur(liste);               tableau initialisé avec une liste initiale d'élements  !!!PEUT VARIER!!!
//      vector<type> indentificateur(taille);             tableau initialisé avec une taille initiale !!!PEUT VARIER!!!
//      vector<type> indentificateur(taille,valeur);      tableau initialisé avec taille fois la même valeur
//      vector<type> indentificateur(ref);                tableau initialisé à partir d'une copie du tableau ref  -> Copie élément par élément
/* --- */
int main()
{
  // Ex : Déclaration d'un tableau DYNAMIQUE d'entier VIDE :
  vector<int> tableaux;
  // Ex : Déclaration d'un tableau DYNAMIQUE d'entier initié avec des valeurs :
  vector<int> age_1({20,35,26,38,22});
  vector<int> age_2 = {20,35,26,38,22};   // Deux écritures équivalentes
  // Ex : Déclaration d'un tableau DYNAMIQUE de taille initiale 5
  vector<int> tab(5);
  // Ex : Déclaration d'un tableau DYNAMIQUE de taille initiale 5 ne contenant que des 0
  vector<int> zeros(5,0);
  // Ex : Déclaration d'un tableau DYNAMIQUE avec une copie d'un tableau
  vector<int> zeros_bis(zeros);

  return 0;
}
