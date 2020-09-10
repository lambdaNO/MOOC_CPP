#include <iostream>
#include <vector>
#include <array>
using namespace std;
/* --- */
typedef unsigned int Position;
typedef vector<int> Sequence;
/* --- */
struct SousSequence {
	Position debut;
	Position fin;
	int somme;
};
/* --- */
SousSequence tranche_1(Sequence const & s);
SousSequence tranche_2(Sequence const & s);
SousSequence tranche_3(Sequence const & s);
void affiche(SousSequence s, Sequence seq);
Sequence saisir_sequence();
/* --- */
int main() {
	Sequence seq = { 11, 13, -4, 3, -26, 7, -13, 25, -2, 17, 5, -8, 1};
	// Sequence seq = { -3, -4, -1, -2, -3 };
	// Sequence seq = { -1, -4, -3, -2, -3 };
	// Sequence seq = { 3, 4, 1, 2, -3 };
	// Sequence seq = { 3, 4, 1, 2, 3 }; 
	// Sequence seq = { 3, -1, -1, -1, 5 }; 
	// Sequence seq = { -5, -4, 1, 1, 1 };
	affiche(tranche_1(seq),seq);
	affiche(tranche_2(seq),seq);
	affiche(tranche_3(seq),seq);
	
	char again;
	do {
		Sequence mySeq(saisir_sequence());
		affiche(tranche_3(mySeq),mySeq);
		cout << "Continuer ? [o] = oui/ [n] = non " << endl;
		cin >> again;
	} while (again == 'o');
	
	return 0;
}
/* --- */
SousSequence tranche_1(Sequence const & s){
	SousSequence sub({0,0,0});
	if (s.size() != 0) {
		for (Position debut(0); debut < s.size(); ++debut) {
			for (Position fin(debut); fin < s.size(); ++fin) {
				int sum(0);
				for (Position p(debut); p <= fin; ++p) {
					sum+=s[p];
				}
				if (sum > sub.somme) {
					sub.debut = debut; sub.fin = fin; sub.somme = sum;
				}
			}	
		}
	}
	return sub;
}
SousSequence tranche_2(Sequence const & s){
	SousSequence sub({0,0,0});
	if (s.size() != 0) {
		sub.somme = s[0];
		for (Position debut(0); debut < s.size(); ++debut) {
			int sum(0);
			for (Position fin(debut); fin < s.size(); ++fin) {
				sum+=s[fin];
				if (sum > sub.somme) {
					sub.debut = debut; sub.fin = fin; sub.somme = sum;
				}
			}	
		}
	}
	return sub;
}
SousSequence tranche_3(Sequence const & s){
	SousSequence sub({ 0, 0, 0 }); 
	if (s.size() != 0) {
		sub.somme = s[0];
		int sum(0);
		Position debut(0);
		for (Position fin(0); fin < s.size(); ++fin) {
			sum+=s[fin];
			if (sum > sub.somme) {
				sub.debut = debut; sub.fin = fin; sub.somme = sum;
			}
			if (sum<=0) {
				debut = fin+1;
				sum = 0;
			}
		}
	}
	return sub;
	
}

void affiche(SousSequence s, Sequence seq) {
	cout << "La tranche maximale est ";
	for (Position i(s.debut); i <= s.fin; ++i) {cout << seq[i] << ", ";	}
	cout << endl << "de somme " << s.somme << endl;
}


Sequence saisir_sequence(){
	Sequence seq;
	int s(0);
	do {
		cout << "Saisir elt (0 = fin) " << endl;
		cin >> s;
		if (s != 0) {
			seq.push_back(s);
		}
	} while ( s!= 0);
	
	cout << "Sequence : ";
	for (auto elt : seq) {cout << elt << ", ";} cout << endl;
	cout << "Taille = " << seq.size() << endl;
	return seq;
}
