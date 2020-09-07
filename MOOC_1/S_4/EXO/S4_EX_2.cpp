#include <iostream>
using namespace std;
/* --- */
// Prototypes
unsigned int sum_rec(unsigned int n);

/* --- */
// Main
int main() {
	char rep('n');
	unsigned int n(0);
	do {
		cout << "Saisir entier n = " << endl;
		cin >> n;
		cout << "S("<< n <<") = " << sum_rec(n) << endl;
    do {
		cout << "Voulez-vous recommencer [o/n] ? "; cin >> rep;
		} while ((rep != 'o') and (rep != 'n'));
	} while (rep == 'o');
  return 0;
}
// Implem des fonctions
unsigned int sum_rec(unsigned int n){
  if (n <= 0){ return 0;}
  else {return n+sum_rec(n-1);}
}
