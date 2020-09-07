#include <iostream>
#include <vector>
#include <string>
using namespace std;
/* --- */
//T[0] sera placé dans le nouveau tableau à l'indice T[1],
//T[2] sera placé dans le nouveau tableau à l'indice T[3],
/* ---------------------------------------------- */
vector<int> elements_en_indices(vector<int> & A);
int main(){
	vector<int> A({4,2,8,0,7,1});
	vector<int> B = elements_en_indices(A);
	for (auto elt : B){
		cout << elt << " ";
	}
	cout << endl;
}
vector<int> elements_en_indices(vector<int> & A){
	vector<int> R(A.size()/2);
	for (size_t i(0);i<R.size();++i){
		R[A[2*i+1]]=A[2*i];
	}
	return R;
}
