#include <iostream>
#include <vector>
#include <array>
#include <utility> // swap
using namespace std;
/* --- */
typedef int Elt;
typedef vector<Elt> Tableau;
/* --- */
void affiche(Tableau const & T, size_t j = -1, size_t kpj = -1);
void shell(Tableau & T);
void echanger(Elt & e1, Elt & e2);
/* --- */

/* --- */
int main() {
	Tableau T({ 3, 5, 12, -1, 215, -2, 17, 8, 3, 5,13,18,23,5,4,3,2,1 });
	affiche(T); cout << "---" << endl;
	shell(T);	cout << "---" << endl;
	affiche(T); 
	return 0;
}
/* --- */
void shell(Tableau & T){
	for (size_t k(T.size()); k >= 1; k /= 2) {
		for (size_t i(k+1); i < T.size(); ++i) {
			size_t j(i-k);
			//cout << "T[" << j<< "] = " << T[j] << "\tT[" << j+k<< "] = " << T[j+k] << endl;
			affiche(T,j,k+j);
			if (T[j] > T[j+k]) {
				swap(T[j], T[j+k]);
				j = j-k;
			} else {
				j = 0;
			}			
		}
	}
	
}


void affiche(Tableau const & T, size_t j, size_t kpj) {
	for (size_t i(0); i< T.size(); ++i) {
		if (i == j || i == kpj) {
			cout <<"[" << T[i] << "] ";
		} else {
			cout << T[i] << " ";
		}
	} 
	cout << endl;
}
