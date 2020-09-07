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

/* --- */
// Exemple de fonction sur un tableau;
// Ecrire une fonction qui (ré)init un tableau tq :
//    saisie(x) avec x>0 ajoute un nombre au taleau
//    saisie(x) avec x=0 recommencer la saisie
//    saisie(x) avec x<0 effacer le dernier élément du tableau

void saisie(vector<int>& t, size_t x=4);  // Modifier le tableau de taille init 4 (modification en place pas de retour -> référence partagée)
void print(vector<int> t);             // Afficher le tableau
int main()
{
  /*
  vector<double> v(3,4.5);
  for (auto elt : v){cout << elt << " ";} cout << endl;
  cout<<"pop_back"<< endl;
  v.pop_back();
  for (auto elt : v){cout << elt << " ";} cout << endl;
  cout<<"push_back"<< endl;
  v.push_back(5.6);
  for (auto elt : v){cout << elt << " ";} cout << endl;
  v.push_back(4.88);
  for (auto elt : v){cout << elt << " ";} cout << endl;
  cout<<"pop_back"<< endl;
  v.pop_back();
  for (auto elt : v){cout << elt << " ";} cout << endl;
  cout<<"Un autre ?"<< endl;
  vector<double> w(3, 5.1);
  w.pop_back();
  w.push_back( 4.3 );
  w.push_back( w.front() );
  w.push_back( w[2] );
  for (auto elt : w){cout << elt << " ";} cout << endl;
  */




  return 0;
}

void print(vector<int> t) {
    for (auto elt : t){ cout << elt << " - ";} cout << endl;
}
void saisie(vector<int>& v, size_t t){
  v.clear();
  cout<< "Saisie de "<< t << " valeur(s) " << endl;
  while (v.size() < t) {
    int val(0);
    cout << "Enter la valeur "<< v.size() << " : ";
    cin >> val;
    if (val <0 && !v.empty()){v.pop_back();}
    else if (val == 0) { v.clear();}
    else if (val > 0) {v.push_back(val);}
  }
}
