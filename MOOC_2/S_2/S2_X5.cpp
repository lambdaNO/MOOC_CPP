#include <iostream>
using namespace std;

class Rectangle {
private:
    double h, l;
public:
    Rectangle()
      : h(2.0), l(4.0)
    { }
    Rectangle(double h1, double l1)
      : h(h1), l(l1)
    { h = h * 2.0;l = l * 4.0; }
    void display(){std::cout << h << ", " << l << std::endl;}
};

class Customer {
private:
    int id;
    double* money;
public:
    Customer() = default;
    Customer(int id1, double* money1)
      : id(id1), money(money1)
    { }
    Customer(Customer const& _other) = default;
    ~Customer(){
       std::cout << "Id: " << id << " destroyed" << std::endl;
       *money = 0;
     }
     double getMoney(){ return *money; }
     void addMoney(double amount) { *money += amount; }
     void display() { std::cout << "Id: " << id << ", amount = " << *money << std::endl; }
};

/*
int main()
{
    Rectangle r1;
    Rectangle r2(1.0, 1.0);
    r1.display();
    r2.display();
    return 0;
}
*/

int main()
{
     double money = 200.0;
     Customer c1;
     {
          Customer c2(2, &money);
          c1 = c2;
          c2.addMoney(100.0);
          c2.display();
     }
     if( c1.getMoney() >= 200.0 )
        { std::cout << "Has 200" << std::endl; } 
     else 
        {std::cout << "No 200" << std::endl;}
     c1.display();
     return 0;
}
