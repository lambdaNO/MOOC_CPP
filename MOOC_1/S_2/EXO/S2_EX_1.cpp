#include <iostream>
#include <cmath>
using namespace std;
/* --- */
int main()
{
  double a(0.),b(0.),c(0.);
  double delta(0.);
  /* --- */
  cout << "Saisir a non nul" << endl;
  cin >> a;
  if (a == 0.) {
    // cerr est comme cout, mais pour les messages d'erreur.
    cerr << "a nul -> STOP" << endl;
    return 1;
  }
  cout << "Saisir b" << endl;
  cin >> b;
  cout << "Saisir c" << endl;
  cin >> c;
  /* --- */
  delta = b*b - 4*a*c;
  cout << "P(x) = "<< a << "x^2 + " << b << "x + " << c << endl << "delta = " << delta << endl;
  /* --- */
  if (delta < 0.0) {
    cout << "Pas de solutions réelles." << endl;
  } else if (delta > 0.0) {
    cout << "Deux solutions : " << (-b-sqrt(delta))/(2.0*a) << " et " << (-b+sqrt(delta))/(2.0*a) << endl;
  } else {
    cout << "Une solution unique : " << -b/(2.0*a) << endl;
  }
  return 0;
}
