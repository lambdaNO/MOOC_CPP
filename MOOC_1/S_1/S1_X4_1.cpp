#include <iostream>
#include <cmath>    // appels aux fonctions mathématiques (remarque les angles sont exprimés en radians (donc pas hésiter à mutlipier par pi (3.14156)))
using namespace std;
/* ------------------------------------------ */
// Opérateurs = +,-,*,/
// Cas particulier : * a/b avec a,b int est le division entière e.g. 1/2 = 0 car 1 = 0*2 + 1, 5/2 = 2 car 5 = 2*2 + 1
//                   * a/b avec b (ou a) float et a (ou b) int -> typage float lors de l'évaluation de l'expression
// Opérateurs +=, -=, *=, /=
// Exemple : a+=5 <=> a = a + 5
// Opérateur sur les entiers : % (modulo) retourne le reste de la div entière
// Opérateurs d'incrément (décréments) ++i <=> i = i + 1; --i <=> i = i - 1;
// Opérateurs <cmath> : sin,cos,tan,asin,acos,atan,atan2 (atan2(y,x) retourne la valeur de arctan de y/x)
//                      sinh,cosh,tanh,exp,log (log néperien), log10, pow(x,y) <=> x^y
//                      sqrt,ceil(x), floor(x), abs
//                      Constantes = M_PI, M_E
//                      Rmq : les angles en c++ sont exprimés en radians
/* ------------------------------------------ */
int main(){
  int a(0);
  a = 2 + 3/2;
  cout << "a = " << a << endl;
  /* --- */
  int val1(1);
  int val2(2);
  val1 += val2; // <=> val1 = val1 + val2
  ++val2;       // <=> val2 = val2 + 1
  cout << "val1 = " << val1 << " val2 = "<< val2 << endl;
  /* --- */
  int m(13);
  int n(4);
  // 13/4 = 3 * 4 + 1
  int q(m / n);   // division entière
  int r(m % n);   // reste division euclidienne
  cout << "q = " << q << " r = "<< r << endl;
  /* --- */
  // ATTENTION AU TYPAGE FORT
  double x(1.5);
  int y;
  y = 3*x;
  cout << "double(x) = " << x << " int n; n = 3*x = "<< y << endl;
  /* --- */
  // ATTENTION aux retours à cause du typage
  double z; z = 1 / 2;  // 1/2 est une div d'entier -> retourne 0 donc z = 0.
  /* --- */
  int note1(4),note2(5);
  double moyenne_1;
  moyenne_1 = (note1+note2)/2;
  double moyenne_2(note1+note2); moyenne_2/= 2;
  cout << "moyenne 1 = " << moyenne_1 << "  moyenne 2 = " << moyenne_2 << endl;
  /* --- */
  int m_ex(13);
  double n_ex(4);
  double q_ex(m / n);

}
