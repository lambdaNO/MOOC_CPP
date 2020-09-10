#include <iostream>
#include <vector>
#include <string>
using namespace std;
/* --- */
// Typedef : donner un autre nom à des types déjà définis (Raccourci d'écriture)
//     Notation : typedef type alias;
//                Avec alias : le nom du nouveau type
//                     type : un type élémentaire ou composé
//    MORALITÉ : définition claire des obbjets que l'on manipule
//               modification de type simplifiée
//               passage plus rapide des paramètres de fonction
/* --- */
typedef vector<double> Vecteur;     // Tableau dynamique de double
typedef vector<Vecteur> Matrice;    // Tableau dynamque de tableau dynamique de double;
//  Matrice <=> vector<vector<double>>
int main()
{
  Matrice rotation(3,Vecteur(3,1.));    // Matrice est donc un tableau dynamique de 3 lignes et 3 colonnes (tableaux dynamiques), chaque colonne est composée de 1.


  return 0;
}
