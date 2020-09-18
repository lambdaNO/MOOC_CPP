
#include <iostream>
#include <string>
#include <vector>
using namespace std;
/*
class Rect {
private:
    double width, height;
public:
    double getWidth() const { return width; }
    double getHeight() const { return height; }
};

class ColoredRect : public Rect {
protected:
    int color;
    void init();
public:
    double getSurface() const { return Rect::getHeight()*Rect::getWidth(); }
    int getColor() const { return color; }
};
*/


class Square {
private:
    double size;
public:
    double surface() { return size*size; }
    double getEdge() { return size; }
};

class Cube : public Square {
public:
    double surface() { return 6*Square::surface(); }
};

class Rect {
public:
    Rect() { cout << "1"; }
    ~Rect() { cout << "2"; }
};

class Rect2: protected Rect {
public:
    Rect2() { cout << "3"; }
    ~Rect2() { cout << "4"; }
};

int main(){
	
	
	//ColoredRect cr;
	//cr.getColor();
	//Rect r;
	//r.getSurface();
	
	Rect2 r;
	
	
	return 0;
}
