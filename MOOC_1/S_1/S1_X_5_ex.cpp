#include <iostream>
#include <cmath>    // appels aux fonctions mathématiques (remarque les angles sont exprimés en radians (donc pas hésiter à mutlipier par pi (3.14156)))
using namespace std;
int main(){
  double c(5.0), a(10.0), b(3.0);
  c = a / b;
  cout << c << endl;
  /*---*/
  int i(69);
  int j;
  int k;

  i = i + 1;  // 70
  k = i;      // 70
  j = k;      // 70
  k = k + 1;  // 71

  cout << i << ", " << j << ", " << k << endl;
  /*---*/
  int i2(45);
  int j2(34);
  int k2(12);
  k2 = i2;  // 45
  i2 = j2;  // 34
  j2 = k2;  // 45
  cout << i2 << ", " << j2 << endl;
  /*---*/
  int a1(11);
  int b1(a1 + 4);   // b1 = 15
  int c1(a1 + b1);  // c1 = 26
  a1 += b1 - 5;     // a1 = 11 + 26 - 5 
  cout << a1 << ", " << 2*b1 << ", " << c1 << endl;

int	pif&herucle(12);
	cout<< pif&hercule << endl;
}
