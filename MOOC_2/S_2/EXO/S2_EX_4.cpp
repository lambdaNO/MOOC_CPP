#include <iostream>
#include <vector>
#include <string>
using namespace std;
/* --- */
class Compte{
	private : 
		string intitule;
		double solde; 
		double taux;
	public : 
		Compte(string const & n, double t) : intitule(n),solde(0.),taux(t) {};
		//~Compte() {cout << "~\tCloture compte ["<<intitule <<"/"<<taux<<"/"<<solde<<"]"<<endl;};
		~Compte() {};
		void afficher() const {cout << "Compte : " << intitule << "\ttaux = " << taux*100 << " %\t Solde = " << solde << endl;};
		string getIntitule() const { return intitule; }
		double getTaux() const { return taux;}
		double getSolde() const { return solde;}
		void crediter(double somme) {solde+= somme;}
		void bouclement() {crediter(taux*solde); cout << "!! Bouclement : " << endl; afficher();}
};
//
class Client {
	private :
		string nom;
		string ville;
		vector<Compte> portefeuille;
	public :
		Client(string const & n, string const & v, double t = 0.01) : nom(n), ville(v), portefeuille(1,Compte(n+" - courant", t)){};
		//~Client() {cout << "~\tCloture client " << nom << " de " << ville << endl;};
		~Client() {}
		void afficher() const {
			cout << "Client : " << nom << " de " << ville << " #(comptes) " << portefeuille.size() << endl;
			for (auto c : portefeuille) { c.afficher();}
		}
		void crediter(string const & n, double somme) {
			for (auto & c : portefeuille) {
				if (c.getIntitule() == nom+" - "+n) {
					c.crediter(somme);
				}
			}
		}
		void nouveau_compte(string const & n, double t) {
			portefeuille.push_back(Compte(nom+" - "+n, t));
		}
		void bouclement() {
			for (auto & c : portefeuille ) {
				c.bouclement();
			}
		}
};
// 
class Banque {
	private :
		vector<Client *> clientelle;	// Constructeur minimal suffit 
	public : 
		~Banque() {cout << "A mort le capitalisme";}
		void nouveau_client(Client & c) {clientelle.push_back(&c);}		// On prend bien la référence mémoire (&c) vers ce client et non la valeur (*c) !
		void afficher() const {
			for (auto & c : clientelle )	{
				// Note : (*X).Y peut aussi s'écrire X->Y, par exemple ici :
				c->afficher();
			};
		}
		void bouclement() {
			for (auto & c : clientelle )	{
				c->bouclement();
			}
		};
};






/* --- */
int main(){
	Banque fictive;
	Client pedro ("Pedro" , "Genève" ); 
	fictive.nouveau_client(pedro); 
	pedro.crediter("courant", 1000.0); 
	pedro.nouveau_compte("épargne", 0.02); 
	pedro.crediter("épargne", 2000.0);
	//pedro.afficher();
	Client alexandra("Alexandra", "Lausanne");
	fictive.nouveau_client(alexandra); 
	alexandra.crediter("courant", 3000.0); 
	alexandra.nouveau_compte("épargne", 0.02); 
	alexandra.crediter("épargne", 4000.0);
	//alexandra.afficher();
	cout << ">> Données avant le bouclement des comptes :" << endl; 
	fictive.afficher();
	fictive.bouclement();
	cout << ">> Données apres le bouclement des comptes :" << endl;
	fictive.afficher();
	
	return 0;
}
	
