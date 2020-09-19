#include <iostream>
#include <cmath>
using namespace std;
/*
    Collections hétérogènes :
        -> polymorphisme d'inclusion * traitement générique sur les instances génériques de hierarchie de classe
        -> passage par référence * pour appliquer le traitement fonction de la nature réelle de l'instance
        => collection hétérogène : traitement générique d'un ensemble d'instances d'une hiérarchie de classe
                                  le comportement est spécifique à chaque instances
        Eg :
            [Personnage] <------- [Magicien]
                         <------- [Voleur]
                         <------- [Guerrier]
            Chaque sous-classe de personnage possède des attributs propres
            idée : définir dans une classe Jeu des méthodes permettant de définir un comportement global indépendant du type de personnage
            class Jeu {
                private :
                    vector<Personnage> persos;      // contient aussi bien un magicien qu'un voleur, ...
                public :
                    void afficher() const;
                    void ajouter(Personnage const &);
            };

            Pour le moment - impossible de faire du polymorphisme car il faut VIRTUAL et PASSAGE REFERENCES
            Une possibilité :
            Un vecteur de pointeurs de personnage;
                Méthode 1 -   vector<Personnage*> persos;
                Méthode 2 (C++11) - vector<unique_ptr<Personnage>> persos;    // avec #include <memory>
            ATTENTION -> Ce ne sont plus des instances qui sont stockées mais des "adresses" des instances !!!!

            ALORS
                Pour ajouter :
                    Jeu jeu;
                    jeu.ajouter(new Guerrier(...));   // Avec new <=> l'allocation dynmaique;
                Modification de la signature :
                    void ajouter(Personnage *);
                Implémentation :
                    void ajouter(Personnage * n) {
                        if (n != nullptr) {   // Garde fou voir MOOC 1
                          persos.push_back(unique_ptr<Personnage>(n));    // Transformation en pointeur intelligent;
                      }
                    }
                Pour afficher :     // Attention on utilise des unique_ptr qui n'ont pas de constructeur de copie
                    void afficher() const {
                        for (auto const & quidam : persos) {
                              quidam->afficher();
                        }
                    }
              


*/
int main() {
    return 0;
};
