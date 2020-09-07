#include <iostream>
#include <vector>        // Appel à la librairie vector
#include <string>
using namespace std;
int saisir_taille();
void saisir_composantes(const string& s,vector<double>& v2);
void print(const string& s, vector<double> v);
double scalaire(vector<double> u, vector<double>v);

int main(){
	int n(saisir_taille());
	cout << "--> Taille saisie n = " << n << "."<< endl;
	/* --- */
	vector<double> v1(n), v2(n);
	saisir_composantes("v1",v1);
	print("v1",v1);
	saisir_composantes("v2",v2);
	print("v2",v2);
	cout << "v1.v2 = " << scalaire(v1,v2) << endl;;
	
  return 0;
}

int saisir_taille() {
  int n(0);
  cout << "-> Saisir taille n = ";
  cin >>n;
  return n;
}
void saisir_composantes(const string& s,vector<double>& v){
  for (size_t i(0);i<v.size();++i){
    cout << s<<"("<<i+1<<") = ";
    cin >> v[i];
  }
}
void print(const string& s, vector<double> v) {
	cout << s << " = ( ";
	for (auto elt : v) {cout << elt << ", ";}
	cout << ")." << endl;
}
double scalaire(vector<double> u, vector<double>v){
	double sc(0.);
	for (size_t i(0); i < u.size(); ++i){
		sc+=(u[i]*v[i]);
	}
	return sc;
}
