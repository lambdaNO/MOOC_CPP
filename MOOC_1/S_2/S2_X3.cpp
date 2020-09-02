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
// Erreurs classiques :
//    if (a = 1) // !!!
//    if (a == 1); cout << "a vaut 1" // !!!
//
// Le type bool à valeur dans {true,false} -> Les méthodes d'affectations sont celles classiques (et peuvent contenir des opérateurs logiques)

//  Tip : toujours utiliser des accolades (même avec des identations)
/* --- */
int main() {
  /* --- */

  int n,p;
  cout << " saisir n " << endl;     // n = 1  // n = 1  // n = 2
  cin >> n;
  cout << " saisir p " << endl;     // p = 1  // p = 3  // p = 1
  cin >> p;
  if ((n<p) && (2*n >= p)){         // Les deux conditions doivent être évaluées à vrai
    cout << "1";
  }
  if ((n<p) || (2*n >= p)){         // au moins une condition doit être évaluée à vrai
    cout << "2";
  }
  if (n<p){
    if (2*n >= p){
      cout << "3";
    } else {
      cout << "4";
    }
  }
  cout << endl;
  

  int a(1),b(2);
  bool c(true);
  bool d(a==b);
  bool e(d or (a<b));
  if (e){
    cout << "e = " << e << endl;
  }


  return 0;
  /* ----- */
}
