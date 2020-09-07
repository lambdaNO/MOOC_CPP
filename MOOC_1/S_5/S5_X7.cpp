#include <iostream>
#include <vector>        // Appel à la librairie vector
#include <array>         // Appel à la libraire array
using namespace std;
/* --- */

/* --- */
void print(vector<int> t) {
    for (auto elt : t){ cout << elt << " - ";} cout << endl;
}

int f(int n)
{
  vector<int> v;
  int j(0);

  while (n != 0) {
    v.push_back(n % 100);
    n = n / 100;
  }

  if (not v.empty()) {
    for (size_t i(v.size()-1); i != 0; --i) {
      for (++j; v[i] >= j; j = j + 2) {
        v[i] = v[i] - j;
      }

      j = 10 * (j-1);
      v[i-1] = v[i-1] + 100 * v[i];
    }

    for (++j; v[0] >= j; j = j + 2) {
      v[0] = v[0] - j;
    }

    // code manquant

    
  }
  return (j-1)/2;
}



int main(){
  /*
  cout << "V1" << endl;
  vector<int> v(6, 1);
  for (size_t i(0) ; i < v.size() ; ++i) {
    v[i] = v[i] + i;
  }
  v.pop_back();
  v.push_back(6);
  */
  /*
  cout << "V2" << endl;
  vector<int> v(5, 1);
  for (size_t i(0); i < v.size(); ++i) {
    v[i] = v[i] + i + 1;
  }
  v.push_back(6);
  */
  /*
  cout << "V3" << endl;
  vector<int> v(5, 1);

  for (size_t i(0); i < v.size() ; ++i) {
    v[i] = v[i] + i;
  }
  v.pop_back();
  v.push_back(6);
  print(v);
  */

  cout << f(20000) << endl;
  return 0;
}
