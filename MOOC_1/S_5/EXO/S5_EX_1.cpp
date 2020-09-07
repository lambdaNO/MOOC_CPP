#include <iostream>
#include <vector>        // Appel à la librairie vector
using namespace std;

int main(){
    vector<double> notes;
    double sum(0.), note(0.), moyenne(0);
    /* --- */
    cout << "Saisie des notes :" << endl;
    do {
      cout << "\tEntrez la note de l'élève " << notes.size() + 1 << " (<0 pour finir) :  ";
      cin >> note;
      if (note >= 0){
        notes.push_back(note);
        sum += note;
      }

    } while (note>=0);
    moyenne = sum/notes.size();
    cout << "Moyenne de classe : " << moyenne << endl;
    cout << "\tDétail des notes : " << endl << "\tElève : note (écart à la moyenne)"<<endl  ;
    for (size_t i(0); i<notes.size();++i){
      cout <<"\t\t"<< i << " : " << notes[i] << " ("<<moyenne-notes[i]<<")"<<endl;
    }


    return 0;
}
