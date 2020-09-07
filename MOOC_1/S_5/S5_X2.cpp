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
//
// A l'initialisation : un tableau dynamique à taille fixée ne contient que des 0 (resp. 0.) si il est de type int (resp. double)
// Manipulation des éléments d'un tableau
// -> Accès : tab[i] avec i \in |[0, |tab|-1]|
// 2 méthodes classiques de parcours :
//  Soit tab, un tableau
//    1) for (auto elt : tab)               // Itération sur les valeurs d'un ensemble
//    2) for (size_t i(0); i < TAILLE: ++i) {tab[i] ...}     // Itération classiques
// Détail méthode 1)
//  for (auto nom_var : tab)                // Si l'on ne VEUT PAS modifier les valeurs du tableau tab
//  for (auto& nom_var : tab)               // Si l'on ne VEUT modifier les valeurs du tableau tab    (passage par référence)
//  Remarque méthode 1)   -> On ne peut pas avoir accès à deux tableaux
//                        -> On ne peux acceder à plusieurs éléments
//                        -> On ne peux pas sauter des éléments
//                        => Utiliser la méthode 2
// Détail méthode 2)
//  for (size_t i(0); i < tab.size(); ++i){ ... }
/* --- */
int main()
{
  // Affectation d'un tableau :
  vector<int> tab_1({1,2,3});
  vector<int> tab_2;
  tab_2 = tab_1;              // Copie de tout les éléments de tab_1 dans tab_2

  // Exemple de Manipulation méthode 1)
  vector<int> ages(5);
  // Parcours avec modification
  cout << "---> SAISIE "<< endl;
  for (auto& age : ages){
    cout << "Age de l'employé : "; cin >> age;    // Ici, age correspond à la valeur du tableau (la case) (et donc l'adresse mémoire)
  }
  // Parcours en simple accès
  cout << "---> PARCOURS "<< endl;
  for (auto age : ages){
    cout << "\t age = " << age << endl;
  }
  // Exemple de Manipulation méthode 1)
  vector<int> ages_bis(5);
  for (size_t i(0); i<ages_bis.size();++i){
    cout << "Age de l'employé  "<< i+1 << " : "; cin >> ages_bis[i]; 
  }



  return 0;
}
