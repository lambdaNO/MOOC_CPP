#include <iostream>
#include <cmath>
using namespace std;
/* --- */
// Prototypes
double f(double x);       // Fonction
double df(double x);      // Dérivée
double Newton(double x);  // Formule de
constexpr double epsilon = 1e-6;
/* --- */
// Main
int main() {
	double x1,x2;
	cout << "Calcul de racine en un point => " << endl;
	cout << "Start -> x = "; cin >> x2;
	do {
		x1 = x2;
		cout << " x = " << x1 << "\t f(x) = " << f(x1) << "\t f'(x) = " << df(x1) << "."<< endl;
		x2 = Newton(x1);
	} while (abs(x1-x2) > epsilon);
	cout << "Solution => x = " << x2 << endl;
  return 0;
}

double f(double x) {
  return (x-1.)*(x-1.5)*(x-2.);
}
double df(double x){
  return (f(x+epsilon)-f(x))/epsilon;
}
double Newton(double x){
  return x - f(x)/df(x);
}
