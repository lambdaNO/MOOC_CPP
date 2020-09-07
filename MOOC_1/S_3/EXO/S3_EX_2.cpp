#include <iostream>
#include <cmath>
using namespace std;
constexpr double g(9.81); // Constante de gravitation
int main(){
  double eps, h0, n;      // eps : coef de rebond de la balle, h0 : hauteur initiale, n : nb de rebond à simuler
  double h1, v0, v1;      // hauteur après le rebond, vitesses avant et après le rebond
  do {
    cout << "Coefficient de rebond (0 <= coeff < 1) : ";
    cin >> eps;
  } while ( (eps < 0.0) or (eps >= 1.0) );
  do {
    cout << "Hauteur initiale (h0 > 0) : ";
    cin >> h0;
  } while (h0 <= 0.0);
  do {
    cout << "Nombre de rebonds (n >= 0) : ";
    cin >> n;
  } while (n < 0);
  /* --- */
  for (int r(1); r <= n; ++r) {
    v0 = sqrt(2.0 * g * h0); // vitesse avant rebond
    v1 = eps * v0; // vitesse apres le rebond
    h1 =(v1 * v1) / (2.0 * g); // hauteur après rebond
    h0 = h1; // qui devient nouvelle haut. avant rebond suivant
  }
  cout<<"Au "<<n<<"e rebond, la hauteur atteinte est de "<<h0<<endl;
  return 0;
}
