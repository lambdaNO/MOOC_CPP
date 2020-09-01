#include <iostream>
using namespace std;
/* ------------------------------------------ */
// Méthode de déclaration :
//  1) type identificateur(valeur);
//  2) type identificateur;
// Méthode d'Affectations
//  nom_variable = expression;
// Méthode d'affectation imuable (pour l'ensemble de l'execution du programme)
// const type identificateur(valeur);
// Types standards
//  - int, double
//  - unsigned int (entier positifs)
//  - char
//  - ...
/* ------------------------------------------ */

int main() {
  // [Initialisation] Déclaration d'une variable d'identificateur "n" de type entier et de valeur 4
  int n(4);
  // Déclaration d'une variable d'identificateur "n_carre" de type entier et sans valeur
  // => Boarf, il faut toujours initialiser une variable pour assurer sa bonne manipulation
  int n_carre;
  // [Initialisation] Déclaration d'une variable d'identificateur "x" de type décimale et de valeur 1.
  double x(1.0);
  // Déclarations multiples
  int m(1);
  int p(1),q(0);
  double z(0.1),y;
  // Affectations
  n_carre = n*n;

  return 0;
}
