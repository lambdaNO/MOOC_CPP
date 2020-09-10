#include <iostream>
using namespace std;
/* --- */
// Principe du pointeur :
//  Permet de faire (et garder) un lien vers une données (variable) et avoir une référence universelle le long de l'execution du programme
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
// Déclaration du pointeur :
//    type* identificateur; : déclarer une variable de nom "identificateur" de type pointeur sur une valeur de type "type"
//          int* ptr  => déclare un pointeur prt qui point sur une valeur de type int
// Initialisation :
//    type* identificateur(adresse);
// Opérateurs sur les pointeurs :
//     & -> retourne l'adresse mémoire de la valeur d'une variable
//        Ex :
//              int x(3);               // Déclaration en mémoire d'une variable x contenant 3 et stockée à l'adresse adr
//              int* ptr(nullptr);      // Déclaration d'un pointeur sur un entier qui ne contient pas d'adresse mémoire pour le moment;
//              ptr = &x;               // Affectation à ptr l'addresse mémoire de x (ptr = adr)
//        Rmq : Si x est de type "type", alors &x est de tupe "type*" (ie pointeur sur "type");
//      * -> retourne la valeur pointée par une variable pointeur;
//        Ex :
//              int x(3);             // x est un type entier
//              int* ptr(nullptr);    // pointeur vers x
//              ptr = &x;             // Affectation du pointeur sur la variable x
//              cout << *ptrx << endl   // => va retourner "3";
//
//        Rmq : Si px est de type "type*", (*px) est la valeur de type "type" pointée par "px"
//				*&i <=> i
//
//  Rappel : Bordel et notations
//    type& id : est une référence sur une varaible id dans le passsage par référnce d'une fonction
//    &id est l'adresse de la varaible id
//    type* id : déclare une varible id comme un pointeur sur un type de base type
//    id* représente le contenu de l'endroit pointé par id (avec id un pointeur)

int main()
{
	//int * ptr(nullptr);             // Déclaration d'un pointeur sur une variable de type entier (ie l'adresse d'un entier) avec nullptr (= ne pointe vers rien)
	//int * prt(&i);                  // Initialisation d'un pointeur ptr pointant sur une zone de mémoire nommée
	//int * ptr(new int(33));         // Allocation dynamique d'un emplacement mémoire capable de contenir une donnée de type particulier

	int x(3);
	int* px(nullptr);
	px = &x;
	cout << &px << endl;				// L'adresse mémoire où est stockée x (et donc la valeur de px)
	cout << *px << endl;				// La valeur associée à l'adresse mémoire vers laquelle pointe px

  /* --- */
  int i(2), j(4);
  int* pk;
  int* pi(&i);
  int* pj(&j);
  int** ppj(&pj);

  if (*pj == 2 * *pi) {
    cout << *pi << " " << *&i << " " << **ppj << " " << *&*&j << endl;
  } else {
      cout << *pk << endl;
  }



  return 0;
}
