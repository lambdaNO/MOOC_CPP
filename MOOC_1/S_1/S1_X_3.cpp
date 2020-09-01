#include <iostream>
using namespace std;
/* ------------------------------------------ */
// cout : flot de sortie (out) (e.g. le terminal)
// << : Affichage représente le flot dans lequel va "passer" le flot d'informations
// cin : saisie utilisateur flot d'entrée standard (in)
// >> x : Toujours cette image du flot mais cette fois ce qui entre (on stock la lecture dans la variable x)
// endl : afficher un saut de ligne
// EN FAIT : cout et endl s'appellent normalement std::cout et std::endl;
//          -> utiliser la fonction using namespace std permet d'écrire les appels à std
// remarque : il est possible d'écrire cin >> n1 >> n2 >> n3 permettant la lecture et l'affectation de plusieurs variables en même temps - mais plus "simple" d'écrire cin>>n1;cin>>n2;cin>>n3;
/* ------------------------------------------ */
int main(){
  int n(4);
  int n_carre;
  n_carre = n*n;
  cout << "n = " << n << ";" << endl;
  cout << "n = " << n << " / 2*n = " << 2*n << ";" << endl;
  cout << "n = " << n << " / n^2 = " << n_carre << ";" << endl;
  /* --- */
  int a(2),b(1);
  b = a*(b+1);
  cout<< "a = "<< a << ", b = " << b << endl;
  /* --- */
  int c(1),d(2);
  c = d;
  d = c;
  cout<< "c = "<< c << ", d = " << c << endl;
  /* --- */
  int e(1),f(2);
  int tmp(e);   // Variable auxilliaire pour l'échange
  e = f;  f = tmp;
  cout<< "e = "<< e << ", f = " << f << endl;
  /* --- */
  int g;
  cout << "Entrer une valeur pour g : ";
  cin >> g;
  int g_carre = g*g; // int g_carre; g_carre = g*g;
  cout << "g = " << g << " et g^2 = " << g_carre << endl;
}
