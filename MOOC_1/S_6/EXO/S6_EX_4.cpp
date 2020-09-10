#include <iostream>
#include <cmath>
#include <array>
#include <vector>
#include <string>
using namespace std;
constexpr char sep(' ');
/* --- */
/* --- */
bool nextToken(string const& str, size_t& debut, size_t& longueur);
bool is_sep(char c);
/* --- */
int main()
{
  string str = "heuu bonjour, voici ma chaîne ! ";
  size_t debut(0), longueur(0);
  /* ------ */
  /*
  cout << "Saisir un str : "<<endl;
  cin >> str;   // Visiblement une alternative avec getline(cin,str)  -> getline lit les caractères à partir d'un flux d'entrée et les place dans une chaîne:
  */
  while (nextToken(str, debut, longueur)) {
    cout << "'" << str.substr(debut, longueur) << "'" << endl;
    debut += longueur;
  }

	return 0;
}
/* --- */
bool is_sep(char c){
  return c == sep;
}
bool nextToken(string const& str, size_t& debut, size_t& longueur){
  const size_t taille(str.size());
  //cout << "NT taille = " << taille << " debut = " << debut <<endl; 
  while (debut < taille && is_sep(str[debut])) {
	  //cout << "\tsep_?("<<str[debut]<<") = " << is_sep(str[debut]) << endl;
	  ++debut;
  }
  longueur = 0;
  for (size_t i(debut); (i < taille && !is_sep(str[i])); ++longueur, ++i){
		//cout << "\t\tstr["<<i<<"] = " << str[i] << "\tlongueur = " << longueur << endl;
  }
  cout << "debut = " << debut << " longueur = " << longueur << endl;
  return (longueur!=0);
}
