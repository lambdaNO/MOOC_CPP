#include <iostream>
using namespace std;
/* --- */
// Prototypes (définir les signatures des fonctions)
double saisie_et_calcul();  // Prototype de fonction (permet de faire comprendre au compilateur le type de la fonction, l'implem pouvant être réalisée après)
double score(double x, double y);
/* --- */
// Classe main (appels aux fonctions)
int main(){
  cout<< "Joueur 1" << endl;
  double sc_j1 = saisie_et_calcul();
  cout<< "Joueur 2" << endl;
  double sc_j2 = saisie_et_calcul();
  /* --- */
  if (sc_j1 > sc_j2) {cout << "J1 gagne" << endl;}
  else if (sc_j2 > sc_j1){cout << "J2 gagne" << endl;}
  else {cout << "Egalité" << endl;}
  return 0;
}
/* --- */
// Implem des fonctions - Définitions 
double saisie_et_calcul(){
  double nb_pts(0.),tps_jeu(0.);
  do {cout << "Nb Points ? [0,100]"; cin >> nb_pts;} while (nb_pts < 0. && nb_pts > 100.);
  do {cout << "Tps joueur ? [0,60]"; cin >> tps_jeu;} while (tps_jeu < 0. && tps_jeu > 60.);
  return score(nb_pts,tps_jeu);
}
double score(double nb_pts, double tps_jeu){
  double score_joueur(0.);
  if (tps_jeu != 0.){
    score_joueur = 1000*nb_pts/tps_jeu;
  }
  return score_joueur;
}
