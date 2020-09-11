#include <iostream>
#include <array>
using namespace std;

class Point {
private:
    double x;
    double y;
public:
    void init() { x = 0.0; y = 0.0; }
    void setX(double newX) { x = newX; }
    void setY(double newY) { y = newY; }
    double getX() const { return x; }
    double getY() const { return y; }
};

int main() {
	Point p1;
	Point p2;
	p1.init();
	p2.init();
	p1.setX(2.5);
	p2.setY(4.0);
	cout << p1.getX() << ", " << p1.getY() << endl;
	cout << p2.getX() << ", " << p2.getY() << endl;
	
	
	
	return 0;
}
