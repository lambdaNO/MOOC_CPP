#include <iostream>
using namespace std;
/* --- */
// Prototypes
bool non_et(bool A, bool B);
bool non(bool A);
bool et(bool A, bool B);
bool ou(bool A, bool B):
/* --- */
// Main
int main() {

  return 0;
}

bool non_et(bool A, bool B) {
  return not(A and B);
}

bool non(bool A){
  return non_et(A,A)
}

bool et(bool A, bool B){
  return non(non_et(A,B));
}

bool ou(bool A, bool B){
  return non_et(non(A),non(B));
}
