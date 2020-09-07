#include <iostream>
#include <cmath>
using namespace std;
/* --- */
int demander_annee();
void affiche_date(int annee, int nb_jours);
int date_Paques(int annee);
/* --- */
int main()
{
	int annee(demander_annee());
	int nb(date_Paques(annee));
	affiche_date(annee,nb);
	return 0;
}
/* --- */


int demander_annee() {
	int annee(0);
	do {
		cout << "Entrez une annee (1583-4000) : ";
		cin >> annee;
	} while (!(annee >= 1583 && annee <= 4000));
	return annee;
}

void affiche_date(int annee, int nb_jours){
	if (nb_jours <= 31) {
		cout << "Date de Paques en " << annee << " : " << nb_jours << " mars"<< endl;
	} else {
		cout << "Date de Paques en " << annee << " : " << (nb_jours-31) << " avril"<< endl;
	}
}	
int date_Paques(int annee){
	int siecle(annee/100);
	int p(((8*siecle) + 13)/25);
	int q(siecle/4);
	int M((15-p-q + siecle)%30);
	int N((4+siecle - q)%7 );
	int d((M + (19*(annee%19)))%30);
	int e((2*(annee % 4) + 4*(annee % 7) + 6*d + N) % 7);
	int jour(e+d +22);
	
	if (e == 6 && ((d==29) or ( (d==28) && ((11*(M+1))%30 <19)))){
		jour = jour -7 ; 
	}
	return jour;
	
}
