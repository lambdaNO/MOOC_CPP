#include <iostream>
#include <cmath>
#include <array>
/*---*/
using namespace std;
/*---*/
class Point3D {
	private :
		double x_;
		double y_;
		double z_;
	public :
		void init();
		void affiche() const;
		double x() const;
		double y() const;
		double z() const;
		double distance(Point3D const & p) const;
		double distance(Point3D const & p1,Point3D const & p2) const;
		
};
//
class Triangle{
	private :
		array<double,3> cotes;
	public :
		void init(); 
		double perimetre() const;
		bool isocele() const;
	
	
};

/*---*/
void Point3D::init() {
	cout << "Construction point : " << endl;
	cout << "\t x = "; cin >> x_;
	cout << "\t y = "; cin >> y_;
	cout << "\t z = "; cin >> z_;
	cout << "-> Point : ";
	affiche();
}
void Point3D::affiche() const {
	cout << "("<<x_<<","<<y_<<","<<z_<<")"<<endl;
}
double Point3D::x() const {
	return x_;
}
double Point3D::y() const {
	return y_;
}
double Point3D::z() const {
	return z_;
}
double Point3D::distance(Point3D const & p) const {
	return sqrt(pow((this->x_ - p.x()),2) + pow((this->y_ - p.y()),2) + pow((this->z_ - p.z()),2));
}
double Point3D::distance(Point3D const & p1,Point3D const & p2) const {
	return sqrt(pow((p1.x() - p2.x()),2) + pow((p1.y() - p2.y()),2) + pow((p1.z() - p2.z()),2));
}
double distance(Point3D const & p1,Point3D const & p2) {
	return sqrt(pow((p1.x() - p2.x()),2) + pow((p1.y() - p2.y()),2) + pow((p1.z() - p2.z()),2));
}



void Triangle::init() {
	array<Point3D,3> sommets;
	for (auto & p : sommets) {p.init();}
	//
	for (size_t i(0); i < sommets.size(); ++i) {
		//cout << i << " - " << (i+1) % 3 << "."<< endl;
		cotes[i] = distance(sommets[i],sommets[(i+1) % 3]);
	}	
}
double Triangle::perimetre() const {
	double p(0.);
	for (auto c : cotes) {
		p+= c;
	}
	return p;
}

bool Triangle::isocele() const {
	return cotes[0] == cotes[1] || cotes[1] == cotes[2] || cotes[2] == cotes[0];
}




/*---*/
int main() {
	/*
		Point3D p1, p2, p3;
		p1.init();
		p2.init(); 
		p3.init();
	*/
	Triangle t;
	t.init();
	cout << "Périmètre = " << t.perimetre() << endl;
	cout << "Isocèle  = " << t.isocele() << endl;
	
	//
	
	
	return 0;
}


