#include <iostream>
#include <array>
#include <vector>
#include <string>
using namespace std;
/* --- */
struct Compo {
  string auteur;
  string sujet;
  string destinataire;
  string politesse;
  char dest_sexe;
  int jour;
  int mois;
};
/* --- */
void genereLettre(Compo const& c);
/* --- */
int main()
{
  Compo c1 = {"John","votre cours","Mireille","Sincèrement",'F',18,12};
  Compo c2 = {"Mireille","votre demande de rendez-vous","John","Amicalement",'M',16,12};
  genereLettre(c1);
  genereLettre(c2);
  return 0;
}
/* --- */
void genereLettre(Compo const& c) {
  string acc("");
  if (c.dest_sexe == 'M'){ acc = "cher";} else { acc = "chère";}
  cout << "Bonjour "<<acc<<" "<< c.destinataire <<", "<< endl;
  cout << "Je vous écris à propos de " << c.sujet << ". "<<endl;
  cout << "Il faudrait que nous nous voyons le "<< c.jour << "/" << c.mois << " pour en discuter."<< endl;
  cout << "Donnez-moi vite de vos nouvelles !"<< endl << c.politesse <<", " << c.auteur << "."<< endl;
}
