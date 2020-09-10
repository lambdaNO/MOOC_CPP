#include <iostream>
#include <vector>
#include <memory>
using namespace std;
/* --- */
// Principe du pointeur :
//  Permet de faire (et garder) un lien vers une données (variable) et avoir une référence universelle le long de l'execution du programme
//  3) Smart pointers (C++11)
// 		Gestion dynamique de la mémoire + eviter l'oublie des delete;
//		=> garbage collector; (plus besoin de delete)
//		=> Charger la librairie  mémory
//		3 types de pointeurs intelligents
//				- unique_ptr : un seul SP pointant vers une adresse mémoire
//											 ne peut être copié mais peut être déplacé ou trabsmis plus loin;
//											 Si on veut désallouer la mémoire associée, on fera ptr.reset() (qui met automatqiuement ptr à nullptr // Qui réalise automatqiuement delete)
//				- shared_ptr : plusieurs pointeurs peuvent pointer vers la même adresse mémoire
//											 zone mémoire partagée par plusieurs endroits du code (sans qu'aucun ne sache quand elle n'est plus utilie pour les autres)
//											Techniquement, pour qu'il puisse y avoir restitution automatique d'une zone mémoire référencée par des shared_ptr, il faut donc qu'il y ait une comptabilité des différentes zones, portions de codes, qui référencent cet emplacement mémoire. Donc, on ne peut désallouer automatiquement cet emplacement que lorsque plus personne ne l'utilise. Et il peut y avoir des situations de dépendance cyclique qui font que l'on arrive plus à restituer proprement la mémoire en utilisant
//											les shared_ptr. A ce moment-là, en combinaison, il va falloir utiliser des weak_ptr qui vont permettre de casser les cycles éventuellement induits par les shared_ptr.
//				- weak_ptr :  plusieurs pointeurs peuvent pointer vers la même adresse mémoire
//											presque comme un shared_ptr mais peut avoir été détruit par ailleurs (ie qu'on est pas compaté dans les dutilisateurs de cette zone mémoire (utile pour casser les cycles de shared_ptr))
//

struct Personne{
	string nom;
	string prenom;
	string age;
};
unique_ptr<Personne> naissance (string nom);


int main()
{
	unique_ptr <int> p1 (new int(3));
	// faire unique_ptr <int> p2(p1); // N'est pas licite car deux unique_ptr ne peuvent pointer sur la même zone mémoire
	cout << *px << endl;
	// Déclaration d'un tableau de pointeur
	vector<unique_ptr<string>> noms;												// Les cases sont des pointeurs capables de pointer vers des variables de type chaine de caractètre
	noms.push_back(unique_ptr<string>(new string("Pierre")));
	noms.push_back(unique_ptr<string>(new string("Paul")));
	// Déplacement des unique_ptr :
	// 			-> Déclaration d'un pointeur (et donc une adresse mémoire)
	unique_ptr<Personne> adresse_quidam(naissance("Pierre"));
	// Par appel de la fonction, on a associé à bb l'adresse adr de la zone mémoire contenant Pierrre
	// adresse_quidam va contenir l'adresse adr de la zone mémoire contenant Pierre
	// Mais par propriété des pointeurs "unique", bb va être rendu non utilisable (avec suppression du lien) + adresse_quidam va contenir l'adresse adr que contenait initialement bb
	// Il y a eu donc déplacement de l'adresse !



  return 0;
}



// Grâce à naissance, on veut créer une personne et retourner le pointeur qui accès à cette zone mémoire
unique_ptr<Personne> naissance (string nom){
		unique_ptr<Personne> bb (new Personne);
		// Initialise le contenu pointé par bb (nom prenom age) <-> avec *bb rempli les champs assiciés
		return bb;
};
