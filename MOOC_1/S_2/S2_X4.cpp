#include <iostream>
using namespace std;
int main() {
  /*
  bool test1(true);
  bool test2(false);
  bool test3(test1 and not test2);
  bool test(test1 and test2 and test3);

  cout << "test = " << test << endl;
  */
  /*
  int a,b;
  a = 2; b = 8;
  bool eval = (a * b >= 15) and (not(a < 4) or (b >= 4 and b <= 7));
  cout << "a = " << a << " b = " << b << "(a * b >= 15) and (not(a < 4) or (b >= 4 and b <= 7)) = " << eval << endl;
  */
  /*
  int a(5);
  int b(7);
  int c(13);

if (a + b > c) {
  cout << "1" << " ";
  b += 5;
} else {
  cout << "2" << " ";
}

if (b % 2 == 0) {
  if (a % c == 0) {
    cout << "3" << " ";
  } else {
    cout << "4" << " ";
  }
} else {
  cout << "5" << " ";
}
*/
/*
bool test1(not (true and (true or false)));
bool test2(false);

if (not test1) {
  cout << "Ré" << " ";
}

if (test1 or test2) {
  if (test1) {
    cout << "Sol" << " ";
  } else {
    cout << "Fa" << " ";
  }
} else {
  cout << "Mi" << " ";
}

cout << "Fa" << " ";
*/
/*
bool test1(not (true and (true or false)));
bool test2(false);

if (test1) {
  cout << "Ré" << " ";
}

if (test1 or test2) {
  if (test1) {
    cout << "Sol" << " ";
  } else {
    cout << "Fa" << " ";
  }
} else {
  cout << "Mi" << " ";
}

cout << "Fa" << " ";
*/
/*
bool test1(not (true and (true or false)));
bool test2(true);

if (not test1) {
  cout << "Ré" << " ";
}

if (not (test1 or test2)) {
  if (test1) {
    cout << "Sol" << " ";
  } else {
    cout << "Fa" << " ";
  }
} else {
  cout << "Mi" << " ";
}

cout << "Fa" << " ";


*/
bool test1(not (true and (true or false)));
bool test2(false);

if (not test1) {
  cout << "Ré" << " ";
}

if (not (test1 or test2)) {
  if (test1) {
    cout << "Sol" << " ";
  } else {
    cout << "Fa" << " ";
  }
} else {
  cout << "Mi" << " ";
}

cout << "Fa" << " ";
  return 0;
  }
