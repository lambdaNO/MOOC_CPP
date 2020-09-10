#include <iostream>
#include <vector>
#include <array>
#include <utility>
using namespace std;
/* --- */
struct Equipe {
	string nom;
	int but_marques;
	int but_encaisses;
	int score;
};

struct Match {
	int eqp_A;
	int eqp_B;
};
/* --- */
void saisie_score(array<Equipe, 4> & P, array<Match,6> const & M);
bool est_Meilleur(Equipe & A, Equipe & B);



/* --- */


	

/* --- */
int main() {
	
	array<Match,6> 	Liste = {Match({3,1}),Match({2,0}),Match({3,0}),Match({2,1}),Match({0,1}),Match({3,2})};
	array<Equipe,4> Poule = {Equipe({"Angleterre",0,0,0}),Equipe({"Croatie",0,0,0}),Equipe({"France",0,0,0}),Equipe({"Suisse",0,0,0})};

	saisie_score(Poule,Liste);
	
	
	return 0;
}
/* --- */

void saisie_score(array<Equipe, 4> & P, array<Match,6> const & M) {
	for (auto m : M) {
		cout << P[m.eqp_A].nom << " - " << P[m.eqp_B].nom << endl;
		array<int,2> score;
		cin >> score[0]>>score[1];
		P[m.eqp_A].but_marques += score[0];
		P[m.eqp_A].but_encaisses += score[1];
		P[m.eqp_B].but_marques += score[1];
		P[m.eqp_B].but_encaisses += score[0];
		//
		if (score[0] > score[1]) {					// Victoire equipe A
			P[m.eqp_A].score +=3;
		} else if (score[0] < score[1]) {			// Victoire equipe B
			P[m.eqp_B].score +=3;
		} else {									// Match nul
			P[m.eqp_A].score+= 1; P[m.eqp_B].score+=1;
		} 	// Défaite entraine + 0
	}
	cout << endl;
	cout << "Resultats " << endl;
	for (auto p : P) {
		cout << p.nom << "\t But marqués : " << p.but_marques << "\t But encaissés : " << p.but_encaisses << "\t Score : " << p.score << endl;
	}
	for (size_t i(0); i < P.size(); ++i){
		for (size_t j(P.size()-1); j>i; --j) {
			if (est_Meilleur(P[j],P[j-1])) {
				swap(P[j],P[j-1]);
			}
		}
	}
	cout << endl;
	cout << "Classement " << endl;
	for (auto p : P) {
		cout << p.nom << "\t Score : " << p.score << endl;
	}
	
}
bool est_Meilleur(Equipe & A, Equipe & B) {
	if (A.score > B.score) {return true;}
	else if (A.score < B.score) { return false;}
	//
	int but_A = A.but_marques - A.but_encaisses;
	int but_B = B.but_marques - B.but_encaisses;
	if (but_A > but_B) {return true;}
	else if (but_A < but_B){return false;}
	//
	if (A.but_marques > B.but_marques) {return true;} 
	else if (A.but_marques < B.but_marques) {return false;}
	//
	return true;
}
