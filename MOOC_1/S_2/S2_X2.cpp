#include <iostream>
using namespace std;
/* --- */
// if (condition){ bloc_vrai } else { bloc_faux }
// evaluation de la condition retourne deux valeurs : true, false
// Opérateurs de comparaison : <,>,<=,>=,==,!=
// Remarque if (n=5) est licite mais à banir car :
// if (n=5) <=> n = 5 et donc if (5); en c++, toute valeur non nulle est équivalente à true =>  if (n=5) sera évaluée à true
// Opérateurs logiques "et" s'exprime "and" ou "&&"  (opérateur binaire)
//                     "ou" s'exprime "or" ou "||"   (opérateur binaire)
//                     "non" s'exprime "not" ou "!"  (opérateur unaire)
/* --- */
int main() {
  int a(1), b(2);
  /* -- */
  if (a==b) {
    cout << "a = b (cas 1)" << endl;
  } else {
    cout << "a != b (cas 2)" << endl;
  }
  /* -- */
  if (2*a == b){
    cout << " 2*a = b" << endl;
  }
  /* ----- */
  int n;
  cout << "Saisir valeur de n dans [1,10]" << endl;
  cin >> n;
  if ((n>= 1) and (n<=10)) {
    cout << "Correct"<< endl;
  } else {
    cout << "Incorrect" << endl;
  }
  /* ----- */
  int x,y;
  cout << "Saisir valeurs de x,y" << endl;
  cin >> x >> y;    // Doivent être saisie sur une même ligne sans virgule (sinon la valeur de y est initialisée à 0)
  cout<<"x = " << x << " et y = " << y << endl;
  if ((x>=0) or (y >= 0)){
    cout << "au moins une valeur est positive" << endl;
  } else {
    cout << "aucune valeur n'est positive" << endl;
  }
  return 0;
  /* ----- */
  



}
