#include <iostream>
#include <cmath>
using namespace std;
/* --- */
int main()
{
  /* Test sur x = {-1,0,1,2,3,8}*/
  double x(0.);
  double eval(0.);
  /* --- */
  cout << "Saisir x" << endl;
  cin >> x;
  /* --- */
  cout << "Exp 1 : x/(1-exp(x))" << endl;
  if (x==0.){
    cout << "   Invalide"  << endl;
  } else {
    eval = x/(1-exp(x));
    cout << "   eval = " << eval << endl;
  }
  cout << "Exp 2 : xlog(x)exp(2/(x-1))" << endl;
  if ( (x <= 0) || (x == 1)){
    cout << "   Invalide"  << endl;
  } else {
    eval = x*log(x)*exp(2/(x-1));
    cout << "   eval = " << eval << endl;
  }
  cout << "Exp 3 : (-x - sqrt(x*x - 8.*x))/(2-x)" << endl;
  if ((x*x - 8.0*x < 0.0) or (x == 2.0)){
    cout << "   Invalide"  << endl;
  } else {
    eval = (-x - sqrt(x*x - 8.*x))/(2-x);
    cout << "   eval = " << eval << endl;
  }
  cout << "Exp 4 :  sqrt((sin(x) - x/20.0) * log(x*x - 1.0/x))" << endl;
  if (x == 0.){
    cout << "   Invalide"  << endl;
  } else {
    double res = x*x - 1.0/x;
    if (res <= 0) {
      cout << "   Invalide"  << endl;
    } else {
      double res_1 = (sin(x) - x/20.0) * log(x*x - 1.0/x);
      if (res_1 < 0){
        cout << "   Invalide"  << endl;
      } else {
        eval = sqrt(res_1);
        cout << "   eval = " << eval << endl;
      }
    }
  }
  return 0;
}
