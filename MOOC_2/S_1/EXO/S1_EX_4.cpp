#include <iostream>

/*---*/
using namespace std;
/*---*/
class Point3D {
	private :
		double x;
		double y;
		double z;
	public :
		void init(double const & a, double const & b, double const & c);
		void affiche() const;
		bool compare(Point3D p) const;
};
/*---*/
void Point3D::init(double const & a, double const & b, double const & c) {
	x = a; y = b; z = c;
}
void Point3D::affiche() const {
	cout << "("<<x<<","<<y<<","<<z<<")"<<endl;
}
bool Point3D::compare(Point3D p) const{
	return (this->x == p.x && this->y == p.y && this->z == p.z);
}

/*---*/
int main() {
	Point3D point1; Point3D point2; Point3D point3;
	point1.init(1.0, 2.0, -0.1);
	point2.init(2.6, 3.5, 4.1); 
	point3 = point1;
	cout << "Point 1 : "; point1.affiche();
	cout << "Point 2 : ";point2.affiche();
	cout << "Point 3 : ";point3.affiche();
	cout << endl;
	cout << "Le point 1 est ";
	if (point1.compare(point2)) {
		cout << "identique au";  
	} else {
		cout << "différent du"; 
	}
	cout << " point 2." << endl;
	cout << endl;
	cout << "Le point 1 est ";
	if (point1.compare(point3)) {
		cout << "identique au"; 
	} else {
	cout << "différent du"; 
	}
	cout << " point 3." << endl;
	
	
	
	return 0;
}


