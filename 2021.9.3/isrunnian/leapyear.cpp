#include<iostream>
using namespace std;

int main()
{
    int year;
    bool isLeapYear;
    cout <<"Enter the year:";
    cin>>year;
    isLeapYear=(((year%4==0)&&(year%100!=0))||(year%400==0));
    if (isLeapYear)
    {
        cout <<year<<"is" << endl;
    }else
    {
        cout <<year<<"is not" << endl;
    }


    return 0;
}
