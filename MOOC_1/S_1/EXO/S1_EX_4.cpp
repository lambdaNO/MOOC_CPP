#include <iostream>
using namespace std;
/* --- */
int main() {
  int x,y;
  double x_d,y_d;
  double a,b,c,d;
  double a_d,b_d,c_d,d_d;
  x = 2; y = 4;
  a = x + y; b = x - y; c = x*y; d = x/y;
  cout << "Int : x = "<< x << " , y = " << y << " a = " << a <<" b = " << b << " c = " << c << " d = " << d << endl;
  x_d = 2; y_d = 4;
  a_d = x_d + y_d; b_d = x_d - y_d; c_d = x_d*y_d; d_d = x_d/y_d;
  cout << "Double : x = "<< x_d << " , y = " << y_d << " a = " << a_d <<" b = " << b_d << " c = " << c_d << " d = " << d_d << endl;
}
