#include <iostream>
using namespace std;

int separer_chiffre_gauche(int& nombre)
{
  int dix(1);
  int temp(nombre);
  while (temp >= 10) {
    dix  *= 10;
    temp /= 10;
  }
  nombre %= dix;
  return temp;
}

/*****************************************************
 * ComplÃ©ter le code à partir d'ici
 *****************************************************/

void ajouter_chiffre_droit(int& nombre, int chiffre){
	 nombre=10*nombre+chiffre;
}

void dire_chiffre(int& nombre, int repetitions_chiffre, int chiffre)
{
	ajouter_chiffre_droit(nombre,repetitions_chiffre);	// Nombre de répétitions -> x*=10+repet
	ajouter_chiffre_droit(nombre,chiffre);				// Chiffre répété		 -> x*=10+chiffre
}

int lire_et_dire(int nombre)
{
	int res(0);
	int rep(1);
	int ch_g(0);
	int ch_g_w(0);
	
	ch_g = separer_chiffre_gauche(nombre);
	while (nombre != 0) {
		ch_g_w = separer_chiffre_gauche(nombre);
		if (ch_g == ch_g_w ) {
			++rep;
		} else {
			dire_chiffre(res,rep,ch_g);
			rep = 1;
			ch_g = ch_g_w;
		}
	}
	if (nombre == 0) {
		dire_chiffre(res,rep,ch_g);
	}
	
	return res;
	
}

/*******************************************
 * Ne rien modifier après cette ligne.
 *******************************************/

void repeter_lire_et_dire(int& nombre, int fois)
{
  while (fois-- > 0) {
    nombre = lire_et_dire(nombre);
  }
}

int main()
{
  int nombre(1);
  int fois(1);
  cin >> nombre >> fois;
  repeter_lire_et_dire(nombre, fois);
  cout << nombre << endl;
  return 0;
}
