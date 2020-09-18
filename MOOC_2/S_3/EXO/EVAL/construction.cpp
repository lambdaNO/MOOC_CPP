#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Pour simplifier
typedef string Forme   ;
typedef string Couleur ;

class Brique
{
private:
  Forme   forme   ;
  Couleur couleur ;

public:
  /*****************************************************
    Compléter le code à partir d'ici
  *******************************************************/
	Brique(Forme f, Couleur c) : forme(f), couleur(c) {};
	ostream & afficher(ostream & sortie) const;
};
ostream & Brique::afficher(ostream & sortie) const {
	if (couleur.empty()) {
		return sortie << forme;
	} else {
		return sortie << "(" << forme << ", " << couleur << ")";
	}
}
ostream & operator<<(ostream & sortie, Brique const & b) {
	return b.afficher(sortie);
}
//----------------------------------------------------------------------
//----------------------------------------------------------------------
//----------------------------------------------------------------------
class Construction {
	friend class Grader;
	vector<vector<vector<Brique>>> contenu;
	public : 
		Construction(Brique const & b);
		ostream & afficher(ostream & sortie) const;
		Construction & operator ^=(Construction const & c);
		Construction & operator -=(Construction const & c);
		Construction & operator +=(Construction const & c);
	
	
};
//----------------------------------------------------------------------
Construction::Construction(Brique const & b) {
	vector<Brique> axe_k(1,b);
	vector<vector<Brique>> axe_j(1,axe_k);
	contenu.push_back(axe_j);
}
//
ostream & Construction::afficher(ostream & sortie) const {
	for (int i(contenu.size()-1); i>=0; --i) {
		cout <<"Couche "<<i<<" :"<< endl;
		for (auto const & j : contenu[i]) {
			for (auto const & k : j) {
				sortie << k;
			}
			sortie << endl;
		}
	}
	return sortie;
}
//
ostream & operator<<(ostream & sortie, Construction & c) {
	return c.afficher(sortie);
}
//	Operateur ^= (interne) et ^ (externe) pour Construction et Brique
Construction & Construction::operator ^=(Construction const & c){
	for (int i(0); i <c.contenu.size(); ++i) {
		contenu.push_back(c.contenu[i]);
	}
	return *this;
}
const Construction operator^(Construction a, Construction const & b) {
	return a^=b;
}
const Construction operator^(Brique a, Brique const & b) {
	Construction c(a);	
	return c^=b;
}
//	Operateur -= (interne) et - (externe) pour Construction et Brique
Construction & Construction::operator -=(Construction const & c){
	if (c.contenu.size() >= contenu.size()) {
		for (int i(0); i <contenu.size(); ++i){
			for (int j(0); j < c.contenu[i].size(); ++j) {
				contenu[i].push_back(c.contenu[i][j]);
			}
		}	
	}
	return *this;
}
Construction operator-(Construction a, Construction const & b) {
	return a-=b;
}
Construction operator-(Brique a, Brique const & b) {
	Construction c(a);
	return c-=b;
}
//	Operateur += (interne) et + (externe) pour Construction et Brique
Construction & Construction::operator +=(Construction const & c){
	// Test de faisabilité : 
	bool ok(true);
	if (c.contenu.size() < contenu.size()) {
		ok = false;	
	} else {
		for (int i(0); i < contenu.size(); ++i) {
			if (c.contenu[i].size() < contenu[i].size()) {
				ok = false;
				break;
			}
		}
	}
	// Construction : 
	if (ok) {
		for (int i(0); i < contenu.size(); ++i) {
			for (int j(0); j < contenu[i].size(); ++j) {
				for (int k(0); k <c.contenu[i][j].size(); ++k) {
					contenu[i][j].push_back(c.contenu[i][j][k]);
				}
			}
		}
	}
	return *this;
}
Construction operator+(Construction a, Construction const & b) {
	return a+=b;
}
Construction operator+(Brique a, Brique const & b) {
	Construction c(a);
	return c+=b;
}

//----------------------------------------------------------------------
const Construction operator*(unsigned int n, Construction const& a) {
	Construction c(a);
	for (size_t i(1); i<n; ++i) {
		c+=a;
	}
	return c;
}
const Construction operator*(unsigned int n, Brique const & b) {
	Construction c(b);
	return n*c;
}

const Construction operator/(unsigned int n, Construction const& a)	{
	Construction c(a);
	for (size_t i(1); i<n; ++i) {
		c^=a;
	}
	return c;
}
const Construction operator/(unsigned int n, Brique const & b) {
	Construction c(b);
	return n/c;
}

const Construction operator%(unsigned int n, Construction const& a) {
	Construction c(a);
	for (size_t i(1); i<n; ++i) {
		c-=a;
	}
	return c;
}
const Construction operator%(unsigned int n, Brique const & b) {
	Construction c(b);
	return n%c;
}

/*******************************************
 * Ne rien modifier après cette ligne.
 *******************************************/

int main()
{
  // Modèles de briques
  Brique toitD("obliqueD", "rouge");
  Brique toitG("obliqueG", "rouge");
  Brique toitM(" pleine ", "rouge");
  Brique mur  (" pleine ", "blanc");
  Brique vide ("                 ", "");

  unsigned int largeur(4);
  unsigned int profondeur(3);
  unsigned int hauteur(3); // sans le toit

  // on construit les murs
  Construction maison( hauteur / ( profondeur % (largeur * mur) ) );

  // on construit le toit
  Construction toit(profondeur % ( toitG + 2*toitM + toitD ));
  toit ^= profondeur % (vide + toitG + toitD);

  // on pose le toit sur les murs
  maison ^= toit;

  // on admire notre construction
  cout << maison << endl;

  return 0;
}
