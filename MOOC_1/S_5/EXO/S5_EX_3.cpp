#include <iostream>
#include <vector>        // Appel à la librairie vector
#include <string>
using namespace std;
/* --- */
vector<vector<double>> lire_matrice();
vector<vector<double>> multiplication(const vector<vector<double>>& Mat1, const vector<vector<double>>& Mat2);
void affiche_matrice(const vector<vector<double>>& M);
/* ---------------------------------------------- */
int main(){
	vector<vector<double>> M1(lire_matrice()),M2(lire_matrice());
	/* --- */
	if (M1[0].size()!= M2.size()){
		cout << "Produit de M1 et M2 impossible - Revoir les dim" << endl;
	} else {
		affiche_matrice(multiplication(M1,M2));
	}
  return 0;
}
/* ---------------------------------------------- */
vector<vector<double>> lire_matrice() {
	int m(0),n(0);
	do {
		cout << "Nombre de lignes = "; cin >> m;
	} while (m < 1);
	do {
		cout << "Nombre de colonnes = "; cin >> n;
	} while (n < 1);
	/* ------- */
	vector<vector<double>> M(m,vector<double>(n));
	for (size_t i(0); i<m; ++i){
		for (size_t j(0); j<n; ++j){
			cout << "M["<<i+1<<","<<j+1<<"] = "; cin>> M[i][j];
		}
	}
	return M;
}
/* --- */
void affiche_matrice(const vector<vector<double>>& M){
	for (auto ligne : M){
		for (auto elt : ligne){
			cout << elt << " ";
		}
		cout << endl;
	}
}
/* --- */
vector<vector<double>> multiplication(const vector<vector<double>>& Mat1, const vector<vector<double>>& Mat2){
	vector<vector<double>> P(Mat1.size(),vector<double>(Mat2[0].size()));
	for (size_t i(0); i< Mat1.size(); ++i){
		for (size_t j(0); j<Mat2[0].size(); ++j){
			for (size_t k(0); k<Mat2.size();++k){
				P[i][j] += Mat1[i][k]*Mat2[k][j];
			}
		}
	}
	return P;
}
