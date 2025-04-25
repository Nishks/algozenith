#include<iostream>
#include<algorithm>
#include <string>

using namespace std;

class Person{
public:
    string GetName(){
        return name_;
    }
    void SetName(string name){
        name_ = name;
    }

    string GetAddress(){
        return address_;
    }
    void SetAddress(string address){
        address_ = address;
    }
    
    int GetAge(){
        return age;
    }
    void SetAge(int age){
        age = age;
    }

private:
    int age;
    string name_;
    string address_;
};


int main(){
    Person p1;
    p1.SetName("nishkarsh");
    cout << p1.GetName() << endl;
}