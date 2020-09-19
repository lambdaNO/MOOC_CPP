#include <iostream>
using namespace std;

/*
class A {
public:
    virtual void print() const { cout << "A"; }
};

class B : public A {
public:
    void print() const { cout << "B";}
};
*/

//void display(A* in) {in->print();}
//void display(A& in) {in.print();}
//void display(A const & in) {in.print();}
//void display(B in) {in.print();}
//void display(A in) {in->print();}
//void display(A**in) {in->print();}
//void display(B* in) {in.print();}
//void display(A in) {in.print();}

class Person {
public:
    void talk();
    virtual void walk();
    virtual void run() final;
    virtual void fling(int distance) const;
};


class Worker : public Person {
	public:
		//void fling(int distance) const;
		//void fling(int distance) override;
		//virtual void run();
		//void talk() override;
};

class A {
public:
    virtual void test() = 0;
    virtual void disp() const { cout << "a"; }
};

class B : public A {
public:
    void test() override { cout << "test"; }
    void disp() const override { cout << "b"; }
};




int main() {
	
	
	/*
	B b;
	A* ptr(nullptr);
	
	ptr = &b;
	display(ptr);
	*/
	
	A* a = new A();
B b;
a = &b;
a->disp();
	
}
