#include <iostream>
#include <cmath>
using namespace std;
/* --- */
int main()
{
  const double pi(acos(-1.0));
  double a0(0.),a1(0.),a2(0.);
  double Q(0.), R(0.), D(0.), T(0.), S(0.);
  double z1(0.), z2(0.), z3(0.);
  cout << "Saisir (a0,a1,a2) tq P(z) = z^3 + a2*z^2 + a1*z + a0" << endl;
  cin >> a0 >> a1 >> a2 ;
  cout << "P(z) = z^3 + " << a2 << "*z^2 + " << a1 <<"*z + "<< a0 << endl;
  /* --- */
  Q = (3*a1 - pow(a2,2))/9.;
  R = (9.0 * a2 * a1 - 27.0 * a0 - 2.0 * a2*a2*a2) / 54.0;
  D = pow(Q,3) + pow(R,2);
  cout << "Q = " << Q << " | R = " << R << " | D = " << D << endl;
  /* --- */
  if (D < 0.){
    T = acos(R/sqrt(-pow(Q,3)));
    z1 = 2.0 * sqrt(-Q) * cos(T/3.0) - a2/3.0;
    z2 = 2.0 * sqrt(-Q) * cos((T+2.0*pi)/3.0) - a2/3.0;
    z3 = 2.0 * sqrt(-Q) * cos((T+4.0*pi)/3.0) - a2/3.0;
    cout << "D <0. -> 3 Racines z = ("<<z1 <<", "<< z2<<", "<<z3<<")."<< endl;
  } else {
    double s = R+sqrt(D);
    if (s == 0.) {S = 0.;}
    else if (s < 0.) { S = - pow(-s,1./3.);} // expression de la racine cubique
    else if (s > 0.) { S = + pow(s,1./3.);}
    double t = R - sqrt(D);
    if (t == 0.) {T = 0.;}
    else if (t < 0.) { T = - pow(-t,1./3.);} // expression de la racine cubique
    else if (t > 0.) { T = + pow(t,1./3.);}
    z1 = -a2 / 3.0 + S + T;   // Calcul de racine n°1 du Polynome
    if (D == 0 && (S+T != 0)) { // Complément des deux racines doubles
      z2 = -a2 / 3.0 - (S + T) / 2.0;
      cout << "D >= 0. et S+T != 0 " << endl << "  racine simple = " << z1 << endl << "  racine double = " << z2 << endl;
    } else {
      cout << "D >= 0. et S+T = 0 " << endl << "  unique racine = " << z1 << endl;
    }
  }
  return 0;
}
