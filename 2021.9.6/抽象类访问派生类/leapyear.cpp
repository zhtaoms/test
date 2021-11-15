#include<iostream>
using namespace std;
class B{
public:
    void f(){g();}
    virtual void g(){
        cout <<"B::g";
    }
};

class D:public B{
public:
    void g(){cout <<"D::g\n";}
};
int main(int argc, char const *argv[])
{
    D d;
    d.f();
    return 0;
}

