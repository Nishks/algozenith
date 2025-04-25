#include <bits/stdc++.h>
using namespace std;

class A
{
public:
    A(int a)
    {
        cout << "Constructor of A is called" << endl;
        a_ = a;
    }
    int GetA() { return a_; }

    ~A()
    {
        cout << "Destructor of A is called" << endl;
    }

private:
    int a_;
};

class B
{
public:
    B(int a)
    {
        cout << "Constructor of B is called" << endl;
        a_ = a;
    }
    int GetA() { return a_; }

    ~B()
    {
        // Clean up operations
        cout << "Destructor of B is called" << endl;
    }

private:
    int a_;
};

//

void dummy()
{
    A obj(3);
}

int main()
{
    // {
    //     A obj(3);
    //     // cout << obj.GetA() << endl;
    // }
    dummy();
    B obj(5);
}