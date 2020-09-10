#include <iostream>
#include <vector>
#include <array>
using namespace std;

enum alphabet { alpha, beta, gamma, delta, epsilon, zeta };
enum langage { Java, C, D, Scala, Haskel, Cpp };
enum direction { N = 2, NE, E, SE, S, SO, O, NO };


int main() {
	
	int i(zeta);
	cout << i << endl;
	//
	for (int i(D); i <= Cpp ; ++i) {
		cout << i << " ";
	} cout << endl;
	//
	for (int i(E); i < O ; ++i) {
		cout << i << " ";
	} cout << endl;
	
	return 0;
	
}
