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
//
// Fonctions spécifiques aux tableaux dynamique
//  Structure générale = nom_tableau.fonction_specifique(arg1,arg2,...);
//  .size()   -> retourne la taille du tableau
//  .front()  -> retourne une référence sur le premier élément du tableau  : tab.front() <=> tab[0]
//  .back()   -> retourne une référence sur le dernier élément du tableau  : tab.back() <=> tab[tab.size()-1]
//  .empty()  -> retourne un booleen
//  .clear()  -> supprime tous les éléments d'un tableau
//  .pop_back() -> supprime le dernier élément du tableau PAS DE RETOUR
//  .push_back(valeur) -> ajoute un élément en fin de tableau
//
//  Tableaux dynamiques multidimensionnels
//  => Faire un tableau de tableaux
//  Ex :  vector<vector<int>> tab(5,vector<int>(6))
//        - Tableau dynamique de 5 tableaux dynamique de taille 6 (nombre de cases)
//  Accès a un vector en entier : tab[i] avec i in |[0, 4]|
//  Accès a une case du tableau j du vecteur i t[i][j] avec i in |[0, 4]| et j in |[0, 5]|
//
//        [i = 0] -> [j=0][j=1][j=2][j=3][j=4][j=5]
//        [i = 1] -> [j=0][j=1][j=2][j=3][j=4][j=5]
//   tab  [i = 2] -> [j=0][j=1][j=2][j=3][j=4][j=5]
//        [i = 3] -> [j=0][j=1][j=2][j=3][j=4][j=5]
//        [i = 4] -> [j=0][j=1][j=2][j=3][j=4][j=5]
//   tab[i][j]  -> élément à la i+1e ligne et la j+1e colonne
//   ATTENTION tab n'est pas une matrice
//   ex
//        [i = 0] -> [j=0][j=1][j=2][j=3]
//        [i = 1] -> [j=0][j=1]
//   tab  [i = 2] -> [j=0][j=1][j=2][j=3][j=4][j=5]
//        [i = 3] -> [j=0][j=1][j=2][j=3]
//        [i = 4] -> [j=0][j=1][j=2]
/* --- */



int main()
{
  vector<vector<int>> tab(
    {
      {1,2,3,42},
      {4,5,6   },
      {7,8     },
      {9,0,1   }
    }
  );
  cout << "Parcours 1 : " << endl;
  for (auto ligne : tab){
    cout << "taille = " << ligne.size() << " / 1er elt = " << ligne.front() << " / "<<ligne.size()<<"e elt = " << ligne.back() << "\t[";
    for (auto elt : ligne){
      cout << elt << " ";
    }
    cout<<"]." << endl;
  }
  cout << "Parcours 2 : " << endl;
  for (size_t i(0); i < tab.size(); ++i){
    for (size_t j(0); j < tab[i].size(); ++j){
      cout << "tab["<<i<<","<<j<<"] = " << tab[i][j] << "\t";
    }
    cout << endl;
  }
  cout << "Parcours 3 - autre exemple : " << endl;
  vector<vector<int>> v({ {1, 2, 3}, {4, 5} });
  cout << v[1][1] << ' ' << v.size() << ' ';
  cout << v[0].size() << ' ' << v[1].size();

  return 0;
}
