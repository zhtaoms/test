#include <iostream>
using namespace std;
class Point{
protected:
    int x,y;
public:
    Point(int a,int b=0) {
        x=a;  y=b;
        cout<<"constructing point("<<x<<","<<y<<")"<<endl;
    }
};
class Line:public Point{
protected:
    int len;
public:
    Line(int a,int b,int l):Point(a,b) {	//¹¹Ôìº¯Êý³õÊ¼»¯ÁÐ±í
        len=l;
        cout<<"Constructing Line,len ..."<<len<<endl;
    }
};
int main(){
    Line L1(1,2,3);
    system("pause");
}
