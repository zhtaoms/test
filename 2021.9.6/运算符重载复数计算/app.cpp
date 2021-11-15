#include <iostream>
#include <string.h>
using namespace std;

class Complex{
private:
    double m_r,m_i;
public:
    Complex(double r=0,double i=0){
        m_r=r;
        m_i=i;
    }
    Complex operator+(Complex p);
    Complex operator-(Complex p);
    Complex operator*(Complex p);
    Complex operator/(Complex p);
    void dispaly();
};
void Complex::dispaly()
{
    if(m_i>0){
   cout <<this->m_r<<"+"<<this->m_i<< endl;
    }
    if(m_i<=0)
    {
   cout <<this->m_r<<"+"<<this->m_i<< endl;

    }
}
Complex Complex::operator+(Complex p)
{
    Complex t;
    t.m_i=this->m_i+p.m_i;
    t.m_r=this->m_r+p.m_r;
    return t;

}
Complex Complex::operator-(Complex p)
{
    Complex t;
    t.m_i=this->m_i-p.m_i;
    t.m_r=this->m_r-p.m_r;
    return t;

}


Complex Complex::operator*(Complex p)
{
    Complex t;
    t.m_i=this->m_r*p.m_i+this->m_i*p.m_r;
    t.m_r=this->m_r*p.m_r-this->m_i*p.m_i;
    return t;

}


Complex Complex::operator/(Complex p)
{
    Complex t;
    double fenmu=1/(p.m_r*p.m_r+p.m_i*p.m_i);
    cout <<fenmu << endl;
    t.m_i=(this->m_i*p.m_r-this->m_r*p.m_i)*fenmu;
    t.m_r=(this->m_r*p.m_r+p.m_i*p.m_i)*fenmu;
    return t;

}




int main(){
    Complex a(1,2),b(1,2);
   Complex c=a/b;
   c.dispaly();

 
}
