#include <iostream>
using namespace std;
/* --- */
//  Structure de Do/While : do { bloc_instruction} while(condition);        -> Condition testée en fin      =>   Au moins une execution du bloc d'instruction
//  Structure de While : while(condition){bloc_instruction};                -> Condition testée au début    =>   Si condition fausse, pas d'execution de boucle; Sinon, execution tant que la condition est vraie 
// Mantra d'utilisation des boucles : 
//      - For : Quand le nombre d'itération est connu a priori
//      - Do/While : Quand l'instruction doit être réalisée au moins une fois
//      - While : sinon
/* --- */
int main(){
    /*
    double note(0.), somme(0.);
    int nb_notes(0);
    bool saisie_invalide(false);
    do {
        cout << "Saisir le nombre de notes :" << endl;
        cin >> nb_notes;
        if (nb_notes <=0){
            cout << "nb_notes doit être supérieur à 0" << endl;
        }
    } while(nb_notes <= 0);
    */
    /* --- */
    /*
    int n(4),k(3);
    do{k += 1;} while (k <= n);
    cout << k << endl;
    */
    /* --- */
    /*
    int a(3), b(5);
    while (b <= 4 * a){ cout << "*" << b << " "; b *= 2;}
    cout << "*" << b << endl;
    */
   int nb_surprise(5),nb_input(0),nb_essai(3);
   do {
       cout << "Plus que " << nb_essai << " essais" << endl;
       cout << "Saisir un nombre de 1 à 10" << endl;
       cin >> nb_input;
       --nb_essai;
    } while (nb_surprise != nb_input && nb_essai >0);
    if (nb_input == nb_surprise){
        cout << "Trouvé" << endl;
    } else {
        cout << "Perdu -> Vrai nombre = "<< nb_surprise << endl;
    }


    
   
    return 0;
}