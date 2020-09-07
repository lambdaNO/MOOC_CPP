#include <iostream>
#include <cmath>
using namespace std;
/* --- */
// Prototypes
double f(double x);
double saisir(char c);
double integre(double a, double b);
/* --- */
// Main
int main() {
  double a = saisir('a'),b = saisir('b');
  cout << "Intervalle d'integration -> [ "<< a << " , "<< b << " ]."<< endl;
  cout << "=> f(x) = " << integre(a,b) << endl;

  return 0;
}
// Implem des fonctions
double f(double x) {
  return pow(x,2);
  //return pow(x,3);
  //return sin(x);
  //return 1/x;
}
double saisir(char c){
  double a(0.);
  cout << "Saisir la borne '" << c << "' de l'intervalle [a,b] : ";
  cin >> a ;
  return a;
}
double integre(double a, double b){
  double res = 41.0 * ( f(a) + f(b) ) + 216.0 * ( f((5*a+b)/6.0) + f((5*b+a)/6.0) ) + 27.0 * ( f((2*a+b)/3.0) + f((2*b+a)/3.0) )  + 272.0 * f((a+b)/2.0) ;
  return res *= (b-a)/840.0;
}
