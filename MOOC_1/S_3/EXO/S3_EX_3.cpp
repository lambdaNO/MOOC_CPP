#include <iostream>
#include <cmath>
using namespace std;
constexpr double g(9.81); // Constante de gravitation
int main(){
  double eps, h0, h_fin;      // eps : coef de rebond de la balle, h0 : hauteur initiale, h_fin : hauteur finale
  double h1, v0, v1;      // hauteur après le rebond, vitesses avant et après le rebond
  int r(0);               // nombre de rebonds;
  do {
    cout << "Coefficient de rebond (0 <= coeff < 1) : ";
    cin >> eps;
  } while ( (eps < 0.0) or (eps >= 1.0) );
  do {
    cout << "Hauteur initiale (h0 > 0) : ";
    cin >> h0;
  } while (h0 <= 0.0);
  do {
    cout << "Hauteur finale (0 < h_fin < h0) : ";
    cin >> h_fin;
  } while ( (h_fin <= 0.0) or (h_fin >= h0) );
  do {
    ++r; // une iteration par rebond
    v0 = sqrt(2.0 * g * h0); // vitesse avant rebond
    v1 = eps * v0; // vitesse apres le rebond
    h1 = (v1 * v1) / (2.0 * g); // hauteur après rebond
    h0 = h1; // qui devient nouvelle haut. avant rebond suivant
  } while (h0 > h_fin);
  /* --- */
  cout << "La balle rebondit " << r << " fois avant que la hauteur de rebond (" << h0 << ") soit inférieure à la limite de " << h_fin << endl;
  return 0;
}
