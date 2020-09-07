#include <iostream>
using namespace std;
/* --- */
// Prototypes
double moyenne(double x, double y);
/* --- */
// Main
int main() {
  double note1(0.),note2(0.);
  cout << "saisir deux notes "<< endl;  cin >> note1 >> note2;
  cout << "moyenne " << moyenne(note1,note2) << endl;

  return 0;
}
// Implem des fonctions
double moyenne(double x, double y){
  return (x+y)/2.;
}
