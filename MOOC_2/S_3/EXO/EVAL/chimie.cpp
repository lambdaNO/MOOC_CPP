#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Flacon
{
private:
  string nom;
  double volume;
  double pH;

public:
  /*****************************************************
    Compléter le code à partir d'ici
  *******************************************************/
	Flacon(string n, double v, double p) : nom(n), volume(v), pH(p) {};
	ostream& etiquette(ostream& sortie) const ;
	Flacon operator+(Flacon const & f) const;
	Flacon & operator += (Flacon const & f);
	
	
};
ostream & Flacon::etiquette(ostream & sortie) const {
	sortie << nom << " : " << volume << " ml, pH " << pH; 
	return sortie;
}
ostream & operator <<(ostream & sortie, Flacon const & f) {
	return f.etiquette(sortie);
}
Flacon Flacon::operator +(Flacon const & f2) const{
	string s(nom + " + " + f2.nom);
	double v(volume + f2.volume);
	double p = -log10((volume * pow(10,-pH) + f2.volume * pow(10,-f2.pH))/(volume + f2.volume));
	return Flacon(s,v,p);	
}
Flacon & Flacon::operator +=(Flacon const & f) {
	this->volume += f.volume;
	this->nom += (" + " + f.nom);
	//double tm_ph = -log10((this->volume * pow(10,-this->pH) + f.volume * pow(10,-f.pH))/(this->volume + f.volume));
	this->pH = -log10((this->volume * pow(10,-this->pH) + f.volume * pow(10,-f.pH))/(this->volume + f.volume));//tm_ph;
	return *this;
}
#define BONUS

/*******************************************
 * Ne rien modifier après cette ligne.
 *******************************************/

void afficher_melange(Flacon const& f1, Flacon const& f2)
{
  cout << "Si je mélange " << endl;
  cout << "\t\"" << f1 << "\"" << endl;
  cout << "avec" << endl;
  cout << "\t\"" << f2 << "\"" << endl;
  cout << "j'obtiens :" << endl;
  cout << "\t\"" << (f1 + f2) << "\"" << endl;
}

int main()
{
  Flacon flacon1("Eau", 600.0, 7.0);
  Flacon flacon2("Acide chlorhydrique", 500.0, 2.0);
  Flacon flacon3("Acide perchlorique",  800.0, 1.5);

  afficher_melange(flacon1, flacon2);
  afficher_melange(flacon2, flacon3);

  return 0;

}
