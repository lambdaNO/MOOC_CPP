#include <iostream>
#include <cmath>
using namespace std;
/* --- */
int main()
{
  /* I = [2,3[ U ]0,1] U [-10,-2] en utilisant les opérateurs logiques traditionnels et seulement < ou == */
  double x(0.);
  /* --- */
  cout << "Saisir x " << endl;
  cin >> x;
  /* --- */
  if ( (!(x < 2.0) && (x < 3.0)) || (!(x < 0.0) && !(x == 0.0) && ((x < 1.0) || (x == 1.0))) || (!(x < -10.0) && ((x < -2.0) || (x == -2.0)))) {
    cout << "x appartient à I" << endl;
  } else {
    cout << "x n'appartient pas à I" << endl;
  }
  return 0;
}
