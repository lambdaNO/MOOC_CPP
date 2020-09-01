#include <iostream>
#include <cmath>    // appels aux fonctions mathématiques (remarque les angles sont exprimés en radians (donc pas hésiter à mutlipier par pi (3.14156)))
using namespace std;
/* ------------------------------------------ */
// Opérateurs <cmath> : sin,cos,tan,asin,acos,atan,atan2 (atan2(y,x) retourne la valeur de arctan de y/x)
//                      sinh,cosh,tanh,exp,log (log néperien), log10, pow(x,y) <=> x^y
//                      sqrt,ceil(x), floor(x), abs
//                      Constantes = M_PI, M_E
//                      Rmq : les angles en c++ sont exprimés en radians
/* ------------------------------------------ */
int main(){
  double angle_deg;
  cout << "Saisir angle (en deg)" << endl;
  cin >> angle_deg;
  double angle_rad(M_PI*angle_deg/180);
  cout << "angle (en rad) = "<< angle_rad << " cos(angle) = " << cos(angle_rad) << endl;
}
