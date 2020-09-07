#include <iostream>
using namespace std;

int main()
{
  int debut(0);
  do {
    cout << "de (>= 1) ? ";
    cin >> debut;
  } while (debut < 1);

  int fin(0);
  do {
    cout << "a (>= " << debut << ") ? ";
    cin >> fin;
  } while (fin < debut);

  /*******************************************
   * Completez le programme a partir d'ici.
   *******************************************/
   for ( int i = debut ; i <= fin ; ++i ) {
 		int cpt( 0 );
 		int n( i ),sv(n);
 		while ( n > 0 ) {
 			if ( n % 3 == 0 ) { n+=4; cpt += 1; }
 			else if ( ( n % 3 != 0 )  &&  ( n % 4 == 0 ) ) { n/= 2; cpt += 1;}
 			else { n-=1; cpt += 1; }
     }
 		cout << sv << " -> " << cpt << endl;
 	 }

  /*******************************************
   * Ne rien modifier apres cette ligne.
   *******************************************/

  return 0;
}
