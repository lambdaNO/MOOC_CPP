#include <iostream>
using namespace std;

/*******************************************
 * Complétez le programme à partir d'ici.
 *******************************************/
class Tirelire {
	private : 
		double montant;
	public :
		double getMontant() const;
		void afficher() const;
		void secouer() const;
		void remplir(double  m);
		void vider();
		void puiser(double  m);
		bool montant_suffisant(double budget, double & solde);
};

double Tirelire::getMontant() const {
	return montant;
};
void Tirelire::afficher() const {
	if (montant == 0) {
		cout << "Vous etes sans le sou." << endl;
	} else {
		cout << "Vous avez : "<<montant<<" euros dans votre tirelire." << endl;
	}
}
void Tirelire::secouer() const {
	if (montant != 0) {
		cout << "Bing bing" << endl;
	}
}
void Tirelire::remplir(double  m) {
	if (m>0) {
		montant+=m;
	}
}
void Tirelire::vider() {
	montant=0;
}

void Tirelire::puiser(double m) {
	if (m >= 0) {
		if (m> montant) {
			montant = 0;		// vider()
		} else {
			montant -= m;
		}
	}
}

bool Tirelire::montant_suffisant(double budget, double &solde){
	if (budget > montant){
		double b;
		if (montant < 0)
		{
			b = 0;
		}
		else 
		{
			b = montant;
		}
		solde = budget - b;
		return false;
	}
	else 
	{
		solde = montant - budget;
		return true;
	}
}


/*******************************************
 * Ne rien modifier après cette ligne.
 *******************************************/

int main()
{
  Tirelire piggy;

  piggy.vider();
  piggy.secouer();
  piggy.afficher();

  piggy.puiser(20.0);
  piggy.secouer();
  piggy.afficher();

  piggy.remplir(550.0);
  piggy.secouer();
  piggy.afficher();

  piggy.puiser(10.0);
  piggy.puiser(5.0);
  piggy.afficher();

  cout << endl;

  // le budget de vos vacances de rève.
  double budget;

  cout << "Donnez le budget de vos vacances : ";
  cin >> budget;

  // ce qui resterait dans la tirelire après les
  // vacances
  double solde(0.0);

  if (piggy.montant_suffisant(budget, solde)) {
    cout << "Vous êtes assez riche pour partir en vacances !"
         << endl
         << "Il vous restera " << solde << " euros"
         << " à la rentrée." << endl << endl;
    piggy.puiser(budget);
  } else {
    cout << "Il vous manque " << solde << " euros"
         << " pour partir en vacances !" << endl << endl;
  }
  return 0;
}
