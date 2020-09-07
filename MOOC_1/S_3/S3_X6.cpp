#include <iostream>
using namespace std;

int main(){
int m(0);
int p(3);
bool test1(true);
bool test2(not test1);

while (m <= p) {
  if (test1 or test2) {
    cout << test1 << " " << m << " ";
    test1 = not test1;
  } else {
    cout << test2 << " " << p << " ";

    test2= !test1;
  }
  ++m;
}

if (test1 or (test2 and not test1)) {
  cout << test1 << " ";
}


	return 0;
}
