#include <iostream>
#include <cmath>
#include <array>
#include <vector>
#include <string>
using namespace std;
/* --- */
struct QCM {
    string question;
    vector<string> reponses;
    int solution;
};
struct Exam {
	vector<QCM> questions;
	int note;
};
/* --- */
void affiche_question(QCM const & q,int & note);
int saisir_entier(int a,int b);
/* --- */
int main()
{

	QCM q1 = {"Combien de dents possède un éléphant adulte", { "32", "de 6 à 10", "beaucoup", "24", "2" },2};
	QCM q2 = {"Laquelle des instructions suivantes est un prototype de fonction",{ "int f(0);" ,"int f(int 0);" ,"int f(int i);" ,"int f(i);" },3};
	QCM q3 = { "Qui pose des questions stupides",{ "le prof. de math","mon copain/ma copine","le prof. de physique","moi","le prof. d'info","personne, il n'y a pas de question stupide","les sondages" } ,6};
	vector<QCM> liste_q({q1,q2,q3});
	Exam ex({liste_q,0});
	for (auto & q : ex.questions) {
		affiche_question(q,ex.note);
	}
	cout << "Vous avez trouvé " << ex.note <<" bonnes réponses sur " << ex.questions.size() << "." << endl;
	return 0;
}
/* --- */

void affiche_question(QCM const & q,int & note) {
	int ans(0);
	cout << q.question << endl;
	for (size_t r(0); r<q.reponses.size(); ++r) {
		cout << "\t"<< r+1 << "- " << q.reponses[r] << endl;
	}
	ans = saisir_entier(1,q.reponses.size());
	if (ans == q.solution) {
		++note;
	}
}
int saisir_entier(int a,int b) {
	int res(0);
	do {
		cout << "Saisir un entier entre "<< a << " et " << b << " : "; cin >> res;
	} while (!(res >= a && res<=b));
	return res;
}
