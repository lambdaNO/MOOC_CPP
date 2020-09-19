#include <iostream>
#include <cmath>
using namespace std;

/*
Surcharge, masquage, et substitution de méthodes virtuelles :
  Rappel :
      Surchage : même nom mais paramètres différents dans la même portée
      Masquage : entités de même noms mais de portées différentes, masquées par les règles de résolution de portée
      substitution (de méthode virtuelle)
          - résolution dynamique -> c'est la méthode de l'instance qui est appelée (si pointeur ou référence + virtual)
          - si l'on redéfinit qu'une seule méthode virtuelle surchargée alors les autres sont masquées

Mots clés -> override : permet de spécifier que la méthode risque d'être substituée
          -> final : permet de spéficier que la méthode ne sera jamais substituée, masquée ...
          Eg : voir les slides avec les expression
          MANTRA : écrire à CHAQUE FOIS override dès lors que l'on souhaite réécrire une méthode hérité d'une superclasse


*/
class A {
    public :
        virtual void m1(int i) const { cout << "A::m1(int) : "<<i<< endl;}
        // Exemple de surcharge
        virtual void m1(string const & s) const { cout << "A::m1(string) : "<<s<< endl;}
};
class B : public A {
    public :
        // substitution de la méthode m1(string const & s) héritée de la classe A (qui devient hors de portée) - Masquage
        // B::m1(string) est la seule atteignable directement
        virtual void m1(string const & s) const { cout << "B::m1(string) : "<<s<<endl;}
};
class C : public A {
    public :
        // Introduction d'une troisième méthode -> Masquage des deux précédente méthode m1
        virtual void m1(double x) const {cout << "C::m1(double) : "<<x<<endl;}
};
/* --- */


int main() {
    /*
    B b;
    //b.m1(2)     // Erreur car elle n'est pas atteignable depuis la classe B -> Opérateur de portée si on veut l'utiliser ;
    b.A::m1(2);   // OK
    b.m1("s");    // Sans souci
    C c;
    c.m1(2);      // C'est l'appel à la méthode double
    // c.m1("2"); // Non toujours pas
    c.A::m1("2"); // Démasquage de la méthode par opérateur de portée
    c.A::m1(2);   // Démasquage de la méthode par operateyr de portée
    */
    /* --- */
    // substitution => virtual + pointeur;
    B b;
    C c;
    A* pa(nullptr);

    pa = &b;            // On fait pointer pa sur B
    pa -> m1("2");
    pa -> m1(2);        // Nous sommes dans la classe A::
                        // m1 est une méthode virtuelle qui est substituée dans la classe B
                        // mais m1 n'a pas de surcharge sur sa forme int -> on appelle sur A
    pa = &c;
    pa -> m1(2.1);      // Nous sommes toujours dans A::
                        // Pas de méthode m1 pour un double -> Passage sur la méthode m1 int de la classe A
                        //
    //pa-> C::m1(2.1)   // NON C est un A (pas l'inverse) -> Pas de démasquage possible
    return 0;
}
