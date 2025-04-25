#include <bits/stdc++.h>
using namespace std;

class A
{
public:
    A(int a, int b) : a_(a), b_(b) {}

    void print()
    {
        cout << "a: " << a_ << " b: " << b_ << endl;
    }

private:
    int a_;
    int b_;
};

int main()
{
    // A obj1(3,2);
    A obj1{3, 2};
    obj1.print();
}