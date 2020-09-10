#include <iostream>
using namespace std;
/* --- */
// Principe du pointeur :
//  Permet de faire (et garder) un lien vers une données (variable) et avoir une référence universelle le long de l'execution du programme
//  Pointeurs ?
//    - Référence ; permet à plusieurs bouts de code de partager des objets (données fonctions) sans les duplique (simulation d'une colonie de fourmis, chaque fourmi « se souvienne » de sa fourmilière -> Chaque fourmi référence sa fourmilière, de la même manière que plusieurs utilisateurs différents d'un site Internet ont son adresse dans leurs signets.)
//    - Généricité ; Pouvoir choisir des éléments non connus a priori (Description générique d'objets)
//    - Allocation dynamique : pouvroir manipuler des objets dont la durée de vie dépasse la portée (ex : maniupler une variable size_t i hors d'un boucle pour)
//  Types de pointeurs :
//    - Référence :
//    - Smart pointers
//    - Pointeurs à la C (<<)
// -------------------------------------------
//  1) Référence ;
//      Une référence permet de designer un objet indirectement, permet de designer un objet existant un mémoire, ...
//      Ex : Passage par référence void f(int & a); ... ... ... int b(3); f(b)    est passé par référrence (on applique directement f sur l'objet b stocké en mémoire - C'est le m^me objet qui est désigné à l'intérieur et à l'exteirur de la fonction f)
//      Déclaration :
//        type & nom_reference(identificateur)
//        => nom_reference peut être utilisé partout où identificateur peut l'être
//        => Ce n'est pas une nouvelle variable, c'est une NOUVELLE ETIQUETTE pour une variable existante
//      Remarque : const s'applique à l'objet définit juste après ET PAS forcement à l'objet stocké en mémoire (dans le cas d'une référence &)
//      Spécificité des références
//        - Douvent absolument être initialisée :
//            int i;
//            int & ri(i);      // Ok car i est préalabement définit
//            int & rj;         // Non cas j n'est pas initialisé (et doit être lié à un objet)
//        - Une référence n'est liée qu'à un seul objet :
//            int i;
//            int& ri(i),
//            int j(2);
//            ri = j;     // Ne peut pas dire que ri est maintenant un alias de j, mais que i prend la valeur de j
//            j = 3;      // ri n'est pas une référence de j
//            cout << i << endl;      va afficher 2 ( et pas 3)
//        - On ne peut pas faire de référence de référence :
//            int i(3);
//            int& ri(i);       // OK
//            int& rii(ri);     // NON -> Une étiquette d'étiquette n'est pas licite
//            int&& rii(ri);    // NON -> même pas en rêve
//            ~~> ri n'est pas un objet, c'est une étiquette, elle n'a pas d'existence propre sans i;
//
//  2) Pointeurs
//      Un pointeur est une variable qui existe en mémoire (et pas seulement une étiquette comme la référence)
//      Un pointeur est physiquement identifié de manière unique par son adresse ie l'adresse de l'emplacement mémoire qui contient sa valeur.
//      ==> Un pointeur est une variable qui contient l'adresse d'un autre objet informatique (eg une variable)
//    MORALITE :
//          - Pointeur = adresse vers une variable
//          - Référence = étiquette
//    Opération sur les pointeurs :
//        int* ptr;   : déclarer un pointeur;      // Ajouter une nouvelle page vide dans un carnet
//        ptr = &x;   : affecter un pointeur;      // Ecrire une adresse sur la page vide
//        ptr = new int(123);   : allouer un pointeur   // Prendre de l'espace mémoire, y mettre une variable et la stocker l'adresse de la variable dans le pointeur (!!!!! le pointeur n'est pas la variable)
//        ==> le pointeur n'est pas la variable pointer
//        delete ptr  : libérer un pointeur (libérer l'adresse pontée par le pointeur)    // Effacer l'adresse contenue dans la page du carnet (mais garder la page)
//        ==> On ne peut pas réutiliser l'adresse qui n'appartient plus au pointeur
//        ==> Poesie : Un pointeur c'est comma la page d'un carnet d'adresse sur laquelle on ne peut écrire qu'une seule adresse à la fois
//        p1 = p2     : copier un pointeur (copie de l'adresse mémoire)
//        p1 = nullptr  : annuler effacer un pointeur (ATTENTION : la variable associée à l'espace mémoire pointé n'est pas libérée, il faudra alors détruire le pointeur avant de l'annuler)
/* --- */
int main()
{
/*
	// Références :
	int val(1);
	int& val_x(val);    // x est un "autre nom" de val (mais référence le même objet)
	// Exemple ;
	int i(3); int& j(i);
	cout << "int i(3); int& j(i);"<< endl;
	i = 4; cout << "\ti = 4;\ti = "<< i << " & j = " << j << endl;
	j = 6; cout << "\tj = 6;\ti = "<< i << " & j = " << j << endl;
	int m(3); int n(m);
	cout << "int i(3); int j(i);"<< endl;
	m = 4; cout << "\ti = 4;\ti = "<< m << " j = " << n << endl;
	n = 6; cout << "\tj = 6;\ti = "<< m << " j = " << n << endl;
	// Exemple ;
	double x(5.6);
	double& y(x);
	double z(y);
	double& t(z);
	// y est une référence sur x, ce sont la même variable en mémoire ; de même, t est une référence sur z.
	// z lui-même, par contre, est une nouvelle variable.
	cout << "x = " << x << ",\t& y(x) = " << y << ",\tz(y) = " << y << ",\t& t(z) = " << t << endl;
	x = 1.2;
	cout <<"x = 1.2;\t -> \t" <<"x = " << x << ",\t& y(x) = " << y << ",\tz(y) = " << y << ",\t& t(z) = " << t << endl;
	y = 2.3;
	cout <<"y = 2.3;\t -> \t" <<"x = " << x << ",\t& y(x) = " << y << ",\tz(y) = " << y << ",\t& t(z) = " << t << endl;
	t = 3.4;
	cout <<"t = 3.4;\t -> \t" <<"x = " << x << ",\t& y(x) = " << y << ",\tz(y) = " << y << ",\t& t(z) = " << t << endl;
	//cout << x << " " << y << " "<< z << " " << t << endl;
	// Exemple ;
  // a et b sont les même
  // on ne PEUT PAS changer la valeur via b
  // (Mais on peut le faire ailleurs)
  int a(3);
  const int& b(a);
  cout << " a = " << a << " b = "<< b << endl;
  //b = 12;   // NON -> Erreur du compilateur
  a = 12;     // OUI et ça modifie aussi b
  cout << " a = " << a << " b = "<< b << endl;
*/


  return 0;
}
