#include <iostream>
#include <cmath>
using namespace std;
int main(){
  int a(0),b(0);
  cout << "Saisir nb a "; cin >> a;
  cout << "Saisir nb b "; cin >> b;
  /* --- */
  int p_u(0),p_v(1);      // Initialisation des termes de suites (précédents)
  int u(0),v(1),n_u(0),n_v(1);          // Initialisation des termes de suites (courants)
  int q(0),r(0),x(a),y(b);// Quotient, reste, suites des nombres obtenus
  /* --- */
  while (y!=0){
    q = x/y; r = x%y;
    x = y; y = r;         // switch pour valeur suivante;
    n_u = p_u - u * q; p_u = u; u = n_u;
    n_v = p_v - v * q; p_v = v; v = n_v;
    cout << "(x,y)=("<<x<<","<<y<<") \t (u,v)=("<<u<<","<<v<<")"<< endl;
  }
  cout << "PGCD("<<a<<","<<b<<") = "<< x << endl;
  return 0;
}
