#include <iostream>
#include <vector>
#include <array>
#include <utility>
using namespace std;
/* --- */
constexpr int nb_etapes(13);
/* --- */
struct Joueur {
	string nom;
	int points;
	unsigned int etapes;
};

/* --- */
array<string, nb_etapes> pendu = {{ "\n\n\n\n\n__________",
"\n |\n |\n |\n |\n__|_______", "\n |\n |\n |\n |\n_/|_______", "\n |\n |\n |\n |\n_/|\\______",
" ______\n |\n |\n |\n |\n_/|\\______",
" ______\n |/\n |\n |\n |\n_/|\\______",
" ______\n |/ |\n |\n |\n |\n_/|\\______",
" ______\n |/ |\n | O\n |\n |\n_/|\\______",
" ______\n |/ |\n | O\n | I\n |\n_/|\\______",
" ______\n |/ |\n | _O\n | I\n |\n_/|\\______",
" ______\n |/ |\n | _O_\n | I\n |\n_/|\\______",
" ______\n |/ |\n | _O_\n | I\n | /\n_/|\\______",
" ______\n |/ |\n | _O_\n | I\n | / \\\n_/|\\______",
}};
/* --- */
int saisir_nb_joueur();
void saisir_info_joueur(vector<Joueur> & L);
string saisir_mot(Joueur & j);
char saisir_lettre(Joueur & j); 
bool bonne_lettre(char l, string& mot, string ref);
/* --- */




/* --- */
int main() {
	
	int nb_joueur(saisir_nb_joueur());
	unsigned int pouvant_jouer(nb_joueur);
	vector<Joueur> joueurs(nb_joueur);
	saisir_info_joueur(joueurs);
	//
	for (size_t i(0); i < nb_joueur && pouvant_jouer > 0; ++i) {
		string mot(saisir_mot(joueurs[i])),mot_trouve;
		for (int j(0); j < 40; ++j) cout << endl;
		if (joueurs[i].etapes < nb_etapes){--(pouvant_jouer);}
		for (size_t j(0); j < mot.size(); ++j) mot_trouve += '_';
		//
		while (mot_trouve!= mot && pouvant_jouer >0) {
			for (unsigned int j(0);	(j < nb_joueur) and (mot_trouve != mot);++j) {
				if ((j != i) and (joueurs[j].etapes < nb_etapes)) {
					cout << endl << "MOT : " << mot_trouve << endl;
					char lettre(saisir_lettre(joueurs[j]));
					if (bonne_lettre(lettre, mot_trouve, mot)) { 
						cout << "Bravo : " << mot_trouve << endl; 
						if (mot_trouve == mot) {
							++(joueurs[j].points);
							cout << "-> GAGNÉ !" << endl; 
						}
					} else {
							++(joueurs[j].etapes);
							cout << "Pas de chance : " << endl;
							cout << pendu[joueurs[j].etapes-1] << endl; 
							if (joueurs[j].etapes >= nb_etapes) {
								cout << "-> PERDU !" << endl; ++(joueurs[i].points); --pouvant_jouer;
							}
					}
			
				}
			}
		}
		if (joueurs[i].etapes < nb_etapes)
		++(pouvant_jouer);
	}
	//
	/*
	cout << endl << "La partie est finie." << endl << "Résultats : " << endl;
	for (unsigned int j(0); j < nb_joueur; ++j) {
		cout << "Joueur " << joueurs[j].nom << " (" << j+1 << ") "; 
		if (joueurs[j].etapes < nb_etapes) {
			cout << "encore en vie ! et avec "<< joueurs[j].points << " point";
			if (joueurs[j].points > 1){
				cout << 's';
			}
		} else {
			cout << "pendu... (points : " << joueurs[j].points << ")"; 	
		
		}
		cout << '.'; 
		cout << endl;
	}
	*/
	
	return 0;
}
/* --- */

int saisir_nb_joueur() {
	int nb_joueur(0);
	do {
		cout << "Saisir le nombre de joueur : " << endl;
		cin >> nb_joueur;
	} while (nb_joueur < 2);
	return nb_joueur;
}

void saisir_info_joueur(vector<Joueur> & L){
	for (size_t i(0); i < L.size(); ++i) {
		cout << "Saisir nom du joueur ("<<i+1<<") : " << endl;
		cin >> L[i].nom;
		L[i].points = 0;	L[i].etapes = 0;	
	}
}
string saisir_mot(Joueur & j) {
	string mot;
	do {
		cout << j.nom << " saisissez un mot : " << endl;
		cin >> mot;
	} while (mot.size() == 0);
	return mot;
}

char saisir_lettre(Joueur & j) {
	char lettre;
	do {
		cout << j.nom << " saisissez une lettre : " << endl;
		cin >> lettre;
	} while (lettre == ' ');
	return lettre;
}
bool bonne_lettre(char l, string& mot, string ref) {
	bool retour = false;
	for (size_t i(0); i < ref.size(); ++i) {
		if ((ref[i] == l) and (mot[i] != l)) { 
			mot[i] = l;	retour = true;
		}
	}
	return retour; 
}
