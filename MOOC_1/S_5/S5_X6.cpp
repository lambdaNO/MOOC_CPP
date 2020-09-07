#include <iostream>
#include <vector>        // Appel à la librairie vector
#include <array>         // Appel à la libraire array
using namespace std;
/* --- */
// Tableaux : Collection de valeurs de même type (homogène)
//            -> Indicée de 0 à |elt|-1
// 2 types en c++ - Tableaux dynamiques (vector) dans les cas où les dimensions peuvent varier
//                - Tableaux statiques (array) dans les cas où les dimensions sont fixes
// -> Taille connue et identiques durant l'execution (plateau d'échecs, algèbre linéaires et multiplication vectorielle)
// Déclaration :
//  array<type,taille> identificateur;
// Initialisation :
//  array<type,taille> identificateur({val_1,...,val_taille});
//  <=> array<type,taille> identificateur = {val_1,...,val_taille};
// Manipulation :
//  - Accès : tab[i];
//  - itération : for(auto ...), for(auto& ...), for(size_t i(0) ...)
//  - taille : tab.size()
//  - affectation globale : array<int,3> tab_1 = {1,2,3}; array<int,3> tab_2; tab_2 = tab_1;
// Tableaux statiques mutlidimensionnel : array<array<type,j>,i> creait un tableau à i ligne et j colonnes (attention les tailles i et j ne varient pas fonction du temps)
//  MORALITE : comme les vector mais avec QUE DES TAILLES FIXES;
// MORALITE
//    STATIQUE :
//        #include<array>;
//        array<type,taille> tab;
//    DYNAMIQUE :
//        #include<vector>;
//        vector<type> tab;
//        ou vector<type> tab(taille);
/* --- */



int main(){
  // Ex 1 : vecteur de taille fixe de type double et de dim 3
  array<double,3> vecteur_3d;
  // Ex 2 : déclaration d'un tableau de 26 entiers
  const size_t nb_cantons(26);
  array<unsigned int,nb_cantons> habitants;
  // Ex 3 :
  const size_t taille(5);
  array<int,taille> age({25,35,45,69,25});
  // ou :
  array<int,taille> age_bis ={25,35,45,69,25};
  // Ex 4 : Multidim :
  array<array<double,2>,2> rotation;
  array<array<int,nb_statistiques>,nb_cantons> statistiques;   // statistiques[i] est un array<int,nb_statistique> c'est à dire un tableau de nb_stat entiers
  array<array<array<double,4>,2>,3> tenseur;
  //
  //            [[[][][][]][[][][][]]]
  //   tenseur  [[[][][][]][[][][][]]]   <=> une matrice en 3 dimensions de 3 lignes, 2 colonnes et d'une profondeur de 4 case
  //            [[[][][][]][[][][][]]]
  // et un accès (comme pour les vectors)
  rotation[1][0] = 0.231
  // Initilisation d'un tableaux statique multidim -> !!! UNE SEULE ACCOLADE :
  array<array<int,3>,4> matrice = {     // 4 lignes et 3 colonnes
    0,1,2,
    3,4,5,
    6,7,8,
    9,0,1
  };




  return 0;
}
