#include <iostream>
#include <vector>
using namespace std;

/*******************************************
 * Complétez le programme Ã  partir d'ici.
 *******************************************/
typedef vector <vector <int> > Carte;
/* --- */
struct Position {
	int i;
	int j;
};
/* --- */
bool binaire(Carte const& carte);
void affiche(Carte const& carte);
bool verifie_et_modifie(Carte& carte);
void efface_etang(Carte & carte);
int find_10(vector<int> l, int start);
int find_01(vector<int> l, int start);
void aff_lig(vector<int> l);
double longueur_cloture(Carte const& carte,double echelle = 2.5);
void marque_composantes(Carte& carte);
void neigh_marque_composantes(Carte& carte, Position pos, int composante, vector<Position>& points) ;
void ajoute_unique(vector<int>& ensemble, int valeur);
bool convexite_lignes(Carte& carte, vector<int> const& labels_bords);
bool convexite_lignes(Carte& carte);



/* --- */
bool binaire(Carte const& carte) {
	for (size_t l(0); l < carte.size(); ++l) {
		for (size_t c(0); c < carte[l].size(); ++c) {
			if (carte[l][c] != 0 && carte[l][c] != 1) {return false;}
		}
	}
	return true;
}
//
void affiche(Carte const& carte) {
	for (auto l : carte) {
		for (auto c : l) {
			cout << c;
		}
		cout << endl;
	}
	cout << endl << "----" << endl;
	
}
//
void efface_etang(Carte & carte) {
	Carte n_carte;
	for (size_t idx_t(0); idx_t < carte.size(); ++idx_t) {
		vector<int> l(carte[idx_t]);
		size_t k(0);
		int deb_et(0),fin_et(0);
		bool stop(false);
		while(k < carte.size() && !stop){
			deb_et = find_10(l,k);
			fin_et = find_01(l,deb_et);
			if (deb_et != 0 && fin_et !=0) {
				for (size_t e(deb_et); e <= fin_et; ++e) {
					l[e] = 1; 
				}
			}
			else {
				stop = true;
			}
			++k;
		}
		n_carte.push_back(l);
	}
	for (size_t i(0); i < carte.size(); ++i) {
		for (size_t j(0); j < carte[i].size(); ++j) {
			carte[i][j] = n_carte[i][j];
		}
	}	
}
//
void aff_lig(vector<int> l){
	for (auto elt : l) {
		cout << elt << " ";
	}
	cout << endl;
}
//
int find_10(vector<int> l, int start){
	size_t idx(start);
	bool find(false);
	int pos(0);
	while (idx < l.size() -1 && !find){
		if (l[idx] == 1 && l[idx+1]==0){
			find = true;
			pos = idx+1;
		}
		++idx;
	}
	return pos;
}
//
int find_01(vector<int> l, int start){
	size_t idx(start);
	bool find(false);
	int pos(0);
	while (idx < l.size() -1 && !find){
		if (l[idx] == 0 && l[idx+1]==1){
			find = true;
			pos = idx;
		}
		++idx;
	}
	return pos;
}
//
double longueur_cloture(Carte const& carte, double echelle) {
	double P(0);
	vector<int> cO(carte.size()), cE(carte.size()), T(carte.size());
    //
    for (size_t x(0); x< carte.size(); ++x) {
		// Détection des zones de terre 
		// Recherche par l'Ouest et par L'est
		size_t y(0);
		size_t z(carte[x].size()-1);
		while (y <carte[x].size() && carte[x][y] != 1){
			++y;
		}
		cO[x] = y;
		while (z >= 0 && carte[x][z]!=1){
			--z;
		}
		cE[x] = z;
		T[x] = z + 1 - y;
		//cout << "x = " << x << "\t cO = " << cO[x] <<"\t cE = " << cE[x] << "\t T = " << T[x] <<endl;
		if (T[x] > 0) {
			P += (2*echelle);
			if (x > 0) {
				int o(cO[x]-cO[x-1]),e(cE[x]-cE[x-1]);
				if (o <0) { o*= -1;}
				if (e <0) { e*= -1;}
				P += o*echelle + e*echelle;
				//cout << "P("<<x<<")="<<P<<endl;
			}
		}	
	}
	//
	P += T[0]*echelle + T[T.size()-1]*echelle;
	return P;
}
//
void marque_composantes(Carte& carte) {
	vector<Position> points;
	int composante(1);
	for(size_t i(0); i<carte.size(); ++i) {
		for(size_t j(0); j<carte[i].size(); ++j) {
			if(carte[i][j]==0) {
				Position p({int(i),int(j)});
				points.push_back(p);
				neigh_marque_composantes(carte,p,++composante,points);
			}
		}
	}
}
//
void neigh_marque_composantes(Carte& carte, Position pos, int composante, vector<Position>& points) {
	if(carte[pos.i][pos.j]==0) {
		carte[pos.i][pos.j]=composante;
		if(pos.i>=1 && carte[(pos.i)-1][pos.j]==0) {
			Position p = { (pos.i)-1,(pos.j) };
			points.push_back(p);
			neigh_marque_composantes(carte,p,composante,points);
		}
		if(pos.j>=1 && carte[pos.i][(pos.j)-1]==0) {
			Position p = { (pos.i),(pos.j)-1 };
			points.push_back(p);
			neigh_marque_composantes(carte,p,composante,points);
		}
		if(pos.i<carte.size()-1 && carte[(pos.i)+1][pos.j]==0) {
			Position p = { (pos.i)+1,(pos.j) };
			points.push_back(p);
			neigh_marque_composantes(carte,p,composante,points);
		}
		if(pos.j<carte[0].size()-1 && carte[pos.i][(pos.j)+1]==0) {
			Position p = { (pos.i),(pos.j)+1 };
			points.push_back(p);
			neigh_marque_composantes(carte,p,composante,points);
		}
	}
}
//
void ajoute_unique(vector<int>& ensemble, int valeur) {
	bool b(false);
	size_t i(0);
	while(i<ensemble.size() && !b) {
		if(ensemble[i]==valeur) {
			b = true;
		}
		++i;
	}
	if(!b) {
		ensemble.push_back(valeur);
	}
}
//
bool convexite_lignes(Carte& carte, vector<int> const& labels_bords) {
	for(size_t i(1); i<carte.size(); ++i) {
		for(size_t j(1); j<carte[i].size()-1; ++j) {
			if(carte[i][j]!=1 && carte[i][j-1]==1) {
				int tmp(j);
				do{
					if(carte[i][j]!=1 && carte[i][j+1]==1) {
						size_t k(0);
						while(k<labels_bords.size() && carte[i][j]!=labels_bords[k]) {
							 ++k;
						}
						if(k<labels_bords.size() && carte[i][j]==labels_bords[k]) {
							cout << "Votre carte du terrain n'est pas convexe par lignes :" << endl;
							cout << "bord extérieur entrant trouvé en position [";
							cout << i;
							cout << "][";
							cout << tmp;
							cout << "]" << endl;
							return false;
						}
					}
					++j;
				}while(j<carte[i].size()-1);
			}
		}
	}
	return true;
}
	
bool convexite_lignes(Carte& carte) {
	marque_composantes(carte);
	vector<int> V;
	for(size_t i(0); i<carte[0].size(); ++i) {
		if(carte[0][i]!=1) {
			ajoute_unique(V,carte[0][i]);
		}
		if(carte[carte.size()-1][i]!=1) {
			ajoute_unique(V,carte[carte.size()-1][i]);
		}
	}
	for(size_t i(0); i<carte.size(); ++i) {
		if(carte[i][0]!=1) {
			ajoute_unique(V,carte[i][0]);
		}
		if(carte[i][carte[i].size()-1]!=1) {
			ajoute_unique(V,carte[i][carte[i].size()-1]);
		}
	}
	return (convexite_lignes(carte,V));
}
//
bool verifie_et_modifie(Carte& carte) {
	
	
	if (!binaire(carte)) {
		cout << "Votre carte du terrain n'est pas convexe par lignes :" << endl;
		return false;
	} 
	if (!convexite_lignes(carte)) {
		return false;
	}
	efface_etang(carte);
	affiche(carte);
	return true;
	
}






/*******************************************
 * Ne rien modifier apràs cette ligne.
 *******************************************/

int main()
{
  Carte carte = {
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,0,0},
    {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,0,0},
    {0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1,0,0},
    {0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,0,0,0,0},
    {0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0},
    {0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0},
    {0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0},
    {0,0,0,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0},
    {0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0},
    {0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
  };

  cout << "Carte au départ :" << endl;
  affiche(carte);
  if (verifie_et_modifie(carte)) {
    cout << "Carte apràs modification :" << endl;
    affiche(carte);
    cout << "Il vous faut " << longueur_cloture(carte)
         << " màtres de clôture pour votre terrain."
         << endl;
  }

  return 0;
}
