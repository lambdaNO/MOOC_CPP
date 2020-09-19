#include <iostream>
#include <cmath>
using namespace std;
/*
Polymorphisme : le polymorphisme est le fait qu'un même code puisse s'adapter automatiquement aux types des données
auxquels il s'applique. Il s'agit d'une notion importante car elle permet d'aller vers du code générique, du code
qui s'écrit de façon unifiée pour différents types de données.
=> Le polymorphisme est le fait d'appliquer le même code à des objets prenant plusieurs formes et que l'exécution du code s'adapte automatiquement à la forme de l'objet
Eg :
    Personnage joueur;
    vector<Personnage> autres_joueurs;    // Ce tableau contient des personnages de plusieurs types (ie de plusieurs sous-classes de personnages)
    for (auto perso : autres_joueurs){
        perso.rencontrer(joueurs)         // où perso peut être élément d'une sous classe de Personnage de type voleur, magicien, ...
                                          // La méthode rencontrer peut varier d'une sous classe à l'autre mais possède un appel unifié
    }
Rappels :
    - Dans une hiérarchie de classes, la sous-classe hérite de la super-classe
        * tous les attributs/méthodes (SAUF constructeurs et destructeurs)
        * le type de la super-classe (on peut affecter un objet de type sous-classe à une variable de type super-classe)
        [Personnage] <--- "est_un" --- [Guerrier]
        Personnage p; Guerrier g;
        // Affectation licite :
        p = g;
    - L'héritage est transitif

Polymorphisme : Les instances d'une sous-classe sont substituables aux instances des classes de leurs ascendances et gardent leurs propriétés propres
=> En c++ Le type de la variable détermine la méthode à executer (type de la super-classe) -> Résolution statique des liens
Résolutions dynamique des liens -> Choix de la méthode fonction de la sous-classe
    Ingédient : -> Pointeurs/Pointeurs
                -> Classes virtuelles

Eg :
class Personnage {
    private/protected : ...
    public :
        void rencontrer(Personnage & p) const {cout << "Bonjour !"<< endl;}
        ...
}
class Guerrier : public Personnage {
    private/protected : ...
    public :
        void rencontrer(Personnage & p) const {cout << "Boum !"<< endl;}
}
void faire_rencontrer(Personnage const & un, Personnage const & autre) {
    cout << un.getnom() << " VS " << autre.getnom() << endl;
    un.rencontrer(autre);       // Va appeler la méthode de la super-classe -> "Bonjour"
}
int main() {
    Guerrier g; Voleur v;
    faire_rencontrer(g,v);      // Va appeler la méthode de la super-classe -> "Bonjour"

    return 0;
}



-----
Méthodes virtuelles :
    => Idée : On veut que la méthode appliquée soit fonction du contenu de la variable et non du type:
    TODO :
    Dans la classe Personnage, Rendre la méthode rencontrer **virtuelle**

        virtual void rencontrer(Personnage & p) const {cout << "Bonjour !"<< endl;}

    (+) Il faut que l'argument passé dans la méthode soit **UNE REF** ou **UN POINTEUR**

    Syntaxe :
        virtual Type nom_fonction(liste_params) [const];    avec liste_params une collection de types références ou pointeurs
    Remarque :
        -> La déclaration "virtual" doit se faire dans la classe LA PLUS GENERALE qui admet cette méthode (ie lors du prototypage d'origine)
        -> Les redéfinitions éventuelles dans les sous classes seront aussi considérées comme virtuelles par transitivité (nul besoin de répéter le KW dans les redéfinitions des méthodes dans les sous-classes)
    TODO :
        -> Les méthodes doivent avoir des arguments de type références ou pointeurs
        -> SINON l'appel va se faire une copie de l'objet (et donc son type -> celui de la super-classe)
        -> Le passage par références constantes fonctionne aussi (const &)
    Remarque :
        -> Dans l'exemple des Mammifere si on avait :
              "~Mammifere()" et pas virtual "~Mammifere()"
           Alors l'objet aurait été partiellement détruit !
    Moralité :
        Lorsque : Méthode virtual + Référence/Pointeur -> c'est la méthode réelle de l'instance qui est appelée
        Conseil -> Les destructeurs doivent être toujours définis comme virtuels (sinon mauvaise désallocation)
        -> Un constructeur ne peut pas être virtuel
        -> L'aspect virtuel des méthodes est ignoré dans les constructeurs







*/
// Exemple 1 :
class Mammifere {
    public :
        Mammifere() {cout << "Naissance d'un Mammifere (Mammifere::Mammifere())" << endl;}
        virtual ~Mammifere() {cout << "Mort d'un Mammifere (Mammifere::~Mammifere())" << endl;}
        void manger() const {cout << "Mammifere mange (Mammifere::manger())" << endl;}
        virtual void avancer() const {cout << "Mammifere avance (Mammifere::avancer())" << endl;}
};
class Dauphin : public Mammifere {
    public :
        Dauphin() {cout << "Naissance d'un Dauphin (Dauphin::Dauphin())" << endl;}
        ~Dauphin() {cout << "Mort d'un Dauphin (Dauphin::~Dauphin())"<< endl;}            // prototypage initial virtual -> retournera "Mort d'un Dauphin"
        void manger() const {cout << "Dauphin mange (Dauphin::manger())"<< endl; }      // prototypage initial non virtual -> retournera "Mammifere mange"
        void avancer() const {cout << "Dauphin avance (Dauphin::avancer())"<< endl;}      // prototypage initial virtual -> retournera "Dauphin avance"
};
// Exemple 2
class A {
    public :
      A() {f();}
      virtual void f() const { cout << "A::f()" << endl;}
};
class B : public A {
    public :
      virtual void f() const { cout << "B::f()" << endl;}
};
// Exemple 3

/* --- */
int main() {
  /*
    // Exemple 1
    Mammifere* lui(new Dauphin());    // Appel à constructeur de Mammifere(Mammifere* ) + Appel à constructeur de Dauphin(new Dauphin())
    lui-> manger();                   // Méthode non virtual -> Mammifere mange
    lui-> avancer();                  // Méthode virtual -> Dauphin avance
    delete lui;   lui = nullptr;      // Appels aux deux destructeurs;
  */

    // Exemple 2
    A a;          // A::f()
    B b;          // Aspect virtuel ignoré dans un constructeur -> A::f()
    A * pa(&b);   //
    pa->f();      // f choisi en fonction de la nature réelle de la classe (car virtual + référence) -> B::f()



    return 0;
}
