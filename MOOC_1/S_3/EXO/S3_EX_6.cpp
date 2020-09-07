#include <iostream>
#include <cmath>
using namespace std;
int main(){
  double u(1.);   // Initiation de la suite (u_0)
  double v(u);    // Initiation de la série v par rapport à u
  cout << "u_{0} = " << u << endl;
  // u=u/(n+1) <=> u/=n
  for (int n(1); n <= 100; ++n){u/=n;v+=u;cout << "u_{"<<n<<"} = " << u <<" \t v_{"<<n<<"} = " << v << endl;}
  return 0;
}
