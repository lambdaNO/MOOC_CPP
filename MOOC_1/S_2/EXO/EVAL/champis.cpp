#include <iostream>
#include <cmath>
using namespace std;
/* --- */
int main(){
  bool Q_foret(false), Q_convexe(false), Q_lamelle(false), Q_anneaux(false);
  bool C_agaric(false), C_amanite(false), C_cepe(false),C_coprin(false),C_girolle(false),C_pied(false);
  /* --- */
  cout << "Pensez à  un champignon : amanite tue-mouches, pied bleu, girolle," << endl
       << "cêpe de Bordeaux, coprin chevelu ou agaric jaunissant." << endl << endl;
  /* --- */
  cout << "Est-ce que votre champignon vit en forêt (1 : oui, 0 : non) ? ";
  cin >> Q_foret;
  if (Q_foret){
    cout << "Est-ce que votre champignon a un chapeau convexe (1 : oui, 0 : non) ? ";
    cin >> Q_convexe;
    if (Q_convexe){
      cout << "Est-ce que votre champignon a un anneau (1 : oui, 0 : non) ? ";
      cin >> Q_anneaux;
      if (Q_anneaux){
        C_amanite = true;
      } else {
        C_pied = true;
      }
    } else {
      cout << "Est-ce que votre champignon a des lamelles (1 : oui, 0 : non) ? ";
      cin >> Q_lamelle;
      if (Q_lamelle){
        C_girolle = true;
      } else {
        C_cepe = true;
      }
    }
  } else {
    cout << "Est-ce que votre champignon a un chapeau convexe (1 : oui, 0 : non) ? ";
    cin >> Q_convexe;
    if (Q_convexe) {
      C_agaric = true;
    } else {
      C_coprin = true;
    }
  }
  /* --- */
  cout << "==> Le champignon auquel vous pensez est ";
  if (C_agaric){cout << "l'agaric jaunissant";}
  else if (C_amanite) {cout << "l'amanite tue-mouches";}
  else if (C_cepe) {cout << "le cêpe de Bordeaux";}
  else if (C_coprin) {cout << "le coprin chevelu";}
  else if (C_girolle) {cout << "la girolle";}
  else if (C_pied){cout << "le pied bleu";}

  return 0;
}
