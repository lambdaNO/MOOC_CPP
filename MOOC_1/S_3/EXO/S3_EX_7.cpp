#include <iostream>
#include <cmath>
using namespace std;
int main(){
  for (int i(1); i<=9;++i){
    for (int j(1); j<=i ;++j){cout << j;}
    cout<<endl;
  }
  /* --- */
  for (int j(1); j <= 9; ++j) {
    for (int i(1); i <= (9-j); ++i) { cout << " "; }
    for (int i(1); i <= j; ++i) { cout << i; }
    cout << endl;
  }
  cout << endl;
  /* --- */
  // For all n lignes -> nb espace avant première étoile : s = n - i avec i in |[0,n]|
  //                  -> nb étoiles : e = 2*i+1
  int n(0);
  cout << "Saisir nb lignes" << endl; cin >> n;
  for (int i(0);i<n;++i){
    for (int j(0);j<(n-i);++j){
      cout << " ";
    }
    for (int j(0);j<(2*i+1);++j){
      cout << "*";
    }
    cout << endl;
  }
  cout << endl;
  return 0;
}
