#include <iostream>
#include <cmath>
using namespace std;
/* --- */
/*
bool f(int a, int&b)
{
  a += 3;
  b *= 2;

  return ((a + b) >= 10);
}
*/
void f1(int i, int j)
{
  int copie(i);
  i = j;
  j = copie;
}

int f2(int j)
{
  j = 1;
  return j-1;
}

int f3(int& i)
{
  i = 0;
  return i+1;
}

int f4(int& j)
{
  j = 1;
  return j;
}


void f(int p, int m , int n, bool b)
{
  for (int i(p); i >= 0; --i) {
    if ((i >= 2) and b) {
      cout << i-2 << " ";
    } else {
      cout << i+2 << " ";
    }
  }

  int k(m);

  while (k <= n) {
    cout << k << " ";
    k *= 3;
  }
  cout << endl;
}


int a(1);

int f(int& p, int q)
{
  a = p + q;
  p = a * q;

 return a+p+q;
}

void g()
{
  int a(3);

  cout << f(a, a) << endl;
  cout << a << endl;
}



int main(){
/*	
  int x(2);
  int y(4);

  if ( f(x,x) ) {
    cout << x + y << " " << x << " " << y << endl;
  } else {
    cout << x * y << " " << y << " " << x << endl;
  }
*/
/*
	int i(1);
    int j(0);
	
	f1(i,j);
	
	cout << "i = " << i << "; j = " << j << endl;
*/
  const int N(9);
  //f(N, N/2, N*2, false);
  g();
  cout << a << endl;


  return 0;
	

}

