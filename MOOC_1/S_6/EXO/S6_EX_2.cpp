#include <iostream>
#include <cmath>
#include <array>
#include <vector>
#include <string>
using namespace std;
/* --- */
struct Complexe {
  double x;   // partie réelle
  double y;   // partie imaginaire
};
/* --- */
string affiche(Complexe const & c);
Complexe addition(Complexe c1, Complexe c2);
Complexe soustraction(Complexe c1, Complexe c2);
Complexe multiplication(Complexe c1, Complexe c2);
Complexe division(Complexe c1, Complexe c2);
void operation(Complexe c1, Complexe c2,char o);
/* --- */
int main()
{
	Complexe a({1,1}),b({0,1}),c({1,1}),d({0,2}),e({2,-3});
	operation(a,b,'+');
	operation(b,b,'*');
	operation(c,c,'*');
	operation(d,b,'/');
	operation(e,c,'/');

  return 0;
}
/* --- */
string affiche(Complexe const & c){
  string res(to_string(c.x));
  if (c.y < 0){
    res+=(" - "+to_string(abs(c.y)));
  } else {
    res+=(" + "+to_string(abs(c.y)));
  }
  res+="i";
  return res;
}
Complexe addition(Complexe c1, Complexe c2) {
  Complexe c({c1.x + c2.x, c1.y + c2.y});
  return c;
}
Complexe soustraction(Complexe c1, Complexe c2) {
  Complexe c({c1.x - c2.x, c1.y - c2.y});
  return c;
}
Complexe multiplication(Complexe c1, Complexe c2){
  Complexe c({c1.x*c2.x - c1.y*c2.y, c1.x*c2.y + c1.y*c2.x });
  return c;
}
Complexe division(Complexe c1, Complexe c2){
  Complexe c({(c1.x*c2.x + c1.y*c2.y)/(pow(c2.x,2)+pow(c2.y,2)),(c1.y*c2.x - c1.x*c2.y)/(pow(c2.x,2)+pow(c2.y,2)) });
  return c;
}
void operation(Complexe c1, Complexe c2,char o){
  Complexe res;
  cout << "("<<affiche(c1)<<") " << o << " ("<<affiche(c2)<<")" << " = ";
  switch (o) {
    case '+': res= addition(c1,c2); break;
    case '-': res=soustraction(c1,c2); break;
    case '*': res=multiplication(c1,c2); break;
    case '/': res=division(c1,c2); break;
  }
  cout << affiche(res) << "." << endl;
}
