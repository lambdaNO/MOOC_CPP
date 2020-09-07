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
  vector<double> tab(10);
  cout << "Le tableau contient : " << endl;
  for (auto elt : tab) {
    cout << elt << " ";
  }
  cout << endl;
  //
  for (auto& el : tab){
    el = 1.2;
  }
  //  Une alternative -> tab = vector<double>(tab.size(),1.2); // Là, on vient écraser l'ancienne valeur de tab par un nouveaux tableau dynamique
  //
  cout << "Parcours des éléments : " << endl;
  for (size_t i(0); i < tab.size(); i++){
    cout << "tab["<<i<<"] = " << tab[i] << endl;
  }
  ////////////////////////////////////////
  vector<double> v(10);
  for (auto& elt : v){
    cout << "valeur ? "; cin >> elt;
  }
  for (size_t i(0); i <v.size(); ++i){
    cout << "ancienne valeur de v["<<i<<"]="<<v[i] << endl;
    cout << "Nouvelle valeur ?"; cin >> v[i];
    cout << "=>valeur de v["<<i<<"]="<< v[i] << endl;
  }
  return 0;
}
