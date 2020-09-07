#include <iostream>
using namespace std;
/* --- */
// for(déclaration_et_initialisation; condition; incrémentation){bloc_instruction;}
// la variable de parcours est local à la fonction (i n'existe pas en dehors de la boucle)
/* --- */
int main()
{
  /*
  for (int i(0); i <5; ++i){
    cout << "i = " << i << " i^2 = " << i*i << endl;
  }
  */
  /*
  int t(5);
  for (int i(0); i <= 10; ++i){
    cout << t<<" x "<<i << " = " << t*i << endl;
  }
  */
  for (int i(0); i < 5; ++i){
    cout << i;
    if (i % 2 == 0) {cout << "p";}
    cout << " ";
  }
  cout << endl;

  return 0;
}
