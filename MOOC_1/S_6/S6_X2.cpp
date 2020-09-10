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
//
// Manipulation :
//  Accès direct : s[i] avec i in |[0,t-1]| avec t la taille de la chaine; le retour est de type char;
//
// Fonction spéciale :
//      Appel : nom_chaine.nom_fonction(arg1,arg2,...);
//   .size()  : taille de la chaine (type size_t)
//   .insert(position, pattern) insère  partir de l'indice (position) la chaine (pattern)
//   .replace(position,n,pattern) replace les n caractrès d'indices |[position,position+n-1]| par la chaine pattern
//        Note : Replace peut aussi être utiliser pour supprimer des éléments de la chaine,
//   .find(pattern)  :  renvoie l'indice dans la chaine du premier caractère de l'occurrence la plus à gauche de string pattern
//   .rfind(pattern) :  renvoie l'indice dans la chaine du premier caractère de l'occurrence la plus à droite de string pattern
//        Remarque : si find() et rfind() ne peuvent s'appliquer, elles retournes la valeur prédéfinie string::npos
//                  Ex : exemple = "baabbaab";  if (exemple.find("xy")!= string::npos){...}
//    .substr(depart,longueur) ; renvoie la sous-chaîne de longueur(longueur) et commençant à l'indice départ
//    ...
/* --- */
int main()
{
  string chaine("ABCD");
  char prem(chaine[0]), dern(chaine[3]);
  //
  string essai("essai");
  string test;

  for(int i(1); i <= 3; ++i) {
      test = test + essai[6-2*i];
      test = essai[i] + test;
  }
  cout << test << endl;

  string exemple("abcd");
  exemple.insert(1,"xx");   // => axxbcd

  exemple = "abcd";
  exemple.replace(1,2,"1234");  // => a1234d

  exemple = "abcd";
  exemple.replace(1,2,"");      // => ad

  exemple = "baabbaab";
  exemple.find("ab");   // => 2
  exemple.rfind("ab");  // => 6

  exemple = "Salut à tous !";
  exemple.substr(8,4);  // => "tous"

  string s("MOOC");
  cout << s[s.size() - 1] << " ";
  cout << s.find("O") << " ";
  cout << s.replace(1, 2, "E") << " ";
  cout << s << endl;


  return 0;
}
