#include <iostream>
using namespace std;

class Base{
private:
    int x;
public:
    Base(int a){
    x=a;
    cout <<"Base constructor x="<<x << endl;
    }
    ~Base(){cout <<"Base desconstructor"<< endl;}

};

class Derived:public Base{
private:
    int y;
public:
    Derived(int a,int b):Base(a){
        y=b;
    cout <<"Derived constructor y="<<y << endl;
    }
    ~Derived(){
        cout <<"Derived desconstructor " << endl;
    }
};

int main(){
    Derived d(1,2);
    system("pause");
}
