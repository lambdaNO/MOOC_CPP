#include <iostream>
using namespace std;
/* --- */
// for(déclaration_et_initialisation; condition; incrémentation){bloc_instruction;}
// la variable de parcours est local à la fonction (i n'existe pas en dehors de la boucle)
/* --- */
int main()
{
  /*
  // Incrément différent de 1
  for (int p(0); p <10; p+=2){
    cout << "p = " << p << endl;
  }
  */
  cout << " -- " << endl;
  // Décrément
  /*
  for (int k(10); k > 0; --k){
    cout << "k = " << k << endl;
  }
  */
  double note,somme(0.);
  int nb_note(0);
  cout<< "Nombre de notes ? " << endl;
  cin >> nb_note;
  if (nb_note != 0){
    for (int i(1);i<=nb_note;++i){
      cout << "Saisir note n°"<<i << endl;
      cin >> note;
      somme += note;
    }
    cout << "Moyenne = " << somme/nb_note << endl;
  }

  return 0;
}
