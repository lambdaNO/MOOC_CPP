#include <iostream>
#include <cmath>
using namespace std;
int main(){
  int n(0),diviseur(1);
  bool pr(true);
  /* --- */
  do {cout << "Entrez un nombre entier > 1 : "; cin >> n; } while (n <= 1);
  /* --- */
  if (n%2 == 0){
    if (n != 2){ pr = false; diviseur = 2;}
  } else {
      const double b_sup(sqrt(n));
      //for (int i(3); pr && (i<=b_sup); i+=2){
      for (unsigned long int i(3); pr && (i<=b_sup); i+=2){		// Pour augmenter la taille du diviseur admissible 
        if (n%i == 0){pr = 0; diviseur = i;}	
      }
    }
  cout << n ;
  if (pr) { cout << " est premier" << endl;}
  else { cout << " n'est pas premier, car il est divisible par " << diviseur << endl;}
  /* --- */
  return 0;
}
