#include <iostream>
using namespace std;

class Test {
private:
    int val;
public:
    Test(Test& other) : val(other.val + 1) {}
    Test(int val_) : val(val_) {}
    int get_val() const { return val; }
    Test const& operator=(Test const& other) {
        val = other.val;
        return *this;
    }
};

ostream& operator<<(ostream& sortie, Test const& t) {
     sortie << t.get_val();
     return sortie;
}

int main()
{
    Test a(1), b(2);
    a = b;
    cout << a << " " << b;
}
