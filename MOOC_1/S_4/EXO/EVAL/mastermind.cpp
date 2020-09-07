#include <iostream>
#include <ctime>

// pour les nombres aléatoires
#include <random>
#include <cstring> // strlen

using namespace std;

// ======================================================================
// Couleur au hasard
std::uniform_int_distribution<int> distribution;
std::default_random_engine generateur(time(NULL)); /* NOT using std::random_device since not
                                                    * all compilers seems to support it :-( */

char tirer_couleur()
{
  static const char* const couleurs = ".RGBCYM";
  static const int nb = strlen(couleurs) - 1;

  return couleurs[distribution(generateur,
                               std::uniform_int_distribution<int>::param_type {0, nb})];
}

// ======================================================================
char poser_question()
{
  char lu(' ');
  cout << "Entrez une couleur : ";
  cin >> lu;
  return lu;
}

// ---- prototype -------------------------------------------------------
bool couleur_valide(char c);

// ======================================================================
char lire_couleur()
{
  char lu(poser_question());
  while (not couleur_valide(lu)) {
    cout << "'" << lu << "' n'est pas une couleur valide." << endl;
    cout << "Les couleurs possibles sont : ., R, G, B, C, Y ou M." << endl;
    lu = poser_question();
  }
  return lu;
}

// ======================================================================
void afficher_couleurs(char c1, char c2, char c3, char c4)
{
  cout << ' ' << c1 << ' ' << c2 << ' ' << c3 << ' ' << c4;
}

// ======================================================================
void afficher(int nb, char c)
{
  while (nb-- > 0) {
    cout << c;
  }
}

// ---- prototype -------------------------------------------------------
void afficher_reponses(char c1, char c2, char c3, char c4,
                       char r1, char r2, char r3, char r4);

// ======================================================================
void afficher_coup(char c1, char c2, char c3, char c4,
                   char r1, char r2, char r3, char r4)
{
  afficher_couleurs(c1, c2, c3, c4);
  cout << " : ";
  afficher_reponses(c1, c2, c3, c4,
                    r1, r2, r3, r4);
  cout << endl;
}

// ======================================================================
void message_gagne(int nb_coups)
{
  cout << "Bravo ! Vous avez trouvé en " << nb_coups << " coups." << endl;
}

// ======================================================================
void message_perdu(char c1, char c2, char c3, char c4)
{
  cout << "Perdu :-(" << endl;
  cout << "La bonne combinaison était : ";
  afficher_couleurs(c1, c2, c3, c4);
  cout << endl;
}

/*****************************************************
 * Compléter le code Ã  partir d'ici
 *****************************************************/
// ======================================================================
bool couleur_valide(char c){
	return ((c == '.') || (c == 'R') || (c == 'G') || (c == 'B') || (c == 'C') || (c == 'Y') || (c == 'M'));
}

// ======================================================================
bool verifier(char c1, char& c2, int& score){
	bool rep(false);
	if (c1 == c2) {
		rep = true;
		++score;
		c2 = 'X';
	}
	return rep;
}

// ======================================================================
void apparier(char c1, char& c2, char& c3, char& c4, int& score){
	bool b1(verifier(c1,c2,score));
	if (!b1) {
		bool b2(verifier(c1,c3,score));
		if (!b2){
			verifier(c1,c4,score);
		}
	}
	
}

// ======================================================================
void afficher_reponses(char c1, char c2, char c3, char c4, char r1, char r2, char r3, char r4){
	int bP(0);
	int mP(0);
	// Bonne Place - X marque la bonne place
	if (c1 == r1) {++bP;r1='X';} else {apparier(c1,r2,r3,r4,mP);}
	if (c2 == r2) {++bP;r2='X';} else {apparier(c2,r1,r3,r4,mP);}
	if (c3 == r3) {++bP;r3='X';} else {apparier(c3,r1,r2,r4,mP);}
	if (c4 == r4) {++bP;r4='X';} else {apparier(c4,r1,r2,r3,mP);}
	// Présente mais mauvaise place ?
	//if (r1 != 'X') {apparier(c1,r2,r3,r4,mP);}
	//if (r2 != 'X') {apparier(c2,r1,r3,r4,mP);}
	//if (r3 != 'X') {apparier(c3,r1,r2,r4,mP);}
	//if (r4 != 'X') {apparier(c4,r1,r2,r3,mP);}
	// Faux
	int f(4-bP-mP);
	// Affichage
	afficher(bP,'#');
	afficher(mP,'+');
	afficher(f,'-');
}

// ======================================================================
bool gagne(char c1, char c2, char c3, char c4, char r1, char r2, char r3, char r4){
	return c1 == r1 && c2 == r2 && c3 == r3 && c4 == r4;
}

// ======================================================================
void jouer(int nbMaxCoup = 8){
	int cpt(0);
	char r1(tirer_couleur());	//r1 = 'Y';
	char r2(tirer_couleur());	//r2 = 'B';
	char r3(tirer_couleur());	//r3 = 'Y';
	char r4(tirer_couleur());	//r4 = 'R';
	char c1('X'), c2('X'),c3('X'),c4('X');
	//
	do {
		c1 = lire_couleur(); c2 = lire_couleur(); c3 = lire_couleur(); c4 = lire_couleur();
		afficher_coup(c1,c2,c3,c4,r1,r2,r3,r4);
		++cpt;
	} while (!gagne(c1,c2,c3,c4,r1,r2,r3,r4) && cpt < nbMaxCoup);
	if (gagne(c1,c2,c3,c4,r1,r2,r3,r4)) {
		message_gagne(cpt);
	} else {
		message_perdu(r1,r2,r3,r4);
	}
}



















/*******************************************
 * Ne rien modifier aprÃ¨s cette ligne.
 *******************************************/

int main()
{
  jouer();
  return 0;
}
