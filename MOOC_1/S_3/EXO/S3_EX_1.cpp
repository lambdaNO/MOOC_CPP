#include <iostream>
using namespace std;
int main(){
  cout << "Table de multiplication" << endl << endl;
  for (int i(0); i<=10;++i){
    cout << "Table de "<< i << " : " << endl;
    for (int j(0); j<=10;++j){
      cout << i << " * " << j << " = " << i*j << endl;
    }
  }
  return 0;
}
