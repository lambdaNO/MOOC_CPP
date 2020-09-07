#include <iostream>
#include <array>        
#include <string>
using namespace std;
constexpr unsigned int T(100);
/* --- */
/* ---------------------------------------------- */
int main(){

	array<bool, T> sup;
	// Initialisation 
	for (auto & elt : sup) {elt = false;};
	// Cas spéciaux 0,1
	sup[0] = true; sup[1] = true;
	//
	for (size_t i(0); i<sup.size();i++){
		if (!sup[i]) {
			cout << " i = " << i << " | ";
			size_t mul(2*i);
			while(mul < sup.size()) {
				cout <<mul << ", ";
				sup[mul] = true;
				mul = mul+i;
			}
			cout << endl;
		}
	}
	
	for (size_t i(0); i<sup.size();i++) {
		if (!sup[i]) { cout << i<<", ";}
	}
	cout << endl;
}



