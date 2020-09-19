#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
/* ------------------------------------------------------------------ */
enum Type {HELICES,REACTION};
constexpr unsigned int ANNEE(2020);
constexpr double TAUX_STD(0.01);
constexpr double TAUX_VOI_AGE(0.02);
constexpr double TAUX_VOI_KM(0.05);
constexpr double TAUX_VOI_CAT1(0.1);
constexpr double TAUX_VOI_CAT2(0.2);
constexpr double TAUX_AVI(0.1);
/* ------------------------------------------------------------------ */
class Vehicule {
	protected :
		string marque;
		unsigned int date;
		double prix_achat;
		double prix_courant;
	public :
		Vehicule(string m="", unsigned int d=0, double p=0.) : marque(m), date(d), prix_achat(p) {prix_courant = 0.;};
		//virtual ~Vehicule();
		virtual void affiche(ostream & sortie) const;
		virtual void calculPrix();

};
void Vehicule::affiche(ostream & sortie) const {sortie << "Marque = " << marque << " - Année = " << date << " - Achat = " << prix_achat << " € - Actuel " << prix_courant << " € " << endl;}
void Vehicule::calculPrix() { double delta((ANNEE - date)*TAUX_STD); prix_courant = max(0., (1-delta)*prix_achat);}
/* ------------------------------------------------------------------ */
class Voiture : public Vehicule {
	protected :
		double cylindree;
		unsigned int nb_porte;
		double puissance;
		double kilometrage;
	public :
		Voiture(string m, unsigned int d, double p, double c, unsigned int n, double w, double k) : Vehicule(m,d,p), cylindree(c), nb_porte(n), puissance(w), kilometrage(k) {};
		void affiche(ostream & sortie) const override;
		void calculPrix() override;
};
void Voiture::affiche(ostream & sortie) const { Vehicule::affiche(sortie); sortie << "\t cylindrée = " << cylindree << " nb porte(s) = " << nb_porte << " puissance = " << puissance << " kilometrage " << kilometrage << "." << endl; }
void Voiture::calculPrix() {
	double delta((ANNEE - date)*TAUX_VOI_AGE); delta += TAUX_VOI_KM*(kilometrage/10000);
	if (marque == "Renault" || marque == "Fiat") {
		delta+=TAUX_VOI_CAT1;
	} else if (marque == "Ferrari" || marque == "Porsche") {
		delta-=TAUX_VOI_CAT2;}
	prix_courant = max(0., (1-delta)*prix_achat);
}

/* ------------------------------------------------------------------ */
class Avion : public Vehicule {
	protected :
		Type type;
		unsigned int nb_h_vol;
	public :
		Avion(string m, unsigned int d, double p, Type t = REACTION, unsigned int v=0) : Vehicule(m,d,p), type(t), nb_h_vol(v) {};
		void affiche(ostream & sortie) const override;
		void calculPrix() override;
};
void Avion::affiche(ostream & sortie) const { Vehicule::affiche(sortie); sortie << "\t type = " << type << " nb heures vol = " << nb_h_vol << endl;}
void Avion::calculPrix() {

	double taux_heure = (type==HELICES) ? 100. : 1000.;
	double delta(TAUX_AVI*nb_h_vol/taux_heure);
	prix_courant = max(0., (1-delta)*prix_achat);
}
/* ------------------------------------------------------------------ */
/* ------------------------------------------------------------------ */
// ================>
class Aeroport {
		private :
				vector<Vehicule*> Veh;
		public :
				ostream & affiche(ostream &) const;
				void ajouter_vehicule(Vehicule*);
				void vider_vehicules();
};

ostream & Aeroport::affiche(ostream & sortie) const {
		if(!Veh.empty()){
				for (auto const & v : Veh){
						v->calculPrix();
						v->affiche(sortie);
				}
		} else {
				sortie << "VIDE !!!!!!" << endl;
		}
		return sortie;
}
ostream & operator<<(ostream & sortie, Aeroport const & A) {
		return A.affiche(sortie);
}

void Aeroport::ajouter_vehicule(Vehicule * v) {
		Veh.push_back(v);		// Déjà un pointeur vers le véhicule;
}

void Aeroport::vider_vehicules() {
		Veh.clear();
}






/* ------------------------------------------------------------------ */
/* ------------------------------------------------------------------ */
int main() {
		// NE PAS OUBLIER LE PASSAGE EN VIRTUAL POUR SPECIFIER QUE L'ON SOUHAITE UTILISER LA METHODDE DE L'INSTANCE
		// + LES PASSAGES PAR REFERENCE
		Aeroport gva;
		gva.ajouter_vehicule(new Voiture("Peugeot", 1998, 147325.79, 2.5, 5, 180.0, 12000));
		gva.ajouter_vehicule(new Voiture("Porsche", 1985, 250000.00, 6.5, 2, 280.0, 81320));
		gva.ajouter_vehicule(new Avion("Cessna", 1972, 1230673.90, HELICES, 250));
		gva.ajouter_vehicule(new Avion("Nain Connu", 1992, 4321098.00, REACTION, 1300));
		gva.ajouter_vehicule(new Voiture("Fiat", 2001, 7327.30, 1.6, 3, 65.0, 3000));

		gva.affiche(cout);

		gva.vider_vehicules();

		gva.affiche(cout);

    return 0;
}
