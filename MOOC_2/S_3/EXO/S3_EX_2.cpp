#include <iostream>
using namespace std;

class Point2D {
	private :
		double x;
		double y;
    public : 
		Point2D(double a=0., double b=0.) : x(a), y(b) {}
		ostream & affiche(ostream & out) const; 
};
ostream & Point2D::affiche(ostream & out) const {
	out << "( " << x << " , " << y << " )." << endl;
	return out;
}
ostream & operator<<(ostream & out, Point2D const & p) {
	return p.affiche(out);
}
//
class Point3D {
	private :
		double x;
		double y;
		double z;
	public : 
		Point3D(double a = 0.,double b = 0., double c = 0.) : x(a), y(b), z(c) {}
		ostream & affiche(ostream & out ) const;
};
ostream & Point3D::affiche(ostream & out) const {
	out << "( " << x << " , " << y <<" , " << z << " )." << endl;
	return out;
}
ostream & operator <<(ostream & out, Point3D const & p) {
	return p.affiche(out);
}
//
// [...]




int main() {
	Point2D p,p1(2,1);
	cout << p << endl;
	cout << p1 << endl;
	Point3D p2,p3(2,1,4);
	cout << p2 << endl;
	cout << p3 << endl;
	// [...]
	
	
	return 0;
}



