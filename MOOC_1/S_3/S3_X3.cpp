#include <iostream>
using namespace std;
/* --- */
// for(déclaration_et_initialisation; condition; incrémentation){bloc_instruction;}
// la variable de parcours est local à la fonction (i n'existe pas en dehors de la boucle)
/* --- */
int main(){
  cout << "Quiz 1" << endl;
  for (int i(0); i< 3; ++i){
    for (int j(0); j<4;++j){
      if (i==j){cout<<"*";}
      else {cout<<j;}
    }
    cout << endl;
  }
  cout << "Quiz 2" << endl;
  for (int i(0); i< 3; ++i){
    for (int j(0); j<i;++j){
      cout<<j;
    }
    cout << endl;
  }
  return 0;
}

