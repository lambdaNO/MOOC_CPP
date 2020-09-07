#include <iostream>
using namespace std;
/* --- */
// Prototypes
unsigned int cherche(unsigned int b_inf, unsigned int b_sup, int coup = 0);
constexpr int MIN(1);
constexpr int MAX(100);
/* --- */
// Main
int main() {
	cout << "Choisir un nombre entre "<< MIN << " et " << MAX << endl;
	cout << "---" << endl;
	int nb_coup(cherche(MIN,MAX));
	cout << "---" << endl;
	if (nb_coup<0){
		cout << "Tu triches" << endl;
	} else {
		cout << "J'ai trouvé en " << nb_coup << " coup(s) " << endl;
	}
	return 0;
}

unsigned int cherche(unsigned int b_inf, unsigned int b_sup, int nb){
	unsigned int pivot((b_inf+b_sup)/2);
	char ans('x');
	if (b_sup < b_inf) {cout << "impossible : " << b_sup << " < " << b_inf << " !! " << endl; return -1;} 
	cout << "=> [ "<< b_inf << " , "<< b_sup << " ] => # coup =" << nb << endl;
	do {
		cout << "Nombre <, > ou = à " << pivot << endl; cin >> ans;
	} while (ans != '=' && ans != '<' && ans != '>');
	switch (ans){
		case '=' : return nb;
		case '<' : return cherche(b_inf,pivot-1,nb+1);
		case '>' : return cherche(pivot+1,b_sup,nb+1);
	}
}
