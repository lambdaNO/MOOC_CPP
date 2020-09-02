#include <iostream>
using namespace std;
/* --- */
// if (condition){ bloc_vrai } else { bloc_faux }
/* --- */
int main() {
  /*
  int n;
  cout << "Saisir un nombre n = " << endl;
  cin >> n;
  if (n<5) {
    cout << "Le nombre est "<< n << endl;
    cout << "Nombre plus petit que 5" << endl;
  } else {
    cout << "Nombre plus grand ou égal à 5" << endl;
  }

  if (n<3) {
    cout << "Le nombre est "<< n << endl;
    cout << "Nombre plus petit que 3" << endl;
    cout << "Branchement sans else." << endl;
  }

  cout << "Bye-Bye !" << endl;
  */
  int x,y,z;
  cout << "lire x : " << ; cin >> x;
  cout << "lire y : " << ; cin >> y;
  cout << "lire z : " << ; cin >> z;
  /* --- */
  if (x==y){
    if (y==z){
      cout << "x = y = z" << endl;
    } else {
      cout << "x = y" << endl;
    }
  } else {
    if (x==z) {
      cout << "x = z" << endl ;
    } else {
      if (y==z) {
        cout << "y = z" << endl ;
      } else {
        cout << "x,y,z sont différentes" << endl ;
      }
    }
  }



  return 0;
}
