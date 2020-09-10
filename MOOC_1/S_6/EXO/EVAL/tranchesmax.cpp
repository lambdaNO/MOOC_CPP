#include <iostream>
#include <cmath>
#include <array>
#include <vector>
#include <string>
using namespace std;
/* --- */


/* --- */
int somme_consecutifs_max(vector<int> const & l);
vector<size_t> lignes_max (vector<vector<int>> const & m);
vector<vector<int>> tranches_max(vector<vector<int>> m);
/* --- */
int main(){
/*
	vector<vector<int>> m = {
		{2, 1, 0, 2},
		{0, 1, 0, 3},
		{1, 3, 0, 0},
		{0, 2, 2, 0}
	};
	m = {
		{2, 1, 0, 2, 0, 3, 2},
		{0, 1, 0, 7, 0},
		{1, 0, 1, 3, 2, 0, 3, 0, 4},
		{5, 0, 5},
		{1, 1, 1, 1, 1, 1, 1}
	};
	m = {
		{2, 1, 0, 2, 0, 3, 2},
		{0, 1, 0, 7, 0},
		{1, 0, 1, 3, 2, 0, 3, 0, 4},
		{},
		{1, 1, 1, 1, 1, 1, 1}
	};
	m = {
		{2, 1, 0, 2, 0, 3, 2},
		{2, 1, 0, 2, 0, 3, 2},
		{2, 1, 0, 2, 0, 3, 2},
		{2, 1, 0, 2, 0, 3, 2},
		{2, 1, 0, 2, 0, 3, 2},
		{2, 1, 0, 2, 0, 3, 2}
	};
	m = {};
	vector<vector<int>> M(tranches_max(m));
	for (auto i : M) {
		for (auto j : i) {
			cout << j << " " ;
		}
		cout << endl;
	}
*/
	

    return 0;
}
/* --- */

int somme_consecutifs_max(vector<int> const & l){
  int p_sum(0),c_sum(0);
	for (auto elt : l) {
		//cout << elt << " p = " << p_sum << " c = " << c_sum << endl;
		if (elt > 0) {
			p_sum+=elt;	
			if (p_sum > c_sum){c_sum = p_sum;}	
		} else {
			p_sum = 0;
		}
	}
	//cout << " -> " << " p = " << p_sum << " c = " << c_sum << endl;
	return c_sum;
}

vector<size_t> lignes_max (vector<vector<int>> const & m){
	int p_size(0), c_size(0);
	vector<int> sum_vec;
	vector<size_t> max_line;
	for (auto l : m) {
		p_size = somme_consecutifs_max(l);
		sum_vec.push_back(p_size);
		if (p_size >= c_size) {
			c_size = p_size;
		}
	}
	//cout << "c = " << c_size << endl;
	for (size_t i(0); i < sum_vec.size(); ++i) {
		//cout << "-> " << sum_vec[i] << endl;
		if (sum_vec[i] == c_size) {
			max_line.push_back(i);
		}
	}
	return max_line;
}
vector<vector<int>> tranches_max(vector<vector<int>> m) {
	vector<size_t> idx(lignes_max(m));
	vector<vector<int>> res;
	for (auto l : idx) {
		//cout << "l  = " << l << endl;
		res.push_back(m[l]);
	}
	return res;
}
