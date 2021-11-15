#include<iostream>
using namespace std;
#define PI 3.1415
#define fanceprice 35.0
#define streetprice 20.0

class Circle
{
    private:
        float r;
    public:
        Circle(float rad);
        float Circlefance();
        float Area();
};

Circle::Circle(float rad)
{
    r=rad;
}

float Circle::Circlefance()
{
    return 2*r*PI;
}
float Circle::Area()
{
    return PI*r*r;
}

int main(){
    float rad;
    cout <<"请输入泳池的半径：" << endl;
    cin>>rad;
    Circle pool(rad);
    Circle pooladd(rad+3);
    float pricefance =(pool.Circlefance()+pooladd.Circlefance())*fanceprice;
    float pricestreet=(pooladd.Area()-pool.Area())*streetprice;
    cout<<"过道的价格为："<< pricestreet<< endl;
    cout<<"栏栅的价格为："<< pricefance<< endl;

    return 0;
}


