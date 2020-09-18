#include <iostream>
#include <string>
using namespace std;

class Timbre
{
private:
  static constexpr unsigned int ANNEE_COURANTE = 2016;

  /*****************************************************
   * Compléter le code à partir d'ici
   *****************************************************/
	protected :
		string nom;
		unsigned int annee;
		string pays;
		double valeur_faciale;
	public : 
		Timbre(string n, unsigned int a, string p = "Suisse", double v = 1.) : nom(n),annee(a), pays(p), valeur_faciale(v) {};
		unsigned int age() const;
		double vente() const;
		ostream & afficher(ostream &) const;
};
unsigned int Timbre::age() const {
	return ANNEE_COURANTE - annee;
}
double Timbre::vente() const {
	//Le prix de vente d’un timbre quelconque (ni rare, ni commémoratif) est 
	//	* sa valeur faciale, si le timbre a moins que cinq ans ; 
	//	* sinon, il vaut la valeur faciale multipliée par 2.5 fois l’âge du timbre (cf exemple de déroulement fourni plus bas).	
	if (age() < 5) {
		return valeur_faciale;
	} else  {
		return valeur_faciale * 2.5*age();
	}
}
ostream & Timbre::afficher(ostream & sortie) const {
	sortie << "de nom "<<nom<< " datant de "<<annee<<" (provenance "<<pays<<") ayant pour valeur faciale "<<valeur_faciale<<" francs";
	return sortie;
}
ostream & operator <<(ostream & sortie, Timbre const & t) {
	sortie << "Timbre ";
	return t.afficher(sortie);
}
/* ---- */
class Rare : public Timbre {
	private : 
		static constexpr unsigned int PRIX_BASE_TRES_RARE = 600;
		static constexpr unsigned int PRIX_BASE_RARE = 400;
		static constexpr unsigned int PRIX_BASE_PEU_RARE = 50;
		static constexpr unsigned int ANNEE_COURANTE = 2016;
		unsigned int nb_ex;
	protected :
		
	public :
		Rare(string n, unsigned int a, string p="Suisse", double v=1.,unsigned int e =100) : Timbre(n,a,p,v), nb_ex(e) {};
		unsigned int nb_exemplaires() const {return nb_ex;};
		double vente() const;
};
double Rare::vente() const {
	unsigned int base;
	if (nb_ex < 100) {
		base = PRIX_BASE_TRES_RARE;
	} else if (nb_ex >=100 && nb_ex < 1000) {
		base = PRIX_BASE_RARE;
	} else {
		base = PRIX_BASE_PEU_RARE;
	}
	return base*(Timbre::age()/10.);
	
}
ostream & operator <<(ostream & sortie, Rare const & t) {
	sortie << "Timbre rare ("<< t.nb_exemplaires() <<" ex.) ";
	return t.afficher(sortie);
}
/* ---- */
class Commemoratif : public Timbre {
	private : 
		static constexpr unsigned int ANNEE_COURANTE = 2016;
	protected : 
		
	public :
		// Pas d'attributs sup dans la sous-classe (slide 34);
		using Timbre::Timbre;
		double vente() const {return 2*Timbre::vente();}
};
ostream & operator <<(ostream & sortie, Commemoratif const & t) {
	sortie << "Timbre commémoratif ";
	return t.afficher(sortie);
}


/*******************************************
 * Ne rien modifier après cette ligne.
 *******************************************/
int main()
{
  /* Ordre des arguments :
  *  nom, année d'émission, pays, valeur faciale, nombre d'exemplaires
  */
  Rare t1( "Guarana-4574", 1960, "Mexique", 0.2, 98 );
  Rare t2( "Yoddle-201"  , 1916, "Suisse" , 0.8,  3 );

  /* Ordre des arguments :
  *  nom, année d'émission, pays, valeur faciale, nombre d'exemplaires
  */
  Commemoratif t3( "700eme-501"  , 2002, "Suisse", 1.5 );
  Timbre       t4( "Setchuan-302", 2004, "Chine" , 0.2 );

  /* Nous n'avons pas encore le polymorphisme :-(
   * (=> pas moyen de faire sans copie ici :-( )  */
  cout << t1 << endl;
  cout << "Prix vente : " << t1.vente() << " francs" << endl;
  cout << t2 << endl;
  cout << "Prix vente : " << t2.vente() << " francs" << endl;
  cout << t3 << endl;
  cout << "Prix vente : " << t3.vente() << " francs" << endl;
  cout << t4 << endl;
  cout << "Prix vente : " << t4.vente() << " francs" << endl;

  return 0;
}
