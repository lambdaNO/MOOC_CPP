#include <iostream>
#include <vector>
#include <memory>
using namespace std;
/* --- */

int main()
{
	/*
	int x(19);
	int* p;			// Init d'un pointeur
	int& y(x);		// y est une référence de x (une autre étiquette)
	
	p = &x;			// p pointe sur la variable x
	x = 25;			// x est modifié
	*p = 20;		// la valeur associée à l'adresse mémoire stockée dans p est mise à 20 (~> x = 20)
					// y est une référrence de x
	cout << x << " " << y << " " << *p << endl;

	
	int a;
	int b;
	int* q;		// Init d'un pointeur

	a = 1;		// Init de a
	q = &a;		// p point sur a
	b = a;		// Affectation de variable simple
	a = 2;		// modification de la valeur de a (sans changer b ??)

	cout << a << " " << b << " " << *q << endl;
	*/
	/*
	int a;
	int b;
	int* p;
	int* q;
	int* r;

	a = 1;
	b = 2;
	p = &a;		// p pointe sur a
	q = &b;		// q pointe sur b
	*p = *q;	// valeur de p devient la valeur de q ( valeur de b = 2)
	*q = *p;	// valeur de q devient la valeur de p ( valeur de a = 2 | voir modif ligne précédente)

	cout << a << " " << b << " " << *p << endl;
	*/
	
	
	int a(7);
	int b(3);
	int* p;
	int* q;

	p = &b;
	cout << "1. " << a << " " << *p << endl;

	q = p;
	// ...code manquant1...
	*q = a;
	//
	cout << "2. " << *q << endl;

	p = q;
	// ...code manquant2...
	*p = a;
	//
	cout << "3. " << *q << endl;

	p = &b;
	a = *p;
	p = p + 1;
	cout << "4. " << *q << endl;
	
	
	
	
  return 0;
}
