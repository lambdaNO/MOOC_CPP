#include <iostream>
using namespace std;
/* --- */
int main() {
  const int BASE(4);      // le nombre de personnes pour laquelle est conçue la recette de base ;
  int nb_indiv;
  double fromage(800.);   // la quantité de fromage en grammes nécessaire pour BASE personnes
  double eau(2.);         // la quantité d'eau en décilitres nécessaire pour BASE personnes ;
  double ail(2.);         // le nombre de gousses d'ail nécessaires pour BASE personnes
  double pain(400.);       // la quantité de pain en grammes nécessaire pour BASE personnes ;
  cout << "Nombre de personnes " << endl;
  cin >> nb_indiv;
  /* --- */
  double nv_fromage = fromage * nb_indiv / BASE;
  double nv_eau = eau *nb_indiv / BASE;
  double nv_ail = ail*nb_indiv / BASE;
  double nv_pain = pain*nb_indiv / BASE;
  /* --- */
  cout << "Pour faire une fondue fribourgeoise pour "<< nb_indiv << " personnes, il vous faut : " << endl << " - " << nv_fromage << " gr de Vacherin fribourgeois " << endl << " - " << nv_eau << " dl d'eau " << endl << " - " << nv_ail << " gousse(s) d'ail " << endl << " - " << nv_pain << " gr de pain " << endl << " - du poivre à volonté" << endl;

  return 0;
}
