#include<iostream>
using namespace std;

struct student{
    int num;
    char name[20];
    char gender;
};
int main(){
    student s={10,"asd",'M'};
    cout << s.num<< endl;
    cout << sizeof(s.num)<< endl;
    cout << sizeof(s.name)<< endl;
    cout << sizeof(s.gender)<< endl;
    cout << sizeof(s)<< endl;
    return 0;
}


