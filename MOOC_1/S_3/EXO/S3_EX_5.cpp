#include <iostream>
#include <cmath>
using namespace std;
int main(){
  double S0(0.), ir(0.), r(.0);            // Prêt initial, taux d'intérêt, remboursement mensuel
  do {cout << "Montant du prêt (S0 > 0)"; cin >> S0;} while (S0 <= 0);
  do {cout << "Remboursement mensuel (r>0)"; cin >> r;} while (r <= 0);
  do {cout << "Taux intérêt (en %)"; cin >> ir;} while (ir <= 0 && ir >= 100);  ir /=100; // Conversion en %
  /* --- */
  double c(0.),S(S0);                      // Somme intérêts cumulés, Montant restants
  int nbr(0);                              // Nombre remboursement
  while (S > 0.){
    ++nbr; c+= ir*S; S-= r;
    cout << nbr << ": S=" << S << ", cumul=" << c << endl;
  }
  // for (double S(S0); S > 0.0; S -= r) {++nbr; c += ir * S;}		// Alternative avec boucle for
  
  
  
  cout << "Somme des intérêts encaissés : " << c << " (sur " << nbr << " mois)." << endl;
  return 0;
}
