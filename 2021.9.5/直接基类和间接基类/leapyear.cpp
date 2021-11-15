#include <iostream>
using namespace std;
class A { 
    int x;
public: 
    A(int aa) {
        x=aa;
        cout<<"Constructing A"<<endl;
    }
    ~A(){ cout<<"Destructing A"<<endl; }
};
class B:public A {
public: 
    B(int x):A(x){ cout<<"Constructing B"<<endl; }
    ~B(){ cout<<"Destructing B"<<endl; }

};
class C :public B{
public: 
    C(int y):B(y){ cout<<"Constructing C"<<endl; }
    ~C(){ cout<<"Destructing c"<<endl; }    
};
int main(){
    C c(1);
    system("pause");
}
