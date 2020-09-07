#include <iostream>
using namespace std;
/* --- */
// Prototypes
double min2(double a,double b);
double min3(double a,double b,double c);
/* --- */
// Main
int main() {

  return 0;
}
// Implem des fonctions
double min2(double a,double b){
  if (a<b) {return a;}
  else if (a>b) {return b;}
  else {return a;}
}
double min3(double a,double b,double c){
  return min2(min2(a,b),c);
}
