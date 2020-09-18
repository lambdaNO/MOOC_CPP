#include <iostream>
using namespace std;
/*
Surchage d'opérateurs -> Définition d'opérateurs perso

3 Niveaux :
  - Surcharge des opérateurs +,-,*,<<
  - Surcharge des opérateurs d'auto-affectation +=,-=     void operator+=(Classe const &)
  - Surchage des opérateurs d'auto-affectation +=, -=     Classe & operator+=(Classe const &)

Exemple :
    class Complexe { ... };
    Complexe z1, z2, z3, z4;
    => Pb : Addition ? l'opérateur "+" n'est pas définit pour la classe Complexe;
    => Pb : Affichage ? l'opérateur "<<" n'est pas définit pour la classe Complexe;
Objectif :
    Etendre l'utilisation des opérateurs usuels à des classes perso
Opérateurs :
    Arithmétique : + - * / ...              Affectation : =
    Logique : &&, ||, !                     Comparaison : < <= > >= != ==
    Incrément : ++
En fait, ça correspond à l'appel d'une fonction ou d'une méthode:
    a R b  -> operatorR(a,b)  ou a.operatorR(b)       eg a+b <->  operator+(a,b) ou a.operator+(b):
    R a    -> operatorR(a)    ou a.operatorR()        eg -a  <->  operator-(a)   ou a.operator-(), ++a <-> operator++(a)  ou a.operator++(),  cout << a <-> operator<<(a) ou  cout.operator<<(a)  avec operator<< est élément de la class iostream
Exemple :
    a * (b + c)
        <-> operator*(a, operator+(b, c)) OU  operator*(a, b.operator+(c)) OU   a.operator*(operator+(b, c))  OU  a.operator*(b.operator+(c))
La surcharge ?  Une méthode qui a le même nom mais pas les mêmes paramètres
Ex : int max(int,int) ou double max(double, double)
Ex : Complexe operator+(Complexe,Complexe)
     Matrice operator+(Matrice,Matrice)
2 types de surcharge
    - externe <-> fonction eg Complexe operator+(Complexe, Complexe);
    - interne <-> méthode eg class Complexe { public Complexe+(Complexe) const };

SURCHARGE EXTERNE
    Les opérateurs sont des fonctions
    z3 = z1 + z2;         // Complexe z1, z2, z3, z4;
    <=> z3 = operator+(z1,z2) <=> const Complexe operator+(Complexe const &, Complexe const &)
=>  Dès fois, on est obligé d'appliquer la surchage externe :
    E.g. opérateurs concernés par une classe mais pour lesquels la classe en question n'est pas l'opérande de gauche
    double x; Complexe z1,z2;     z2 = x*z1   <-> z2 = x.operator*(z1)      NON le premier n'a pas de sens - x n'est pas un objet mais un type élémentaire;
                                              <-> z2 = operator*(x,z1)      OUI
SURCHARGE INTERNE
    eg :  z1.operatorOp+(z2);
    public :
        Complexe operator+(Complexe) const;
    Syntaxe :
        class nomClasse {
            // prototype de l'op
            type_retour operatorOp(type_parametre);
        };
        // Défintion :
        type_retour nomClasse::operatorOp(type_parametre) {
            ...
        }

MANTRA :
    * Préférer la surchage externe àç chaque fois que l'opérateur peut s'écrire à l'aide de l'interface de la classe
    * Si l'opérateur est proche de la classe i.e. nécessire des accès internes ou des copies supplémentaires inutiles (eg opérator+=) utiliser la surchage interne

Pourquoi des const, des ostream & .
    const Complexe operator+(Complexe,Complexe const &) ??
        z3 = z1 + z2      // OK
        ++(z1 + z2)       // NON z1+z2 est une constante -> Quelle utilité de l'incrémenter ?  ie ++(operator+(z1,z2))
        z1 + z2 = f(x) ;  // Pas utile de l'écrire à gauche d'un signe égal ...
        => Le résultat d'une addition est un nombre complexe et ne peut être modifié
    ostream & operator<<(ostream& sortie, complexe & z)
        cout << z1 << endl;   <=>   operator<<(operator<<(cout,z1),endl) donc on modifie par référence l'ostream et la valeur de retour est l'ostream lui même
    Complexe & Complexe::operator+=(Complexe const &)
        z1+= z2;
        // Car c'est juste z1 que l'on modifie
        L'implémentation :
        Complexe & Complexe::operator+=(Complexe const & z2) {
            x+= z2.getX(); y+= z2.getY();
            return *this;                 // Correspond à la valeur de mon instance courante sur laquelle j'opère le += // this correspond à l'adresse mémoire;
        }
        MANTRA : Toujours éviter les copies inutiles dans les opérateurs d'auto-affectation;
        Eg :
        Complexe Complexe::operator+=(Complexe z2) {
            Complexe z3; x+= z2.x; y+= z2.y; z3 = *this; return z3;
            // 3 copies inutiles (le z courant, z2 et z3 = z2+z courant)
        } // Préférer la surchage précédente;


L'opérateur d'égalité (=)
    Universel - Pas forcement besoin de le redéfinir;
    Il fait une copie de surface;
    Si on veut le supprimer :
    Class GrosseClasse {
        public :

        private :
            GrosseClasse & operator=(GrosseClasse const &) = delete;

    };
    SI ON DOIT VRAIMENT LE REDEFINIR :
    Exemple :
    #include <utility>
    [...]
    class Classe {private : X x; Y y; public : ...}
    void swap (Classe & a, Classe & b) {
        swap(a.x, b.x); swap(a.y, b.y); ...
    }
    Classe & Classe::operator=(Classe source) {
        swap(*this, source);
        return *this;
    }

*/
/* --- */
class Complexe {
    private :
        double x;
        double y;
    public :
		Complexe () : x(0.), y(0.) {};
        Complexe(double a, double b) : x(a), y(b) {}
        ~Complexe(){};
        double getX() const {return x;}
        double getY() const {return y;}
        void affiche() const { cout << "z = " << x << " + i * " << y << endl;}
        // Moche et à ne pas faire mais ça existe (**)  -> Donner accès aux parties privée de la classe (ATTENTION : la définition de la fonction est bien hors de la classe)
        //    -> Ici c'est juste le prototype pour donner accès aux parties privées.
        //friend const Complexe operator*(double, Complexe const &);
        //friend ostream& operator<<(ostream&, Complexe const &)
        // Surchage interne :
        //    z1+=z2  - N'est pas const car il modifie la valeur de z1;
        void operator+=(Complexe const & z2);


};
// Opérateur de surcharge externe (fonction)
const Complexe operator+(Complexe const & z1, Complexe const & z2){
    return Complexe(z1.getX()+z2.getX(),z1.getY()+z2.getY());
}
const Complexe operator*(double x, Complexe const & z) {
    //return z*a;     //CAS : On suppose qu'il existe une surcharge interne au complexe operator*(double) ou une surchage externe telle que operator*(Complexe, double)
    return Complexe(x*z.getX(),x*z.getY());
}
ostream & operator<<(ostream & sortie, Complexe const & z) {
    // Remarque :  cout, qui est une instance de la classe ostream, est passé par référence. En effet, l'affichage en question, " cout << z1 ", va bien modifier <i>cout</i>, puisqu'on va écrire des informations sur <i>cout</i>, on va le modifier, et donc comme on modifie cet argument, il faut absolument le passer par référence.
    sortie << "z = "<<z.getX() <<" + i * " << z.getY() << "   (SE-1)";
    return sortie;
}
/*
Méthode alternative :
ostream & operator<<(ostream & sortie, Complexe const & z) {
    sortie << z.to_string();              // avec : string Complexe::to_string() const;
    return sortie;
}
ostream & operator<<(ostream & sortie, Complexe const & z) {
    return z.affiche(sortie);                   // avec : ostream Complexe::affiche(ostream & sortie) const;
}

ATTENTION A NE PAS FAIRE MAIS CA EXISTE (**) :
ostream & operator<<(ostream & sortie, Complexe const & z) {
    // Accès directet aux éléments de la classe sans passer par des accesseurs :
    // Il faut ajouter dans le classe complexe des méthodes friend avec prototype de la fonction;
    sortie << "z = "<<z.x <<" + i * " << z.y << "   (SE-1)";
    return sortie;
}
*/
// Implémentation de la surcharge interne
void Complexe::operator+=(Complexe const & z2) {
    // x et y sont toujours accessible puisque l'on est dans l'implémentation Complexe::
    x+= z2.getX(); y+= z2.getY();
}
// Implémentation d'une surchage externe + à partir d'une surchage interne +=
//  Ici, on renvoit dans z1 la somme de z1 et z2 -> z1 est passé par valeur (zone local sur laquelle on travaille) et z2 est passé par référence constance
// Autre exemple om on à le choix
/*
    z3 = z1.operator+(z2);    // Interne
    z3 = operator+(z1,z3);    // Externe
*/
/*
// Commenter l'implémentation du operator+ précédente
const Complexe operator+(Complexe z1,Complexe const & z2) {
    return z1 += z2;
}
*/



/* --- */
int main() {
    Complexe z1(1.,2.), z2(3.,4.);
    Complexe z3,z4,z5;
    z1.affiche(); z2.affiche();
    z3 = z1+z2;
    z3.affiche();
    z4 = 2*z3;
    z4.affiche();
    cout << z4 << endl;
    z1+= z4;
    z1.affiche();


    return 0;
}
