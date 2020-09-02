#include <iostream>
using namespace std;

int main()
{
  cout << "Donnez l'heure de début de la location (un entier) : ";
  int debut;
  cin >> debut;

  cout << "Donnez l'heure de fin de la location (un entier) : ";
  int fin;
  cin >> fin;

  /*****************************************************
   * Completer le code a  partir d'ici
   *****************************************************/
   int montant(0);
   int montant_1(1),duree_1(0);  // [0,7]h ou [17,24]h
   int montant_2(2),duree_2(0);  // [7,17]h
   /* --- */
   if ( (0<=debut) && (debut <= 24) && (0<=fin) && (fin <= 24) ){
     if (debut < fin){
       /* --- */
       // date debut in [0,7]
       if (debut >= 0 && debut <= 7){
         // fin dans [0,7]
         if (fin >= 0 && fin <= 7){ duree_1 = fin - debut; }
         // fin dans [7,17]
         else if (fin >= 7 && fin <= 17) {duree_1 = 7- debut; duree_2 = fin - 7;}
         // fin dans [17,24]
         else if (fin >= 17 && fin <= 24) {duree_1 = 7 - debut + fin - 17; duree_2 = 10;}
         // date debut in [7,17]
       } else if (debut >= 7 && debut <= 17){
         // fin dans [7,17]
         if (fin >= 7 && fin <= 17) {duree_2 = fin - debut;}
         // fin dans [17,24]
         else {duree_2 = 17 - debut; duree_1 = fin - 17;}
         // date debut in [17,24]
       } else {
         duree_1 = fin - debut;
       }
       /* --- */
       //cout << "debut = " << debut << " fin = " << fin << " duree = (" << duree_1 << ", " << duree_2 << ")" << endl;
       cout << "Vous avez loué votre vélo pendant" << endl;
       if (duree_1 != 0) {
         cout << duree_1 <<" heure(s) au tarif horaire de " << montant_1 << " franc(s)" << endl;
       }
       if (duree_2 != 0) {
         cout << duree_2 <<" heure(s) au tarif horaire de " << montant_2 << " franc(s)" << endl;
       }
       montant = duree_1*montant_1 + duree_2*montant_2;
       cout << "Le montant total à payer est de " << montant << " franc(s)." << endl;
       /* --- */
     } else {
       if (debut == fin){
         cout << "Bizarre, vous n'avez pas loué votre vélo bien longtemps !" << endl;
       } else {
         cout << "Bizarre, le début de la location est après la fin ..." << endl;
       }
     }
   } else {
     cout << "Les heures doivent être comprises entre 0 et 24 !" << endl;
   }

  /*******************************************
   * Ne rien modifier aprÃ¨s cette ligne.
   *******************************************/

  return 0;
}
