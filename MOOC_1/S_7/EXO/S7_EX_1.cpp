#include <iostream>
using namespace std;
/* --- */
int demander_nombre(int a, int b);
/* --- */
int main()
{
	double v1(42),v2(13),v3(66);
	double* choix;
	switch (demander_nombre(1,3)) {
		case 1: choix = &v1; break;			// & retourne l'adresse mémoire
		case 2: choix = &v2; break;
		case 3: choix = &v3; break;
	}
	cout << "Adresse mémoire associée = " << choix << endl;
	return 0;
}
/* --- */
int demander_nombre(int a, int b){
	if (a > b) { int tmp(b); b=a; a=tmp; }
	int res;
	do {
		cout << "Entrez un nombre entier compris entre "<< a << " et " << b <<" : ";
		cin >> res;
	} while (!(res >= a && res <= b));
	return res;
}
