#include <iostream>
using namespace std;
/* --- */
// Notion de variable - locale (dans un bloc)
//                    - globale (déclarée avant le bloc) -> NE JAMAIS UTILISER
// Règle de portée : la plus proche
/* --- */
int main(){
    /*
    double x(3.14);
    {
        double x(2.27);
        cout << x << ", ";
    }
    cout << x << endl;
    */
    int i(120);

    for (int i(0); i < 5; ++i)
    {
        cout << i << endl;
    }

    cout << i << endl;

    return 0;
}