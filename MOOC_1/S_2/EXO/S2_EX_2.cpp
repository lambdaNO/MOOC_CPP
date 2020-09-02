#include <iostream>
#include <cmath>
using namespace std;
/* --- */
int main()
{
  double x(0.);
  /* --- */
  cout << "Saisir x non nul" << endl;
  cin >> x;
  /* --- */
  if (x >= -1 && x < 1) {
    cout << "x appartient à I" << endl;
  } else {
    cout << "x n'appartient pas à I" << endl;
  }
  return 0;
}
