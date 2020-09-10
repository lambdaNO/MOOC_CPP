#include <iostream>
#include <cmath>
#include <array>
#include <vector>
#include <string>
using namespace std;
/* --- */

char code(char c,int d);
char decale(char c, char debut, int decalage);
string code(string s,int d);
string decode(string s, int d);
/* --- */
int main()
{
/*
	cout << code("Fuyez manants",4) << endl;
	cout << code("Fuyez manants",6) << endl;
	cout << code("Fuyez manants",-4) << endl;
	cout << code("Avez-vous vu mes 3 chats et mes 2 chiens ?",4)<< endl;
	cout << decode("Jycid qererxw", 4) << endl;
	cout << decode("Laekf sgtgtzy", 6) << endl;
	cout << decode("Bquav iwjwjpo", -4) << endl;
	cout << decode("Ezid-zsyw zy qiw 3 glexw ix qiw 2 glmirw ?", 4) << endl;
*/
  return 0;
}
/* --- */
string code(string chaine, int decalage) {
	string s = "";
	size_t taille(chaine.size()),i(0);
	while (i < taille) {
		char c = code(chaine[i], decalage);
		s += c;
		i++;
	}
	return s;
}
string decode(string chaine, int decalage){
  return code(chaine,-decalage);
}

char code(char c, int d) {
	if (c >= 'a' && c <= 'z') {
		  return decale(c, 'a', d);
	} else if (c >= 'A' && c <= 'Z') {
		  return decale(c, 'A', d);
	}
	return c;
}
char decale(char c, char debut, int decalage) {
	while (decalage < 0) decalage += 26;
	return debut + (((c - debut) + decalage) % 26);
}
