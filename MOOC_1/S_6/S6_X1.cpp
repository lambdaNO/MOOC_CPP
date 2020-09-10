#include <iostream>
#include <string>
using namespace std;
/* --- */
// String :
// Préambule : #include <string>
// Déclaration :
//               string identificateur;       // Intialisé à la chaine vide
// Déclaration et initialisation :
//               string identificateur("mon_texte");
// Remarque :
//    * String utilise des "."      // un ou plusieurs caractères
//    * char utilise des '.'        // caractètre unique
//        - Déclaration : char u; u = 's';
//        - Déclaration et initialisation : char c('x');
// Opération de concaténation : Opérateur "+"
//    chaine1 + chaine2;
// Remarque : Combinaisons possibles pour la concaténation :
//  string + string; string + char; string + "..." où "..." est appelée expression littérale
// Opération de comparaison : == et !=
//    Ex : do {reponse = poser_question();} while(reponse != "oui");
/* --- */
int main()
{
  // Ex :chaine = ""; chaine2 ="test"; chaine ="test3"; chaine = "a"; // Concaténation automatique
  string chaine, chaine2("test"); chaine = "  test3"; chaine = 'a';
  // Ex : Concaténation :
  string nom,prenom, famille;
  nom = prenom +" "+ famille;
  // Ex concaténation 2 :
  string mot0("des"), mot1(mot0), mot2("question"),s(mot1 + ' ' + mot2 + "s");;
  cout << s << endl;

  return 0;
}
