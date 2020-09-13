#include <iostream>
using namespace std;
class Fleur {
	private:
		const string couleur;
	public:
		Fleur(const string& espece, const string& couleur)	: couleur(couleur){
			cout << espece << " fraichement cueillie" << endl;
		}
		Fleur(const Fleur& f)	: couleur(f.couleur){
			cout << "Fragile corolle taillee" << endl;
		}
		~Fleur() { cout << "qu'un simple souffle..." << endl; }
		void eclore() const { cout << "veine de " << couleur << endl; }

};


int main(){
	Fleur f1("Violette", "bleu");
	Fleur f2(f1);
	f2.eclore();
	cout << "Donne un poème un peu fleur bleue" << endl << "ne laissant plus ";
	return 0;
}
